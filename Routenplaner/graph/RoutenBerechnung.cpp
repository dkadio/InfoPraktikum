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
	int i = 0;
	//startpunkt im graph suchen
	//Punktlokation* a = dijkstrahraph->knotenListe.front();
	/*	for (auto startiterator = dijkstrahraph->getKnotenListe().begin();
	 startiterator != dijkstrahraph->getKnotenListe().end();
	 startiterator++) {
	 cout << ((Knoten*) *startiterator)->toString();
	 }*/
	//nachfolger anschauen, distanzen der nachfolger eintragen und vorgaenger setzen
	Knoten * aktuellerKnoten = start;
	Knoten * vorherigerKnoten = start;
	Knoten * check;
	start->setDistanz(0);
	while (!aktuellerKnoten->isBesucht()
			|| aktuellerKnoten->getId() != start->getId()) {
		i++;

		cout
				<< "#########################\n\n\nstarte dijkstra###################\n";
		cout << "knoten " << i << "\n";
		cout << "suche nachfolgervon "
				<< aktuellerKnoten->getEigenschaften()->getId() << "\n";
		list<Knoten*> nachfolgerListe = aktuellerKnoten->getNachfolger();
		for (auto it = nachfolgerListe.begin(); it != nachfolgerListe.end();
				it++) {

			cout << (*it)->getEigenschaften()->getId();
			cout << "\n";

		}

		for (auto it = nachfolgerListe.begin(); it != nachfolgerListe.end();
				it++) {

			cout << "\n\naendereVorgaenger ";
			cout << (*it)->getEigenschaften()->getId();
			(*it)->aendereVorgaenger(aktuellerKnoten);
		}
		aktuellerKnoten->setBesucht(true);
		check = aktuellerKnoten;
		cout << "\ncheck knoten = " << check->getId();
		aktuellerKnoten = getKuerzesterNachfolger(aktuellerKnoten);
		cout << "\n Distanz Aktueller Knoten: " << aktuellerKnoten->getDistanz()
				<< " id: " << aktuellerKnoten->getEigenschaften()->getId();
		if (check->getId() == aktuellerKnoten->getId()) {
			if (aktuellerKnoten->getVorgaenger()->getId() == start->getId()) {
				cout << "\nvorgaenger ist start knoten! suche nach nachfolgern!"
						<< "\n";
				aktuellerKnoten = getKuerzesterNachfolger(start);
				if (aktuellerKnoten->getId() == start->getId()) {
					cout << "Ende des Algorithmus";
				}
			} else {

				aktuellerKnoten = aktuellerKnoten->getVorgaenger();
				aktuellerKnoten->setBesucht(false);
				cout << "\nsetze besucht auf false von "
						<< aktuellerKnoten->getId() << " : "
						<< aktuellerKnoten->isBesucht() << " " << false;

				cout << "\nAktueller knoten ist: " << aktuellerKnoten->getId();
			}
		}
		/*cout << "\nvorgaenger von "
		 << aktuellerKnoten->getEigenschaften()->getId() << " ist "
		 << aktuellerKnoten->getVorgaenger()->getId();
		 */
		cout << "\n #####################################";
	}

	// suche hier nach knoten die noch nicht besucht wurden
}

Knoten* RoutenBerechnung::getKuerzesterNachfolger(Knoten* knoten) {
	float kuerzesteDistanz = -1;// = (*knoten->getNachfolger().begin())->getDistanz();
	Knoten* ausgbae = ziel; //(*knoten->getNachfolger().begin());
	cout << "\n########suche kuerzeste distanz: \n";
	for (auto it = knoten->getNachfolger().begin();
			it != knoten->getNachfolger().end(); it++) {

		cout << "\nuntersuche ";
		cout << (*it)->getEigenschaften()->getId();
		cout << "\n";

		if (!(*it)->isBesucht()) {
			cout << "wurde noch nicht besucht\n";
			if (kuerzesteDistanz == -1) {
				cout << "\ndistanz war kleiner = -1 \n";
				kuerzesteDistanz = (*it)->getDistanz();
				ausgbae = (*it);
				cout << "\n distanz = " << kuerzesteDistanz << "\n";
			}
			if (kuerzesteDistanz > -1) {
				if ((*it)->getDistanz() < kuerzesteDistanz) {
					kuerzesteDistanz = (*it)->getDistanz();
					ausgbae = (*it);
					cout << "\n distanz = " << kuerzesteDistanz << "\n";
				}
			}

			cout << "kuerzeste distanz ist: ";
			cout << kuerzesteDistanz;
		} else {
			cout << " wurde bereits besucht!" << "\n";
		}

		/*	if ((*it)->getDistanz() < kuerzesteDistanz && !(*it)->isBesucht()) {
		 kuerzesteDistanz = (*it)->getDistanz();
		 ausgbae = (*it);
		 cout << ausgbae->getEigenschaften()->getId();

		 }*/

	}
	if (kuerzesteDistanz == -1) {
		cout
				<< "\nKein knoten der noch nicht besucht ist, nimm den vorgaenger von ";
		cout << knoten->getId();
		//	cout << " also: " << knoten->getVorgaenger()->getId();
		if (knoten->getId() == start->getId()) {
			cout
					<< "\nstart knoten wieder erreicht - und keine Knoten von hier aus der nicht besucht ist!\n";

		}
		return knoten;
	}
	cout << "\n**aktueller kürzester knoten \n";
	cout << ausgbae->getEigenschaften()->getId();
	return (ausgbae);
}

