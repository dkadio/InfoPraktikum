#ifndef FILEOPENER_H_
#define FILEOPENER_H_

#include <vector>
#include <string>
#include <cstring>

#include <iostream>
#include <fstream>

#include <sstream>

#include "./../exceptions/FileNotFoundException.h"
using namespace std;
/**
 * Diese Klasse &ouml;ffnet eine Datei.<br>
 * Die Datei wird zeilenweise in einen Vector eingelesen.
 */
class FileOpener {
public:
	FileOpener();
	virtual ~FileOpener();

	/**
	 * Diese Methode &ouml;ffnet den Dateistream.
	 * @param adresse Die Adresse, wo die Datei gespeichert ist.
	 */
	void oeffneDatei(const char*);

	/**
	 * Diese Methode liest die Datei zeilenweise aus. Die Zeilen werden als ein String
	 * im Vector abgelegt.<br>
	 */
	void leseDateiAus(void);

	/**
	 * Diese Methode spaltet die Zeilen der eingelesenen Datei in ihre Einzelteile auf.
	 * Als Seperator wird das Zeilen <i>;</i> genutzt.
	 */
	void spalteZeilen(void);

	//Getter
	const vector<vector<string> >& getDatensatz() const {
		return (datenSatz);
	}

private:
	/**
	 * Dieses Attribut speichert den Datensatz. Es besteht aus einem Vector, der wiederum
	 * Vectoren enth&auml;lt. Die Untervectoren enthalten die einzelnen Spalten der
	 * eingelesenen Zeilen.
	 */
	vector<vector<string> > datenSatz;

	/**
	 * Die ge&ouml;ffnete Datei.
	 */
	ifstream datei;

};

#endif /* FILEOPENER_H_ */
