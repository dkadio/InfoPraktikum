#ifndef TYPPROBLEMECXEPTION_H_
#define TYPPROBLEMECXEPTION_H_
#include <exception>
#include <string>

using namespace std;

/**
 * Diese Exception wird geworfen, wenn es bei einer Typumwandlung zu einem Problem gekommen
 * ist.
 */
class TypProblemEcxeption {
public:
	TypProblemEcxeption(string fehler);
	virtual ~TypProblemEcxeption();

	virtual const char * what() const throw ();
private:
	string fehler;
};

#endif /* TYPPROBLEMECXEPTION_H_ */
