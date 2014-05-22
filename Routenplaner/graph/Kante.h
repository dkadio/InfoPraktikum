/*
 * Kante.h
 *
 *  Created on: 22.05.2014
 *      Author: christoph
 */

#ifndef KANTE_H_
#define KANTE_H_

#include "Knoten.h"
/**
 * Eine Kante ist durch zwei Punkte definiert. Einem Startknoten und einem Endknoten.<br>
 * Diese Klasse wird zum Berechnen des k&uuml;zesten Weges genutzt.
 */
class Kante {
public:
	/**
	 * Der Konstruktor der Kanten Klasse.<br>
	 * @param von Die Kante, von der aus die neue Kante erstellt wird. Daraus kann
	 * die bisherige Distanz vom Startknoten und der von Punkt der neuen Kante ermittelt
	 * werden.
	 * @param nach Der zweite Knoten der Kante.
	 */
	Kante(Kante *von, Knoten *nach);
	virtual ~Kante();
	float getDistanz() const;

private:
	/**
	 * Der erste Punkt der Kante.
	 */
	Knoten * von;
	/**
	 * Der zweite Punkt der Kante.
	 */
	Knoten * nach;
	/**
	 * Die Distanz vom Startknoten, des Graphen bis zum zweiten Knoten der
	 * Kante.
	 */
	float distanz;
};

/**
 * Ben&ouml;tigtes Struct f&uuml;r den Pririt&auml;tsvergleich.<br>
 * Dieses Struct muss der Queue mitgegeben werden, damit sie die Knoten Objekte
 * vergleichen kann.
 */
struct vergleichDistanzen {
	bool operator()(Kante* lhs, Kante* rhs) {
		return lhs->getDistanz() < rhs->getDistanz();
	}
};

#endif /* KANTE_H_ */
