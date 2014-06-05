#ifndef GEBIETSLOKATION_H_
#define GEBIETSLOKATION_H_

//Klassenwerte definieren. Diese werden durch die Methode getType() zur&uuml;ck
//gegeben. So kann geprueft werden, um welchen Typ es sich handelt.
#define GEBIET 0
#define LINEAR 1
#define PUNKT 2

#include <string>
#include <vector>
#include <map>
#include "../hilfsklassen/Aktualitaet.h"
#include "AttributDefines.h"
#include<sstream>

using namespace std;
/**
 * Diese Klasse stellt ein Gebiet dar. Gebietslokationen sind laut der Dokumentation
 * des Bundesamtes mit einem "A" gekennzeichnet. Sie definieren grobe Gebiete,
 * wie beispielsweise Kontinente, L&auml;nder Ballungsr&auml;me oder Fl&uml;sse.
 */
class Linearlokation;
class Gebietslokation {
public:
	/**
	 * Dieser Konstruktor soll als Standardkonstruktor genutzt werden. <br>
	 * Aus dem Vector werden die entsprechenden Attribute der Zeile ausgelesen.
	 * @param Ein Vector, der einer Zeile aus dem Datensatz entspricht.
	 */
	Gebietslokation(vector<string> *zeile);
	virtual ~Gebietslokation();

	/**
	 * Mit dieser Methode kann dem Vector mit den Linearlokationen ein
	 * Element angeh&auml;ngt werden.<br>
	 * Der Vektor enth&auml;lt alle Linearlokationen, die in diesem Gebiet
	 * liegen.
	 * @param lokation Die Linearlokation, die angeh&auml;ngt werden soll.
	 */
	void addLinLokation(Linearlokation *lokation);

	/**
	 * Gibt informationen zu dem Objekt zur&uuml;ck.
	 * @return Ein String, wo was drin steht.
	 */
	virtual string toString();

	/**
	 * M&ouml;glichkeit um den Typ der Klasse zu pr&uuml;fen.<br>
	 * Die M&ouml;glichen R&uuml;ckgabewerte sind zu Beginn der Klasse
	 * als define gesetzt.
	 * @return Gibt das define GEBIET zurueck.
	 */
	virtual int getType();

	//Alles Getter, nicht weiter kommentierwuerdig
	const string& getFirstName() const;
	int getId() const;
	const string& getAdminBundesLand() const;
	Aktualitaet* getAktualitaet() const;
	int getFeinTyp() const;
	const vector<Linearlokation*>& getLinLocations() const;
	char getTypBuchstabe() const;
	int getTypZahl() const;

protected:
	/**
	 * Die Id einer Lokation erlaubt eine eindeutige Zuordnung dieser Lokation.
	 * In der Hierarchie folgende Lokationen verweisen auf diese Id.<br>
	 * Die ID entspricht dem "LOCATIONCODE" der Dokumentation.
	 */
	unsigned int id;
	/**
	 * Der Grob Typ einer Lokation gibt an, um weche Lokation es sich handelt.
	 * Er ist nur mit einem Buchstaben gekennzeichnet. Dieser Buchstabe ist im Fall
	 * der Gebietslokation immer A.
	 * Das Feld "TYPE" in der Dokumentation des Bundesamtes setzt sich aus @link typBuchstabe
	 * @endlink und @link typZahl @endlink zusammen.
	 */
	char typBuchstabe;

	/**
	 * Zur Beschriebung der Lokation geh&ouml;rt eine Zahl. Die Zahl beschreit, um welche
	 * Lokation es sich handelt.<br>
	 * M&ouml;glich sind:<br>
	 * <ol>
	 * 		<li>Kontinent</li>
	 * 		<li>L&auml;ndergruppe</li>
	 * 		<li>Land</li>
	 * 		<li><i>Nicht definiert</i></li>
	 * 		<li>Gew&auml;sser</li>
	 * 		<li>Allgemeines Gebiet</li>
	 * 		<li>Bundesland</li>
	 * 		<li>regierungsbezirk</li>
	 * 		<li>Gemeinde / Stadt</li>
	 * 		<li>Gemeindeteil</li>
	 * 		<li>Teilgebiet</li>
	 * </ol>
	 * F&uml;r die Benennung wurde jeweils die Beschreibung des ersten @link feinTyp @endLink
	 * verwendet.<br>
	 * Das Feld "TYPE" in der Dokumentation des Bundesamtes setzt sich aus @link typBuchstabe
	 * @endlink und @link typZahl @endlink zusammen.
	 */
	int typZahl;

	/**
	 * Der feinTyp beschreibt den Typ einer Lokation genauer. <br>
	 * Der Typ A5 beispielsweise steht f&uuml;r ein Gew&auml;sser. Wird das Gew&auml;sser
	 * durch den Feintyp 2 genauer spezifiziert, wird das allgemeine Ge&auml;sser zu einem
	 * Binnensee.
	 */
	int feinTyp;

	/**
	 * Der Name der Location.<br>
	 * Bsp.:Deutschland
	 */
	string firstName;

	/**
	 * Dieses Attribut gibt an, welches Bundesland f&uuml;r die Bearbeitung zust&auml;ndig ist.
	 * Dieses Attribut wird im aktuellen Release nicht genutzt, ist aber dennoch der
	 * Vollst&auml;ndigkeit halber enthalten.
	 */
	string adminBundesLand;

	/**
	 *Beschreibt vermutlich die Aktualit&auml;t des Datensatzes. Wird im aktuellen Release
	 *nicht genutzt.
	 */
	Aktualitaet *aktualitaet;

	/**
	 * In diesem Vector sind die Linearlocations enthalten, die zu diesem Gebiet ge&ouml;ren.
	 */
	vector<Linearlokation*> linLocations;

	/**
	 * Diese Methode initialisiert alle Werte der Klasse mit
	 * 0, false oder NULL.
	 */
	virtual void initialisieren();
};

#endif /* GEBIETSLOKATION_H_ */
