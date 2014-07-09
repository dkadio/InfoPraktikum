
.SUFFIXES: .cpp .o
include ../config


.cpp.o:
	$(CPP) $(WARN) -I. -std=c++11 -c $<

OBJ= FileOpener.o

all: $(OBJ)

clean:
	-rm $(OBJ)


