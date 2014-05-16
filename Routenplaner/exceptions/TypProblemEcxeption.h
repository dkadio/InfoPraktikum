/*
 * TypProblemEcxeption.h
 *
 *  Created on: 08.05.2014
 *      Author: christoph
 */

#ifndef TYPPROBLEMECXEPTION_H_
#define TYPPROBLEMECXEPTION_H_
#include <exception>
#include <string>

using namespace std;

class TypProblemEcxeption {
public:
	TypProblemEcxeption(string fehler);
	virtual ~TypProblemEcxeption();

    virtual const char * what() const throw();
private:
    string fehler;
};

#endif /* TYPPROBLEMECXEPTION_H_ */
