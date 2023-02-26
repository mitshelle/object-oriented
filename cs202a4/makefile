# Make file for create magic squares project

CC	= g++
CCFLAGS = -Wall -Wextra -pedantic -std=c++11 -g

OBJS	= magicSqr.o boardTypeImp.o magicSquareImp.o
OBJS1	= brdMain.o boardTypeImp.o
DEPS	= boardType.h magicSquareType.h
DEPS1	= boardType.h

all: magicSqr

magicSqr: $(OBJS)
	$(CC) $(CCFLAGS) -o magicSqr $(OBJS)

magic.o:	magicSqr.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c magicSqr.cpp


brdMain: $(OBJS1)
	$(CC) $(CCFLAGS) -o brdMain $(OBJS1)

brdMain.o:	brdMain.cpp $(DEPS1)
	$(CC) $(CCFLAGS) -c brdMain.cpp

boardTypeImp.o:	boardTypeImp.cpp $(DEPS1)
	$(CC) $(CCFLAGS) -c boardTypeImp.cpp

magicSquareImp.o: magicSquareImp.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c magicSquareImp.cpp

# -----
# clean by removing object files.

clean:
	rm $(OBJS)
	rm $(OBJS1)
