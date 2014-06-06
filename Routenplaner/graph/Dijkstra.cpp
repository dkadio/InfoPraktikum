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
	starteDijkstra(startKnoten);
	PriorityQueue queue = PriorityQueue(graph, startKnoten);
	 queue.queueInitialisieren(startKnoten);
	 Knoten * aktuellerKnoten = queue.getFirst();
	 while (aktuellerKnoten != NULL) {
	 queue.nacholfgerEintragen(aktuellerKnoten);
	 aktuellerKnoten = queue.getFirst();
	 }
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
    return(ergebnis);
	//return (getRoute(startKnoten, endKnoten));
}

void Dijkstra::starteDijkstra(Knoten* startKnoten) {
	PriorityQueue queue = PriorityQueue(graph);
	queue.queueInitialisieren(startKnoten);
	Knoten * aktuellerKnoten = queue.getFirst();
	while (aktuellerKnoten != NULL) {
		queue.nacholfgerEintragen(aktuellerKnoten);
		aktuellerKnoten = queue.getFirst();
	}
}

list<Knoten*> Dijkstra::dreheListe(list<Knoten*>* liste) {
	list<Knoten*> rueckwaertsErgebnis;
	list<Knoten*> ergebnis;
	//Jetzt die Liste umdrehen, damit die Strecke nicht von Ende nach Start angezeigt wird
	for (auto it = liste->rbegin();
			it != liste->rend(); it++) {
		ergebnis.push_back(*it);
	}
	return (ergebnis);

}

list<Knoten*> Dijkstra::getRoute(Knoten* startKnoten, Knoten* endKnoten) {
	//Ergebnis vom Endknoten aus aufbauen
	list<Knoten*> rueckwaertsErgebnis;
	Knoten* ergebnisKnoten = endKnoten;
	while (ergebnisKnoten != NULL && ergebnisKnoten != startKnoten) {
		rueckwaertsErgebnis.push_back(ergebnisKnoten);
		ergebnisKnoten = ergebnisKnoten->getVorgaenger();
	}
	return (dreheListe(&rueckwaertsErgebnis));
}
