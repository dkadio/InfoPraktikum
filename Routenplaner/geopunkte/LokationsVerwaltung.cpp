#include "LokationsVerwaltung.h"
LokationsVerwaltung::LokationsVerwaltung(vector<vector<string> > *datenSatz) {
	objekteErstellen(datenSatz);
}
LokationsVerwaltung::~LokationsVerwaltung() {
	//  Alle Daten l&ouml;schen.
	for (map<int, Gebietslokation*>::iterator it = gebieteMap.begin();
			it != gebieteMap.end(); it++) {
		delete it->second;
	}
	//Danach die leeren Pointer aus den Datenstrukturen entfernen
	gebieteMap.clear();

}

//Achtung, fehlerhaft und deprecated
void LokationsVerwaltung::objektErstellen(vector<string> *zeile,
		string pattern) {
    throw "Veraltete Methode in Lokalitaetsverwaltung aufgerufen";
	if (checkGebietsLokation(zeile)) {
		speichereGebietsLokation(new Gebietslokation(zeile));
	} else if (checkLineaLokation(zeile)) {
		new Linearlokation(zeile, (Gebietslokation*) NULL);
	} else if (checkPunktlokation(zeile)) {
		//cout << "Spalte 32  " << zeile->at(31) << "\n";
	}
}

void LokationsVerwaltung::speichereGebietsLokation(Gebietslokation* lokation) {
	insertMap(lokation);
}

void LokationsVerwaltung::speichereLinearLokation(vector<string>* zeile) {
	Gebietslokation *areaReference = gebieteMap.at(
			atoi(zeile->at(AREA_REFERENCE).c_str()));
	Linearlokation *linearLokation = new Linearlokation(zeile, areaReference);
	areaReference->addLinLokation(linearLokation);
	insertMap(linearLokation);

}

void LokationsVerwaltung::speicherePunkLokation(vector<string>* zeile) {
	Punktlokation *punkLokation;
	Linearlokation *linearReference = NULL;
	Gebietslokation *areaReference = NULL;
	if (!zeile->at(LINEAR_REFERENCE).empty()) {
		linearReference = (Linearlokation*) gebieteMap.at(
				atoi(zeile->at(LINEAR_REFERENCE).c_str()));
	}
	if (!zeile->at(AREA_REFERENCE).empty()) {
		areaReference = gebieteMap.at(atoi(zeile->at(AREA_REFERENCE).c_str()));
	}

	//(Linearreference und Georeference sind NULL)
	punkLokation = new Punktlokation(zeile, areaReference, linearReference);
	if (linearReference != NULL) {
		linearReference->addPktLokation(punkLokation);
	}
	insertMap(punkLokation);
}

void LokationsVerwaltung::objekteErstellen(vector<vector<string> >* datenSatz) {
//Erster Durchlauf, Erstellen der Gebietslokationen
	for (auto it = datenSatz->begin(); it != datenSatz->end(); it++) {
		if (checkGebietsLokation(&*it)) {
			speichereGebietsLokation(new Gebietslokation(&*it));
		}
	}
//Zeiter Durchlauf, Erstellen der Linearlokationen
	for (auto it = datenSatz->begin(); it != datenSatz->end(); it++) {
		if (checkLineaLokation(&*it)) {
			speichereLinearLokation(&*it);
		}
	}
//Dritter Durchlauf, Erstellen der Punktlokationen
	for (auto it = datenSatz->begin(); it != datenSatz->end(); it++) {
		if (checkPunktlokation(&*it)) {
			speicherePunkLokation(&*it);
		}
	}

	/*Vierter Durchlauf, Verknuepfung der Abhaengigkeiten
	 Abhaengigkeiten koennen nur zwischen Linear- und Punktlokationen
	 aufgebaut werden.*/
	for (auto it = datenSatz->begin(); it != datenSatz->end(); it++) {
		if (checkLineaLokation(&*it)) {
			((Linearlokation*) gebieteMap.find(atoi(it->at(LOCATIONCODE).c_str()))->second)->verweiseAufbauen(
					&gebieteMap, &*it);
		} else if (checkPunktlokation(&*it)) {
			((Punktlokation*) gebieteMap.find(atoi(it->at(LOCATIONCODE).c_str()))->second)->verweiseAufbauen(
					&gebieteMap, &*it);
		}
	}
}

void LokationsVerwaltung::insertMap(Gebietslokation* lok) {
	gebieteMap.insert(pair<int, Gebietslokation*>(lok->getId(), lok));
}

Gebietslokation* LokationsVerwaltung::suchName(string name) {
	//deprecated
	//return (namenMap.find(name)->second);
	return NULL;
}


bool LokationsVerwaltung::checkGebietsLokation(vector<string>* zeile) {
	return (regex_match(zeile->at(TYPE), regex("\"A(.*)")));
}

bool LokationsVerwaltung::checkLineaLokation(vector<string>* zeile) {
	return (regex_match(zeile->at(TYPE), regex("\"L(.*)")));
}

vector<Gebietslokation*> LokationsVerwaltung::suchen(string name) {
	return (suchen(name, false));
}

vector<Gebietslokation*> LokationsVerwaltung::suchen(int id) {
	vector<Gebietslokation*> vec;
	vec.push_back(gebieteMap.find(id)->second);
	return (vec);
}

vector<Gebietslokation*> LokationsVerwaltung::suchen(string name,
		bool uebereinstimmung) {
	vector<Gebietslokation*> vec;
	if (uebereinstimmung) {
		for (auto it = gebieteMap.begin(); it != gebieteMap.end(); it++) {
			if (it->second->getFirstName() == name) {
				vec.push_back(it->second);
			}
		}
	} else {
		string regEx = "(.*)";
		regEx += name;
		regEx += "(.*)";
		for (auto it = gebieteMap.begin(); it != gebieteMap.end(); it++) {
			if (regex_match(it->second->getFirstName(), regex(regEx))) {
				vec.push_back(it->second);
			}
		}
	}
	return (vec);
}

const map<int, Gebietslokation*>& LokationsVerwaltung::getGebieteMap() const {
	return (gebieteMap);
}

bool LokationsVerwaltung::checkPunktlokation(vector<string>* zeile) {
	return (regex_match(zeile->at(TYPE), regex("\"P(.*)")));
}

bool LokationsVerwaltung::validierePunklokation(int id) {
	try {
		//Testen, ob das gefundene Objekt eine Pkt Lok ist
		Gebietslokation *lok = gebieteMap.at(id);
		if (lok->getType() == PUNKT) {
			return (true);
		} else {
			return (false);
		}
	} catch (out_of_range &e) {
		//Wenn kein Objekt hinter dieser Id steht
		return (false);
	}
}
