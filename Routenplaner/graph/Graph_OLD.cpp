#include "Graph_OLD.h"

Graph_OLD::Graph_OLD(map<int, Gebietslokation*> rohDaten) {
	map<int, Knoten*> konstruktionsMap;
	erstelleKnoten(konstruktionsMap, rohDaten);
	verlinkeKnoten(konstruktionsMap, rohDaten);
	konstruktionsMap.clear();
}

Graph_OLD::~Graph_OLD() {
	for (auto it = knotenListe.begin(); it != knotenListe.end(); it++) {
		delete *it;
	}
	knotenListe.clear();
}

void Graph_OLD::erstelleKnoten(map<int, Knoten*>& konstruktionsMap,
		const map<int, Gebietslokation*>& rohdaten) {
	//Alle Elemente durchlaufen
	for (auto it = rohdaten.begin(); it != rohdaten.end(); it++) {
		//Pruefen, ob Element eine Punklokation ist
		Punktlokation *pktLok = (Punktlokation*) it->second;
		if (pktLok->getType() == PUNKT && pktLok->getIntersectioncode() != NULL) {
			try {
				//Pruefen, ob der Intersection Code des Elements existiert
				//Wenn nicht wird eine Out Of Range Exception ausgeloest.
				//In dem Fall kann ein neuer Knoten erstellt werden.
				konstruktionsMap.at(pktLok->getIntersectioncode()->getId());
			} catch (const out_of_range& oor) {
				Knoten *k = new Knoten(pktLok);
				knotenListe.push_back(k);
				konstruktionsMap[k->getEigenschaften()->getId()] = k;
			}
		}
		if (pktLok->getType() == PUNKT && pktLok->getIntersectioncode() == NULL) {
			Knoten *k = new Knoten(pktLok);
			knotenListe.push_back(k);
			konstruktionsMap[k->getEigenschaften()->getId()] = k;
		}
	}
}

void Graph_OLD::verlinkeKnoten(map<int, Knoten*> konstruktionsMap,
		const map<int, Gebietslokation*> &rohdaten) {
	int i = 0;
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
		//Die Offsets des Intersection Codes eintragen
		if (pLok->getIntersectioncode() != NULL) {
			try {
				if (pLok->getIntersectioncode()->getPositiveOffset() != NULL) {
					knoten->addNachfolger(
							konstruktionsMap.at(
									pLok->getIntersectioncode()->getPositiveOffset()->getId()));
				}
			} catch (out_of_range &e) {
				/*cout << "\n" << i++ << " Id: "
				 << pLok->getIntersectioncode()->getPositiveOffset()->getId();*/
			}
			try {
				if (knoten->getEigenschaften()->getIntersectioncode()->getNegativeOffset() != NULL) {
					knoten->addNachfolger(
							konstruktionsMap.at(
									pLok->getIntersectioncode()->getNegativeOffset()->getId()));
				}
			} catch (out_of_range &e) {
				/*	cout << "\n" << i++ << " Id: "
				 << pLok->getIntersectioncode()->getNegativeOffset()->getId(); */
			}
		}
	}

}

string Graph_OLD::toString() {
	ostringstream s;
	s << "\nAusgabe des Graphen: \n";
	for (auto it = knotenListe.begin(); it != knotenListe.end(); it++) {
		s << ((Knoten*) *it)->toString();
	}
	s << "\nEnde Graph\n";
	return (s.str());
}
