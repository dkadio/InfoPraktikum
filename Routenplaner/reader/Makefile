
.SUFFIXES: .cpp .o

CPP=g++48
WARN=-Wall -pedantic

.cpp.o:
	$(CPP) $(WARN) -I. -std=c++11 -c $<

OBJ= FileOpener.o

all: $(OBJ)

clean:
	-rm $(OBJ)


