/*
 * Graph.h
 *
 *  Created on: 13.05.2014
 *      Author: deniz
 */

/**
 * Diese Klasse stellt einen Graph dar. Die enth&auml;lt neben
 * einer geeigneten Datenstruktur auch Methoden um den Graph aufzubauen.<br>
 * Ein Knoten ist durch maximal 3 Nachfolger gekennzeichnet.<br>
 * Die Knoten sind alle in einer doppelt verketteten Liste enthalten.
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include "Knoten.h"
//TODO stdlib wieder entfernen (War Nur zum Testen)
#include <stdlib.h>

using namespace std;

class Graph {
public:
	/**
	 * Der Standardkonstrukor. Er baut den Graphen ohne Wertung der einzelnen
	 * Knoten auf.
	 */
	Graph(map<int, Gebietslokation*> rohDaten);
	/**
	 * Der Destruktor.<br>
	 * Er destruiert die enthaltenen Knoten.
	 */
	virtual ~Graph();

	/**
	 * Diese Methode erstellt die erste Spalte der Adjazenzmatrix (n=0).<br>
	 * Dabei werden neue Knoten erstellt und in die Liste eingepflegt.
	 * @param konstruktionsMap Die Konstruktionsmap, dort sind die neuen
	 * Knoten zusammen mit einer Id gespeichert.
	 * @param rohdaten Eine Map mit den Rohdaten, also allen Lokationen.
	 */
	void erstelleKnoten(map<int, Knoten*> &konstruktionsMap,
			const map<int, Gebietslokation*> &rohdaten);

	/**
	 * Diese Methode baut die eigentloch Adjazenzliste auf. Hierzu werden die
	 * Spalten n>0 gef&uuml;llt.<br>
	 * Der Einlesevorgang l&auml;ft in zwei Stufen. Erst wird aus jeder Punktlokation
	 * ein Knoten erzeugt.<br>
	 * Im zweiten Schritt wird in jedem Knoten, dessen Punktlokation einen
	 * Intersectioncode hat, der Intersectioncode als Nachfolger eingetragen.<br>
	 * Da die Knoten der Intersectioncodes w&auml;hrend dem ersten Erstellen noch nicht
	 * existieren m&uuml;ssen wird, verlinkt diese Methode sie im zweiten Schritt.
	 * @param konstruktionsMap Die Kkonstruktionsmap erlaubt einen schnellen Zugriff
	 * auf ein Knotenobjekt.
	 */
	void verlinkeKnoten(map<int, Knoten*> konstruktionsMap,
			const map<int, Gebietslokation*> &rohdaten);

	/**
	 * Dient nur zum Validieren des Einlesens.
	 * @return Ein String mit allen enthaltenen Knoten.
	 */
	string toString();

	/**
	 * Diese Methode gibt anhand einer gegebenen Id einen Knoten zur&uuml;ck.
	 * @param id Die Id des gesuchten Knotens.
	 * @return Ein Pointer auf den gesuchten Knoten.
	 */
	Knoten *getKnoten(int id);

	/**
	 * Diese Methode durchl&auml;ft den Graphen und ruft bei allen Knoten die
	 * clear() Methode auf.
	 */
	void clear();

	const list<Knoten*>& getKnotenListe() const;

private:
	/**
	 * Diese Liste enth&auml;lt den eigentlichen Graphen.
	 */
	list<Knoten*> knotenListe;
};

//knoten.getitem().getnachfolger().getitem().getentfernung();

#endif /* GRAPH_H_ */
