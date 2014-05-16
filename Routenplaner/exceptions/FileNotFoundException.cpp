/*
 * FileNotFoundException.cpp
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#include "FileNotFoundException.h"

FileNotFoundException::FileNotFoundException(const char* message) {
	this->meldung = message;

}

FileNotFoundException::~FileNotFoundException() throw() {
	//nichts allokiert
}

