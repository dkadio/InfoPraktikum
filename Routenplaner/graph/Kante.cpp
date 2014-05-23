/*
 * Kante.cpp
 *
 *  Created on: 22.05.2014
 *      Author: christoph
 */

#include "Kante.h"

Kante::Kante(Kante *von, Knoten *nach) {
	visited = false;
	if (von == NULL || nach == NULL) {
		distanz = 0;
        von = NULL;
	} else {
		Knoten *start = von->nach;
		this->distanz = von->getDistanz() + start->berechneLaenge(nach);
        this->von = start;

	}
	this->vorgaengerKante = von;
    this->nach = nach;

}

Kante::~Kante() {
	// Da braucht nichts destruiert zu werden
}

float Kante::getDistanz() const {
	return distanz;
}

Knoten* Kante::getNach() const {
	return nach;
}

Knoten* Kante::getVon() const {
	return von;
}

Kante* Kante::getVorgaengerKante() const {
	return vorgaengerKante;
}

void Kante::setVisited(bool visited) {
	this->visited = visited;
}
