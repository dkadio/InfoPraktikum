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
	 * Diese Methode startet den Dijkstra Algorithmus.<br>
	 * Sie tr&auml;gt die Nachfolger aller Knoten in die Priority Queue ein.<br>
	 * Die Relaxierung findet in der Priority Queue statt.
	 * Nachdem alle Nachfolger eingetragen sind, sucht die Methode
	 * den Weg vom gegebenen Endknoten zum Startknoten und ordnet die
	 * Liste r&uuml;ckw&auml;rts an.
	 * @param startKnoten Der Knoten, von dem der Weg starten soll.
	 * @param endKnoten Der Knoten, an dem der Weg enden soll.
	 * @return Eine Liste mit dem k&uuml;rzesten Weg. Von startKnoten nach endKnoten.
	 *
	 */
	list<Knoten*> starteDijkstra(Knoten* startKnoten, Knoten *endKnoten);
private:
	/**
	 * Dieses Attribut enth&auml;lt den eigentlichen Graphen.<br>
	 * Aus diesem wird die Priority Queue gef&uuml;llt und der k&uuml;zeste Weg berechnet.
	 */
	Graph * graph;
};

#endif /* DIJKSTRA_H_ */
