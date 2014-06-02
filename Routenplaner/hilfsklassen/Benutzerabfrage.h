/*
 * Benutzerabfrage.h
 *
 *  Created on: 02.06.2014
 *      Author: deniz
 */

#ifndef BENUTZERABFRAGE_H_
#define BENUTZERABFRAGE_H_


#include "../graph/Graph.h"
#include  <iostream>
#include  "sicherLesen.h"
#include <string>
#include "../graph/Dijkstra.h"

#define ENDE 0
#define ROUTE_BERECHNEN 1
#define ZIEL_EINLESEN 2
#define START_EINLESEN 3

class Benutzerabfrage {
public:
	Benutzerabfrage(Graph* graph);
	virtual ~Benutzerabfrage();
	void startebenutzerabfrage();
private:
	Graph * graph;
	Knoten* ziel;
	Knoten* start;
	void zeigemenu();
	void leseitemein(int);
	Knoten* sucheNachNamen();
	void routeberechnen();
};


#endif /* BENUTZERABFRAGE_H_ */
