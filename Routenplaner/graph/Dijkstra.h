/*
 * Dijkstra.h
 *
 *  Created on: 28.05.2014
 *      Author: christoph
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "PriorityQueue.h"

using namespace std;

/**
 * Diese Klasse enth&auml;t die eigentlichen Methoden, um den Dijkstra Algorithmus
 * abzuwickeln.
 */
class Dijkstra {
public:
	Dijkstra(Graph* graph);
	virtual ~Dijkstra();

	/**
	 * Diese Methode startet den Dijkstra Algorithmus.
	 * @param startKnoten Der Knoten, von dem der Weg starten soll.
	 * @param endKnoten Der Knoten, an dem der Weg enden soll.
	 * @return Eine Liste mit dem besten Weg. Von startKnoten nach endKnoten.
	 *
	 */
	list<Knoten*> starteDijkstra(Knoten* startKnoten, Knoten *endKnoten);
private:
	Graph * graph;
};

#endif /* DIJKSTRA_H_ */
