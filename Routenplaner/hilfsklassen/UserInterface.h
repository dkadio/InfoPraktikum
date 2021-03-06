/*
 * UserInterface.h
 *
 *  Created on: 05.06.2014
 *      Author: christoph
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

#define ENDE 0 //Beendet das Programm
#define START 1 //Liest einen Startknoten aus
#define ZIEL 2 //Liest den Zielknoten aus

#include <string>
#include<sstream>

#include "../geopunkte/LokationsVerwaltung.h"
#include "SicherLesen.h"
#include "../reader/FileOpener.h"
#include "../graph/Dijkstra.h"

using namespace std;
/**
 * Diese Klasse ist die Schnittstelle f&uuml;r den Benutzer.<br>
 * Hier erfolgen die Eingaben des Benutzers und hier werden die Ergebnisse ausgegeben.
 */
//static const char* dateiPfad = "../utf8.csv";
static const char* dateiPfad =
		"/Users/christoph/Documents/HTW/SEM6/InfoPraktikum/InfoPraktikum/Routenplaner/utf8.csv";

class UserInterface {
public:
	UserInterface();
	UserInterface(Graph * graph);

	virtual ~UserInterface();

	/**
	 * Diese Methode startet die Men&uuml;f&uuml;hrung des Programms.
	 */
	void start();

private:
	/**
	 * Diese Methode gibt das Hauptmen&uuml; des Programms aus.<br>
	 * Das Men&uuml; wird in Abh&auml;ngigkeit der vorhandenen Daten angezeigt.
	 * @return ein Menue mit der Auswahl f&uuml;r den Benutzer.
	 */
	string getMenue();

	/**
	 * Diese Methode wertet die Benutzereingabe aus.
	 * @param Die Eingabe des Benutzers.
	 */
	string switchMenueEingabe(int eingabe);

	/**
	 * Diese Methode gibt eine Liste mit Knotenpointern aus.<br>
	 * Die einzelnen Eintr&auml;ge werden durchnummeriert.
	 * @return Ein String mit allen Elementen der Liste.
	 */
	string vectorAusgeben(vector<Knoten*> * liste);

	/**
	 * Gibt den Knoten an der gegebenen Stelle aus.
	 * @param liste Die Liste, in der gesucht werden soll.
	 * @param stelle Die Stelle, an der gesuchte Knoten steht.
	 * @return Der gesuchte Knoten.
	 */
	Knoten * getKnoten(vector<Knoten*> * liste, int stelle);

	/**
	 * Diese Methode beinhaltet eine Men&uuml;f&uuml;hrung, die dem Benutzer
	 * erlaubt einen Knoten zu suchen.
	 * @return Der gesuchte Knoten.
	 */
	Knoten * knotenEinlesen();

	/**
	 * Diese Methode &ouml;ffnet die Date und liest sie aus.
	 * @return ein FileOpener Pointer.
	 */
	FileOpener * oeffneDatei();

	/**
	 * Diese Methode gibt eine Liste aus.<br>
	 * Dazu durchl&auml;ft sie die Liste und ruft die toString() Methode der
	 * Elemente auf.<br>
	 * Sie wird haupts&auml;chlich f&uuml;r die berechneten Routen gebutzt.
	 * @param Ein Pointer auf die Liste, die ausgegeben werden soll.
	 * @return Ein String, der die Elemente der Liste enth&auml;lt.
	 */
	string listeAusgeben(list<Knoten*> &liste);

	/**
	 * Der Graph aus dem die Route berechnet werden soll.
	 */
	Graph * graph;

	/**
	 * Ein Pointer auf ein Dijkstra Objekt.
	 */
	Dijkstra *dijkstra;

	/**
	 * Der Startknoten, von dem aus der Dijkstra berechnet wurde.
	 */
	Knoten * startKnoten;
};

#endif /* USERINTERFACE_H_ */
