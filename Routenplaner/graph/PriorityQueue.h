#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include "Graph.h"

/**
 * Diese Klasse stellt eine Priority Queue dar.<br>
 * Sie ist speziell auf die Bed&uuml;rfnisse des Dijkstra Algorithmus zugeschnitten.<br>
 * Das Flag, ob ein Knoten besucht wurde wird hier st&auml;rker ber&uuml;cksichtigt, als
 * bei der Queue der STL.
 */
class PriorityQueue {
public:
	/**
	 * Der Standardkonstruktor der Klasse.<br>
	 * Wird dieser benutzt, muss vor der ersten Benutzung die Methode queueInitialisieren()
	 * aufgerufen werden.
	 */
	PriorityQueue(Graph * graph);

	/**
	 * Dieser Konstrktor ruft implizit die Methode queueInitialisieren() auf.<br>
	 * Dadurch kann die Queue direkt genutzt werden.<br>
	 */
	PriorityQueue(Graph * graph, Knoten* startKnoten);
	virtual ~PriorityQueue();

	/**
	 * Diese Methode speichert einen Knoten in die Prio Queue.<br>
	 * Ist dieser Knoten bereits enthalten, wird gepr&uuml;ft, ob sich eine
	 * k&uuml;rzere Distanz ergibt und dem entsprechend die Distanz und der
	 * Vorg&auml;nger ge&auml;ndert.<br>
	 * Verbessert sich die Distanz nicht, passiert nichts.
	 * @param vorgaenger Der Knoten, der der Vorg&auml;nger des einzutragenden Knoten ist.
	 * @param knoten Der Knoten, der eingetragen werden soll.
	 */
	void knotenEintragen(Knoten * vorgaenger, Knoten* knoten);

	/**
	 * Diese Methode tr&auml;gt die Nachfolger des &uuml;bergebenen Knotens in
	 * die Queue ein. Hierzu wird die Methode knotenEintragen() aufgerufen.
	 * @param Der Knoten, dessen Nachfolger eingetragen werden sollen.
	 */
	void nacholfgerEintragen(Knoten *knoten);

	/**
	 * Diese Methode erstellt die ersten Eintr&auml;ge der Queue.<br>
	 * Sie tr&auml;gt die Nachfolger des Startknotens ein.
	 */
	void queueInitialisieren(Knoten* startknoten);

	/**
	 * Diese Methode gibt den Knoten mit der h&ouml;chsten Priorit&auml;t aus.<br>
	 * Der Knoten, der die niedrigste Distanz zum Startknoten hat und noch nicht
	 * besucht wurde hat die h&ouml;chste Priorit&auml;t.
	 * @return Der Knoten mit der niedrigsten Distanz zum Startknoten, der noch nicht
	 * besucht wurde. Gibt es keinen Knoten mehr, der noch nicht besucht wurde, wird
	 * NULL zur&uuml;ck gegeben.
	 */
	Knoten * getFirst();

	/**
	 * Diese Methode pr&uuml;ft, ob sich die Distanz des Knoten mit dem neuen Vorg&auml;nger
	 * &auml;ndert.<br>
	 * Ist das der Fall, &auml;ndert sie den Vorg&auml;nger und die Distanz.
	 * @param vorgaenger Der neue Vorg&auml;nger, anhand dessen gepr&uuml;ft werden soll.
	 * @param knoten Der Knoten, der relaxiert werden soll.
	 */
	void knotenRelaxieren(Knoten* vorgaenger, Knoten* knoten);

	/**
	 * Diese Methode gibt die Anzahl der Elemente zur&uuml;ck, die
	 * in der Queue gespeichert sind.
	 * @return Die Anzahl der Elemente, die in der Queue gespeichert sind.
	 */
	unsigned long getSize();

	//TODO queue.clear()
private:
	/**
	 * Diese Map ist die Datenstruktur, die der Queue zu Grunde liegt.<br>
	 * Effizient beim Zugriff auf Id und iterierbar.
	 */
	map<int, Knoten*> queue;
};

#endif /* PRIORITYQUEUE_H_ */
