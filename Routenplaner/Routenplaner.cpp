#include "Routenplaner.h"
using namespace std;
Hello::Hello() {
	// Das Ding kann eh nichts

}

Hello::~Hello() {
	//delete von Hand in der Main
}

int main() {
	//Datei auslesen
	FileOpener *datei = new FileOpener();
	datei->oeffneDatei("../utf8.csv");
	datei->leseDateiAus();

	cout << "\n\n------------Einlesen abgeschlossen-----------\n\n";
	vector<vector<string> > erg = datei->getDatensatz();

	LokationsVerwaltung *lokVerwaltung = new LokationsVerwaltung(&erg);
	delete datei;

	Graph *graph = new Graph(lokVerwaltung->getGebieteMap());

	UserInterface * interface = new UserInterface(graph);
	interface->start();
	delete interface;
	delete graph;
	delete lokVerwaltung;

	return (EXIT_SUCCESS);
}
