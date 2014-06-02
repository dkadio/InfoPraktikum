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
	Knoten * aktuellerKnoten = queue.getFirst();
	while (aktuellerKnoten != NULL) {
		queue.nacholfgerEintragen(aktuellerKnoten);
		if (aktuellerKnoten == NULL) {
			cout << "Dijkstra fertig";
		}
		aktuellerKnoten = queue.getFirst();
	}

	//Hier noch pruefen, ob alle Knoten verlinkt sind

	//Ergebnis vom Endknoten aus aufbauen
	list<Knoten*> rueckwaertsErgebnis;
	Knoten* ergebnisKnoten = endKnoten;
	while (ergebnisKnoten != NULL && ergebnisKnoten != startKnoten) {
		rueckwaertsErgebnis.push_back(ergebnisKnoten);
		ergebnisKnoten = ergebnisKnoten->getVorgaenger();
	}
	list<Knoten*> ergebnis;
	//Jetzt die Liste umdrehen, damit die Strecke nicht von Ende nach Start angezeigt wird
	for (auto it = rueckwaertsErgebnis.rbegin();
			it != rueckwaertsErgebnis.rend(); it++) {
		ergebnis.push_back(*it);
	}
	return (ergebnis);
}
