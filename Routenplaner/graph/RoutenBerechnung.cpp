/*
 * RoutenBerechnung.cpp
 *
 *  Created on: 22.05.2014
 *      Author: christoph
 */

#include "RoutenBerechnung.h"

RoutenBerechnung::RoutenBerechnung(Knoten *start, Knoten *ziel, Graph* graph) {
	this->start = start;
	this->ziel = ziel;
	this->dijkstrahraph = graph;
}

RoutenBerechnung::~RoutenBerechnung() {
	//TODO Destruktor testen
	while (!graph.empty()) {
		delete graph.top();
		graph.pop();
	}
}

void RoutenBerechnung::routeBerechnen() {
	startdijkstra();
}

void RoutenBerechnung::kanteErstellen(Kante* vorgaengerKante,
		Knoten* endKnoten) {
	graph.push(new Kante(vorgaengerKante, endKnoten));
}

void RoutenBerechnung::nachfolgerEinpflegen(Kante *vorgengerKante,
		Knoten* knoten) {
	for (auto it = knoten->getNachfolger().begin();
			it != knoten->getNachfolger().end(); it++) {
		kanteErstellen(vorgengerKante, *it);
	}
}

void RoutenBerechnung::startdijkstra() {
	//startpunkt im graph suchen
	//Punktlokation* a = dijkstrahraph->knotenListe.front();
	/*	for (auto startiterator = dijkstrahraph->getKnotenListe().begin();
	 startiterator != dijkstrahraph->getKnotenListe().end();
	 startiterator++) {
	 cout << ((Knoten*) *startiterator)->toString();
	 }*/
	//nachfolger anschauen, distanzen der nachfolger eintragen und vorgaenger setzen
	Knoten * aktuellerKnoten = start;
	start->setDistanz(0);
	while (!aktuellerKnoten->isBesucht()) {
		list<Knoten*> nachfolgerListe = aktuellerKnoten->getNachfolger();
		for (auto it = nachfolgerListe.begin(); it != nachfolgerListe.end();
				it++) {
			(*it)->aendereVorgaenger(aktuellerKnoten);
		}
		aktuellerKnoten->setBesucht(true);
		aktuellerKnoten = getKuerzesterNachfolger(aktuellerKnoten);
		cout<<"\n Distanz Aktueller Kniten: "<<aktuellerKnoten->getDistanz();
	}

	//den nachfolger nehmen der die kuerzeste distanz hat und besucht auf true setzen

	//selbes spiel mit diesem nachfolger
}

Knoten* RoutenBerechnung::getKuerzesterNachfolger(Knoten* knoten) {
	float kuerzesteDistanz = (*knoten->getNachfolger().begin())->getDistanz();
	Knoten* ausgbae = (*knoten->getNachfolger().begin());
	for (auto it = knoten->getNachfolger().begin();
			it != knoten->getNachfolger().end(); it++) {
		if ((*it)->getDistanz() < kuerzesteDistanz) {
			kuerzesteDistanz = (*it)->getDistanz();
			ausgbae = (*it);
		}
	}
	return (ausgbae);
}
