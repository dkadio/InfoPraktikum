/*
 * Aktualitaet.cpp
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#include "Aktualitaet.h"

Aktualitaet::Aktualitaet() {
	initTime(0, 0, 0, 0, 0, 0);

}

Aktualitaet::Aktualitaet(int tag, int monat, int jahr, int stunde, int minute,
		int sekunde) {
	initTime(tag, monat, jahr, stunde, minute, sekunde);
}

Aktualitaet::Aktualitaet(std::string zeit) {
	int sekunde = 0;
	int minute = 0;
	int stunde = 0;
	int tag = 0;
	int monat = 0;
	int jahr = 0;
	datumEinlesen(&sekunde, &minute, &stunde, &tag, &monat, &jahr, zeit);
	initTime(tag, monat, jahr, stunde, minute, sekunde);
}

Aktualitaet::~Aktualitaet() {
	delete zeit;
}

int Aktualitaet::checkSekunde(int sekunde) {
	if (sekunde < 0 || sekunde > 59) {
		return (1);
	} else {
		return (0);
	}
}

int Aktualitaet::checkMinute(int minute) {
	return (checkSekunde(minute));
}

int Aktualitaet::checkStunde(int stunde) {
	if (stunde < 0 || stunde > 23) {
		return (1);
	} else {
		return (0);
	}
}

int Aktualitaet::checkTag(int tag) {
	if (tag < 0 || tag > 31) {
		return (1);
	} else {
		return (0);
	}
}

int Aktualitaet::checkMonat(int monat) {
	if (monat < 0 || monat > 12) {
		return (1);
	} else {
		return (0);
	}
}

int Aktualitaet::checkJahr(int jahr) {
	// Wird nicht benoetigt
	return (0);
}

void Aktualitaet::datumEinlesen(int* sekunde, int* minute, int* stunde,
		int* tag, int* monat, int* jahr, string datum) {
	/**string substring[6];
	 int i = 0;
	 //Nur die Zahlen auslesen
	 for (string::iterator it = datum.begin(); it < datum.end(); it++) {
	 if (isdigit(*it)) {
	 substring[i] += *it;
	 } else {
	 i++;
	 }
	 }*/
	//Mithilfe Regex den Datumsstring aufspalten und in ein Array blasen
	const regex pattern("\\d+");

	const sregex_token_iterator end;
	int ergebisArray[SEKUNDE+1];
	int anzahlWerte = 0;
	for (sregex_token_iterator i(datum.begin(), datum.end(), pattern); i != end;
			++i, ++anzahlWerte) {
		ergebisArray[anzahlWerte] = stoi(*i);
	}
	if (anzahlWerte > SEKUNDE) {
		*sekunde = ergebisArray[SEKUNDE];
		*minute = ergebisArray[MINUTE];
		*stunde = ergebisArray[STUNDE];
		*tag = ergebisArray[TAG];
		*monat = ergebisArray[MONAT];
		*jahr = ergebisArray[JAHR];
	}
}

void Aktualitaet::initTime(int tag, int monat, int jahr, int stunde, int minute,
		int sekunde) {
	this->zeit = new tm;
	this->zeit->tm_sec = sekunde;
	this->zeit->tm_min = minute;
	this->zeit->tm_hour = stunde;
	this->zeit->tm_mday = tag;
	this->zeit->tm_mon = monat;
	this->zeit->tm_year = jahr;
}

void Aktualitaet::ckeckDatum(int tag, int monat, int jahr, int stunde,
		int minute, int sekunde) throw (ZeitException) {
	string fehler = "";
	int fehlerAnzahl = 0;
	if (checkSekunde(sekunde)) {
		fehler +=
				"Die Sekunden muessen 0>= sekunde <60 sein! Eingelesen wurde: \n";
		fehlerAnzahl++;
	}
	if (checkMinute(minute)) {
		fehler +=
				"Die Minuten muessen 0>= sekunde <60 sein! Eingelesen wurde: \n";
	}
	if (checkStunde(stunde)) {
		fehler +=
				"Die Stunden muessen 0>= sekunde <24 sein! Eingelesen wurde: \n";
	}
	if (checkTag(tag)) {
		fehler += "Die Tage muessen 0>= sekunde <32 sein! Eingelesen wurde: \n";
	}
	if (checkMonat(monat)) {
		fehler +=
				"Die Monate muessen 0>= sekunde <13 sein! Eingelesen wurde: \n";
	}
	if (checkJahr(jahr)) {
		fehler += "Unbekannter Fehler im Jahr!\n+ Eingelesen wurde: \n";
	}

//Falls ein Fehler aufgetreten ist, dann Exception mit der entsprechenden Meldung.
	if (fehlerAnzahl) {
		throw new ZeitException(fehler.c_str());
	}
}

string Aktualitaet::toString() {
	stringstream erg;
//TODO Hierfuer noch ne schoene Fkt. finden
	erg << zeit->tm_mday << "." << zeit->tm_mon << "." << zeit->tm_year << " "
			<< zeit->tm_hour << ":" << zeit->tm_min << ":" << zeit->tm_sec;
	return (erg.str());
}

 struct tm Aktualitaet::getZeit() const {
	return (*zeit);
}
