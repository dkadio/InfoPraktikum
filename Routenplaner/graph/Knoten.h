/*
 * Knoten.h
 *
 *  Created on: 13.05.2014
 *      Author: deniz
 */

#ifndef KNOTEN_H_
#define KNOTEN_H_

#define IN_FINITY -1
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
	int getId();

	string toString();

	Punktlokation* getEigenschaften() {
		return (eigenschaften);
	}

	/**
	 * Diese Methode setzt den Vorg&auml;nger des Knotens auf NULL und die Distanz#
	 * auf INFINITY.
	 */
	void clear();
	list<Knoten*> getNachfolger() const;

	bool isBesucht() const;
	float getDistanz() const;
	Knoten* getVorgaenger() const;
	void setBesucht(bool besucht);
	void setDistanz(float distanz);
	void setVorgaenger(Knoten* vorgaenger);

private:
	/**
	 * Der Vorgaenger des Knoten, dieser dient der sp&auml;teren Verfolgung des
	 * k&uuml;zesten Weges.
	 */
	Knoten * vorgaenger;

	Punktlokation* eigenschaften; //getid ist die knotennummer
	list<Knoten*> nachfolger;

	/**
	 * Enth&auml;lt die Distanz bis zum Startknoten.
	 */
	float distanz;

	bool besucht;
};
#endif /* KNOTEN_H_ */
