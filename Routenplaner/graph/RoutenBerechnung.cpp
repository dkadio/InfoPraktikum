/*
 * RoutenBerechnung.cpp
 *
 *  Created on: 22.05.2014
 *      Author: christoph
 */

#include "RoutenBerechnung.h"

RoutenBerechnung::RoutenBerechnung(Knoten *start, Knoten *ziel, Graph* graph) {
	this->start = start;
	this->ziel = ziel;
	this->dijkstrahraph = graph;
}

RoutenBerechnung::~RoutenBerechnung() {
	//TODO Destruktor testen
	while (!graph.empty()) {
		delete graph.top();
		graph.pop();
	}
}

void RoutenBerechnung::routeBerechnen() {
	startdijkstra();
}

void RoutenBerechnung::kanteErstellen(Kante* vorgaengerKante,
		Knoten* endKnoten) {
	graph.push(new Kante(vorgaengerKante, endKnoten));
}

void RoutenBerechnung::nachfolgerEinpflegen(Kante *vorgengerKante,
		Knoten* knoten) {
	for (auto it = knoten->getNachfolger().begin();
			it != knoten->getNachfolger().end(); it++) {
		kanteErstellen(vorgengerKante, *it);
	}
}

void RoutenBerechnung::startdijkstra() {

	bool allebesucht = false;
	Knoten * aktuellerKnoten = start;
	start->setDistanz(0);
	start->setVorgaenger(start);

	while (!allebesucht) {
		list<Knoten*> nachfolgerListe = aktuellerKnoten->getNachfolger();
		for (auto it = nachfolgerListe.begin(); it != nachfolgerListe.end();
				it++) {

			cout << "\n\naendereVorgaenger ";
			cout << (*it)->getEigenschaften()->getId();
			(*it)->aendereVorgaenger(aktuellerKnoten);

		}
		aktuellerKnoten->setBesucht(true);
		aktuellerKnoten = getKuerzesterNachfolger();
		allebesucht = true;
		for (auto it = dijkstrahraph->getKnotenListe().begin();
				it != dijkstrahraph->getKnotenListe().end(); it++) {
			if (!(*it)->isBesucht()) {
				allebesucht = false;
			}
		}
		cout << "\n #####################################";
	}
}

// suche hier nach knoten die noch nicht besucht wurden

Knoten* RoutenBerechnung::getKuerzesterNachfolger() {
	//durchsuche den ganzen graphen nach den knoten die die geringste distanz aufweisen
	Knoten* naechsterknoten;
	vector<Knoten*> min;
	auto first = min.begin();
	auto last = min.end();
	auto smallest = first;
	for (auto it = dijkstrahraph->getKnotenListe().begin();
			it != dijkstrahraph->getKnotenListe().end(); it++) {
		if ((*it)->getDistanz() > -1 && !(*it)->isBesucht()) {
			min.push_back(*it);
		}
	}
	while (++first!=last)
	    if ((*first)->getDistanz()<(*smallest)->getDistanz())    // or: if (comp(*first,*smallest)) for version (2)
	      smallest=first;
	  naechsterknoten = (*smallest);
	  cout << "\n\n kuerzeste distannz " << naechsterknoten->getDistanz() << "\n \n";
	cout << "return "<< naechsterknoten->getId();
	return naechsterknoten;
}

