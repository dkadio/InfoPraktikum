
.SUFFIXES: .cpp .o

CPP=g++48
WARN=-Wall -pedantic

LIB=libgeopunkte.a

.cpp.o:
	$(CPP) $(WARN) -I. -std=c++11 -c $<

OBJ= Gebietslokation.o Linearlokation.o LokationsVerwaltung.o Punktlokation.o

all: $(LIB)

$(LIB): $(OBJ)
	ar ru $(LIB) $(OBJ)

clean:
	-rm $(OBJ) $(LIB)


