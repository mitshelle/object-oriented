# Make file for student, money, undergrad, and grad classes.

CC	= g++ 
CCFLAGS = -Wall -Wextra -pedantic -std=c++11 -g

GOBJS	= gradMain.o underGradImp.o gradImp.o studentImp.o moneyImp.o
GDEPS	= grad.h underGrad.h student.h

UOBJS	= underMain.o underGradImp.o studentImp.o moneyImp.o
UDEPS	= underGrad.h student.h

SOBJS	= stdMain.o studentImp.o moneyImp.o
SDEPS	= student.h money.h

all: gradMain

gradMain: $(GOBJS)
	$(CC) $(CCFLAGS) -o gradMain $(GOBJS)
gradMain.o:	gradMain.cpp $(GDEPS)
	$(CC) $(CCFLAGS) -c gradMain.cpp

gradImp.o:	gradImp.cpp $(SDEPS)
	$(CC) $(CCFLAGS) -c gradImp.cpp


underMain: $(UOBJS)
	$(CC) $(CCFLAGS) -o underMain $(UOBJS)

underMain.o:	underMain.cpp $(UDEPS)
	$(CC) $(CCFLAGS) -c underMain.cpp

underGradImp.o:	underGradImp.cpp $(SDEPS)
	$(CC) $(CCFLAGS) -c underGradImp.cpp


stdMain: $(SOBJS)
	$(CC) $(CCFLAGS) -o stdMain $(SOBJS)

stdMain.o:	stdMain.cpp $(SDEPS)
	$(CC) $(CCFLAGS) -c stdMain.cpp

studentImp.o:	studentImp.cpp $(SDEPS)
	$(CC) $(CCFLAGS) -c studentImp.cpp

moneyImp.o:	moneyImp.cpp money.h
	$(CC) $(CCFLAGS) -c moneyImp.cpp

# -----
# clean by removing object files.

clean:
	rm $(GOBJS)
