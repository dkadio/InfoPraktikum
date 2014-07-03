/**
 * Diese Klasse stellt einen Graph dar. Die enth&auml;lt neben
 * einer geeigneten Datenstruktur auch Methoden um den Graph aufzubauen.<br>
 * Ein Knoten ist durch maximal 3 Nachfolger gekennzeichnet.<br>
 * Die Knoten sind alle in einer doppelt verketteten Liste enthalten.<br>
 * In dieser Klasse wird eine KonstruktionMap genutzt. Diese KonstruktionsMap
 * beinhaltet Pointer auf alle erstellten Knoten. Sie wird gepflegt, da beim
 * Verlinken der Knoten (Abhängigkeiten aufbauen) im schlechtesten Fall
 * 4*(Anzahl Punktloationen) Zugriffe auf bestehende Knoten erfolgen und diese
 * Zugriffe nur anhand der Id geschehen. Nach dem Erstellungsprozess wird
 * die Konstruktionsmap verworfen.
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include "Knoten.h"

using namespace std;

class Graph {
public:
	/**
	 * Der Standardkonstrukor. Er baut den Graphen ohne Wertung der einzelnen
	 * Knoten auf.<br>
	 * @param rohDaten Eine Map mit Lokationen.
	 */
	Graph(map<int, Gebietslokation*> rohDaten);
	/**
	 * Der Destruktor.<br>
	 * Er destruiert die enthaltenen Knoten.
	 */
	virtual ~Graph();

	/**
	 * Diese Methode durchl&auml;ft alle Lokationen.<br>
	 * Ist die aktuelle Lokation eine Punklokation, wird daraus ein Knoten erstellt.<br>
	 * Deren Pointer wird in die Liste mit den Knoten aufgenommen.
	 * @param konstruktionsMap Die Konstruktionsmap. In ihr sind alle erstellten Knoten
	 * enthalten. Bzw. Pointer auf sie.
	 * @param rohdaten Eine Map mit Lokationen.
	 */
	void erstelleKnoten(map<int, Knoten*> &konstruktionsMap,
			const map<int, Gebietslokation*> &rohdaten);

	/**
	 * Diese Methode verlinkt die Knoten.<br>
	 * Der Hintergrund ist, dass die Nachfolger eines Knotens selber wieder Knoten sind.<br>
	 * Diese Objekte sind aber w&auml;hrend des Einlesen noch nicht zwangsl&auml;fig
	 * erstellt.
	 * @param konstruktionsMap Die Konstruktionsmap. In ihr sind alle erstellten Knoten
	 * enthalten. Bzw. Pointer auf sie.
	 * @param rohdaten Eine Map mit Lokationen.
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
	 * Diese Methode durchl&auml;ft alle Knoten des Graphen und setzt ihre Vorg&auml;nger
	 * auf NULL und ihre Strecken auf INFINITY.
	 */
	void clear();
	/**
	 * Diese Methode gibt die Anzahl der Knoten zur&uuml;ck, die im Graph entahlten sind.
	 * @return Die Anzahl der Elemente, die im Graphen enthalten sind.
	 */
	unsigned long size();

	/**
	 * Die Methode sucht nach einem Suchstring in allen vorhandenen Punktlokationen in RoadNumber und oder Roadname, Firstname, secondname
	 * und gibt alle gefundenen Lokationen als Vector zurueck
	 */
	vector<Knoten*> sucheName(string);
private:
	/**
	 * Diese Liste enth&auml;lt den eigentlichen Graphen.
	 */
	list<Knoten*> knotenListe;
};

#endif /* GRAPH_H_ */
