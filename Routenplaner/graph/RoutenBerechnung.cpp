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
	while (!graph.empty()) {
		delete graph.top();
		graph.pop();
	}
}


void RoutenBerechnung::routeBerechnen() {
	//Die ersten Kanten aufbauen
    kanteErstellen(NULL, start);
	//Den ersten Endknoten initialisieren
	Knoten *aktuellerEndknoten = start;
	Kante *aktuelleEndkante;

	//Solange der beste Weg, bzw. dessen Endknoten nicht das Ziel ist
	while (aktuellerEndknoten != this->ziel && !aktuelleEndkante->isVisited()) {
		//Die schnellste nicht besuchte Kante aus queue ziehen
		aktuelleEndkante = graph.top();
		//cout<<"\n"<<aktuelleEndkante->getDistanz()<< "Id: "<<aktuelleEndkante->getVon()->getId()<<"\n";
		aktuelleEndkante->setVisited(true);
		//Endknoten fuer das Schleifenkriterium und das Einpflegen zuweisen
		aktuellerEndknoten = aktuelleEndkante->getNach();
		//Vom besten Weg die Nachfolger einpflegen
		nachfolgerEinpflegen(aktuelleEndkante, aktuellerEndknoten);
	}
}



void RoutenBerechnung::kanteErstellen(Kante* vorgaengerKante,
		Knoten* endKnoten) {
	graph.push(new Kante(vorgaengerKante, endKnoten));
}

void RoutenBerechnung::nachfolgerEinpflegen(Kante *vorgengerKante,
		Knoten* knoten) {
	for (auto it = knoten->getNachfolger().begin();
			it != knoten->getNachfolger().end(); it++) {
		cout<<"\n Wird neu angelegt: "<< (*it)->getId();
		kanteErstellen(vorgengerKante, *it);
	}
}
