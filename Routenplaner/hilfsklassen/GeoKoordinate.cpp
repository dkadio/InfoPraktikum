/*
 * GeoKoordinate.cpp
 *
 *  Created on: 28.04.2014
 *      Author: christoph
 */

#include "GeoKoordinate.h"

GeoKoordinate::GeoKoordinate(string xKoordinate, string yKoordinate) {
	this->laengenGrad = 0;
	gradEinlesen(xKoordinate, &this->laengenGrad);

	this->breitenGrad = 0;
	gradEinlesen(yKoordinate, &this->breitenGrad);
}

GeoKoordinate::~GeoKoordinate() {

}

void GeoKoordinate::gradEinlesen(string zeichen, float* angabe) {
	try {
		unsigned long int lenght = zeichen.length();
		string nachkommastellen = zeichen.substr(lenght - NACHKOMMA_STELLEN,
		NACHKOMMA_STELLEN);
		string vorkommastellen = zeichen.substr(
				lenght - (NACHKOMMA_STELLEN + VORKOMMA_STELLEN),
				VORKOMMA_STELLEN);
		*angabe = stoi(vorkommastellen)
				+ (((stoi(nachkommastellen)) / (pow(10, NACHKOMMA_STELLEN))));
	} catch (const invalid_argument &e) {
		//Dieser Fehler duerfte eigentlch nicht auftreten.
		std::cerr << "\n" << e.what() << "\nFehler in der Datei" << "\n";
	}
}

float GeoKoordinate::entfernungBerechnen(GeoKoordinate* ziel) {
	float distance, dx, dy, lat;
	lat = (this->breitenGrad + ziel->breitenGrad) / 2 * 0.01745;
	dx = 111.3 * cos(lat) * (this->laengenGrad - ziel->laengenGrad);
	dy = 111.3 * (this->breitenGrad - ziel->getBreitenGrad());

	return (distance = sqrt(dx * dx + dy * dy));
}

string GeoKoordinate::toString() {
	stringstream s;
	s << "\nKoordinaten: " << this->breitenGrad << " " << this->laengenGrad;
	return (s.str());
}

float GeoKoordinate::getBreitenGrad() const {
	return (breitenGrad);
}

float GeoKoordinate::getLaengenGrad() const {
	return (laengenGrad);
}

