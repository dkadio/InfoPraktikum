/*
 * Graph.cpp
 *
 *  Created on: 13.05.2014
 *      Author: deniz
 */

#include "Graph.h"

Graph::Graph(map<int, Gebietslokation*> rohDaten) {
	map<int, Knoten*> konstruktionsMap;
	erstelleKnoten(konstruktionsMap, rohDaten);
	verlinkeKnoten(konstruktionsMap, rohDaten);
	//TODO Pruefen, ob hier Destruktoren aufgerufen werden
	konstruktionsMap.clear();
}

Graph::~Graph() {
	for (auto it = knotenListe.begin(); it != knotenListe.end(); it++) {
		delete *it;
	}
	knotenListe.clear();
}

void Graph::erstelleKnoten(map<int, Knoten*>& konstruktionsMap,
		const map<int, Gebietslokation*>& rohdaten) {
	//Alle Elemente durchlaufen
	for (auto it = rohdaten.begin(); it != rohdaten.end(); it++) {
		//Pruefen, ob Element eine Punklokation ist
		Punktlokation *pktLok = (Punktlokation*) it->second;
		if (pktLok->getType() == PUNKT) {
			Knoten *k = new Knoten(pktLok);
			knotenListe.push_back(k);
			konstruktionsMap[k->getEigenschaften()->getId()] = k;
		}
	}
}

void Graph::verlinkeKnoten(map<int, Knoten*> konstruktionsMap,
		const map<int, Gebietslokation*> &rohdaten) {
	for (list<Knoten*>::iterator it = knotenListe.begin();
			it != knotenListe.end(); it++) {
		Knoten *knoten = *it;
		Punktlokation *pLok = knoten->getEigenschaften();
		//POffset als Nachfolger eintragen
		if (pLok->getPositiveOffset() != NULL) {
			knoten->addNachfolger(konstruktionsMap[pLok->getId()]);
		}
		//NOffset als Nachfolger eintragen
		if (pLok->getNegativeOffset() != NULL) {
			knoten->addNachfolger(konstruktionsMap[pLok->getId()]);
		}
		//Den Intersectioncode als Nachfolgereintragen
		if (pLok->getIntersectioncode() != NULL) {
			try {
				knoten->addNachfolger(
						konstruktionsMap.at(
								pLok->getIntersectioncode()->getId()));
			} catch (out_of_range &e) {
				cout << "\nIntersectioncode nicht gefunden";
				cout
						<< "\nDas Programm wird aufgrund des unerwarteten Fehlers beendet";
				exit(EXIT_FAILURE);
			}
		}
	}

}

string Graph::toString() {
	ostringstream s;
	s << "\nAusgabe des Graphen: \n";
	for (auto it = knotenListe.begin(); it != knotenListe.end(); it++) {
		s << ((Knoten*) *it)->toString();
	}
	s << "\nEnde Graph\n";
	s << "Der Graph enthaelt " << knotenListe.size() << " Elemente.\n";
	return (s.str());
}

Knoten* Graph::getKnoten(int id) {
	for (auto it = knotenListe.begin(); it != knotenListe.end(); it++) {
		if ((*it)->getId() == id) {
			return (*it);
		}
	}
	throw out_of_range("Der gesuchte Knoten konnte nicht gefunden werden.");
}

void Graph::clear() {
	for (auto it = knotenListe.begin(); it != knotenListe.end(); it++) {
		(*it)->clear();
	}
}

const list<Knoten*>& Graph::getKnotenListe() const {
	return knotenListe;
}
