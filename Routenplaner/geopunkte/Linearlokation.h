/*
 * Linearlokation.h
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#ifndef LINEARLOKATION_H_
#define LINEARLOKATION_H_

#include"./Gebietslokation.h"
/**
 * Diese Klasse stellt eine Linearlocation dar.<br> In ihr sind alle Atribute enthalten,
 * die eine Linearlocation zus&auml;tzlich zu einer Gebietslokation enth&auml;lt.<br>
 * Sie erbt von der Klasse @link Gebietslokation @endlink.
 */
class Punktlokation;
class Linearlokation: public Gebietslokation {
public:
	/**
	 * Dieser Konstruktor ist der Standardkonstruktor dieser Klasse. Er enth&auml;lt
	 * die Zeile, die schon in der Gebietslokation beschrieben wurde und zus&auml;tzlich
	 * einen Pointer auf eine Area Reference.
	 * @param zeile Die Zeile der Datei, aus der die Linearlokation ausgelesen werden
	 * soll.
	 * @param areaReference Ein Pointer auf die Gebietslokation, in der sich diese
	 * Linearlokation befindet.
	 *
	 */
	Linearlokation(vector<string> *zeile, Gebietslokation *areaReference);
	virtual ~Linearlokation();

	/**
	 * Mit dieser Methode wird eine Punklokation in die Linearlokation eingetragen.<br>
	 * Diese Klasse enth&auml,t einen Vector, in dem alle Punklokationen gespeichert sind,
	 * die in dieser Linearlokation enthalten sind.
	 * @param pktLocation Der Pointer auf die einzutragende Punktlokation.
	 */
	void addPktLokation(Punktlokation *pktLocation);

	/**
	 * Diese Methode baut die Verweise zu anderen Linearlokationen auf,
	 * die zum Zeitpunkt der Konstruktion des Objekts noch nicht feststanden.<br>
	 * Dadurch k&ouml;nnen alle direkten Nachbarn (auf der Karte gesehen) direkt
	 * adressiert werden.
	 * Diese Verweise sind:<br>
	 * <ul>
	 * 	<li>Positive Offset</li>
	 * 	<li>Negative Offset</li>
	 * 	<li>Intersection Code</li>
	 * 	<li>Interrupts Road</li>
	 * </ul>
	 * @param gebieteMap Ein Pointer auf die Map,
	 * mit der anhand einer ID ein Obejekt gefunden werden kann.
	 * @param zeile Ein Pointer auf den Vector, der die Zeile
	 * repr&auml;sentiert.
	 */
	void verweiseAufbauen(map<int, Gebietslokation*> *gebieteMap,
			vector<string> *zeile);

	/**
	 * Gibt einen String mit Informationen &uuml;ber das Objket zur&uuml;ck.
	 * @return Ein String mit den Informationen &uuml;ber das Objekt.
	 */
	virtual string toString();

	/**
	 * M&ouml;glichkeit um den Typ der Klasse zu pr&uuml;fen.
	 * @return Gibt das define LINEAR zurueck.
	 */
	virtual int getType();

	//Nur Getter und Setter, brauchen nicht weiter kommentiert zu werden.
	const string& getAdminCounty() const;
	Gebietslokation* getAreaReference();
	bool isInNegative() const;
	bool isInPositive() const;
	Linearlokation* getInterruptsRoad();
	Linearlokation* getIntersectioncode();
	Linearlokation* getNegativeOffset();
	Linearlokation* getPositiveOffset();
	bool isOutNegative() const;
	bool isOutPositive() const;
	const string& getPoldir() const;
	bool isPresentNegative() const;
	bool isPresentPositive() const;
	const string& getRoadName() const;
	const string& getRoadNumber() const;
	const string& getSecondName() const;
	bool isTern() const;
	bool isUrban() const;
	int getVeraendert() const;
	void setAreaReference(Gebietslokation* areaReference);
	const vector<Punktlokation*>& getPunktLokations() const;

protected:
	/**
	 * Die Stra&szlig;ennummer. Sie besteht aus dem Bezeichner der Stra&szlig;e
	 * und der Nummer der Stra&szlig;e. <br>
	 * Bsp.: A620
	 */
	string roadNumber;

	/**
	 * Der Stra&szlig;enname.<br>
	 * Beispiel: B405 (Stra&szlig;ennummer), Metzer Stra&szlig;e (Stra&szlig;enname).
	 */
	string roadName;

	/**
	 * Ein zus&auml;tzlicher Name der Lokation.<br>
	 * Lt. Doku des Bundesamtes "Zweiter Name".
	 */
	string secondName;

	/**
	 * Area Verweis auf das Gebiet, in dem die Lokation liegt.<br>
	 * Dieses Attribut enth&auml;lt einen Pointer auf ein @link Gebietslokation @endlink
	 * Objekt.
	 */
	Gebietslokation *areaReference;

	/**
	 * Verweis auf die Vorg&auml;ngerlokation bezogen auf die Erfassungsrichtung.
	 * <br>Dieses Attribut enth&auml;lt einen Pointer auf die vorherige
	 * Lokation.
	 */
	Linearlokation *negativeOffset;

	/**
	 * Verweis auf die Nachfolgerlokation bezogen auf die Erfassungsrichtung.
	 * <br>Dieses Attribut enth&auml;lt einen Pointer auf die folgende
	 * Lokation.
	 */
	Linearlokation *positiveOffset;

	/**
	 * Flag, ob Verkehr st&auml;dtischen Characters vorliegt.<br>
	 * (1=ja, 0=nein)
	 */
	bool urban;

	/**
	 * Verweis auf die Loction, einer anderen Stra&szlig;e an gleicher Stelle.
	 * (zirkul&auml;re Verkettung)<br>
	 * Dieses Attribut enth&auml;lt einen Pointer auf die mit der Id verkn&uuml;pften
	 * Linearlokation.
	 */
	Linearlokation *intersectioncode;

	/**
	 * Verweis auf die n&auml;chste Lokation nach der Unterbrechung im
	 * Stra&szlig;enverlauf.<br>
	 * Dieses Attribut enth&auml;lt einen Pointer auf die mit der Id verkn&uuml;pften
	 * Linearlokation.
	 */
	Linearlokation *interruptsRoad;

	/**
	 *Flag, ob Lokation in Erfassungsrichtung zug&auml;nglich ist.<br>
	 *(1=ja, 0=nein)
	 */
	bool inPositive;

	/**
	 * Flag, ob Lokation in Erfassungsrichtung verlassen werden kann.<br>
	 * (1=ja, 0=nein)
	 */
	bool outPositive;

	/**
	 *Flag, ob Lokation entgegen Erfassungsrichtung zug&auml;nglich ist.<br>
	 *(1=ja, 0=nein)
	 */
	bool inNegative;

	/**
	 * Flag, ob Lokation entgegen Erfassungsrichtung verlassen werden kann.<br>
	 * (1=ja, 0=nein)
	 */
	bool outNegative;

	/**
	 * Flag, ob Lokation in Erfassungsrichtung vorhanden ist.<br>
	 * (1=ja, 0=nein)
	 */
	bool presentPositive;

	/**
	 * Flag, ob Lokation entgegen Erfassungsrichtung vorhanden ist.<br>
	 * (1=ja, 0=nein)
	 */
	bool presentNegative;

	/**
	 * Flag, ob Datensatz bei Aktualisierungsverlauf gegen&uuml;ber der Vorg&auml;ngerversion
	 * ver&auml;ndert wurde.<br>
	 * (Nur vor Release erkennbar 0=nein, 1=ja, 2=neu, 3=l&ouml;schen)
	 */
	int veraendert;

	/**
	 * Angabe, ob Lokation zum TERN-Netz geh&ouml;rt.<br>
	 * (1=ja, 0=nein)
	 */
	bool tern;

	/**
	 * Hinweis auf die zust&auml;ndige Polizeidienststelle.
	 */
	string poldir;

	/**
	 * Hinweis auf f&uuml;r die Bearbeitung zust&auml;ndiges Bundesand.
	 */
	string adminCounty;

	/**
	 * Diese Mehode liest die Attributwerte der Klasse ein.<br>
	 * Die Werte werden mit dem Zeilenvector &uuml;bergeben.
	 * @param zeile Ein Vector mit den Werten, die aus einer Zeile der
	 * Datei eingelesen wurden.
	 */
	void leseWerteEin(vector<string> *zeile);

	/**
	 * Dieser Vector enth&auml;lt die Punktlokationen, die diese
	 * Linearlokation als Linear Reference angegeben haben.
	 */
	vector<Punktlokation*> punktLokations;

	/**
	 * Diese Methode sucht in der Map anhand der in der Zeile enthaltenden Id nach den
	 * Objekten, die als positive und negative Offset angegeben sind und tr&auml;gt
	 * sie in die entsprechenden Attribute ein.
	 * @param gebieteMap Ein Pointer auf die Map, die alle Gebiete enth&auml;t.
	 * @param zeile Die Zeile, die diese Linearlokation beschriebt.
	 */
	void speichereOffset(map<int, Gebietslokation*> *gebieteMap,
			vector<string> *zeile);

	/**
	 * Diese Methode sucht in der Map anhand der in der Zeile enthaltenden Id nach den
	 * Objekten, die als Intersection Code angegeben sind und tr&auml;gt
	 * sie in die entsprechenden Attribute ein.
	 * @param gebieteMap Ein Pointer auf die Map, die alle Gebiete enth&auml;t.
	 * @param zeile Die Zeile, die diese Linearlokation beschriebt.
	 */
	void speichereIntersectionCode(map<int, Gebietslokation*> *gebieteMap,
			vector<string> *zeile);

	/**
	 * Diese Methode sucht in der Map anhand der in der Zeile enthaltenden Id nach den
	 * Objekten, die als Interrupts Road angegeben sind und tr&auml;gt
	 * sie in die entsprechenden Attribute ein.
	 * @param gebieteMap Ein Pointer auf die Map, die alle Gebiete enth&auml;t.
	 * @param zeile Die Zeile, die diese Linearlokation beschriebt.
	 */
	void speichereInterruptsRoad(map<int, Gebietslokation*> *gebieteMap,
			vector<string> *zeile);

	/**
	 * Diese Methode initialisiert alle Werte der Klasse mit
	 * 0, false, NULL.
	 */
	virtual void initialisieren();

};

#endif /* LINEARLOKATION_H_ */
