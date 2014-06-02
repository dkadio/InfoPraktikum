/*
 * Benutzerabfrage.cpp
 *
 *  Created on: 02.06.2014
 *      Author: deniz
 */

#include "Benutzerabfrage.h"

Benutzerabfrage::Benutzerabfrage(Graph* graph) {
	// TODO Auto-generated constructor stub
	this->graph = graph;
}

Benutzerabfrage::~Benutzerabfrage() {
}

void Benutzerabfrage::startebenutzerabfrage() {
	int eingabe = ENDE;
	do {
		zeigemenu();
		cin >> eingabe;
		leseitemein(eingabe);
	} while (eingabe != ENDE);
}

void Benutzerabfrage::zeigemenu() {
	cout << "Ende: " << ENDE << "\n";
	cout << "Berechne die Route: " << ROUTE_BERECHNEN << "\n";
	cout << "Ziel eingeben: " << ZIEL_EINLESEN << "\n";
	cout << "Start eingeben: " << START_EINLESEN << "\n";
}

void Benutzerabfrage::leseitemein(int eingabe) {

	switch (eingabe) {
	case ENDE:
		cout << "Programm wird beendet\n";
		break;
	case ROUTE_BERECHNEN:
		//starte dijkstraklasse
		routeberechnen();
		break;
	case ZIEL_EINLESEN:
		//starte einlesen nach namen
		this->ziel = sucheNachNamen();
		break;
	case START_EINLESEN:
		//starte einlesen nach namen
		this->start = sucheNachNamen();
		break;

	default:
		cout << "Ungueltige Einagbe\n";
		break;
	}

}

Knoten* Benutzerabfrage::sucheNachNamen() {
	cout << "\nGeben Sie den Namen der gesuchten Lokation ein: ";
	string suchString = "";
	cin >> suchString;
	cout << "\nihre eingabe: " << suchString;
	vector<Knoten*> ergebnisliste = this->graph->sucheName(suchString);
	//gib die ergebnisse aus und les die id des knotens ein
	auto begin = ergebnisliste.begin();
	auto end = ergebnisliste.end();
	for (begin != end; begin++) {
		cout << (*begin)->getEigenschaften()->toString();
	}
	cout << "\nBitte geben Sie die Id des Knotens ein" << "\n";
	int knotenId = 0;

	cin >> knotenId;

	return graph->getKnoten(knotenId);

	/*
	 cout << "\nVor Objekt erstellen";
	 cout << "\nVor Routenberechnung";
	 Knoten* start = graph->getKnoten(24178);
	 Knoten* ende = graph->getKnoten(772);

	 */
}

void Benutzerabfrage::routeberechnen() {
	//this->ziel = graph->getKnoten(772);
	//this->start = graph->getKnoten(24178)
	Dijkstra *dijkstra = new Dijkstra(this->graph);

	cout << " dijkstra erstellt\n";

	list<Knoten*> ergebnis = dijkstra->starteDijkstra(this->start, this->ziel);
	cout << " dijkstra berechnet\n";
	cout << "\n\nRoute: ";
	for (auto it = ergebnis.begin(); it != ergebnis.end(); it++) {
		cout << "\n" << (*it)->getEigenschaften()->getFirstName()

		<< " Strasse: " << (*it)->getEigenschaften()->getRoadNumber()
				<< " Entfernung: " << (*it)->getDistanz();
	}
	cout << "\n";

	delete dijkstra;
}
