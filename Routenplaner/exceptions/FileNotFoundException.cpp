#include "FileNotFoundException.h"

FileNotFoundException::FileNotFoundException(const char* message) {
	this->meldung = message;

}

FileNotFoundException::~FileNotFoundException() throw () {
	//nichts allokiert
}

