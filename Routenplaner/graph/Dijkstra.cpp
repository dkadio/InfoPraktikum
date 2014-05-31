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
		Knoten * aktuellerKnoten = NULL;
		do {
			aktuellerKnoten = queue.getFirst();
			queue.nacholfgerEintragen(aktuellerKnoten);
			if (aktuellerKnoten == NULL) {
				cout << "\n\n\nNullknoten gefunden\n\n\n";
			}
		} while (aktuellerKnoten != NULL);
	} catch (out_of_range &e) {
		if (graph->size() != queue.getSize()) {
			//Keine Ahnung irgendwas sollte man da machen, auch wenns nur ne Exception ist
		}
	}
	//Ergebnis vom Endknoten aus aufbauen
	cout << "\nVor erster Liste";
	list<Knoten*> rueckwaertsErgebnis;
	Knoten* ergebnisKnoten = endKnoten;
	while (ergebnisKnoten != NULL) {
		rueckwaertsErgebnis.push_back(ergebnisKnoten);
		ergebnisKnoten = ergebnisKnoten->getVorgaenger();
	}
	list<Knoten*> ergebnis;
	cout << "\nIn die erste Liste geschaufelt";
	for (auto it = rueckwaertsErgebnis.rbegin();
			it != rueckwaertsErgebnis.rend(); it++) {
		ergebnis.push_back(*it);
	}
	return (ergebnis);
}
