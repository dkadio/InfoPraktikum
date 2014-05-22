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

	bool isVisited() const {
		return (visited);
	}

	/**
	 * &Uuml;berladen des Vergleichsoperators.<br>
	 * Dieser wird f&uuml;r die Sortierung der Queue ben&ouml;tigt.
	 */
	bool operator <(const Kante * other) const {
		if (this->isVisited()) {
			return false;
		} else if (other->isVisited()) {
			return (true);
		}
		return this->getDistanz() < other->getDistanz();
	}

	 Knoten* getNach() const;
	 Knoten* getVon() const;
	 Kante* getVorgaengerKante() const;

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
	 * Dieses Attribut dient der Darstellung der Route.
	 */
	Kante *vorgaengerKante;

	/**
	 * Die Distanz vom Startknoten, des Graphen bis zum zweiten Knoten der
	 * Kante.
	 */
	float distanz;

	bool visited;
};

/**
 * Ben&ouml;tigtes Struct f&uuml;r den Pririt&auml;tsvergleich.<br>
 * Dieses Struct muss der Queue mitgegeben werden, damit sie die Knoten Objekte
 * vergleichen kann.<br>
 * Wenn der Linke Comperat schon besucht wurde, wird false zur&uuml;ck gegeben, wenn der
 * rechte Comperant besucht wurde, wird true zur&uuml;ck gegeben.
 */
struct less {
	bool operator()(Kante* lhs, Kante* rhs) {
		if (lhs->isVisited()) {
			return false;
		} else if (rhs->isVisited()) {
			return (true);
		}
		return lhs->getDistanz() < rhs->getDistanz();
	}
};

#endif /* KANTE_H_ */
