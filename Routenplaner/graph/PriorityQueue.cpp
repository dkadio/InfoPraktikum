/*
 * PriorityQueue.cpp
 *
 *  Created on: 28.05.2014
 *      Author: christoph
 */

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(Graph * graph) {
	graph->clear();

}

PriorityQueue::PriorityQueue(Graph* graph, Knoten* startKnoten) :
		PriorityQueue(graph) {
	queueInitialisieren(startKnoten);
}

PriorityQueue::~PriorityQueue() {
	// TODO Auto-generated destructor stub
}

void PriorityQueue::knotenEintragen(Knoten* vorgaenger, Knoten* knoten) {
	//Erst mal checken, ob es den Knoten schon in der Queue gibt
	if (!knoten->isBesucht()) {
		try {
			//Testen ob bereits drin
			queue.at(knoten->getId());
		} catch (out_of_range &e) {
			//Wenn nicht eintragen
			//TODO Die insert Methode testen
			queue[knoten->getId()]= knoten;
		}
	}
	//Dann checken, ob sich was verbessert, quasi relaxieren
	float distanzAktuell = knoten->getDistanz();
	float distanzNeu = vorgaenger->getDistanz();
	distanzNeu +=
			knoten->getEigenschaften()->getGeoKoordinate()->entfernungBerechnen(
					vorgaenger->getEigenschaften()->getGeoKoordinate());
	if (distanzAktuell == IN_FINITY || distanzNeu < distanzAktuell) {
		knoten->setVorgaenger(vorgaenger);
		knoten->setDistanz(distanzNeu);
	}
}

void PriorityQueue::nacholfgerEintragen(Knoten* knoten) {
	for (auto it = knoten->getNachfolger().begin();
			it != knoten->getNachfolger().end(); it++) {
		knotenEintragen(knoten, *it);
	}

}

void PriorityQueue::queueInitialisieren(Knoten* startknoten) {
	nacholfgerEintragen(startknoten);
}

Knoten* PriorityQueue::getFirst() throw (out_of_range) {
	Knoten * rueckgabe = NULL;
	auto it = queue.begin();
//Das erste nicht besuchte Element finden
	do {
		if (it++->second->isBesucht()) {
			rueckgabe = it->second;
		}
	} while (!it->second->isBesucht());
//Die kleinste nicht besuchte Distanz suchen
	while (it != queue.end()) {
		if (it->second->isBesucht()) {
			if (it->second->getDistanz() < rueckgabe->getDistanz()) {
				rueckgabe = it->second;
			}
		}
	}
	if (rueckgabe == NULL) {
		throw(out_of_range("Es gibt keine weiteren Elemente in der Queue"));
	} else {
		return (rueckgabe);
	}
}
