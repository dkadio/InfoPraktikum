/*
 * Punktlokation.cpp
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#include "Punktlokation.h"

Punktlokation::Punktlokation(vector<string> *zeile,
		Gebietslokation *areaReference, Linearlokation *linearReference) :
		Linearlokation(zeile, areaReference) {
	initialisieren();
	this->linearReference = linearReference;
	if (!zeile->at(NETZKNOTEN1_NR).empty()) {
		try {
			this->netzKontenNummerVor = stoi(zeile->at(NETZKNOTEN1_NR));
		} catch (const std::invalid_argument &e) {
			this->netzKontenNummerVor = 0;
		}
	}
	if (!zeile->at(NETZKNOTEN2_NR).empty()) {
		try {
			this->netzKontenNummerNach = stoi(zeile->at(NETZKNOTEN2_NR));
		} catch (const std::invalid_argument &e) {
			this->netzKontenNummerNach = 0;
		}
	}
	if (!zeile->at(STATION).empty()) {
		try {
			this->station = stoi(zeile->at(STATION));
		} catch (const std::invalid_argument &e) {
			this->station = 0;
		}
	}
	this->geoKoordinate = new GeoKoordinate(zeile->at(X_KOORDINATE),
			zeile->at(Y_KOORDINATE));
}

Punktlokation::~Punktlokation() {
	delete this->geoKoordinate;
}

string Punktlokation::toString() {
	stringstream s;
	s << Linearlokation::toString();
/*	s << "\nLinear Reference: ";
	if (this->linearReference != NULL) {
		s << this->linearReference->getFirstName() << ", Id: "
				<< this->linearReference->getId();
	} else {
		s << "Keine Linear Reference hinterlegt.";
	}
	s << "\nNetzknotennummer vor der Lokation: " << this->netzKontenNummerVor;
*/	s << "\nNetzknotennummer nach der Lokation: " << this->netzKontenNummerNach;
	if (this->geoKoordinate != NULL) {
		s << this->geoKoordinate->toString();
	}
	return (s.str());
}

int Punktlokation::getType() {
	return (PUNKT);
}

GeoKoordinate * Punktlokation::getGeoKoordinate() const {
	return (geoKoordinate);
}

Linearlokation* Punktlokation::getLinearReference() const {
	return (linearReference);
}

int Punktlokation::getNetzKontenNummerNach() const {
	return (netzKontenNummerNach);
}

int Punktlokation::getNetzKontenNummerVor() const {
	return (netzKontenNummerVor);
}

int Punktlokation::getStation() const {
	return (station);
}
;

void Punktlokation::initialisieren() {
	this->linearReference = NULL;
	this->netzKontenNummerVor=0;
	this->netzKontenNummerNach=0;
	this->station=0;
	this->geoKoordinate=NULL;

}
