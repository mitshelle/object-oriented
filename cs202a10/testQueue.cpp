//  Main program for testing
//	Test the queue implementation

#include <iostream>
#include <fstream>
#include <string>
#include "linkedQueue.h"

using namespace std;

int main()
{
// *****************************************************************
//  Headers...

	string	bars, stars;
	bars.append(65, '-');
	stars.append(65, '*');

	cout << bars << endl << "CS 202 - Assignment #10" << endl;
	cout << "Basic Testing for Linked Queue" << endl;

// *****************************************************************
//  Test basic queue operations.
//	Create some integer queues, add items, delete items,
//	display queues, etc...

	cout << endl << stars << endl << "Test Queue Operations " <<
			"- Integers:" << endl << endl;

	linkedQueue<int> queue0, queue1;
	linkedQueue<int> queue2;
	int	j;
  
	for (int i=1; i<=20; i++)
		queue0.addItem(i);

	cout << "Queue 0 (original): ";
	queue0.printQueue();
	cout << endl;
	cout << "Queue 0 (count): " << queue0.queueCount();
	cout << endl << endl;
  
	for (int i=1; i<=20; i+=2) {
		j = queue0.front();
		queue0.deleteItem();
		queue1.addItem(j);
		j = queue0.front();
		queue0.deleteItem();
		queue2.addItem(j);
	}

	cout << "Queue 1 (odds):     ";
	queue1.printQueue(); 
	cout << endl;
	cout << "Queue 1 (count): " << queue1.queueCount();
	cout << endl << endl;

	cout << "Queue 2 (evens):    ";
	queue2.printQueue(); 
	cout << endl;
	cout << "Queue 2 (count): " << queue2.queueCount();
	cout << endl << endl;

// --------------------------------------
//	Testing with shorts.

	cout << endl << stars << endl << "Test Queue Operations " <<
			"- Shorts:" << endl << endl;

	linkedQueue<short> squeue0(5), squeue1(5);
	linkedQueue<short> squeue2(5);
	int	slen = 50;

	for (short i=1; i<=slen; i++)
		squeue0.addItem(i);

	cout << "Shorts Queue 0 (original): " << endl;
	squeue0.printQueue();
	cout << endl;
	cout << "Shorts Queue 0 (count): " << squeue0.queueCount();
	cout << endl << endl;


	for (short i=1; i<=slen; i+=2) {
		j = squeue0.front();
		squeue0.deleteItem();
		squeue1.addItem(j);
		j = squeue0.front();
		squeue0.deleteItem();
		squeue2.addItem(j);
	}

	cout << "Shorts Queue 1 (odds):     " << endl;
	squeue1.printQueue(); 
	cout << endl;
	cout << "Shorts Queue 1 (count): " << squeue1.queueCount();
	cout << endl << endl;

	cout << "Shorts Queue 2 (evens):    " << endl;
	squeue2.printQueue(); 
	cout << endl;
	cout << "Shorts Queue 2 (count): " << squeue2.queueCount();
	cout << endl << endl;

	if (squeue1.queueCount() + squeue2.queueCount() !=
		static_cast<unsigned int>(slen))
			cout << "ERROR - Invalid queue sizes." << endl;

// --------------------------------------
//  Floating point tests
//	Create some queues for floating point items.

	cout << bars << endl << "Test Queue Operations " <<
			"- Floats:" << endl << endl;

	{
		linkedQueue<double> queue3(5);

		for (int i=1; i<=7; i++)
			queue3.addItem(static_cast<double>(i)+0.5);

		cout << "Queue 3 (floats, original): ";
		queue3.printQueue();
		cout << endl;

		cout << "Queue 3 (floats, modified): ";
		queue3.printQueue();
		cout << endl << endl;

		cout << "Queue 3 (count): " << queue3.queueCount();
		cout << endl;
		cout << "Queue 3 (first item): " << queue3.front();
		cout << endl;
		cout << "Queue 3 (last item): " << queue3.back();
		cout << endl << endl;
	}

// --------------------------------------
//  Many entries testing

	cout << bars << endl << "Test Queue Operations " <<
			"- Many Items:" << endl << endl;
	bool	worked = true;

	linkedQueue<unsigned int> queue4;
	unsigned int	testSize=400000;

	for (unsigned int i=1; i<=testSize; i++)
		queue4.addItem(i);

	if (queue4.queueCount() != testSize)
		cout << "main: error, incorrect queue size." << endl;

	for (unsigned int i=1; i<=testSize; i++) {
		if (queue4.front() != i)
			worked = false;
		queue4.deleteItem();
	}
	if (queue4.queueCount() != 0)
		worked = false;

	if (worked)
		cout << "Many items, test passed." << endl;
	else
		cout << "Many items, test failed." << endl;

	cout << endl;

// *****************************************************************
//  All done.

	cout << bars << endl << "Game Over, thank you for playing." << endl;

	return	EXIT_SUCCESS;
}
