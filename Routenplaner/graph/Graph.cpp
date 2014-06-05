#include "Graph.h"

Graph::Graph(map<int, Gebietslokation*> rohDaten) {
	map<int, Knoten*> konstruktionsMap;
	erstelleKnoten(konstruktionsMap, rohDaten);
	verlinkeKnoten(konstruktionsMap, rohDaten);
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
		if (it->second->getType() == PUNKT) {
			Punktlokation *pktLok = (Punktlokation*) it->second;
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
			try {
				knoten->addNachfolger(
						konstruktionsMap.at(
								pLok->getPositiveOffset()->getId()));
			} catch (out_of_range &e) {
				string fehler = "Der Positive Offset mit der Id ";
				fehler += pLok->getIntersectioncode()->getId();
				fehler += " konnte nicht gefunden werden.";
				throw(fehler);
			}
		}
		//NOffset als Nachfolger eintragen
		if (pLok->getNegativeOffset() != NULL) {
			try {
				knoten->addNachfolger(
						konstruktionsMap.at(
								pLok->getNegativeOffset()->getId()));
			} catch (out_of_range &e) {
				string fehler = "Der Negative Offset mit der Id ";
				fehler += pLok->getIntersectioncode()->getId();
				fehler += " konnte nicht gefunden werden.";
				throw(fehler);
			}
		}
		//Den Intersectioncode als Nachfolger eintragen
		if (pLok->getIntersectioncode() != NULL) {
			try {
				knoten->addNachfolger(
						konstruktionsMap.at(
								pLok->getIntersectioncode()->getId()));
			} catch (out_of_range &e) {
				string fehler = "Der Intersectioncode mit der Id ";
				fehler += pLok->getIntersectioncode()->getId();
				fehler += " konnte nicht gefunden werden.";
				throw(fehler);
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

unsigned long Graph::size() {
	return (knotenListe.size());
}

vector<Knoten*> Graph::sucheName(string allocator) {
	vector<Knoten*> ergebnis;
	for (auto it = knotenListe.begin(); it != knotenListe.end(); it++) {

		if (((*it)->getEigenschaften()->getFirstName().find(allocator)
				!= string::npos)
				|| ((*it)->getEigenschaften()->getRoadNumber().find(allocator)
						!= string::npos)
				|| ((*it)->getEigenschaften()->getSecondName().find(allocator)
						!= string::npos)
				|| ((*it)->getEigenschaften()->getRoadName().find(allocator)
						!= string::npos)) {

			ergebnis.push_back((*it));
		}
	}
	return ergebnis;
}
