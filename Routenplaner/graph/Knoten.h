/*
 * Knoten.h
 *
 *  Created on: 13.05.2014
 *      Author: deniz
 */

#ifndef KNOTEN_H_
#define KNOTEN_H_
#include <list>
#include "../geopunkte/Punktlokation.h"

/**
 * Diese Klasse repr&auml;sentiert einen Knotenpunkt im Graph.<br>
 * Ein Knoten hat maximal 3 Nachfolger,<br>
 * <ol>
 * 	<li>Positive Offset </li>
 * 	<li>Negative Offset </li>
 * 	<li>Intersection Code </li>
 * </ol><br>
 *
 */
using namespace std;
class Knoten {
public:
	Knoten(Punktlokation* punktLokation);
	virtual ~Knoten();
	void addNachfolger(Knoten *nachfolger);
	/**
	 * Berechnet die Distanz zu einem anderen Knoten.
	 * @param Der Knoten zu dem die Entfernung berechnet werden soll.
	 * @return Die Entfernung zu dem anderen Knoten in Kilometern.
	 */
	float berechneLaenge(Knoten * derAnnere);

	/**
	 * Diese Methode &auml;ndert in Abh&auml;ngigkeit, ob sich die Distanz verbessert
	 * den Vorg&auml;nger des Knotens und die Distanz zu ihm.
	 */
	void aendereVorgaenger(Knoten * vorgaenger);
	int getId();

	/**
	 * Diese Methode muss aufgerufen werden, bevor eine neue Route berechnet wird.
	 * <br>Sie setzt visited auf false und l&ouml;scht den Vorg&auml;nger.
	 */
	void clear();

	string toString();
	Punktlokation* getEigenschaften() {
		return (eigenschaften);
	}

	const list<Knoten*>& getNachfolger() const;

	bool isBesucht() const {
		return besucht;
	}

	void setBesucht(bool besucht) {
		this->besucht = besucht;
	}

	float getDistanz() const {
		return distanz;
	}

	void setDistanz(float distanz) {
		this->distanz = distanz;
	}

	const Knoten* getVorgaenger()  {
		return vorgaenger;
	}

	void setVorgaenger( Knoten*& vorgaenger) {
		this->vorgaenger = vorgaenger;
	}

private:
	Punktlokation* eigenschaften; //getid ist die knotennummer
	list<Knoten*> nachfolger;
	Knoten* vorgaenger;
	bool besucht;
	float distanz;
};
#endif /* KNOTEN_H_ */
