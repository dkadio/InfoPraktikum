#include "Knoten.h"

Knoten::~Knoten() {
	//Hier bloss nichts destruieren!
	//Die enthaltenen Punklokationen werden an anderer Stelle destruiert
}

Knoten::Knoten(Punktlokation* punktLokation) {
	clear();
	this->eigenschaften = punktLokation;
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
	s << "";
	s << "\nName: " << eigenschaften->getFirstName()<< " , "<< eigenschaften->getRoadNumber();
	return (s.str());
}

string Knoten::toStringRoute() {
	ostringstream s;
	s << toString();
	s << " Entfernung zum Start: " << distanz << " Geo Koordninaten: "
			<< eigenschaften->getGeoKoordinate()->toString();
	return (s.str());
}

list<Knoten*> Knoten::getNachfolger() const {
	return nachfolger;
}

void Knoten::clear() {
	this->vorgaenger = NULL;
	this->distanz = IN_FINITY;
    this->besucht = false;
}

bool Knoten::isBesucht() const {
	return besucht;
}

float Knoten::getDistanz() const {
	return distanz;
}

Knoten* Knoten::getVorgaenger() const {
	return vorgaenger;
}

void Knoten::setBesucht(bool besucht) {
	this->besucht = besucht;
}

void Knoten::setDistanz(float distanz) {
	this->distanz = distanz;
}

void Knoten::setVorgaenger(Knoten* vorgaenger) {
	this->vorgaenger = vorgaenger;
}

