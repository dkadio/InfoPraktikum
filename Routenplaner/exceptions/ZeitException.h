#ifndef ZEITEXCEPTION_H_
#define ZEITEXCEPTION_H_
#include <exception>
#include  <string>
/**
 * Diese Exception wird geworfen, wenn Fehler in der Umwandlung von Zeiten auftreten.<br>
 * Weiterhin sind hier auch Methoden enthalten, die diese Pr&uuml;fung durchf&uumhren.<br>
 * Die Pr&uuml;fmethoden geben im Fehlerfall eine 1 zur&uuml;ck. Wenn alles I.O. ist, eine
 * 0.
 */
class ZeitException: public std::exception {
public:
	ZeitException(const char* message);
	virtual ~ZeitException() throw () {
	}
	;
	/**
	 * Methode, die den Grund der Exception zur&uuml;ck gibt.
	 * @return Den Grund des Fehlers.
	 */
	const char * what() const throw () {
		return meldung.c_str();
	}

private:
	std::string meldung;
	ZeitException();

};

#endif /* ZEITEXCEPTION_H_ */
