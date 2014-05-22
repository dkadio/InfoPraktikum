/*
 * LokationsVerwaltung.cpp
 *
 *  Created on: 26.04.2014
 *      Author: christoph
 */

#include "LokationsVerwaltung.h"
LokationsVerwaltung::LokationsVerwaltung(vector<vector<string> > *datenSatz) {
	objekteErstellen(datenSatz);
}
LokationsVerwaltung::~LokationsVerwaltung() {
	/**
	 * Alle Daten l&ouml;schen.
	 */
	for (map<int, Gebietslokation*>::iterator it = gebieteMap.begin();
			it != gebieteMap.end(); it++) {
		delete it->second;
	}
	gebieteVector.clear();
	gebieteMap.clear();
	namenMap.clear();

}

void LokationsVerwaltung::objektErstellen(vector<string> *zeile,
		string pattern) {
	if (checkGebietsLokation(zeile)) {
		speichereGebietsLokation(new Gebietslokation(zeile));
	} else if (checkLineaLokation(zeile)) {
		new Linearlokation(zeile, (Gebietslokation*) NULL);
	} else if (checkPunktlokation(zeile)) {
		cout << "Spalte 32  " << zeile->at(31) << "\n";
	}
}

void LokationsVerwaltung::speichereGebietsLokation(Gebietslokation* lokation) {
	gebieteVector.push_back(lokation);
	insertMap(lokation);
}

void LokationsVerwaltung::speichereLinearLokation(vector<string>* zeile) {
	Gebietslokation *areaReference = gebieteMap.at(
			stoi(zeile->at(AREA_REFERENCE)));
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
				stoi(zeile->at(LINEAR_REFERENCE)));
	}
	if (!zeile->at(AREA_REFERENCE).empty()) {
		areaReference = gebieteMap.at(stoi(zeile->at(AREA_REFERENCE)));
	}

	//TODO Hier suchen, wenn seltsame Fehler auftreten.
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
			((Linearlokation*) gebieteMap.find(stoi(it->at(LOCATIONCODE)))->second)->verweiseAufbauen(
					&gebieteMap, &*it);
		} else if (checkPunktlokation(&*it)) {
			((Punktlokation*) gebieteMap.find(stoi(it->at(LOCATIONCODE)))->second)->verweiseAufbauen(
					&gebieteMap, &*it);
		}
	}
}

void LokationsVerwaltung::insertMap(Gebietslokation* lok) {
	gebieteMap.insert(pair<int, Gebietslokation*>(lok->getId(), lok));
	namenMap.insert(pair<string, Gebietslokation*>(lok->getFirstName(), lok));
}

Gebietslokation* LokationsVerwaltung::suchName(string name) {
	//deprecated
	return (namenMap.find(name)->second);
}

const multimap<string, Gebietslokation*>& LokationsVerwaltung::getNamenMap() const {
	return (namenMap);
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
	//TODO Suche testen
	vector<Gebietslokation*> vec;
	if (uebereinstimmung) {
		for (auto it = gebieteMap.begin(); it != gebieteMap.end(); it++) {
			if (it->second->getFirstName() == name) {
				vec.push_back(it->second);
			}
		}
	} else {
		//TODO Suche testen und ggf effizient gestalten
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
		Gebietslokation *lok = gebieteMap.at(id);
		if (lok->getType() == PUNKT) {
			return (true);
		} else {
			return (false);
		}
	} catch (out_of_range &e) {
		return (false);
	}
}
