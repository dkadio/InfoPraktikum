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
	clear();
}

void Knoten::addNachfolger(Knoten* nachfolger) {
	this->nachfolger.push_back(nachfolger);
}

float Knoten::berechneLaenge(Knoten * derAnnere) {
	 float a = (derAnnere->getEigenschaften()->getGeoKoordinate()->entfernungBerechnen(
			this->eigenschaften->getGeoKoordinate()));
	 cout << "\nberechnete laenge in berechne laenge von ";
	 cout << derAnnere->getEigenschaften()->getId();
	 cout << " nach ";
	 cout <<  this->getEigenschaften()->getId();
	 cout << ": ";
	 cout << a;
	 return a;
}

int Knoten::getId() {
	return (eigenschaften->getId());
}

string Knoten::toString() {
	ostringstream s;
	s << "";
	s << "\nName: " << eigenschaften->getFirstName() << " Anzahl Nachfolger: "
			<< nachfolger.size() << " Id=" << this->getEigenschaften()->getId();
	return (s.str());
}

const list<Knoten*>& Knoten::getNachfolger() const {
	return nachfolger;
}

void Knoten::aendereVorgaenger(Knoten* vorgaenger) {
	if (distanz < 0) {
		this->vorgaenger = vorgaenger;
		distanz = vorgaenger->getDistanz();
		cout << "\n** laenge des vorgaengers :";
		cout << distanz;
		distanz += this->berechneLaenge(vorgaenger);
	}
	if ((vorgaenger->getDistanz() + this->berechneLaenge(vorgaenger)) < distanz) {
		this->vorgaenger = vorgaenger;
		this->distanz = vorgaenger->getDistanz() + berechneLaenge(vorgaenger);
	}
}

void Knoten::clear() {
	this->besucht = false;
	this->distanz = -1;
}
