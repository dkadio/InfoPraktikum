#ifndef KNOTEN_H_
#define KNOTEN_H_

#define IN_FINITY -1
#include <list>
#include "../geopunkte/Punktlokation.h"

/**
 * Diese Klasse repr&auml;sentiert einen Knotenpunkt im Graph.<br>
 * Ein Knoten hat einen Nachfolger, ein besucht Flag und eine Distanz.
 * Zus&auml;tzlich enth&auml;lt er einen Pointer auf eine Punklokation und
 * eine Liste mit Nachfolgern.<br>
 * Der Vorg&auml;nger ergibt sich aus der Dijkstraberechnung. Die Nachfolger
 * ergeben sich aus dem Datensatz.
 */
using namespace std;
class Knoten {
public:
	Knoten(Punktlokation* punktLokation);
	virtual ~Knoten();
	void addNachfolger(Knoten *nachfolger);
	/**
	 * Berechnet die Distanz zu einem anderen Knoten.
	 * @param Der Knoten zu dem die Entfernung berechnet werden soll.
	 * @return Die Entfernung zu dem anderen Knoten in Kilometern.
	 */
	float berechneLaenge(Knoten * derAnnere);
	int getId();

	string toString();

	Punktlokation* getEigenschaften() {
		return (eigenschaften);
	}

	/**
	 * Diese Methode setzt den Vorg&auml;nger des Knotens auf NULL und die Distanz
	 * auf INFINITY.
	 */
	void clear();
	list<Knoten*> getNachfolger() const;

	//Nur Getter und Setter
	bool isBesucht() const;
	float getDistanz() const;
	Knoten* getVorgaenger() const;
	void setBesucht(bool besucht);
	void setDistanz(float distanz);
	void setVorgaenger(Knoten* vorgaenger);

private:
	/**
	 * Der Vorgaenger des Knoten, dieser dient der sp&auml;teren Verfolgung des
	 * k&uuml;zesten Weges.
	 */
	Knoten * vorgaenger;

	/**
	 * Die Eigenschaften des Knotens sind eine Punklokation, bzw. ein Pointer
	 * darauf.<br>
	 * Die Id eines Knotens ist der Einfachheit halber die Id der dazu geh&ouml;rigen
	 * Punktlokation.
	 */
	Punktlokation* eigenschaften; //getid ist die knotennummer

	/**
	 * Die Nachfolger des Knotens sind Knoten, die von diesem erreicht werden
	 * k&ouml;nen.<br>
	 * Vereinfacht gesagt, sind das die Knoten, die zum Positive Offset, dem Negative
	 * Offset und dem Intersectioncode der Eigenschaften geh&ouml;ren.
	 */
	list<Knoten*> nachfolger;

	/**
	 * Enth&auml;lt die Distanz bis zum Startknoten in Kilometern.
	 */
	float distanz;

	/**
	 * Ein Knoten ist besucht, wenn seine Nachfolger in die Queue aufgenommen
	 * wurden.
	 */
	bool besucht;
};
#endif /* KNOTEN_H_ */
