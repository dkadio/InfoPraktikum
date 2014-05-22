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
		distanz = von->getDistanz() + von->nach->berechneLaenge(nach);
        this->von = von->nach;

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
