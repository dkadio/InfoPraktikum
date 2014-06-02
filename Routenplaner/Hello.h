/*
 * Hello.h
 *
 *  Created on: 25.04.2014
 *      Author: christoph
 */

#ifndef HELLO_H_
#define HELLO_H_

#include "./reader/FileOpener.h"
#include "geopunkte/LokationsVerwaltung.h"
#include "hilfsklassen/BenutzerInterface.h"
#include <vector>
#include <regex>
#include <cmath>
#include <unistd.h>
#include "graph/Graph.h"
#include "graph/Dijkstra.h"
#include "hilfsklassen/Benutzerabfrage.h"
//#include "hilfsklassen/SuchenKlasse.h"

class Hello {
public:
	Hello();
	virtual ~Hello();
};

#endif /* HELLO_H_ */
