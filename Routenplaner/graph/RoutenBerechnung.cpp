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
	for (auto startiterator = dijkstrahraph->getKnotenListe().begin();
			startiterator != dijkstrahraph->getKnotenListe().end();
			startiterator++) {
		cout << ((Knoten*) *startiterator)->toString();
	}
	//nachfolger anschauen, distanzen der nachfolger eintragen und vorgaenger setzen
	list<Knoten*> nachfolgerListe = start->getNachfolger();
	for(auto it = nachfolgerListe.begin(); it != nachfolgerListe.end(); it++){
		((Knoten*)*it)->aendereVorgaenger(start);
	}
	//den nachfolger nehmen der die kuerzeste distanz hat und besucht auf true setzen

	//selbes spiel mit diesem nachfolger
}
