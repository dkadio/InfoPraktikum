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
			queue[knoten->getId()] = knoten;
		}
	}
	//Dann checken, ob sich was verbessert, quasi relaxieren
	knotenRelaxieren(vorgaenger, knoten);
}

void PriorityQueue::nacholfgerEintragen(Knoten* knoten) {
	list<Knoten*> nachfolger = knoten->getNachfolger();
	//Wenn die Nachfolger eines Knoten eingetragen wurden, dann setze ihn auf besucht
	knoten->setBesucht(true);
	for (auto it = nachfolger.begin(); it != nachfolger.end(); it++) {
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
		if (!(it->second->isBesucht())) {
			rueckgabe = it->second;
		}
		it++;
	} while (rueckgabe == NULL && it != queue.end());
	//Wenn es keine nicht besuchten Knoten gibt->aussteigen
	if (rueckgabe == NULL) {
		return rueckgabe;
	}
	//Die kleinste nicht besuchte Distanz suchen
	//Wenn noch nicht besucht, dann pruefe, ob der Iterator kleiner
	//als das aktuell kleinste Element
	while (it != queue.end()) {
		if (!it->second->isBesucht()) {
			if (it->second->getDistanz() < rueckgabe->getDistanz()) {
				rueckgabe = it->second;
			}
		}
		it++;
	}
	return (rueckgabe);
}

void PriorityQueue::knotenRelaxieren(Knoten* vorgaenger, Knoten* knoten) {
	float distanzAktuell = knoten->getDistanz();
	float distanzNeu = vorgaenger->getDistanz();
	distanzNeu +=
			knoten->getEigenschaften()->getGeoKoordinate()->entfernungBerechnen(
					vorgaenger->getEigenschaften()->getGeoKoordinate());
	if (distanzAktuell == IN_FINITY || distanzNeu < distanzAktuell) {
		knoten->setVorgaenger(vorgaenger);
		knoten->setDistanz(distanzNeu);
		//Sorgt dafuer, dass von hier aus neu relaxiert wird.
		//TODO Testen, ob hier Fehler auftreten (wie z.B. Dauerschleifen ;-))
		//knoten->setBesucht(false);
	}
}

int PriorityQueue::getSize() {
	return (queue.size());
}
