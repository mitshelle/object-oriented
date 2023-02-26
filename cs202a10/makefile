# makefile for reversing audio file with linked stack & queue
# uses templates

CC  = g++
CCFLAGS = -Wall -Wextra -pedantic -std=c++11 -g


all:  reverse

reverse:  reverse.o 
	$(CC) $(CCFLAGS) -o reverse reverse.o

reverse.o:	reverse.cpp linkedStack.h linkedQueue.h 
	$(CC) $(CCFLAGS) -c reverse.cpp

testStack.o:	testStack.cpp linkedStack.h
	$(CC) $(CCFLAGS) -c testStack.cpp

testQueue.o:	testQueue.cpp linkedQueue.h
	$(CC) $(CCFLAGS) -c testQueue.cpp

# clean by removing object files.
clean:
	rm	testStack.o
	rm	testQueue.o
