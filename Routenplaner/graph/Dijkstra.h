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

	/**
	 * Diese Methode errechnet lediglich den Graphen mit den k&uuml;rzesten Wegen
	 * von einem gegebenen Startknoten aus. Die Berechnung ist in
	 * @ink starteDijkstra(Knoten* startKnoten, Knoten *endKnoten) @endlink
	 * beschrieben.
	 * @param startKnoten Der Konten, von dem aus die k&uuml;rzesten Wege berechnet
	 * werden sollen.
	 */
	void starteDijkstra(Knoten* startKnoten);
	/**
	 * Diese Methode sortiert die Reihenfolge einer Liste um.
	 */
	list<Knoten*> dreheListe(list<Knoten*> * liste);

	/**
	 * Diese Methode berechnet die k&uuml;zeste Route in einem fertigen
	 * Graphen.<br>
	 * Bevor diese Methode aufgerufen werden darf, m&uuml;ssen die k&uuml;zesten
	 * Wege bereits von einem Startknoten aus berechnet worden sein.
	 */
	list<Knoten*> getRoute(Knoten* startKnoten, Knoten* endKnoten);

private:
	/**
	 * Dieses Attribut enth&auml;lt den eigentlichen Graphen.<br>
	 * Aus diesem wird die Priority Queue gef&uuml;llt und der k&uuml;zeste Weg berechnet.
	 */
	Graph * graph;

};

#endif /* DIJKSTRA_H_ */
