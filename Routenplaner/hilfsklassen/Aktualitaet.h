/*
 * Aktualitaet.h
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#ifndef AKTUALITAET_H_
#define AKTUALITAET_H_
#include <cstring>
#include<time.h>
#include<string>
#include <sstream>
#include <regex>
#include "./../exceptions/ZeitException.h"


#define TAG 0
#define MONAT 1
#define JAHR 2
#define STUNDE 3
#define MINUTE 4
#define SEKUNDE 5

using namespace std;
class Aktualitaet {
public:
	/**
	 * Dieser Konstruktor dient lediglich dem Konstruieren eines Objekts, wenn der Datensatz
	 * keinen Wert f&uuml;r seine Aktualit&auml;t vorgibt.<br>
	 * Standardm&auml;&szlig wird mit der Unixzeit(0) initialisiert.
	 */
	Aktualitaet();
	/**
	 * Dieser Konstruktor enth&auml;lt alle Parameter, die zur Speicherung der Aktualit&auml;t
	 * ben&ouml;tigt werden.
	 * @param tag Der Tag im Monat (1-31).
	 * @param monat Der Monat im Jahr (1-12).
	 * @param jahr Das Jahr (Zahlenwert, nur durch die Grenzen des Integer begrenzt).
	 * @param stunde (Die Stunde 0-24).
	 * @param minute (0-60).
	 * @param sekunde (0-60).
	 */
	Aktualitaet(int tag, int monat, int jahr, int stunde, int minute,
			int sekunde);
	/**
	 * Dieser Konstruktor kann mit dem String aus der Eingabedatei initialisiert werden.
	 * Eine Pr&uuml;fung findet nur auf eine F&uuml;llung des Strings statt.
	 * @param zeit
	 */
	Aktualitaet(std::string zeit);
	virtual ~Aktualitaet();

	/**
	 * Diese Methode pr&uuml;ft die &uuml;bergebenen Werte auf ihre Plausibilit&auml;t.
	 * Hierzu werden die einzelnen "check" Methoden aufgerufen.
	 * @param tag Der Tag des Monats.
	 * @param monat Der Monat des Jahres.
	 * @param jahr Das Jahr.
	 * @param stunde Die Stunde.
	 * @param minute Die Minute.
	 * @param sekunde Die Sekunde.
	 */
	void ckeckDatum(int tag, int monat, int jahr, int stunde, int minute,
			int sekunde) throw (ZeitException);

	/**
	 * Diese Methode gibt das Datum wieder in der Form aus, in der es in der Datei steht.
	 * @return Das Datum in der Form, wie es in die Datei geh&ouml;rt.
	 */
	string toString();
	struct tm getZeit() const;

private:
	struct tm *zeit;
	/**
	 * Dieser Funktion erlaubt es, das Datum aus der Datei einzulesen. Die einzelnen Werte des
	 * Datums werden in Integer Werte gespeichert.
	 *
	 * @param sekunde Pointer auf die Sekunde.
	 * @param minute Pointer auf die Minute.
	 * @param stunde Pointer auf die Stunde.
	 * @param tag Pointer auf den Tag.
	 * @param monat Pointer auf den Monat.
	 * @param jahr Pointer auf das Jahr.
	 * @param datum Das Datum was eingelesen werden soll.
	 */
	void datumEinlesen(int *sekunde, int *minute, int *stunde, int *tag,
			int *monat, int *jahr, string datum);

	/**
	 * Initialisiert das ZeitStruct.
	 * @param tag
	 * @param monat
	 * @param jahr
	 * @param stunde
	 * @param minute
	 * @param sekunde
	 */
	void initTime(int tag, int monat, int jahr, int stunde, int minute,
			int sekunde);

	/**
	 * Pr&uml;ft, ob die Sekundenangabe ein plausibler Wert ist. Es werden nur 0>= Werte <60
	 * akzeptiert.
	 * @param seknde Die Anzahl der Sekunden.
	 * @return 0, wenn i.O. 1, wenn Fehler.
	 */
	int checkSekunde(int sekunde);

	/**
	 * Pr&uml;ft, ob die Minutenangabe ein plausibler Wert ist. Es werden nur 0>= Werte <60
	 * akzeptiert.
	 * @param stunde Die Anzahl der Minuten.
	 * @return 0, wenn i.O. 1, wenn Fehler.
	 */
	int checkMinute(int sekunde);

	/**
	 * Pr&uml;ft, ob die Stundenangabe ein plausibler Wert ist. Es werden nur 0>= Werte <24
	 * akzeptiert.
	 * @param stunde Die Anzahl der Stunden.
	 * @return 0, wenn i.O. 1, wenn Fehler.
	 */
	int checkStunde(int stunde);

	/**
	 * Pr&uml;ft, ob die Tagesangabe ein plausibler Wert ist. Es werden nur 0>= Werte <32
	 * akzeptiert.
	 * @param tag Die Anzahl der Tage (vgl. Kalender).
	 * @return 0, wenn i.O. 1, wenn Fehler.
	 */
	int checkTag(int tag);

	/**
	 * Pr&uml;ft, ob die Monatsangabe ein plausibler Wert ist. Es werden nur 0>= Werte <13
	 * akzeptiert.
	 * @param sekunde Die Anzahl der Monate (Bsp. 1 f&uuml;r Januar).
	 * @return 0, wenn i.O. 1, wenn Fehler.
	 */
	int checkMonat(int monat);

	/**
	 Aktuell nicht implementiert.
	 * @param sekunde Die Jahreszahl.
	 * @return 0, immer 0.
	 */
	int checkJahr(int jahr);
};
/*
bool operator==(Aktualitaet & lhs, Aktualitaet & rhs) {
	if (lhs.getZeit().tm_sec != rhs.getZeit().tm_sec) {
		return (false);
	}
	if (lhs.getZeit().tm_min != rhs.getZeit().tm_min) {
		return (false);
	}
	if (lhs.getZeit().tm_hour != rhs.getZeit().tm_hour) {
		return (false);
	}
	if (lhs.getZeit().tm_year != rhs.getZeit().tm_year) {
		return (false);
	}
	if (lhs.getZeit().tm_mon != rhs.getZeit().tm_mon) {
		return (false);
	}
	if (lhs.getZeit().tm_mday != rhs.getZeit().tm_mday) {
		return (false);
	}
	return (true);
}*/

#endif /* AKTUALITAET_H_ */
