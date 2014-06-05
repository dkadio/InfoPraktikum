/**
 * Diese Klasse stellt einen Graphen dar. Sie enth&auml;lt neben
 * einer geeigneten Datenstruktur auch Methoden um den Graph aufzubauen.<br>
 * Ein Knoten ist durch maximal 3 Nachfolger gekennzeichnet.<br>
 * Die Knoten sind alle in einer doppelt verketteten Liste enthalten.
 *
 * @deprecated Da die Datenstruktur des Knoten grunds&auml;tzlich ge&auml;ndert wurde,
 * musste diese Klasse von Grund auf neu aufgebaut werden. Tore seid gewarnt, dieser Weg
 * f&uuml;rt nicht zum Ziel.
 */

#ifndef GRAPH_OLD_H_
#define GRAPH_OLD_H_

#include <map>
#include "Knoten.h"

class Graph_OLD {
public:
	Graph_OLD(map<int, Gebietslokation*> rohDaten);
	virtual ~Graph_OLD();

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
	 * Spalten n>0 gef&uuml;llt.
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
private:
	/**
	 * Diese Liste enth&auml;lt den eigentlichen Graphen.
	 */
	list<Knoten*> knotenListe;
};

//knoten.getitem().getnachfolger().getitem().getentfernung();

#endif /* GRAPH_H_ */
