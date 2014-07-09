
CPP=g++48
WARN=-pedantic -Wall

all: Routenplaner

LIBS= reader/FileOpener.o geopunkte/libgeopunkte.a hilfsklassen/libhilf.a  \
	graph/libgraph.a exceptions/libexceptions.a  


Routenplaner.o: 
	$(CPP) $(WARN) -I. -std=c++11 -c Routenplaner.cpp

Routenplaner: subdirs Routenplaner.o
	$(CPP) -o Routenplaner Routenplaner.o $(LIBS)


subdirs: 
	make -C graph
	make -C reader
	make -C exceptions
	make -C geopunkte
	make -C hilfsklassen
clean:
	-rm Routenplaner Routenplaner.o 
	make -C graph clean
	make -C reader clean
	make -C exceptions clean
	make -C geopunkte clean
	make -C hilfsklassen clean
	
