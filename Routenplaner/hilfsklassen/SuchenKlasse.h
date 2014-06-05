/*
 * SuchenKlasse.h
 *
 *  Created on: 07.05.2014
 *      Author: christoph
 */

#ifndef SUCHENKLASSE_H_
#define SUCHENKLASSE_H_

#define ENDE 0
#define SUCH_ID 1
#define SUCH_TYP_BUCHSTABE 2
#define SUCH_TYP_ZAHL 3
#define SUCH_FEIN_TYP 4
#define SUCH_FIRST_NAME 5
#define SUCH_ADMIN_BL 6
#define SUCH_AKTUALITAET 7
#define SUCH_ROAD_NUMBER 8
#define SUCH_ROAD_NAME 9
#define SUCH_SECOND_NAME 10
#define SUCH_AREA_REFERENCE_BYREF 11
#define SUCH_AREA_REFERENCE_BYID 12
#define SUCH_POFFSET_BYREF 13
#define SUCH_POFFSET_BYID 14
#define SUCH_NOFFSET_BYREF 15
#define SUCH_NOFFSET_BYID 16
#define SUCH_URBAN 17
#define SUCH_INTERSECTION_CODE_BYREF 18
#define SUCH_INTERSECTION_CODE_BYID 19
#define SUCH_INTERRUPTS_ROAD_BYREF 20
#define SUCH_INTERRUPTS_ROAD_BYID 21
#define SUCH_TERN 22
#define SUCH_POL_DIR 23
#define SUCH_ADMIN_COUNTY 24
#define SUCH_NETZKNOTEN_VOR 25
#define SUCH_NETZKNOTEN_NACH 26

#define BOOL 1
#define INT 2
#define CHAR 3
#define STRING 4
#define POINTER 5
#define UNSIGNED 6

#include "../geopunkte/LokationsVerwaltung.h"
#include "../exceptions/TypProblemEcxeption.h"

/**
 * Diese Klasse ist ein Container f&uuml;r alle m&ouml;glichen
 * Suchen, die man auf die Lokationsobjekte ansetzen kann.<br>
 */
class SuchenKlasse {
public:
	SuchenKlasse(LokationsVerwaltung const *lokV);
	virtual ~SuchenKlasse();

	/**
	 * Diese Methode ermittelt aus dem eingegebenen int Wert
	 * den entsprechenden Datentyp.<br>
	 * Diese Abfrage bezieht sich auf die defines.
	 * @param eingabe Der Wert eines der Defines
	 * @return Ein weiteres Define, was den Datentyp angibt.
	 */
	int getDatenTyp(int eingabe);
	/**
	 * Diese Methode zeigt an, welche Suchfunktionen verf&uuml;gbar sind.<br>
	 * @return Ein String mit den verf&uuml;gbaren Suchfunktionen und einer
	 * kleinen Men&uuml;f&uuml;hrung.
	 */
	string zeigeSuchOptionen();

	/**
	 * Diese Methode schreibt eine Zeile f&uuml;r die Methode zeigeSuchOptionen.
	 * @param Kommando Die Zahl, die sp&auml;ter f&uuml;r die Men&uuml;f&uuml;hrung
	 * angezeigt werden soll.
	 * @param beschreibung Was das Kommando machen soll.
	 * @return EIne Zeile f&uuml;r die Methode zeigeSuchOptionen.
	 */
	string getSuchZeile(int Kommando, string beschreibung);

	vector<Gebietslokation*> suchen(int modus, bool vergleich)
			throw (TypProblemEcxeption);
	vector<Gebietslokation*> suchen(int modus, int vergleich)
			throw (TypProblemEcxeption);
	vector<Gebietslokation*> suchen(int modus, char vergleich)
			throw (TypProblemEcxeption);
	vector<Gebietslokation*> suchen(int modus, string vergleich)
			throw (TypProblemEcxeption);
	vector<Gebietslokation*> suchen(int modus, Gebietslokation* vergleich)
			throw (TypProblemEcxeption);
	vector<Gebietslokation*> suchen(int modus, unsigned int vergleich)
			throw (TypProblemEcxeption);

	/**
	 * Diese Methode sucht Lokationen anhand ihrer Id.
	 * @param id Die Id, die gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchId(int id);

	/**
	 * Diese Methode sucht Lokationen anhand ihrers Typs.
	 * @param id Der char Typ, nach dem gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchTypBuchstabe(char buchstabe);

	/**
	 * Diese Methode sucht Lokationen anhand ihrers Zahlentyps.
	 * @param id Der Zahlentyp, der gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchTypZahl(int zahl);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Feintyps.
	 * @param feinTyp Der Feintyp, anhand dem gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchFeinTyp(int feinTyp);

	/**
	 * Diese Methode sucht Lokationen anhand ihres First Names.
	 * @param firstName Der First Name, anhand dem gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchFirstName(string firstName);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Admin Bundeslands.
	 * @param adminBundesland Das administrative Bundesland, anhand dessen
	 *  gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchAdminBundesland(string adminBundesLand);

	/**
	 * Diese Methode sucht Lokationen anhand ihrer Aktualit&auml;t.
	 * @param aktualitart Die Aktualit&auml;t, anhand der gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchAktualitaet(string aktualitaet);

	/**
	 * Diese Methode sucht Lokationen anhand ihrer Road Number.
	 * @param roadNumber Die Road Number, anhand der gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchRoadNumber(string roadNumber);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Road Names.
	 * @param roadName Der Road Name, anhand dem gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchRoadName(string roadName);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Second Names.
	 * @param feinTyp Der Feintyp, anhand dem gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchSecondName(string secondName);

	/**
	 * Diese Methode sucht Lokationen anhand ihrer Area Reference.
	 * @param areaReference Die Area Reference, anhand der gesucht werden soll,
	 * bzw. ein Pointer darauf.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchAreaReference(Gebietslokation *areaReference);

	/**
	 * Diese Methode sucht Lokationen anhand ihrer Area Reference.<br>
	 * Aus Gr&uuml;nden der Performance ist die Methode
	 * @link suchAreaReference(Gebietslokation &areaReference)@endlink vorzuziehen.
	 * @param areaReference Die Area Reference, anhand der gesucht werden soll,
	 * bzw. ihre Id.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchAreaReference(int id);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Positive Offset.
	 * @param positiveOffset Der Positive Offset, anhand der gesucht werden soll,
	 * bzw. ein Pointer darauf.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchPositiveOffset(
			Gebietslokation *positiveOffset);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Positive Offset.<br>
	 * Aus Gr&uuml;nden der Performance ist die Methode
	 * @link suchPositiveOffset(Gebietslokation &positiveOffset)@endlink vorzuziehen.
	 * @param positiveOffset Der Positive Offset, anhand der gesucht werden soll,
	 * bzw. seine Id.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchPositiveOffset(int id);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Negative Offset.
	 * @param negativeOffset Der Negative Offset, anhand der gesucht werden soll,
	 * bzw. ein Pointer darauf.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchNegativeOffset(
			Gebietslokation *negativeOffset);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Negative Offset.<br>
	 * Aus Gr&uuml;nden der Performance ist die Methode
	 * @link suchNegativeOffset(Gebietslokation &negativeOffset)@endlink vorzuziehen.
	 * @param id Der Positive Offset, anhand der gesucht werden soll,
	 * bzw. seine Id.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchNegativeOffset(int id);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Negative Offset.<br>
	 * Aus Gr&uuml;nden der Performance ist die Methode
	 * @link suchNegative(Gebietslokation &negativeOffset)@endlink vorzuziehen.
	 * @param id Der Positive Offset, anhand der gesucht werden soll,
	 * bzw. seine Id.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchUrban(bool urban);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Intersection Codes.
	 * @param intersectionCode Der Intersection Code, anhand dem gesucht werden soll,
	 * bzw. ein Pointer darauf.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchIntersectionCode(
			Gebietslokation *intersectionCode);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Intersection Codes.<br>
	 * Aus Gr&uuml;nden der Performance ist die Methode
	 * @link suchIntersectionCode(Gebietslokation &intersectionCode)@endlink
	 * vorzuziehen.
	 * @param id Der Positive Offset, anhand der gesucht werden soll,
	 * bzw. seine Id.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchIntersectionCode(int id);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Intersection Codes.
	 * @param intersectionCode Der Intersection Code, anhand dem gesucht werden soll,
	 * bzw. ein Pointer darauf.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchInterruptsRoad(
			Gebietslokation *interruptsroad);

	/**
	 * Diese Methode sucht Lokationen anhand ihres Interrupts Road.<br>
	 * Aus Gr&uuml;nden der Performance ist die Methode
	 * @link suchInterruptsRoad(Linearlokation &interruptsroad@endlink
	 * vorzuziehen.
	 * @param id Die Id des Interrupts Road, anhand der gesucht werden soll,
	 * bzw. seine Id.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchInterruptsRoad(int id);

	/**
	 * Diese Methode sucht Lokationen anhand ihrers TERN Flags.
	 * @param tern Das Flag, das gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchTern(bool tern);

	/**
	 * Diese Methode sucht Lokationen anhand ihrer zust&auml;ndigen Polizei
	 * Dienststelle.
	 * @param polDir Die Dienststelle, ddie gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchPolDir(string polDir);

	/**
	 * Diese Methode sucht Lokationen anhand ihreres zust&auml;ndigen Bundeslands.
	 * @param adminCounty Das Bundesland, das gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchAdminCounty(string adminCounty);

	/**
	 * Diese Methode sucht Lokationen anhand ihreres Netzknoten Vor.
	 * @param netzKnotenVor Der Netzknoten vor, der gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchNetzKnotenVor(unsigned int netzKnotenVor);

	/**
	 * Diese Methode sucht Lokationen anhand ihreres Netzknoten Nach.
	 * @param netzKnotenNach Der Netzknoten nach, der gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchNetzknotenNach(unsigned int netzKnotenNach);

	/**
	 * Diese Methode sucht Lokationen anhand ihrerer Station.
	 * @param station Der Netzknoten vor, die gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchStation(int station);

	/**
	 * Diese Methode sucht Lokationen anhand ihrerer Geokoordinate.
	 * @param geoKoordinate Die Geokoordinate, nach der gesucht werden soll.
	 * @return Einen Vector mit den gefundenen Lokationen.
	 */
	vector<Gebietslokation*> suchGeokoordinate(GeoKoordinate *geoKoordinate);

	/**
	 * Diese Methode &uuml;bernimmt die eigentliche Suche.<br>
	 * Die f&uuml;r den Vergleich zust&auml;ndige Methode ist der () Operator.<br>
	 * Jede Suchmethode muss diesen in einem Struct implementiert haben.
	 * @note Optimierungen der Suche k&ouml;nnen hier vorgenommen werden.
	 * @param Funktion Die Methode, die als Vergleichsmethode genutzt werden soll.<br>
	 * Sie muss ich jeder such* Methode implementiert sein.
	 * @param suchWert Der Wert, nach dem gesucht werden soll.
	 * @return Ein Vector mit den gesuchten Datens&auml;tzen.
	 */
	template<class Funktion, typename suchWert>
	inline vector<Gebietslokation*> sucheTemplate(Funktion f, suchWert wert);

private:
	/**
	 * Ein Pointer auf ein Lokalit&auml;tsverwaltungsobjekt.<b>
	 * Dort sind die Datens&auml;tze enthalten, die durchsucht werden
	 * sollen.
	 */
	const LokationsVerwaltung *lokalitaetsVerwaltung;
};

template<class Funktion, typename suchWert>
inline vector<Gebietslokation*> SuchenKlasse::sucheTemplate(Funktion f,
		suchWert wert) {
	auto first = (lokalitaetsVerwaltung->getGebieteMap()).begin();
	auto last = lokalitaetsVerwaltung->getGebieteMap().end();
	vector<Gebietslokation*> vec;
	while (first != last) {
		if (f(first->second, wert)) {
			vec.push_back(first->second);
		}
		++first;
	}
	return (vec);
}

#endif /* SUCHENKLASSE_H_ */
