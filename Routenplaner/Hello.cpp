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
	datei->oeffneDatei(
		"/Users/christoph/Documents/HTW/SEM6/InfoPraktikum/Code/Routenplaner/utf8.csv");
	datei->leseDateiAus();
	cout << "\n\n------------Einlesen abgeschlossen-----------\n\n";
	vector<vector<string> > erg = datei->getDatensatz();

	LokationsVerwaltung *lokVerwaltung = new LokationsVerwaltung(&erg);
	delete datei;

	Graph *g = new Graph(lokVerwaltung->getGebieteMap());
	cout << g->toString();
	delete g;

	BenutzerInterface interface = BenutzerInterface(lokVerwaltung);
	interface.zeigeHauptMenue();
	/* (auto it = lokVerwaltung->getNamenMap().begin();
	 it != lokVerwaltung->getNamenMap().end(); it++) {
	 cout << "\nName: " << it->first << "Value: " << it->second->toString();
	 }*/
	/*
	 * Suche
	 * */
	/*
	 string eingabe = "";
	 vector<Gebietslokation*> gefundeneLokationen;
	 while (eingabe != "end") {
	 eingabe = "";
	 cout << "\nBitte den gesuchten Begriff eingeben: (end fuer ende)\n";
	 cin >> eingabe;
	 gefundeneLokationen = lokVerwaltung->suchen(eingabe);

	 if (gefundeneLokationen.empty()) {
	 cout << "\nDer Datensatz konnte nicht gefunden werden.\n";
	 } else {
	 for (auto it = gefundeneLokationen.begin();
	 it != gefundeneLokationen.end(); it++) {
	 cout << ((Gebietslokation*) *it)->toString();
	 }
	 }
	 gefundeneLokationen.clear();
	 }

	 Punktlokation *wallerFangen = (Punktlokation*) lokVerwaltung->suchen(
	 "Wallerfangen").at(1);
	 Punktlokation *slsMitte = (Punktlokation*) lokVerwaltung->suchen(
	 "Saarlouis-Mitte").at(0);

	 cout << "\nVergleich von " << wallerFangen->getFirstName() << " und "
	 << slsMitte->getFirstName();
	 cout << "\nGeokoord Wallerfangen: "
	 << wallerFangen->getGeoKoordinate()->toString();
	 cout << "\nGeokoord SLS Mitte: " << slsMitte->getGeoKoordinate()->toString();
	 cout << "\nDer Abstand zwischen den beiden: "
	 << wallerFangen->getGeoKoordinate()->entfernungBerechnen(
	 slsMitte->getGeoKoordinate()) << "\n";
	 delete datei;
	 delete lokVerwaltung;*/

	//sleep(30); //Um zu sehen, was der Speicher macht
	return (EXIT_SUCCESS);           // Optionale Rückgabe an das Betriebssystem
}

