/*
 * BenutzerInterface.cpp
 *
 *  Created on: 06.05.2014
 *      Author: christoph
 */

#include "BenutzerInterface.h"

BenutzerInterface::BenutzerInterface(LokationsVerwaltung* lokVerwaltung) {
	this->lokVerwaltung = lokVerwaltung;
	this->suchKlasse = new SuchenKlasse(lokVerwaltung);

}

BenutzerInterface::~BenutzerInterface() {
	delete lokVerwaltung;
	delete suchKlasse;
}
//TODO Eingaben Typsicher machen
void BenutzerInterface::zeigeHauptMenue() {
	unsigned int auswahl = ENDE;
	do {
		cout << "\nWas wollen Sie tun?";
		cout << "\nEnde durch - " << ENDE;
		cout << "\n" << NAMEN_SUCHEN << " - oeffnet die Suche nach einem Namen";
		cout << "\n" << ID_SUCHEN << " - oeffnet die Suche nach einer Id";
		cout << "\n" << ALLE_LOKS << " - gibt alle Lokationen aus";
		cout << "\n" << GEMEINSAMKEITEN
				<< " - startet die Suche nach Gemeinsamkeiten";
		cout << "\nAuswahl: ";
		cin >> auswahl;
		cin.clear();
		switch (auswahl) {
		case NAMEN_SUCHEN:
			zeigeSuche();
			break;
		case ID_SUCHEN:
			zeigeIdSuche();
			break;
		case ALLE_LOKS:
			zeigeAlle();
			break;
		case GEMEINSAMKEITEN:
			gemeinsamkeitenSuchen();
			break;
		default:
			cout << "\nFalsche Auswahl!\n";

		}
	} while (auswahl != ENDE);
}

void BenutzerInterface::zeigeSuche() {
	cout << "Geben Sie den Namen der gesuchten Lokation ein: ";
	string suchString = "";
	cin >> suchString;
	cin.clear();
	vector<Gebietslokation*> treffer = lokVerwaltung->suchen(suchString);
	cout << vectorAusgeben(&treffer);
	if (treffer.empty()) {
		return;
	}
	cout << "\nWelche Lokation moechten Sie sich weiter betrachten?"
			<< " Waehlen Sie bitte die entsprechende Nummer:";
	unsigned int nummer = 0;
	cin >> nummer;
	if (nummer < treffer.size()) {
		zeigeFeinMenue(treffer.at(nummer));
	} else {
		cout << "So gross ist der Vector gar nicht.";
	}
}

void BenutzerInterface::zeigeIdSuche() {
	cout << "Geben Sie die Id der gesuchten Lokation ein: ";
	int suchString = ENDE;
	cin >> suchString;
	cin.clear();
	vector<Gebietslokation*> treffer = lokVerwaltung->suchen(suchString);
	for (int i = 0; i < treffer.size(); i++) {
		cout << "\n\n Stelle: " << i;
		cout << treffer.at(i)->toString();
	}
	if (treffer.empty()) {
		return;
	}
	cout << "\nWelche Lokation moechten Sie sich weiter betrachten?"
			<< " Waehlen Sie bitte die entsprechende Nummer:";
	unsigned int nummer = 0;
	cin >> nummer;
	if (nummer < treffer.size()) {
		zeigeFeinMenue(treffer.at(nummer));
	} else {
		cout << "So gross ist der Vector gar nicht.";
	}
}

void BenutzerInterface::zeigeFeinMenue(Gebietslokation* lok) {
	int klassenTyp = lok->getType();
	int eingabe = 0;
	do {
		cout << "\nWas moechten Sie mit der Lokation tuen?";
		cout << "\nEnde durch -" << ENDE;
		if (klassenTyp >= GEBIET) {
			cout << "\nName anzeigen - " << NAME_ANZEIGEN;
		}
		if (klassenTyp > GEBIET) {
			cout << "\nUebergeordnete Lokation anzeigen - "
					<< UEBERGEORDNETE_LOKATION_ANZEIGEN;
		}
		if (klassenTyp > LINEAR) {
			cout << "\nUebergeordnete Strasse anzeigen - "
					<< UEBERGEORDNETE_STRASSE_ANZEIGEN;
		}
		if (klassenTyp >= GEBIET) {
			cout << "\nPositive Offeset anzeigen - " << POFFSET_ANZEIGEN;
		}
		if (klassenTyp >= GEBIET) {
			cout << "\nNegative Offeset anzeigen - " << NOFFSET_ANZEIGEN;
		}
		cout << "\nId anzeigen - " << ID_ANZEIGEN;
		if (klassenTyp > 1) {
			cout << "\nKoordinaten anzegen - " << KOORDINATE_ANZEIGEN;
		}
		if (klassenTyp == LINEAR) {
			cout << "\nPunktlokationen ausgeben - " << LINEAR_AUSGEBEN;
		}
		cout << "\nJetzt waehlen: ";
		cin >> eingabe;

		//TODO evtl. noch Pruefung vor dem casten
		switch (eingabe) {
		case NAME_ANZEIGEN:
			cout << "\n" << lok->getFirstName();
			break;
		case UEBERGEORDNETE_LOKATION_ANZEIGEN:
			cout << "\n";
			if (((Linearlokation*) lok)->getAreaReference() != NULL) {
				cout << ((Linearlokation*) lok)->getAreaReference()->toString()
						<< "\n";
			} else {
				cout << "Keine Area Reference gefunden";
			}
			break;
		case UEBERGEORDNETE_STRASSE_ANZEIGEN:
			cout << "\n";
			if (((Punktlokation*) lok)->getLinearReference() != NULL) {
				cout << ((Punktlokation*) lok)->getLinearReference()->toString()
						<< "\n";
			} else {
				cout << "Keine Linear Reference gefunden";
			}
			break;
		case POFFSET_ANZEIGEN:
			cout << "\n";
			if (((Linearlokation*) lok)->getPositiveOffset() != NULL) {
				cout << ((Linearlokation*) lok)->getPositiveOffset()->toString()
						<< "\n";
			} else {
				cout << "Kein Positive Offeset gefunden";
			}
			break;

		case NOFFSET_ANZEIGEN:
			cout << "\n";
			if (((Linearlokation*) lok)->getNegativeOffset() != NULL) {
				cout << ((Linearlokation*) lok)->getNegativeOffset()->toString()
						<< "\n";
			} else {
				cout << "Kein Negative Offeset gefunden";
			}
			break;
		case KOORDINATE_ANZEIGEN:
			cout << "\n";
			if (((Punktlokation*) lok)->getGeoKoordinate() != NULL) {
				cout << ((Punktlokation*) lok)->getGeoKoordinate()->toString()
						<< "\n";
			} else {
				cout << "Keine Geo Koordinate gefunden";
			}
			break;
		case LINEAR_AUSGEBEN:
			linearAusgeben((Linearlokation*) lok);
		default:
			cout << "\nDu kannst gar nichts.";
		}
	} while (eingabe != ENDE);
}

void BenutzerInterface::zeigeAlle() {
	for (auto it = lokVerwaltung->getGebieteMap().begin();
			it != lokVerwaltung->getGebieteMap().end(); it++) {
		cout << "\nName: " << it->first << "Value: " << it->second->toString();
	}
}

void BenutzerInterface::linearAusgeben(Linearlokation* linLok) {
	//cout << vectorAusgeben(&(linLok->getPunktLokations()));
}

void BenutzerInterface::gemeinsamkeitenSuchen() {
	int steuerEingabe = ENDE;
	vector<Gebietslokation*> treffer;
	do {
		steuerEingabe = ENDE;
		cout << suchKlasse->zeigeSuchOptionen() << "\nJetzt waehlen: ";
		cin >> steuerEingabe;
		cout << "\nBitte den gesuchten Wert eingeben: ";
		try {
			switch (suchKlasse->getDatenTyp(steuerEingabe)) {
			case INT: {
				int auswahl = sicherIntLesen();
				treffer = suchKlasse->suchen(steuerEingabe, auswahl);
				break;
			}
			case BOOL: {
				bool auswahl = (bool) sicherIntLesen();
				treffer = suchKlasse->suchen(steuerEingabe, auswahl);
				break;
			}
			case CHAR: {
				char auswahl = *(sicherStringLesen().begin());
				treffer = suchKlasse->suchen(steuerEingabe, auswahl);
				break;
			}
			case STRING: {
				string auswahl = sicherStringLesen();
				treffer = suchKlasse->suchen(steuerEingabe, auswahl);
				break;
			}
			case POINTER:
				cout << "\nFunktion hier nicht verfuegbar.\n";
				break;
			case UNSIGNED: {
				unsigned int auswahl = (unsigned int) sicherDoubleLesen();
				treffer = suchKlasse->suchen(steuerEingabe, auswahl);
				break;
			}
			case ENDE:
				//MAch nichts
				break;
			default:
				cout << "\nFalsche Eingabe\n";
			}
			cout << vectorAusgeben(&treffer);
		} catch (TypProblemEcxeption &e) {
			cerr << e.what();
		}
	} while (steuerEingabe != ENDE);
}

string BenutzerInterface::vectorAusgeben(
		const vector<Gebietslokation*>* treffer) {
	ostringstream ausgabe;
	if (treffer->empty()) {
		ausgabe << "\nKeine Treffer enthalten.";
	}
	for (int i = 0; i < treffer->size(); i++) {
		ausgabe << "\n\n Stelle: --------------- " << i;
		ausgabe << (treffer->at(i))->toString();
	}
	return (ausgabe.str());
}

 string BenutzerInterface::vectorAusgeben(
 const vector<Linearlokation*>* treffer) {
 ostringstream ausgabe;
 for (int i = 0; i < treffer->size(); i++) {
 ausgabe << "\n\n Stelle: --------------- " << i;
 ausgabe << treffer->at(i)->toString();
 }
 if (treffer->empty()) {
 ausgabe << "\nKeine Treffer enthalten.";
 }
 return (ausgabe.str());
 }

 string BenutzerInterface::vectorAusgeben(
 const vector<Punktlokation*>* treffer) {
 ostringstream ausgabe;
 for (int i = 0; i < treffer->size(); i++) {
 ausgabe << "\n\n Stelle: --------------- " << i;
 ausgabe << treffer->at(i)->toString();
 }
 if (treffer->empty()) {
 ausgabe << "\nKeine Treffer enthalten.";
 }
 return (ausgabe.str());
 }
