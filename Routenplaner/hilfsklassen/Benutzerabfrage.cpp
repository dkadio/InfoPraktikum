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
	this->ziel = NULL;
	this->start = NULL;
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
	cout << "\nEnde: " << ENDE << "\n";
	cout << "Berechne die Route: " << ROUTE_BERECHNEN << "\n";
	cout << "Ziel eingeben: " << ZIEL_EINLESEN << "\n";
	cout << "Start eingeben: " << START_EINLESEN << "\n";
}

void Benutzerabfrage::leseitemein(int eingabe) {

	switch (eingabe) {
	case ENDE:
		cout << "\nProgramm wird beendet\n";
		break;
	case ROUTE_BERECHNEN:
		//starte dijkstraklasse
		if(ziel != NULL || start != NULL){
			routeberechnen();
		}else{
			if(ziel != NULL){
				cout << "Bitte Start knoten angeben\n";
			}else{
				cout << "Bitte Ziel Knoten angeben\n";
			}
		}
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
		cout << "\nUngueltige Einagbe\n";
		break;
	}

}

Knoten* Benutzerabfrage::sucheNachNamen() {
	vector<Knoten*> ergebnisliste;
	do{
	cout << "\nGeben Sie den Namen der gesuchten Lokation ein: ";
	string suchString = "";
	cin >> suchString;
	ergebnisliste = this->graph->sucheName(suchString);
	//gib die ergebnisse aus und les die id des knotens ein
	auto begin = ergebnisliste.begin();
	auto end = ergebnisliste.end();
	int i = 0;
	for (;begin != end; begin++) {
		cout << "\nKnotennummer: " << i;
		cout << (*begin)->getEigenschaften()->toString();
		cout << "\n\n################################################\n";
	}
	cout << "\ngefundene elemente: " << ergebnisliste.size();
	}while(ergebnisliste.size() == 0);
	cout << "\nBitte geben Sie die Knotennummer. ein" << "\n";
	int knotenId = 0;

	cin >> knotenId;

	return ergebnisliste.at(knotenId);

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
