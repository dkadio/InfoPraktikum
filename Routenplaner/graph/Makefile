
.SUFFIXES: .cpp .o

CPP=g++48
WARN=-Wall -pedantic

LIB=libgraph.a

.cpp.o:
	$(CPP) $(WARN) -I. -std=c++11 -c $<

OBJ= Dijkstra.o Graph.o Graph_OLD.o Knoten.o PriorityQueue.o

all: $(LIB)

$(LIB): $(OBJ)
	ar ru $(LIB) $(OBJ)

clean:
	-rm $(OBJ) $(LIB)


