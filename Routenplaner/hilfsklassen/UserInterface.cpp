#include "UserInterface.h"

UserInterface::UserInterface() {
	FileOpener *datei = new FileOpener();
	datei->oeffneDatei(dateiPfad);
	datei->leseDateiAus();
	vector<vector<string> > erg = datei->getDatensatz();
	this->lokalitaetsVerwaltung = new LokationsVerwaltung(&erg);
	delete datei;
	this->graph = new Graph(this->lokalitaetsVerwaltung->getGebieteMap());
	this->startKnoten = NULL;
	this->zielKnoten = NULL;
}

UserInterface::~UserInterface() {
	delete this->graph;
	delete this->lokalitaetsVerwaltung;
}

int main(void) {
	cout
			<< "\nDie Datensaetze werden vorbereitet\nDies kann eine Weile dauern...\n";
	UserInterface userInterface = UserInterface();
	int eingabe = -1;

	while (eingabe != 0) {
		cout << userInterface.getMenue();
		eingabe = sicherIntLesen();
		userInterface.switchMenueEingabe(eingabe);
	}

}

string UserInterface::getMenue() {
	ostringstream ausgabe;
	ausgabe << "\n";
	ausgabe << ENDE << " - um das Programm zu beenden\n";
	ausgabe << " - um den Startknoten zu waehlen\n";
	if (startKnoten != NULL) {
		ausgabe << ZIEL << " - um den Zielknoten zu waehlen\n";
	}
	ausgabe << "Bitte jetzt waehlen: ";
	return ausgabe.str();
}

string UserInterface::switchMenueEingabe(int eingabe) {
	ostringstream ausgabe;
	string name = "";
	Knoten * zielKnoten;
	switch (eingabe) {
	case ENDE:
		ausgabe << "\nVielen Dank fuer die Benutzung des Programms";
		break;
	case START:
		this->startKnoten = knotenEinlesen();
		ausgabe << "\nDer Graph wird berechnet";
		break;
	case ZIEL:
		zielKnoten = knotenEinlesen();
		break;
	default:
		ausgabe << "\nIhre Eingabe war leider ungueltig";
	}
	return (ausgabe.str());
}

string UserInterface::vectorAusgeben(vector<Knoten*>* liste) {
	ostringstream ausgabe;
	if (liste->size() == 0) {
		ausgabe << "\nKeine Knoten gefunden!";
		return (ausgabe.str());
	}
	auto it = liste->begin();
	for (int i = 0; i < liste->size(); i++) {
		ausgabe << i << " " << (*it)->toString();
	}
	return (ausgabe.str());
}

Knoten* UserInterface::getKnoten(vector<Knoten*>* liste, int stelle) {
	auto it = liste->begin();
	*it = NULL;
	for (int i = 0; i < stelle; i++) {
		it++;
	}
	return (*it);
}

Knoten* UserInterface::knotenEinlesen() {
	cout << "Bitte geben Sie den Namen des gesuchten Knotens ein: ";
	string name = sicherStringLesen();
	vector<Knoten*> ergebnisVector = graph->sucheName(name);
	vectorAusgeben(&ergebnisVector);
	cout << "\nBitte geben Sie die gewuenschte Nummer des Knoten ein: ";
	int knotenNummer = sicherIntLesen();
	return (getKnoten(&ergebnisVector, knotenNummer));

}
