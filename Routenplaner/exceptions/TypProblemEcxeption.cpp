/*
 * TypProblemEcxeption.cpp
 *
 *  Created on: 08.05.2014
 *      Author: christoph
 */

#include "TypProblemEcxeption.h"

TypProblemEcxeption::TypProblemEcxeption(string fehler) {
	this->fehler = fehler;
}

TypProblemEcxeption::~TypProblemEcxeption() {
	//Nichts allokiert
}

const char* TypProblemEcxeption::what() const throw () {
	return (fehler.c_str());
}
