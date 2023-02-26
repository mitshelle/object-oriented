//  Main program for testing
//	Test the stack implementation

#include <iostream>
#include <fstream>
#include <string>
#include "linkedStack.h"

using namespace std;

int main()
{
// *****************************************************************
//  Headers...

	string	bars, stars;
	bars.append(65, '-');
	stars.append(65, '*');

	cout << bars << endl << "CS 202 - Assignment #10" << endl;
	cout << "Basic Testing for Linked Stack" << endl;

// *****************************************************************
//  Basic tests for linked stack implementation.
//	Reservse number in a list by pushing each item
//	on stack and then poping.

	cout << endl << stars << endl << "Test Stack Operations "
				"- Reversing:" << endl << endl;

// ---------------------
//  Integers

	linkedStack<int> istack;
	int	inums[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	unsigned int	ilen = ( sizeof(inums) / sizeof(inums[0]) );

	istack.initializeStack();
	linkedStack<int> istackA;

	cout << "Original List:     ";
	for (unsigned int i=0; i<ilen; i++) {
		istack.push(inums[i]);
		cout << inums[i] << " ";
	}

	cout << endl << "Reverse List:      ";
	for (unsigned int i=0; i<ilen; i++) {
		cout << istack.top() << " ";
		istackA.push(istack.top());
		istack.pop();
	}

	cout << endl << "Copy A (original): ";
	for (unsigned int i=0; i<ilen; i++) {
		cout << istackA.top() << " ";
		istackA.pop();
	}

	cout << endl << endl;

// ---------------------
//  shorts

	linkedStack<short> sstack;
	const unsigned int	slen = 50;
	int	snums[slen] = {};

	for (unsigned int i=0; i<slen; i++)
		snums[i] = rand()%1000;

	sstack.initializeStack();
	linkedStack<int> sstackA;

	cout << "Original Shorts List:     ";
	for (unsigned int i=0; i<slen; i++) {
		if (i%20 == 0)
			cout << endl;
		sstack.push(snums[i]);
		cout << snums[i] << " ";
	}

	cout << endl << endl << "Reverse Shorts List:      ";
	for (unsigned int i=0; i<slen; i++) {
		if (i%20 == 0)
			cout << endl;
		cout << sstack.top() << " ";
		sstackA.push(sstack.top());
		sstack.pop();
	}

	cout << endl << endl << "Copy A (original): ";
	for (unsigned int i=0; i<slen; i++) {
		if (i%20 == 0)
			cout << endl;
		cout << sstackA.top() << " ";
		sstackA.pop();
	}

	cout << endl << endl;

// ---------------------
//  Doubles
//		Create some stacks for doubles.

	linkedStack<double> dstack;
	linkedStack<double> dstackA;

	double	dnums[] = {1.1, 3.3, 5.5, 7.7, 9.9, 11.11, 13.13,
						15.5, 17.1, 19.2, 21.3, 23.4, 25,5,
						27.6, 29.7, 31.8, 33.9, 35.1, 37.2};
	unsigned int	dlen = ( sizeof(dnums) / sizeof(dnums[0]) );

	dstack.push(1000.0);
	dstack.initializeStack();

	cout << bars << endl << "Test Stack Operations " <<
			"- Doubles:" << endl << endl;

	cout << "Original List:     ";
	for (unsigned int i=0; i<dlen; i++) {
		dstack.push(dnums[i]);
		cout << dnums[i] << " ";
	}

	cout << endl << "Reverse List:      ";
	for (unsigned int i=0; i<dlen; i++) {
		cout << dstack.top() << " ";
		dstackA.push(dstack.top());
		dstack.pop();
	}

	cout << endl << "Copy A (original): ";
	for (unsigned int i=0; i<dlen; i++) {
		cout << dstackA.top() << " ";
		dstackA.pop();
	}

	cout << endl << endl;

// --------------------------------------
//  Many entries testing

	cout << bars << endl << "Test Stack Operations " <<
			"- Many Items:" << endl << endl;
	bool	workedStk = true;

	linkedStack<int> iStackBig(5);
	unsigned int	testSize2=400000;

	for (unsigned int i=1; i<=testSize2; i++)
		iStackBig.push(i);

	if (iStackBig.stackCount() != testSize2)
		cout << "main: error, incorrect stack size." << endl;

	for (int i=testSize2; i>0 ; i--) {
		if (iStackBig.top() != i)
			workedStk = false;
		iStackBig.pop();
	}
	if (iStackBig.stackCount() != 0)
		workedStk = false;

	if (workedStk)
		cout << "Many items, test passed." << endl;
	else
		cout << "Many items, test failed." << endl;

	cout << endl;


// *****************************************************************
//  All done.

	cout << bars << endl << "Game Over, thank you for playing." << endl;

	return	EXIT_SUCCESS;
}
