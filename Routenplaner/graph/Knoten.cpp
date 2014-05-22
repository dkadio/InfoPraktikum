/*
 * Knoten.cpp
 *
 *  Created on: 13.05.2014
 *      Author: deniz
 */

#include "Knoten.h"

Knoten::~Knoten() {
	//Hier bloss nichts destruieren!
	//Die enthaltenen Punklokationen werden an anderer Stelle destruiert
}

Knoten::Knoten(Punktlokation* punktLokation) {
	this->eigenschaften = punktLokation;
	this->besucht = false;
	this->distanz = 10000000;
}

void Knoten::addNachfolger(Knoten* nachfolger) {
	this->nachfolger.push_back(nachfolger);
}

float Knoten::berechneLaenge(Knoten * derAnnere) {
	return (derAnnere->getEigenschaften()->getGeoKoordinate()->entfernungBerechnen(
			this->eigenschaften->getGeoKoordinate()));
}

int Knoten::getId() {
	return (eigenschaften->getId());
}

string Knoten::toString() {
	ostringstream s;
	s<<"";
	s << "\nName: " << eigenschaften->getFirstName() << " Anzahl Nachfolger: "
			<< nachfolger.size()<< " Id=" <<this->getEigenschaften()->getId();
	return (s.str());
}

const list<Knoten*>& Knoten::getNachfolger() const {
	return nachfolger;
}
