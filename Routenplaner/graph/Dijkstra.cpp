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
		aktuellerKnoten = queue.getFirst();
		if (aktuellerKnoten == NULL) {
			cout << "\n\nDijkstra fertisch";
		}
	}

	//Hier noch pruefen, ob alle Knoten verlinkt sind

	//Ergebnis vom Endknoten aus aufbauen
	cout << "\nVor erster Liste";
	list<Knoten*> rueckwaertsErgebnis;
	Knoten* ergebnisKnoten = endKnoten;
	while (ergebnisKnoten != NULL) {
        cout<<"\nErgebnis: "<<ergebnisKnoten->getVorgaenger()->getEigenschaften()->getFirstName();
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
