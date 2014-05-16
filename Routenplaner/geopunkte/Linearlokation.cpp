/*
 * Linearlokation.cpp
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#include "Linearlokation.h"

Linearlokation::Linearlokation(vector<string> *zeile,
		Gebietslokation *areaReference) :
		Gebietslokation(zeile) {
	initialisieren();
	this->areaReference = areaReference;
	leseWerteEin(zeile);
}

Linearlokation::~Linearlokation() {
	punktLokations.clear();
}

const string& Linearlokation::getAdminCounty() const {
	return (adminCounty);
}

Gebietslokation* Linearlokation::getAreaReference() {
	return (areaReference);
}

bool Linearlokation::isInNegative() const {
	return (inNegative);
}

bool Linearlokation::isInPositive() const {
	return (inPositive);
}

Linearlokation* Linearlokation::getInterruptsRoad() {
	return (interruptsRoad);
}

Linearlokation* Linearlokation::getIntersectioncode() {
	return (intersectioncode);
}

Linearlokation* Linearlokation::getNegativeOffset() {
	return (negativeOffset);
}

Linearlokation* Linearlokation::getPositiveOffset() {
	return (positiveOffset);
}

bool Linearlokation::isOutNegative() const {
	return (outNegative);
}

bool Linearlokation::isOutPositive() const {
	return (outPositive);
}

const string& Linearlokation::getPoldir() const {
	return (poldir);
}

bool Linearlokation::isPresentNegative() const {
	return (presentNegative);
}

bool Linearlokation::isPresentPositive() const {
	return (presentPositive);
}

const string& Linearlokation::getRoadName() const {
	return (roadName);
}

const string& Linearlokation::getRoadNumber() const {
	return (roadNumber);
}

const string& Linearlokation::getSecondName() const {
	return (secondName);
}

bool Linearlokation::isTern() const {
	return (tern);
}

bool Linearlokation::isUrban() const {
	return (urban);
}

int Linearlokation::getVeraendert() const {
	return (veraendert);
}

void Linearlokation::setAreaReference(Gebietslokation* areaReference) {
	this->areaReference = areaReference;
}

void Linearlokation::leseWerteEin(vector<string>* zeile) {
	this->roadNumber = zeile->at(ROADNUMBER);
	this->roadName = zeile->at(ROADNAME);
	this->secondName = zeile->at(SECOND_NAME);
	try {
		this->urban = stoi(zeile->at(URBAN));
	} catch (const std::invalid_argument &e) {
		this->urban = 0;
	}
	try {
		this->inPositive = stoi(zeile->at(IN_POSITIVE));
	} catch (const std::invalid_argument &e) {
		this->inPositive = 0;
	}
	try {
		this->outPositive = stoi(zeile->at(OUT_POSITIVE));
	} catch (const std::invalid_argument &e) {
		this->outPositive = false;
	}
	try {
		this->inNegative = stoi(zeile->at(IN_NEGATIVE));
	} catch (const std::invalid_argument &e) {
		this->inNegative = false;
	}
	try {
		this->outNegative = stoi(zeile->at(OUT_NEGATIVE));
	} catch (const std::invalid_argument &e) {
		this->outNegative = false;
	}
	try {
		this->presentPositive = stoi(zeile->at(PRESENT_POSITIVE));
	} catch (const std::invalid_argument &e) {
		this->presentPositive = false;
	}
	try {
		this->presentNegative = stoi(zeile->at(PRESENT_NEGATIVE));
	} catch (const std::invalid_argument &e) {
		this->presentNegative = false;
	}
	try {
		this->veraendert = stoi(zeile->at(VERAENDERT));
	} catch (const std::invalid_argument &e) {
		this->veraendert = false;
	}
	try {
		this->tern = stoi(zeile->at(TERN));
	} catch (const std::invalid_argument &e) {
		this->tern = false;
	}
	this->poldir = zeile->at(POLDIR);
	this->adminCounty = zeile->at(ADMIN_County);
}

void Linearlokation::addPktLokation(Punktlokation* pktLocation) {
	this->punktLokations.push_back(pktLocation);
}

//TODO Hier checken, ob stoi typensicher werden soll oder ob es Sinn macht, einfach den
//Fehler zu unterdruecken
void Linearlokation::speichereOffset(map<int, Gebietslokation*>* gebieteMap,
		vector<string> *zeile) {
	try {
		int positiveOffset = stoi(zeile->at(POSITIVE_OFFSET));
		this->positiveOffset = (Linearlokation*) gebieteMap->find(
				positiveOffset)->second;
	} catch (invalid_argument &e) {
		//braucht nicht behandelt zu werden, wenn nicht vorhanden braucht auch
		//nichts eingelesen zu werden.
	}
	try {
		int negativeOffset = stoi(zeile->at(NEGATIVE_OFFSET));
		this->negativeOffset = (Linearlokation*) gebieteMap->find(
				negativeOffset)->second;
	} catch (invalid_argument &e) {
		//braucht nicht behandelt zu werden, wenn nicht vorhanden braucht auch
		//nichts eingelesen zu werden.
	}
}

void Linearlokation::speichereIntersectionCode(
		map<int, Gebietslokation*>* gebieteMap, vector<string> *zeile) {
	try {
		int interSectionCode = stoi(zeile->at(INTERSECTIONSCODE));
		this->intersectioncode = (Linearlokation*) gebieteMap->find(
				interSectionCode)->second;
	} catch (invalid_argument &e) {
		//braucht nicht behandelt zu werden, wenn nicht vorhanden braucht auch
		//nichts eingelesen zu werden.
	}
}

void Linearlokation::verweiseAufbauen(map<int, Gebietslokation*>* gebieteMap,
		vector<string>* zeile) {
	speichereOffset(gebieteMap, zeile);
	speichereInterruptsRoad(gebieteMap, zeile);
	speichereIntersectionCode(gebieteMap, zeile);
}

string Linearlokation::toString() {
	stringstream s;
	s << Gebietslokation::toString();
	s << "\nRoad Number: " << this->roadNumber;
	s << "\nRoad Name:" << this->roadName;
	s << "\nSecond Name: " << this->secondName;
	if (this->areaReference != NULL) {
		s << "\nArea Reference: " << this->areaReference->getFirstName()
				<< ", Id: " << this->areaReference->getId();
	}
	s << "\nNegative Offset: ";
	if (this->negativeOffset != NULL) {
		s << this->negativeOffset->getFirstName() << ", Id: "
				<< this->negativeOffset->getId();
	} else {
		s << " Es ist kein Negative Offset hinterlegt.";
	}
	s << "\nPositive Offset: ";
	if (this->positiveOffset != NULL) {
		s << this->positiveOffset->getFirstName() << ", Id: "
				<< this->positiveOffset->getId();
	} else {
		s << " Es ist kein positive Offset hinterlegt.";
	}
	s << "\nIntersection Code:";
	if (this->intersectioncode != NULL) {
		s << this->intersectioncode->getFirstName() << ", Id: "
				<< this->intersectioncode->getId();
	} else {
		s << " Es ist kein Intersectioncode hinterlegt.";
	}
	s << "\nInterrupts Road";
	if (this->interruptsRoad != NULL) {
		s << this->interruptsRoad->getFirstName() << ", Id: "
				<< this->interruptsRoad->getId();
	} else {
		s << " Es ist kein Interrupts Road hinterlegt hinterlegt.";
	}
	return (s.str());
}

int Linearlokation::getType() {
	return (LINEAR);
}

const vector<Punktlokation*>& Linearlokation::getPunktLokations() const {
	return (punktLokations);
}

void Linearlokation::speichereInterruptsRoad(
		map<int, Gebietslokation*>* gebieteMap, vector<string> *zeile) {
	try {
		int interruptsRoad = stoi(zeile->at(POSITIVE_OFFSET));
		this->interruptsRoad = (Linearlokation*) gebieteMap->find(
				interruptsRoad)->second;
	} catch (invalid_argument &e) {
		//braucht nicht behandelt zu werden, wenn nicht vorhanden braucht auch
		//nichts eingelesen zu werden.
	}
}

void Linearlokation::initialisieren() {
	this->roadName = "";
	this->roadNumber = "";
	this->secondName = "";
	this->areaReference = NULL;
	this->negativeOffset = NULL;
	this->positiveOffset = NULL;
	this->urban = false;
	this->intersectioncode = NULL;
	this->interruptsRoad = NULL;
	this->inPositive = false;
	this->outPositive = false;
	this->inNegative = false;
	this->outNegative = false;
	this->presentPositive = false;
	this->presentNegative = false;
	this->veraendert = 0;
	this->tern = false;
	this->poldir = "";
	this->adminCounty = "";
}
