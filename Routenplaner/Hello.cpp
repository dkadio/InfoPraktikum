/*
 * Hello.cpp
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#include "Hello.h"
using namespace std;
Hello::Hello() {
	// Das Ding kann eh nichts

}

Hello::~Hello() {
	//delete von Hand in der Main
}

#include <iostream>                                     // Ein- und Ausgabebibliothek

int main() {                                             // Hauptfunktion
	//Jetzt mal die Datei auslesen
	FileOpener *datei = new FileOpener();
	//datei->oeffneDatei("../utf8.csv");
	//ich brauche es so fuer den Debugger
	try {
		datei->oeffneDatei(

				"/Users/christoph/Documents/HTW/SEM6/InfoPraktikum/InfoPraktikum/Routenplaner/utf8.csv");
	} catch (FileNotFoundException &e) {
		datei->oeffneDatei("../utf8.csv");
	}
	datei->leseDateiAus();
	cout << "\n\n------------Einlesen abgeschlossen-----------\n\n";
	vector<vector<string> > erg = datei->getDatensatz();

	LokationsVerwaltung *lokVerwaltung = new LokationsVerwaltung(&erg);
	delete datei;

	Graph *g = new Graph(lokVerwaltung->getGebieteMap());
	//cout << g->toString();

	//BenutzerInterface interface = BenutzerInterface(lokVerwaltung);
	//interface.zeigeHauptMenue();

	cout << "\nVor Objekt erstellen";
	Dijkstra *dijkstra = new Dijkstra(g);
	cout << "\nVor Routenberechnung";
	Knoten* start = g->getKnoten(24178);
	Knoten* ende = g->getKnoten(772);
	list<Knoten*> ergebnis = dijkstra->starteDijkstra(start, ende);

	cout << "\n\nRoute: ";
	for (auto it = ergebnis.begin(); it != ergebnis.end(); it++) {
		cout << "\n" << (*it)->getEigenschaften()->getFirstName()
				<< " Strasse: " << (*it)->getEigenschaften()->getRoadNumber()
				<< " Entfernung: " << (*it)->getDistanz();
	}
	cout << "\n";

	delete g;
	delete dijkstra;
	delete lokVerwaltung;

	return (EXIT_SUCCESS);          // Optionale Rueckgabe an das Betriebssystem
}

