/*
 * Punktlokation.h
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#ifndef PUNKTLOKATION_H_
#define PUNKTLOKATION_H_

#include"Linearlokation.h"
#include "../hilfsklassen/GeoKoordinate.h"

class Punktlokation: public Linearlokation {
public:
	Punktlokation(vector<string> *zeile, Gebietslokation *areaReference,
			Linearlokation *linearReference);
	virtual ~Punktlokation();

	/**
	 * To String Methode der Klasse Punktlokation.
	 * @return Einige Attribute der Klasse als String.
	 */
	virtual string toString();

	/**
	 * M&ouml;glichkeit um den Typ der Klasse zu pr&uuml;fen.
	 * @return Gibt das define LINEAR zurueck.
	 */
	virtual int getType();

	GeoKoordinate* getGeoKoordinate() const;
	 Linearlokation* getLinearReference() const;
	int getNetzKontenNummerNach() const;
	int getNetzKontenNummerVor() const;
	int getStation() const;

private:
	/**
	 * Pointer auf die &uuml;bergeordnete Linearlokation.
	 */
	Linearlokation *linearReference;

	//exitNumber; TODO rausfinden, was man damit macht und was f&uuml;r ein Datentyp das ist

	//diversionPositive TODO rausfinden, was man damit macht und was f&uuml;r ein Datentyp das ist

	//diversionNegative TODO rausfinden, was man damit macht und was f&uuml;r ein Datentyp das ist

	/**
	 * Netzknotennummer der Lokation oder Netzknotennummer des vor der Lokation
	 * liegenden Netzknoten.
	 */
	//TODO Netzknotennummer evtl. als Referenz
	unsigned int netzKontenNummerVor;

	/**
	 * Netzknotennummer des nach der Lokation liegenden Netzknoten.
	 */
	unsigned int netzKontenNummerNach;

	/**
	 * Entfernung der Lokation vor dem Netzknoten 1 in Richtung Netzknoten 2.<br>
	 * Die Angabe ist in Metern.
	 */
	int station;

	/**
	 * Dieses Attribut enth&auml;lt einen Pointer
	 * auf ein Geokoordinaten Objekt. Dieses enth&auml;lt
	 * den L&auml;ngen- und den Breitengrad.
	 */
	GeoKoordinate *geoKoordinate;

	/**
	 * Diese Methode initialisiert alle Werte der Klasse mit
	 * 0, false, NULL.
	 */
	virtual void initialisieren();
};

#endif /* PUNKTLOKATION_H_ */
