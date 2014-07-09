
.SUFFIXES: .cpp .o

include ../config

LIB=libhilf.a

.cpp.o:
	$(CPP) $(WARN) -I. -std=c++11 -c $<

OBJ= Aktualitaet.o BenutzerInterface.o GeoKoordinate.o \
     SuchenKlasse.o UserInterface.o

all: $(LIB)

$(LIB): $(OBJ)
	ar ru $(LIB) $(OBJ)

clean:
	-rm $(OBJ) $(LIB)


