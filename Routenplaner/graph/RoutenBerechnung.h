/*
 * RoutenBerechnung.h
 *
 *  Created on: 22.05.2014
 *      Author: christoph
 */

#ifndef ROUTENBERECHNUNG_H_
#define ROUTENBERECHNUNG_H_

#include "Kante.h"
#include <queue>
#include <list>
#include <algorithm>
#include "Graph.h"

//TODO stdlib wieder entfernen (War Nur zum Testen)
#include <stdlib.h>

using namespace std;
/**
 * Die Klasse Routenberechnung &uuml;bernimmt die eigentliche Routenberechnung.<br>
 * Hierzu wird der gesamte Graph durchlaufen und durch die Priority Queue relaxiert.
 */
class RoutenBerechnung {
public:
	RoutenBerechnung(Knoten *start, Knoten *ziel, Graph *graph);
	virtual ~RoutenBerechnung();

	/**
	 * Diese Methode berechnet die Route.
	 */
	void routeBerechnen();

	/**
	 * Diese Methode erstellt eine Kante und pflegt diese in den den Graphen ein.
	 * @param vorgaengerKante Ein Pointer auf die Vorg&auml;nger Kante.
	 * @param endKnoten Ein Pointer auf den zweiten Knoten der Kante.
	 */
	void kanteErstellen(Kante *vorgaengerKante, Knoten * endKnoten);

	/**
	 * Diese Methode pflegt die Nachfolger eines Knoten in den Grapfen ein.
	 * @param knoten Der Knoten, dessen Nachfolger eingepfelgt werden sollen.
	 */
	void nachfolgerEinpflegen(Kante *vorgengerKante,Knoten* knoten);
	void startdijkstra();

	/**
	 * Diese Methode gibt den k&uuml;rzesten Nachfolger zu dem gegebenen
	 * Knoten.
	 * @param Der Knoten, dessen Nachfolger gesucht werden sollen.
	 * @return Der Nachfolger mit der k&uuml;rzesten Distanz.
	 */
	Knoten* getKuerzesterNachfolger();
private:
	priority_queue<Kante*,vector<Kante*>, Kante::less> graph;

	/**
	 * Der Startknoten, von dem aus die Route berechnet werden soll.
	 */
	Knoten *start;
	/**
	 * Der Zielknoten, von dem aus die Route berechnet werden soll.
	 */
	Knoten *ziel;
	Graph *dijkstrahraph;
};

#endif /* ROUTENBERECHNUNG_H_ */
