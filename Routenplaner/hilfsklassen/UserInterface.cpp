#include "UserInterface.h"

UserInterface::UserInterface(Graph * graph) {
	this->graph = graph;
	this->dijkstra = new Dijkstra(graph);
	this->startKnoten = NULL;
}

UserInterface::~UserInterface() {
	//Graph wird in der Main destruiert
	delete this->dijkstra;
}

string UserInterface::getMenue() {
	ostringstream ausgabe;
	ausgabe << "\n";
	ausgabe << ENDE << " - um das Programm zu beenden\n";
	ausgabe << START << " - um den Startknoten zu waehlen\n";
	if (startKnoten != NULL && dijkstra != NULL) {
		ausgabe << ZIEL << " - um den Zielknoten zu waehlen\n";
	}
	ausgabe << "Bitte jetzt waehlen: ";
	return ausgabe.str();
}

string UserInterface::switchMenueEingabe(int eingabe) {
	ostringstream ausgabe;
	string name = "";
	Knoten * zielKnoten;
	list<Knoten*> ergebnis;
	switch (eingabe) {
	case ENDE:
		ausgabe << "\nVielen Dank fuer die Benutzung des Programms";
		break;
	case START:
		this->startKnoten = knotenEinlesen();
		cout << "\nDer Graph wird berechnet, diese Operation dauert ein wenig.";
		dijkstra->starteDijkstra(startKnoten);

		break;
	case ZIEL:
		zielKnoten = knotenEinlesen();
		ergebnis = dijkstra->getRoute(startKnoten, zielKnoten);
		ausgabe << listeAusgeben(ergebnis);
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
		ausgabe << "\n\nStelle: " << i << (*it)->toString();
		it++;
	}
	return (ausgabe.str());
}

Knoten* UserInterface::getKnoten(vector<Knoten*>* liste, int stelle) {
	return (liste->at(stelle));
}

Knoten* UserInterface::knotenEinlesen() {
	cout << "Bitte geben Sie den Namen des gesuchten Knotens ein: ";
	string name = sicherStringLesen();
	vector<Knoten*> ergebnisVector = graph->sucheName(name);
	cout << vectorAusgeben(&ergebnisVector);
	cout << "\nBitte geben Sie die gewuenschte Nummer des Knoten ein: ";
	int knotenNummer = sicherIntLesen();
	Knoten * ergebnis = getKnoten(&ergebnisVector, knotenNummer);
	return (ergebnis);

}

FileOpener* UserInterface::oeffneDatei() {
	FileOpener *datei = new FileOpener();
	datei->oeffneDatei(dateiPfad);
	datei->leseDateiAus();
	return (datei);
}

void UserInterface::start() {
	cout
			<< "\nDie Datensaetze werden vorbereitet\nDies kann eine Weile dauern...\n";
	int eingabe = -1;

	while (eingabe != 0) {
		cout << getMenue();
		eingabe = sicherIntLesen();
		cout << switchMenueEingabe(eingabe);
	}
}

string UserInterface::listeAusgeben(list<Knoten*> &liste) {
	ostringstream ausgabe;
	for (auto it = liste.begin(); it != liste.end(); it++) {
		ausgabe << (*it)->toString() << "\n";
	}
	return (ausgabe.str());
}
