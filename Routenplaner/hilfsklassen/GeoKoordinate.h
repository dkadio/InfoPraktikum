/*
 * GeoKoordinate.h
 *
 *  Created on: 28.04.2014
 *      Author: christoph
 */

#ifndef GEOKOORDINATE_H_
#define GEOKOORDINATE_H_

#define NACHKOMMA_STELLEN 5
#define BEGIN_GRADANGABE 1
#define VORKOMMA_STELLEN 2

#include <string>
#include <cmath>
#include <sstream>
#include <cmath>


#include  <iostream> //TODO nachdem cout raus, dann das auch raus

using namespace std;

/**
 * Diese Klasse stellt eine Georkoordinate dar.<br>
 * Sie enth&auml;lt neben dem L&auml;ngen- und Breitengrad, auch Mehoden zur
 * Berechnung.<br>
 * Der<b> L&auml;ngengrad</b> beschreibt den Winkel eines Dreiecks. Dieses Dreieck
 * besteht aus zwei gedachten Strecken und der Verbindung zwischen diesen.
 * Die Startpunkte der Strecken ist jewails der Erdmittelpunkt. Das Ende der ersten
 * Strecke ist fest mit dem Nullmeridian definiert, im Fall von WGS84 l&auml;ft der
 * Nullmeridian 100m &ouml;stlich vom Observatorium Greenwitch, London vorbei.
 * Die zweite Strecke ist die Strecke vom Erdmittelpunkt bis zum beschriebenen Ort.<br>
 * Grob ausgedr&uuml;ckt, stellt man sich einen Globus vor verlaufen die L&auml;ngengrade
 * in der Richtung, wie man den Globus drehen kann.
 * <br><br>
 * Der Breitengrad wird analog zum L&auml;ngengrad definiert. Hier ist der Nullmeridian
 * der &Auml;quator. Um beim Beispiel des Globuses zu bleiben, die Breitengrade verlaufen
 * hier von oben nach unten, bzw. umgekehrt.
 * <br>
 * Durch L&auml;ngen- und Breitengrad kann ein beliebiger Ort auf der Erdkugel beschrieben
 * werden.<br>
 * <b>Aufbau eines Grades: </b><br>
 * Ein Grad ist in Zahlentupel zu zwei Zahlen aufgeteilt. Er wird von links nach rechts
 * gelesen.
 * <b>Bedeutung der Tupel:</b><br>
 * <ol>
 * 	<li>Volle Grad</li>
 * 	<li>Gradminuten</li>
 * 	<li>Gradsekunden</li>
 * </ol>
 *
 */
class GeoKoordinate {
public:
	GeoKoordinate(string xKoordinate, string yKoordinate);
	virtual ~GeoKoordinate();

	/**
	 * Im Datensatz sind die Gradangaben als Zahlenwert mit vorhergehendem "+"
	 * angegeben.<br>
	 * Diese Methode zerlegt den string und legt die Werte im &uuml;bergebenen Struct ab.
	 * @param zeichen Der String mit der Gradangabe, der aus dem Datensatz ausgelesen
	 * wurde.
	 * @param gradAngabe Ein Pointer auf das Struct, in das die Werte abgelegt werden sollen.
	 */
	void gradEinlesen(string zeichen, float *angabe);

	/**
	 * Berechnet die entfernung von der aktuellen GeoKoordinate zu einer Ziel Geokoordinate
	 * Gibt den Wert der entfernung in Km als Float zurueck
	 * @param ziel die entfernte Geokoordinate zu der der Weg berechnet wrden soll
	 */
	float entfernungBerechnen(GeoKoordinate *ziel);


	string toString();
	float getBreitenGrad() const;
	float getLaengenGrad() const;

private:

	/**
	 * Der L&auml;ngengrad der Lokation.<br>
	 * Auch Ostkoordinate.<br>
	 * In der Dokumentation als X Koordinate bezeichnet.
	 */
	float laengenGrad;

	/**
	 * Der Breitengrad der Lokation.<br>
	 * Auch Nordkoordinate. <br>
	 * In der Dokumentation als Y-Koordinate bezeichnet.
	 */
	float breitenGrad;

};

#endif /* GEOKOORDINATE_H_ */
