/*
 * Kante.cpp
 *
 *  Created on: 22.05.2014
 *      Author: christoph
 */

#include "Kante.h"

Kante::Kante(Kante *von, Knoten *nach) {
	distanz = von->getDistanz() + von->nach->berechneLaenge(nach);
	this->von = von->nach;
	this->nach = nach;

}

Kante::~Kante() {
	// Da braucht nichts destruiert zu werden
}

float Kante::getDistanz() const {
	return distanz;
}
