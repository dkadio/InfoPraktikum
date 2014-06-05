#ifndef PUNKTLOKATION_H_
#define PUNKTLOKATION_H_

#include"Linearlokation.h"
#include "../hilfsklassen/GeoKoordinate.h"

/**
 * Diese Klasse repr&auml;sentiert eine Punklokation. Sie erbt von Gebietslokation
 * und Linearlokation und enth&auml;lt die Attribute, die speziell f&uuml;r eine
 * Punklokation sind.<br>
 * Sie enth&auml;lt Methoden um ihre Attribute aus den Rohdaten einzulesen.
 */
class Punktlokation: public Linearlokation {
public:
	/**
	 * Der Standardkonstruktor dieser Klasse.
	 * @param zeile Eine Zeile des Datensatzes.
	 * @param Die &uuml;bergeordnete Gebietslokation.
	 * @param Die &uuml;bergeordnete Linearlokation.
	 */
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
	 * @return Gibt das define PUNKT zurueck.
	 */
	virtual int getType();

	//Nur Getter
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

	//exitNumber; -> Weder Datentyp noch Zweck von Exitnumber gefunden

	//diversionPositive -> Weder Datentyp noch Zweck von Exitnumber gefunden

	//diversionNegative -> Weder Datentyp, noch Zweck von diversionNegative gefunden

	/**
	 * Netzknotennummer der Lokation oder Netzknotennummer des vor der Lokation
	 * liegenden Netzknoten.
	 */
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
