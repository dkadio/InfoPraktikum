/*
 * BenutzerInterface.h
 *
 *  Created on: 06.05.2014
 *      Author: christoph
 */

#ifndef BENUTZERINTERFACE_H_
#define BENUTZERINTERFACE_H_

#define ENDE 0
#define NAMEN_SUCHEN 1
#define ID_SUCHEN 2
#define ALLE_LOKS 3
#define GEMEINSAMKEITEN 4
#define ROUTE_BERECHNEN 5

#define NAME_ANZEIGEN 1
#define UEBERGEORDNETE_LOKATION_ANZEIGEN 2
#define UEBERGEORDNETE_STRASSE_ANZEIGEN 3
#define POFFSET_ANZEIGEN 4
#define NOFFSET_ANZEIGEN 5
#define ID_ANZEIGEN 6
#define KOORDINATE_ANZEIGEN 7
#define LINEAR_AUSGEBEN 8 //Gibt die Punktlokationen einer Linear Reference aus

#include "../geopunkte/LokationsVerwaltung.h"
#include  "SuchenKlasse.h"
#include  <iostream>
#include  "sicherLesen.h"
#include  "../graph/RoutenBerechnung.h"
#include "../graph/Graph.h"

/**
 * Erste Klasse f&uuml;r ein Benutzerinterface.<br>
 * Sie erlaubt das genaue Betrachten von Lokationen und
 * bietet hierf&uuml;r eine Men&uuml;f&uuml;hrung an.
 */
class BenutzerInterface {
public:
	BenutzerInterface(LokationsVerwaltung* lokVerwaltung);
	virtual ~BenutzerInterface();
	/**
	 * Diese Methode gibt das Hauptmenue auf der Konsole aus.
	 */
	void zeigeHauptMenue();

	/**
	 * Diese Methode enth&auml;lt die Darstellung d&uuml;r die Suche nach einer
	 * Lokation und gibt diese auf der Konsole aus.
	 */
	void zeigeSuche();

	/**
	 * Diese Methode erlaubt die Suche nach einer Id.
	 */
	void zeigeIdSuche();

	/**
	 * Das Feinmenue wird von der Suchfunktion aufgerufen.<br>
	 * Dort k&ouml;nnen Methoden aufgerufen werden um sich Werte
	 * einer Lokation anzeigen zu lassen.
	 * @param lok Der Pointer auf die Lokation, die angezeigt werden soll.
	 */
	void zeigeFeinMenue(Gebietslokation * lok);

	/**
	 * Diese Methode gibt alle Lokationen aus.
	 */
	void zeigeAlle();

	/**
	 * Diese Methode gibt alle Punktlokationen aus, die in einer Linearlokation
	 * enthalten sind.
	 * @param linLok Die Linear Lokation, die ausgegeben werden soll.
	 */
	void linearAusgeben(Linearlokation * linLok);

	/**
	 * Diese Methode aktiviert die Suche der Suchklasse.<br>
	 * Hier&uuml;ber kann der gesamte Datenbestand nach den
	 * gegebenen Kriterien durchsucht werden.
	 */
	void gemeinsamkeitenSuchen();

	/**
	 * Diese Methode f&uuml;hrt durch das Menue um eine Route zu berechnen.
	 */
	void routeBerechnen();

	/**
	 * Diese Methode gibt einen Vector aus. Bei der Ausgbe wird ein Index erstellt,
	 * um auf die einzelnen Elemente zugreifen zu k&ouml;nnen.
	 * @param vector Die Referenz auf den Vector, der ausgegeben werden soll.
	 * @return Ein string mit den Elementen des Vectors und dem entsprechenden Index.
	 */
	string vectorAusgeben(const vector<Gebietslokation*> *treffer);
	string vectorAusgeben(const vector<Linearlokation*> *treffer);
	string vectorAusgeben(const vector<Punktlokation*> *treffer);


	/**
	 * Gibt an einer beliebigen Stelle des Graphen die Nachfolger aus.
	 */
	void nachfolgerAusGraphAusgeben();
private:
	LokationsVerwaltung* lokVerwaltung;
	SuchenKlasse *suchKlasse;
	Graph *graph;
};

#endif /* BENUTZERINTERFACE_H_ */
