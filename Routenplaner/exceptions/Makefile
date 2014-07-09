
.SUFFIXES: .cpp .o

CPP=g++48
WARN=-Wall -pedantic

LIB=libexceptions.a

.cpp.o:
	$(CPP) $(WARN) -I. -std=c++11 -c $<

OBJ= FileNotFoundException.o TypProblemEcxeption.o ZeitException.o

all: $(LIB)

$(LIB): $(OBJ)
	ar ru $(LIB) $(OBJ)

clean:
	-rm $(OBJ) $(LIB)


