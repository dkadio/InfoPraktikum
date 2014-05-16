/*
 * SuchenKlasse.cpp
 *
 *  Created on: 07.05.2014
 *      Author: christoph
 */

#include "SuchenKlasse.h"

SuchenKlasse::SuchenKlasse(LokationsVerwaltung const *lokV) {
	this->lokalitaetsVerwaltung = lokV;

}

SuchenKlasse::~SuchenKlasse() {
	//Nichts allokiert
}

vector<Gebietslokation*> SuchenKlasse::suchId(int id) {
	struct Equals {
		bool operator()(Gebietslokation* lok, int vergleich) {
			if (lok->getId() == vergleich) {
				return (true);
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	vector<Gebietslokation*> vec = sucheTemplate(vergleichsOperator, id);
	return (vec);
}

vector<Gebietslokation*> SuchenKlasse::suchTypBuchstabe(char buchstabe) {
	struct Equals {
		bool operator()(Gebietslokation* lok, char vergleich) {
			if (lok->getTypBuchstabe() == vergleich) {
				return (true);
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, buchstabe));
}

vector<Gebietslokation*> SuchenKlasse::suchTypZahl(int zahl) {
	struct Equals {
		bool operator()(Gebietslokation* lok, int vergleich) {
			if (lok->getTypZahl() == vergleich) {
				return (true);
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, zahl));
}

vector<Gebietslokation*> SuchenKlasse::suchFeinTyp(int id) {
	struct Equals {
		bool operator()(Gebietslokation* lok, int vergleich) {
			if (lok->getId() == vergleich) {
				return (true);
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	vector<Gebietslokation*> vec = sucheTemplate(vergleichsOperator, id);
	return (vec);
}

vector<Gebietslokation*> SuchenKlasse::suchFirstName(string firstName) {
	struct Equals {
		bool operator()(Gebietslokation* lok, string vergleich) {
			if (lok->getFirstName() == vergleich) {
				return (true);
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, firstName));
}

vector<Gebietslokation*> SuchenKlasse::suchAdminBundesland(
		string adminBundesLand) {
	struct Equals {
		bool operator()(Gebietslokation* lok, string vergleich) {
			if (lok->getAdminBundesLand() == vergleich) {
				return (true);
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, adminBundesLand));
}
/*
 vector<Gebietslokation*> SuchenKlasse::suchAktualitaet(
 Aktualitaet& aktualitaet) {
 struct Equals {
 bool operator()(Gebietslokation* lok, Aktualitaet vergleich) {
 if (*lok->getAktualitaet() == vergleich) {
 return (true);
 } else {
 return (false);
 }
 }
 } vergleichsOperator;
 return (suche(vergleichsOperator, aktualitaet));
 }
 */

vector<Gebietslokation*> SuchenKlasse::suchRoadNumber(string roadNumber) {
	struct Equals {
		bool operator()(Gebietslokation* lok, string vergleich) {
			if (lok->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getRoadNumber() == vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, roadNumber));
}

vector<Gebietslokation*> SuchenKlasse::suchRoadName(string roadName) {
	struct Equals {
		bool operator()(Gebietslokation* lok, string vergleich) {
			if (lok->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getRoadName() == vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, roadName));
}

vector<Gebietslokation*> SuchenKlasse::suchSecondName(string secondName) {
	struct Equals {
		bool operator()(Gebietslokation* lok, string vergleich) {
			if (lok->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getSecondName() == vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, secondName));
}

vector<Gebietslokation*> SuchenKlasse::suchAreaReference(
		Gebietslokation* areaReference) {
	struct Equals {
		bool operator()(Gebietslokation* lok, Gebietslokation *vergleich) {
			if (lok->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getAreaReference() == vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, areaReference));
}

vector<Gebietslokation*> SuchenKlasse::suchAreaReference(int id) {
	struct Equals {
		bool operator()(Gebietslokation* lok, int vergleich) {
			if (lok->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getAreaReference()->getId()
						== vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, id));
}

vector<Gebietslokation*> SuchenKlasse::suchPositiveOffset(
		Gebietslokation* positiveOffset) {
	struct Equals {
		bool operator()(Gebietslokation* lok, Gebietslokation *vergleich) {
			if (lok->getType() > GEBIET && vergleich->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getPositiveOffset()
						== (Linearlokation*) vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, positiveOffset));
}

vector<Gebietslokation*> SuchenKlasse::suchPositiveOffset(int id) {
	struct Equals {
		bool operator()(Gebietslokation* lok, int vergleich) {
			if (lok->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getNegativeOffset()->getId()
						== vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, id));
}

vector<Gebietslokation*> SuchenKlasse::suchNegativeOffset(
		Gebietslokation* negativeOffset) {
	struct Equals {
		bool operator()(Gebietslokation* lok, Gebietslokation *vergleich) {
			if (lok->getType() > GEBIET && vergleich->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getNegativeOffset()
						== (Linearlokation*) vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (SuchenKlasse::sucheTemplate(vergleichsOperator, negativeOffset));
}

vector<Gebietslokation*> SuchenKlasse::suchNegativeOffset(int id) {
	struct Equals {
		bool operator()(Gebietslokation* lok, int vergleich) {
			if (lok->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getNegativeOffset()->getId()
						== vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, id));
}
vector<Gebietslokation*> SuchenKlasse::suchUrban(bool urban) {
	struct Equals {
		bool operator()(Gebietslokation* lok, bool vergleich) {
			if (lok->getType() > GEBIET) {
				if (((Linearlokation*) lok)->isUrban() == vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, urban));
}

vector<Gebietslokation*> SuchenKlasse::suchIntersectionCode(
		Gebietslokation* intersectionCode) {
	struct Equals {
		bool operator()(Gebietslokation* lok, Gebietslokation *vergleich) {
			if (lok->getType() > GEBIET && vergleich->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getIntersectioncode()
						== (Linearlokation*) vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (SuchenKlasse::sucheTemplate(vergleichsOperator, intersectionCode));
}

vector<Gebietslokation*> SuchenKlasse::suchIntersectionCode(int id) {
	struct Equals {
		bool operator()(Gebietslokation* lok, int vergleich) {
			if (lok->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getIntersectioncode()->getId()
						== vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, id));
}

vector<Gebietslokation*> SuchenKlasse::suchInterruptsRoad(
		Gebietslokation* interruptsroad) {
	struct Equals {
		bool operator()(Gebietslokation* lok, Gebietslokation *vergleich) {
			if (lok->getType() > GEBIET && vergleich->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getInterruptsRoad() == vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (SuchenKlasse::sucheTemplate(vergleichsOperator, interruptsroad));
}

vector<Gebietslokation*> SuchenKlasse::suchInterruptsRoad(int id) {
	struct Equals {
		bool operator()(Gebietslokation* lok, int vergleich) {
			if (lok->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getInterruptsRoad()->getId()
						== vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, id));
}

vector<Gebietslokation*> SuchenKlasse::suchTern(bool tern) {
	struct Equals {
		bool operator()(Gebietslokation* lok, bool vergleich) {
			if (lok->getType() > GEBIET) {
				if (((Linearlokation*) lok)->isTern() == vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, tern));
}

vector<Gebietslokation*> SuchenKlasse::suchPolDir(string polDir) {
	struct Equals {
		bool operator()(Gebietslokation* lok, string vergleich) {
			if (lok->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getIntersectioncode()->getPoldir()
						== vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, polDir));
}

vector<Gebietslokation*> SuchenKlasse::suchAdminCounty(string adminCounty) {
	struct Equals {
		bool operator()(Gebietslokation* lok, string vergleich) {
			if (lok->getType() > GEBIET) {
				if (((Linearlokation*) lok)->getAdminCounty() == vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, adminCounty));
}

vector<Gebietslokation*> SuchenKlasse::suchNetzKnotenVor(
		unsigned int netzKnotenVor) {
	struct Equals {
		bool operator()(Gebietslokation* lok, unsigned int vergleich) {
			if (lok->getType() > LINEAR) {
				if (((Punktlokation*) lok)->getNetzKontenNummerVor()
						== vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, netzKnotenVor));
}

vector<Gebietslokation*> SuchenKlasse::suchNetzknotenNach(
		unsigned int netzKnotenNach) {
	struct Equals {
		bool operator()(Gebietslokation* lok, unsigned int vergleich) {
			if (lok->getType() > LINEAR) {
				if (((Punktlokation*) lok)->getNetzKontenNummerNach()
						== vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, netzKnotenNach));
}

vector<Gebietslokation*> SuchenKlasse::suchStation(int station) {
	struct Equals {
		bool operator()(Gebietslokation* lok, int vergleich) {
			if (lok->getType() > LINEAR) {
				if (((Punktlokation*) lok)->getStation() == vergleich) {
					return (true);
				} else {
					return (false);
				}
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, station));
}

string SuchenKlasse::zeigeSuchOptionen() {
	ostringstream ausgabe;
	ausgabe << "\nWas wollen Sie suchen?\n";
	ausgabe << getSuchZeile(SUCH_ID, "die die gleiche Id haben");
	ausgabe
			<< getSuchZeile(SUCH_TYP_BUCHSTABE,
					"die den gleichen Typ Buchstaben haben");
	ausgabe << getSuchZeile(SUCH_TYP_ZAHL, "die den gleichen Zahlentyp haben");
	ausgabe << getSuchZeile(SUCH_FEIN_TYP, "die den gleichen Feintyp haben");
	ausgabe << getSuchZeile(SUCH_FEIN_TYP, "die den gleichen First Name haben");
	ausgabe
			<< getSuchZeile(SUCH_ADMIN_BL,
					"die das gleiche Administrative Bundesland haben");
	ausgabe << getSuchZeile(SUCH_AKTUALITAET, "die gleiche Aktualitaet haben");
	ausgabe << getSuchZeile(SUCH_ROAD_NUMBER, "die gleiche Road Number haben");
	ausgabe << getSuchZeile(SUCH_ROAD_NAME, "den gleichen Road Name haben");
	ausgabe
			<< getSuchZeile(SUCH_SECOND_NAME,
					"den gleichen Section Name haben");
	ausgabe
			<< getSuchZeile(SUCH_AREA_REFERENCE_BYREF,
					"die gleiche Area Reference haben, anhand Pointer");
	ausgabe
			<< getSuchZeile(SUCH_AREA_REFERENCE_BYID,
					"die gleiche Area Reference haben, anhand ihrer ID");
	ausgabe
			<< getSuchZeile(SUCH_POFFSET_BYREF,
					"den gleichen Positive Offset haben, anhand Pointer");
	ausgabe
			<< getSuchZeile(SUCH_POFFSET_BYID,
					"den gleichen Positive Offset haben, anhand ID");
	ausgabe
			<< getSuchZeile(SUCH_NOFFSET_BYREF,
					"den gleichen Negative Offset haben, anhand Pointer");
	ausgabe
			<< getSuchZeile(SUCH_NOFFSET_BYID,
					"den gleichen Negative Offset haben, anhand ID");
	ausgabe << getSuchZeile(SUCH_URBAN, "die das gleiche Urban Flag haben");
	ausgabe
			<< getSuchZeile(SUCH_INTERSECTION_CODE_BYREF,
					"den gleichen Intersection Code haben, anhand Pointer");
	ausgabe
			<< getSuchZeile(SUCH_INTERSECTION_CODE_BYID,
					"den gleichen Intersection Code haben, anhand ID");
	ausgabe
			<< getSuchZeile(SUCH_INTERRUPTS_ROAD_BYREF,
					"den gleichen Interrupts Road haben, anhand Pointer");
	ausgabe
			<< getSuchZeile(SUCH_INTERRUPTS_ROAD_BYID,
					"den gleichen Interrupts Road haben, anhand ID");
	ausgabe << getSuchZeile(SUCH_TERN, "das gleiche Tern Flag haben");
	ausgabe
			<< getSuchZeile(SUCH_POL_DIR,
					"die gleiche zustaendige Polizeidienstelle haben");
	ausgabe
			<< getSuchZeile(ADMIN_County,
					"das gleiche administrative Bundesland haben");
	ausgabe
			<< getSuchZeile(SUCH_NETZKNOTEN_VOR,
					"den gleichen Netzknoten Vor haben");
	ausgabe
			<< getSuchZeile(SUCH_NETZKNOTEN_NACH,
					"den gleichen Netzknoten Nach haben");
	return (ausgabe.str());
}

string SuchenKlasse::getSuchZeile(int Kommando, string beschreibung) {
	ostringstream ausgabe;
	ausgabe << "\n " << Kommando << " - Alle Lokationen suchen, die "
			<< beschreibung << ".";
	return (ausgabe.str());
}

vector<Gebietslokation*> SuchenKlasse::suchen(int modus, bool vergleich)
		throw (TypProblemEcxeption) {
	switch (modus) {
	case SUCH_URBAN:
		return (suchUrban(vergleich));
		break;
	case SUCH_TERN:
		return (suchTern(vergleich));
		break;
	default:
		throw TypProblemEcxeption(
				"Falscher Modus, oder kein Bool Wert uebergeben");
	}
	vector<Gebietslokation*> vec;
	return (vec);
}

vector<Gebietslokation*> SuchenKlasse::suchen(int modus, int vergleich)
		throw (TypProblemEcxeption) {
	switch (modus) {
	case SUCH_ID:
		return (suchId(vergleich));
		break;
	case SUCH_TYP_ZAHL:
		return (suchTypZahl(vergleich));
		break;
	case SUCH_FEIN_TYP:
		return (suchFeinTyp(vergleich));
		break;
	case SUCH_AREA_REFERENCE_BYID:
		return (suchAreaReference(vergleich));
		break;
	case SUCH_POFFSET_BYID:
		return (suchPositiveOffset(vergleich));
		break;
	case SUCH_NOFFSET_BYID:
		return (suchNegativeOffset(vergleich));
		break;
	case SUCH_INTERSECTION_CODE_BYID:
		return (suchIntersectionCode(vergleich));
		break;
	case SUCH_INTERRUPTS_ROAD_BYID:
		return (suchInterruptsRoad(vergleich));
		break;
	default:
		throw TypProblemEcxeption(
				"Falscher Modus oder kein Zahlenwert uebgergeben");
	}
	vector<Gebietslokation*> vec;
	return (vec);
}

vector<Gebietslokation*> SuchenKlasse::suchen(int modus, string vergleich)
		throw (TypProblemEcxeption) {
	switch (modus) {
	case SUCH_FIRST_NAME:
		return (suchFirstName(vergleich));
		break;
	case SUCH_ADMIN_BL:
		return (suchAdminBundesland(vergleich));
		break;
	case SUCH_ROAD_NUMBER:
		return (suchRoadNumber(vergleich));
		break;
	case SUCH_ROAD_NAME:
		return (suchRoadName(vergleich));
		break;
	case SUCH_SECOND_NAME:
		return (suchSecondName(vergleich));
		break;
	case SUCH_POL_DIR:
		return (suchPolDir(vergleich));
		break;
	case SUCH_ADMIN_COUNTY:
		return (suchAdminCounty(vergleich));
		break;
	case SUCH_AKTUALITAET:
		return (suchAktualitaet(vergleich));
		break;
	default:
		throw TypProblemEcxeption(
				"Falscher Modus oder keine Zeichenkette uebergeben");
	}
	vector<Gebietslokation*> vec;
	return (vec);
}

vector<Gebietslokation*> SuchenKlasse::suchen(int modus,
		Gebietslokation* vergleich) throw (TypProblemEcxeption) {
	switch (modus) {
	case SUCH_AREA_REFERENCE_BYREF:
		return (suchAreaReference(vergleich));
		break;
	case SUCH_POFFSET_BYREF:
		return (suchPositiveOffset(vergleich));
		break;
	case SUCH_NOFFSET_BYREF:
		return (suchNegativeOffset(vergleich));
		break;
	case SUCH_INTERSECTION_CODE_BYREF:
		return (suchIntersectionCode(vergleich));
		break;
	case SUCH_INTERRUPTS_ROAD_BYREF:
		return (suchInterruptsRoad(vergleich));
		break;
	default:
		throw TypProblemEcxeption(
				"Falscher Modus oder kein Gebietslokation Pointer uebergeben");
	}
	vector<Gebietslokation*> vec;
	return (vec);

}

vector<Gebietslokation*> SuchenKlasse::suchen(int modus, char vergleich)
		throw (TypProblemEcxeption) {
	switch (modus) {
	case SUCH_TYP_BUCHSTABE:
		return (suchTypBuchstabe(vergleich));
		break;
	default:
		throw TypProblemEcxeption(
				"Falscher Modus oder kein Buchstabe uebergeben");
	}
	vector<Gebietslokation*> vec;
	return (vec);
}

vector<Gebietslokation*> SuchenKlasse::suchen(int modus, unsigned int vergleich)
		throw (TypProblemEcxeption) {
	switch (modus) {
	case SUCH_NETZKNOTEN_VOR:
		return (suchNetzKnotenVor(vergleich));
		break;
	case SUCH_NETZKNOTEN_NACH:
		return (suchNetzknotenNach(vergleich));
		break;
		throw TypProblemEcxeption(
				"Falscher Modus oder kein Zahlenwert uebergeben");
	}
	vector<Gebietslokation*> vec;
	return (vec);
}

int SuchenKlasse::getDatenTyp(int eingabe) {
	switch (eingabe) {
	case SUCH_URBAN:
		return (BOOL);
		break;
	case SUCH_TERN:
		return (BOOL);
		break;
	case SUCH_ID:
		return (INT);
		break;
	case SUCH_TYP_ZAHL:
		return (INT);
		break;
	case SUCH_FEIN_TYP:
		return (INT);
		break;
	case SUCH_AREA_REFERENCE_BYID:
		return (INT);
		break;
	case SUCH_POFFSET_BYID:
		return (INT);
		break;
	case SUCH_NOFFSET_BYID:
		return (INT);
		break;
	case SUCH_INTERSECTION_CODE_BYID:
		return (INT);
		break;
	case SUCH_INTERRUPTS_ROAD_BYID:
		return (INT);
		break;
	case SUCH_FIRST_NAME:
		return (STRING);
		break;
	case SUCH_ADMIN_BL:
		return (STRING);
		break;
	case SUCH_ROAD_NUMBER:
		return (STRING);
		break;
	case SUCH_ROAD_NAME:
		return (STRING);
		break;
	case SUCH_SECOND_NAME:
		return (STRING);
		break;
	case SUCH_POL_DIR:
		return (STRING);
		break;
	case SUCH_ADMIN_COUNTY:
		return (STRING);
		break;
	case SUCH_AKTUALITAET:
		return (STRING);
		break;
	case SUCH_AREA_REFERENCE_BYREF:
		return (POINTER);
		break;
	case SUCH_POFFSET_BYREF:
		return (POINTER);
		break;
	case SUCH_NOFFSET_BYREF:
		return (POINTER);
		break;
	case SUCH_INTERSECTION_CODE_BYREF:
		return (POINTER);
		break;
	case SUCH_INTERRUPTS_ROAD_BYREF:
		return (POINTER);
		break;
	case SUCH_TYP_BUCHSTABE:
		return (CHAR);
		break;
	case SUCH_NETZKNOTEN_VOR:
		return (UNSIGNED);
		break;
	case SUCH_NETZKNOTEN_NACH:
		return (UNSIGNED);
		break;
	}
	return (ENDE);

}

vector<Gebietslokation*> SuchenKlasse::suchGeokoordinate(
		GeoKoordinate* geoKoordinate) {
	struct Equals {
		bool operator()(Gebietslokation* lok, GeoKoordinate *vergleich) {
			if (lok->getType() > LINEAR) {
				GeoKoordinate *geo = ((Punktlokation*) lok)->getGeoKoordinate();
				if (geo->getBreitenGrad() != vergleich->getBreitenGrad()) {
					return (false);
				}
				if (geo->getLaengenGrad() != vergleich->getLaengenGrad()) {
					return (false);
				}
				return (true);
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, geoKoordinate));
}

vector<Gebietslokation*> SuchenKlasse::suchAktualitaet(string aktualitaet) {
	struct Equals {
		bool operator()(Gebietslokation* lok, string vergleich) {
			if (lok->getAktualitaet()->toString() == vergleich) {
				return (true);
			} else {
				return (false);
			}
		}
	} vergleichsOperator;
	return (sucheTemplate(vergleichsOperator, aktualitaet));
}
