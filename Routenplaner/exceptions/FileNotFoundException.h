/*
 * FileNotFoundException.h
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#ifndef FILENOTFOUNDEXCEPTION_H_
#define FILENOTFOUNDEXCEPTION_H_

#include <exception>
#include  <string>

/**
 * Diese Exception wird geworfen, wenn die gesuchte Datei nicht gefunden werden konnte.
 */
class FileNotFoundException : public std::exception{
public:
	FileNotFoundException(const char* message);
	virtual ~FileNotFoundException()throw();

	const char * what() const throw () {
		return meldung.c_str();
	}

	const char* toString() {
		return meldung.c_str();
	}

private:
	std::string meldung;
	FileNotFoundException();

};

#endif /* FILENOTFOUNDEXCEPTION_H_ */
