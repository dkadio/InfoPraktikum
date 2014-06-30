#include "FileOpener.h"

FileOpener::FileOpener() {
}

FileOpener::~FileOpener() {
	//Nichts zu tun
}

void FileOpener::oeffneDatei(const char* adresse) {
	datei.open(adresse, ifstream::in);
	//datei.open("/Users/christoph/Documents/HTW/SEM6/InfoPraktikum/InfoPraktikum/Routenplaner/utf8.csv", ifstream::in); TODO Fuer Release loeschen
	if (!datei) {
		throw FileNotFoundException("Die Datei konnte nicht gefunden werden.");
	}
}

void FileOpener::leseDateiAus() {
	string zeile, spalte;
	vector<string> zeilenVector;
	while (getline(datei, zeile)) {
		istringstream stringStream(zeile);
		while (getline(stringStream, spalte, ';')) {
			zeilenVector.push_back(spalte);
			spalte = "";
		}
		if (!zeilenVector.empty()) {
			datenSatz.push_back(zeilenVector);
			zeilenVector.clear();
		}
	}
}
