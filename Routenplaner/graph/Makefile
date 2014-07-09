
.SUFFIXES: .cpp .o

include ../config

LIB=libgraph.a

.cpp.o:
	$(CPP) $(WARN) -I. -std=c++11 -c $<

OBJ= Dijkstra.o Graph.o Graph_OLD.o Knoten.o PriorityQueue.o

all: $(LIB)

$(LIB): $(OBJ)
	ar ru $(LIB) $(OBJ)

clean:
	-rm $(OBJ) $(LIB)


