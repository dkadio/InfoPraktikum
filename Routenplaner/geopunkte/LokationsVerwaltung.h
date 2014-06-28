#ifndef LOKATIONSVERWALTUNG_H_
#define LOKATIONSVERWALTUNG_H_

#include <vector>
#include <map>
#include <string>
#include "Gebietslokation.h"
#include "Linearlokation.h"
#include "Punktlokation.h"
#include "AttributDefines.h"
#include <regex>

#define GEBIETSLOKATION A
#define LINLOKATION L
#define PUNKTLOKATION P

using namespace std;

/**
 * Diese Klasse verwaltet die verschiedenen Lokationen.<br>
 * Neben den Strukturen zum Verwalten sind Methoden implementiert, die zum Einlesen
 * der Datei, bzw. dem Verarbeiten der Rohdatens&auml;tze ben&ouml;tigt werden.
 * Die Daten werden in einer Map vorgehalten um den schnellen Zugriff auf Id zu
 * erm&ouml;glichen.
 */
class LokationsVerwaltung {
public:
	/**
	 * Dieser Konstruktor &uuml;bernimmt beim Aufruf die Verarbeitung der Rohdaten.<br>
	 * Rohdaten sind die Daten, die beim reinen Einlesen in einen Vector weggeschrieben
	 * werden.<br>
	 * In diesem Konstruktor werden aus den Rohdaten Lokations Objekte erzeugt, die
	 * in entsprechenden Datenstrukturen gespeichert werden.
	 */
	LokationsVerwaltung(vector<vector<string> > *datenSatz);

	virtual ~LokationsVerwaltung();
	/**
	 * Diese Methode entscheidet anhand des Types der Zeile, welches Objekt erstellt werden
	 * soll, erstellt es und l&auml;dt es in die Datenstrukturen.
	 * @param Ein Vector aus Strings, der einer Zeile unseres Datensatzes entspricht.
	 *
	 * @deprecated Die Unterscheidung findet schon in w&auml;hrend der Schleifendurchl&auml;fe
	 * in der Methode objekteErstellen() statt.
	 */
	void objektErstellen(vector<string> *zeile, string pattern);

	/**
	 * Diese Methode verteilt den Pointer auf die verschiedenen Datenstrukturen.
	 * @param lokation Ein Pointer auf eine Gebietslokation.
	 */
	void speichereGebietsLokation(Gebietslokation *lokation);

	/**
	 * Diese Methode verteilt den Pointer auf die verschiedenen Datenstrukturen.<br>
	 * Vor der Verteilung wird ein LinearLokation Objekt erstellt.
	 * Dabei werden auch die entsprechenden Gebietslokationen gesucht, in denen die
	 * Linearlokationen abgelegt werden.
	 * @param lokation Ein Pointer auf einen Vector, der einer Zeile des Datensatzes
	 * entspricht.
	 */
	void speichereLinearLokation(vector<string> *zeile);

	/**
	 * Diese Methode erstellt ein Punklokations Objekt und verteilt den Pointer
	 * auf die verschiedenen Datenstrukturen.<br>
	 * Vor der Verteilung wird ein PunktLokation Objekt erstellt.
	 * Dabei werden auch die entsprechenden Linearlokationen gesucht, in denen die
	 * Punktlokationen abgelegt werden.
	 * @param lokation Ein Pointer auf einen Vector, der einer Zeile des Datensatzes
	 * entspricht.
	 */
	void speicherePunkLokation(vector<string> *zeile);

	//Getter
/*	const vector<Gebietslokation*>& getGebieteVector() const {
		return (gebieteVector);
	}*/

	/**
	 * Diese Methode durchla&aumlft den Datensatz Vector mehrmals.<br>
	 * Da die Objekte untereinander Abh&auml;ngigkeiten haben, m&uuml;ssen
	 * sie in mehreren Schritten erstellt werden:
	 *<ol>
	 *	<li> Erstellen der Gebietslokationen.</li>
	 *	<li> Erstellen der Linearlokationen </li>
	 *	<li> Erstellen der Punktlokationen </li>
	 *	<li> Zuordnen der Abh&auml;ngkeiten </li>
	 *</ol>
	 * @param datenSatz Der Vector, der die eingelesene Datei enth&auml;lt.
	 */
	void objekteErstellen(vector<vector<string> > *datenSatz);

	/**
	 * Methode um die Values in die Maps einzutragen.
	 * @param lok Eine Referenz vom Typ Gebietslokation. Sie wird in die Maps
	 * eingetragen.
	 */
	void insertMap(Gebietslokation *lok);

	/**
	 * Mit dieser Methode kann man geziehlt nach dem Namen einer Lokalit&auml;t
	 * suchen.
	 * @param name Der Name der Lokation, die gesucht werden soll.
	 * @return Der Inhalt der toString Methode des gefunden Objekts.
	 *
	 * @deprecated Diese Methode findet nur mit Gl&uuml;ck den richtigen
	 * Eintrag. Sie wurde durch suchen(string) und suchen(int) ersetzt.
	 */
	Gebietslokation* suchName(string name);

	/**
	 * Diese Methode sucht anhand des gegebenen Namen passende Datens&auml;tze.
	 * @param Der Name, nach dem gesucht werden soll.
	 * @return Ein Vector mit den Treffern f&uuml;r die Suche.
	 */
	vector<Gebietslokation*> suchen(string name);

	/**
	 * Diese Methode sucht anhand der gegebenen Id passende Datens&auml;tze.
	 * @return Ein Vector mit den Treffern f&uuml;r die Suche.
	 * @param id Die Id, nach der gesucht werden soll.
	 * @return Ein Vector, dessen erster Eintrag der gesuchte Datensatz ist.
	 */
	vector<Gebietslokation*> suchen(int id);

	/**
	 * Diese Methode sucht anhand des gegebenen Namen passende Datens&auml;tze.<br>
	 * Diese Methode kann entweder nach dem Namen suchen, oder nach Zeichenketten,
	 * die im Namen enthalten sind.
	 * @param name Der Name, nach dem gesucht werden soll.<br>
	 * Diese Suchfunktion sucht intern anhand eines RegEx.
	 * @param uebereinstimmung Ein Flag, ob der &uuml;bergebene Suchstring genau dem
	 * gesuchten Wort entsprechen muss, oder nur ein Teilstring des Namens sein soll.
	 * @return Ein Vector mit den Treffern f&uuml;r die Suche.
	 */
	vector<Gebietslokation*> suchen(string name, bool uebereinstimmung);

	//Nur Getter
	const multimap<string, Gebietslokation*>& getNamenMap() const;
	const map<int, Gebietslokation*>& getGebieteMap() const;

	/**
	 * Diese Methode pr&uuml;ft, ob es sich um eine g&uuml;ltige Id zu einer
	 * Punklokation handelt.
	 * @param id Die Id der Punklokation, die getestet werden soll.
	 * @return true, wenn es sich um eine g&uuml;tige Punktlokation handelt, false
	 * wenn nicht.
	 */
	bool validierePunklokation(int id);
private:
	/**
	 * Dieses Attribut ist die prim&auml;re Datenstruktur f&uuml;r die Datens&auml;tze.
	 * Dort sind die Gebietslokationen organisiert, die wiederum rekrusiv Datens&auml;tze
	 * mit Linearlokationen und Punktlokationen enthalten.
	 *
	 *
	 * @deprecated Der Vector wird nicht mehr ben&ouml;tigt.
	 * Das Durchlaufen einer Map ist effizient genug.
	 */
	//vector<Gebietslokation*> gebieteVector;

	/**
	 * Dieses Attribut erlaubt den schnellen Zugriff auf Objekte anhand ihrer Id.
	 * Der Key ist der LOCATIONCODE einer Lokation, der Value ist der Pointer
	 * auf das Objekt selber.
	 */
	map<int, Gebietslokation*> gebieteMap;

	/**
	 * Dieses Attribut erlaubt das schnelle Suchen einer Lokation anhand eines Namens.<br>
	 * Da es nicht ausgeschlossen ist, dass ein Name mehrmals vorkommt, ist das Attribut als
	 * Multiset realisiert. Bei der Abfrage muss darauf geachtet werden, dass mehrere
	 * R&uuml;ckgabewerte auftreten k&ouml;nnen.
	 *
	 *
	 * @deprecated Aufgrund anderer Suchkriterien kann prinzipiell auf die Namenmap verzichtet
	 * werden.
	 */
	//multimap<string, Gebietslokation*> namenMap;

	/**
	 * Diese Methode pr&uuml;ft anhand einer Regular Expression ob die &uuml;bergebene
	 * Zeile eine Gebietslokation enth&auml;lt.
	 * @param zeile Ein Vector, der eine Zeile aus dem Datensatz repr&auml;sentiert.
	 * @return FALSE, wenn es sich bei der Zeile nicht um eine Gebietslokation handelt. TRUE andernfalls.
	 */
	bool checkGebietsLokation(vector<string> *zeile);

	/**
	 * Diese Methode pr&uuml;ft anhand einer Regular Expression ob die &uuml;bergebene
	 * Zeile eine Linearlokation enth&auml;lt.
	 * @param zeile Ein Vector, der eine Zeile aus dem Datensatz repr&auml;sentiert.
	 * @return FALSE, wenn es sich bei der Zeile nicht um eine Linearlokation handelt. TRUE andernfalls.
	 */
	bool checkLineaLokation(vector<string> *zeile);

	/**
	 * Diese Methode pr&uuml;ft anhand einer Regular Expression ob die &uuml;bergebene
	 * Zeile eine Punktlokation enth&auml;lt.
	 * @param zeile Ein Vector, der eine Zeile aus dem Datensatz repr&auml;sentiert.
	 * @return FALSE, wenn es sich bei der Zeile nicht um eine Punktlokation handelt. TRUE andernfalls.
	 */
	bool checkPunktlokation(vector<string> *zeile);
};

#endif /* LOKATIONSVERWALTUNG_H_ */
