include ../config
.SUFFIXES: .cpp .o


LIB=libexceptions.a

.cpp.o:
	$(CPP) $(WARN) -I. -std=c++11 -c $<

OBJ= FileNotFoundException.o TypProblemEcxeption.o ZeitException.o

all: $(LIB)

$(LIB): $(OBJ)
	ar ru $(LIB) $(OBJ)

clean:
	-rm $(OBJ) $(LIB)


