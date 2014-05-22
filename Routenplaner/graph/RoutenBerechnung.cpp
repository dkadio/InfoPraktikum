/*
 * RoutenBerechnung.cpp
 *
 *  Created on: 22.05.2014
 *      Author: christoph
 */

#include "RoutenBerechnung.h"

RoutenBerechnung::RoutenBerechnung(Knoten *start, Knoten *ziel) {
	this->start = start;
	this->ziel = ziel;
}

RoutenBerechnung::~RoutenBerechnung() {
	//TODO Destruktor testen
	while(!graph.empty()){
		delete graph.top();
		graph.pop();
	}
}

void RoutenBerechnung::routeBerechnen() {
	nachfolgerEinpflegen(NULL, start);
}

void RoutenBerechnung::kanteErstellen(Kante* vorgaengerKante,
		Knoten* endKnoten) {
	graph.push(new Kante(vorgaengerKante, endKnoten));
}

void RoutenBerechnung::nachfolgerEinpflegen(Kante *vorgengerKante,Knoten* knoten) {
	for(auto it = knoten->getNachfolger().begin(); it != knoten->getNachfolger().end(); it++){
		kanteErstellen(vorgengerKante,*it);
	}
}
