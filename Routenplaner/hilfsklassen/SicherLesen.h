/**
 * SicherLesen.h
 *
 *  Created on: 23.06.2012
 *      Author: Christoph Drost
 *  Headerfile was Funktionen einbindet um sicher Werte einlesen zu koennen.
 *  Jede der entahltenen Methoden beinhaltet einen Eingabestrom. Dieser wird nach
 *  dem Einlesen auf eine semantisch korrekte Eingabe geprüft und bei einem Fehler
 *  zurueck gesetzt. Wenn ein Fehler auftritt, werden die Methoden so lange rekursiv
 *  aufgerufen, bis ein gueltiger Wert zurueckgegeben wird.
 *
 *
 *  Soll in jedes kommende Projekt eingebunden werden.
 *
 */

#ifndef SICHERLESEN_H_
#define SICHERLESEN_H_
#include <iostream>
#include <string>
using namespace std;

/**
 *Sicheres Int Einlesen
 *Prueft auf Fehleingaben beim int-Lesen
 *@return eingelesener Wert
 */
static inline int sicherIntLesen() {
	int wert;
	cin >> wert;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
		cout << "Ungueltige Eingabe fuer Ganzzahl. Nochmal versuchen!" << endl;
		wert = sicherIntLesen();
	}
	return wert;
}

/**
 *Sicheres double Einlesen
 *Prueft auf Fehleingaben beim double-Lesen
 *@return eingelesener Wert
 */
static inline double sicherDoubleLesen() {
	double wert;
	std::cin >> wert;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
		cout << "Ungueltige Eingabe fuer reelle Zahl. Nochmal versuchen!"
				<< endl;
		wert = sicherDoubleLesen();
	}
	return wert;
}
/**
 * Sicheres Einlesen eines Strings
 * Nach der Eingabe mehrerer Woerter wird nur das erste zurueck gegeben
 * Saemtliche Leehrzeichen werden entfernt
 * @deprecated Diese Methode wurde verienfacht.
 */
/*static string sicherStringLesen() {
 string in;
 string out;
 cin.clear();
 getline(cin, in);
 if (in.find(' ') == string::npos) {
 out = in;
 } else if (in.find(' ') != string::npos && in.find(' ') != 0) {
 out = in.substr(0, in.find(' '));
 } else if (in.find(' ') != string::npos && in.find(' ') == 0
 && (in.length() < 2)) {
 out = "LeereEingabe";
 } else if (in.find(' ') != string::npos && in.find(' ') == 0
 && (in.length() >= 2)) {
 int i = 0;
 while (in[i] == ' ') {
 i++;
 }
 out = in.substr(i, in.find(' ', i + 1));
 } else {
 throw "\nUnbekannter Fehler bei der Eingabe!\n";
 }
 return out;
 }*/


/**
 *  Sicheres Einlesen eines Strings.
 */
static inline string sicherStringLesen() {
	string in;
	cin >> in;
	if (cin.fail()) {
		cin.clear();
		sicherStringLesen();
	}
	return in;
}
#endif /* SICHERLESEN_H_ */
