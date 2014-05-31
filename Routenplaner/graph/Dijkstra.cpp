/*
 * Dijkstra.cpp
 *
 *  Created on: 28.05.2014
 *      Author: christoph
 */

#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph* graph) {
	this->graph = graph;

}

Dijkstra::~Dijkstra() {
	this->graph = NULL;
}

list<Knoten*> Dijkstra::starteDijkstra(Knoten* startKnoten, Knoten* endKnoten) {
	PriorityQueue queue = PriorityQueue(graph, startKnoten);
	queue.queueInitialisieren(startKnoten);
	try {
		//Ich weiss, boehhse
		while (true) {
			Knoten * aktuellerKnoten = queue.getFirst();
			cout << "\nNachfolger: "
					<< aktuellerKnoten->getEigenschaften()->getFirstName();
			queue.nacholfgerEintragen(aktuellerKnoten);
		}
	} catch (out_of_range &e) {
		if (graph->size() != queue.getSize()) {
			std::cout << "\n\nDijsktra abgeschlossen\n\n";
			//Keine Ahnung irgendwas sollte man da machen, auch wenns nur ne Exception ist
		}
	}
	//Ergebnis vom Endknoten aus aufbauen
	list<Knoten*> rueckwaertsErgebnis;
	Knoten* ergebnisKnoten = endKnoten;
	while (ergebnisKnoten != NULL) {
		rueckwaertsErgebnis.push_back(ergebnisKnoten);
		ergebnisKnoten = ergebnisKnoten->getVorgaenger();
	}
	list<Knoten*> ergebnis;
	for (auto it = rueckwaertsErgebnis.rbegin();
			it != rueckwaertsErgebnis.rend(); it++) {
		ergebnis.push_back(*it);
	}
	return (ergebnis);
}
