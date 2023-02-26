// CS 202 Provided Main

//	This can be used in two ways
//		- create magic square based on command line options
//		- perform tests for the magic square object 

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "magicSquareType.h"

using namespace std;


void makeMagic(magicSquareType &, bool);

// **********************************************************************

int main(int argc, char *argv[])
{
// ----------------------------------------------------------------------
//  Declarations...

	int				order;
	string			stars(60, '*');
	stringstream	mySS;

// ----------------------------------------------------------------------
//  Check for user provided command line args

	if (argc > 1) {
		if (argc != 3) {
			cout << "Error, invalid command line arguments." << endl;
			return 0;
		}

		if (string(argv[1]) != "-o") {
			cout << "Error, must specify '-o' magic square order specifier." << endl;
			return 0;
		}

		mySS << argv[2];		// string to inetger conversion
		mySS >> order;			// check for error on conversion

		if (mySS.fail()) {
			cout << "Error, invalid order." << endl;
			return	EXIT_SUCCESS;
		}

		// declare a magic square object
		//		note, check for valid board size
		magicSquareType		mSqr1(order, "Test");

		makeMagic(mSqr1, true);

		return	EXIT_SUCCESS;
	}

// ----------------------------------------------------------------------
//  Declare some magic squares
//		use support routine to create magic square and display

	magicSquareType mSqr3(3, "Test, Order 3");
	magicSquareType mSqr4(4, "Test, Order 4");
	magicSquareType mSqr5(5, "Test, Order 5");
	magicSquareType mSqr6(6, "Test, Order 6");
	magicSquareType mSqr8(8, "Test, Order 8");
	magicSquareType mSqr9(9, "Test, Order 9");
	magicSquareType mSqr10(10, "Test, Order 10");
	magicSquareType mSqr12(12, "Test, Order 12");
	magicSquareType mSqr13(13, "Test, Order 13");
	magicSquareType mSqr14(14, "Test, Order 14");

	makeMagic(mSqr3, true);
	makeMagic(mSqr4, true);
	makeMagic(mSqr5, true);
	makeMagic(mSqr6, true);
	makeMagic(mSqr8, true);
	makeMagic(mSqr9, true);
	makeMagic(mSqr10, true);
	makeMagic(mSqr12, true);
	makeMagic(mSqr13, true);
	makeMagic(mSqr14, true);

// ----------------------------------------------------------------------
//  Read a two 3x3 magic squares form user

	cout << stars << endl;
	cout << "Read Testing, 3x3..." << endl << endl;

	magicSquareType mSqr33(3, "Read Test #1");

	mSqr33.readMagicSquare();
	makeMagic(mSqr33, false);

	cout << endl << stars << endl;

	mSqr33.clearMagicSquare();
	mSqr33.readMagicSquare();
	makeMagic(mSqr33, false);

	cout << endl << endl;

// ----------------------------------------------------------------------
//  Read an 11x11 magic square from user

	cout << stars << endl;
	cout << "Read Testing, 11x11..." << endl << endl;

	magicSquareType mSqr11(11, "Read Test #2");

	mSqr11.readMagicSquare();
	makeMagic(mSqr11, false);

	cout << endl << stars << endl;

	mSqr11.clearMagicSquare();
	mSqr11.setTitle("Read Test #3");
	mSqr11.readMagicSquare();
	makeMagic(mSqr11, false);

	cout << endl << endl;

// ----------------------------------------------------------------------
//  Read an 6x6 magic square from user

	cout << stars << endl;
	cout << "Read Testing, 6x6..." << endl << endl;

	magicSquareType mSqr66(6, "Read Test #4");

	mSqr66.readMagicSquare();
	makeMagic(mSqr66, false);

	cout << endl << endl;

// ----------------------------------------------------------------------
//  Read an 8x8 magic square from user.

	cout << stars << endl;
	cout << "Read Testing, 8x8..." << endl << endl;

	magicSquareType mSqr88(8, "Read Test #5");

	mSqr88.readMagicSquare();
	makeMagic(mSqr88, false);

	cout << endl << stars << endl;

	mSqr88.clearMagicSquare();
	mSqr88.setTitle("Read Test #6");
	mSqr88.readMagicSquare();
	makeMagic(mSqr88, false);

	cout << endl << endl;

// ----------------------------------------------------------------------
//  All done, end program...

	return	EXIT_SUCCESS;
}

// ***********************************************************************
//  Support routine for creating, printing, and validating
//		a magic square and also prints a cute message

void makeMagic(magicSquareType &mSqr, bool makeIt)
{
	const char* green = "\033[0;32m";
	const char* white = "\033[0;37m";
	const char* red   = "\033[0;31m";
	const char* bold   = "\033[1m";
	const char* unbold   = "\033[0m";

	string stars;
	stars.append(60,'*');

	cout << endl << stars << endl << endl;

	if (makeIt)
		mSqr.createMagicSquare();

	mSqr.printMagicSquare();

	if ( mSqr.validateMagicSquare() )
		cout << bold << green << "Valid Magic Square."
			<< white << unbold << endl;
	else
		cout << bold << red << "Not a Magic Square Solution." <<
			white << unbold << endl;
	cout << endl;

}