// CS 202
// Assignment #3 - Provided Main
// Uses and tests various functions from the student class

#include <iostream>
#include <string>

#include "student.h"

using namespace std;

int main()
{
// ----------------------------------------------------------------------
//  Display a simple header...

	string	bars;
	bars.append(70,'-');

	cout << endl << bars << endl;
	cout << "CS 202 - Assignment #6" << endl;
	cout << "Student Class -> Test Program." << endl << endl;

// ----------------------------------------------------------------------
//  Create some student objects.

	student simpson("Simpson", "Homer", "L000001254", "NUE", 1.0, 1000.00);
	student leonard("Leonard", "Lenny", "L000018716", "NUE", 3.2, 975.25);
	student carlson("Carlson", "Carl", "L000022716", "NUE", 2.75, 2221.50);
	student bouvier("Bouvier", "Selma", "L000011116", "UNS", 2.25, 1400.75);
	student krabappel("Krabappel", "Edna", "L000021231", "WOM", 2.15,
								1500.0, 1000.00);
	student neahasapeemapetilon("Nahasapeemapetilon", "Apu", "L000012123",
								"FOL", 3.45, 1600.0);
	student groundskeeper("Groundskeeper", "Willie", "L000087290", "PHY",
								1.77, 2900.0, 1000.00);
	student riviera("Riviera", "Nick", "L000000666", "NUC", 1.0, 9200.25,
								1500.00);
	student tempStudent1;
	student tempStudent2("Terwilliger", "Cecil", "L000012001"); 
	student tempStudent3("Spuckler", "Cletus", "L000000000", "", 2.21,
								27.75, 0.05);
	student dropOut("Gumble", "Barney");

// ----------------------------------------------------------------------
//  Enter data for temp students

	tempStudent1.setName("Hutz", "Lionel");
	tempStudent1.setID("L000012345");
  
	tempStudent1.setMajor("RE");
  
	tempStudent1.setGPA(2.99);
  
	tempStudent1.setCharges(4523.25, 1000.00);
  

	tempStudent2.setID("L000010045");
  
	tempStudent2.setMajor("PSY");
  
	tempStudent2.setGPA(3.99);
  
	tempStudent2.setCharges(9523.25, 9000.00);
  

	dropOut.setID("L000010005");
	dropOut.setMajor("RE");
	dropOut.setGPA(0.75);
	dropOut.setCharges(1503.55, 1000.00);

// ----------------------------------------------------------------------
//  make some changes...

	double	chg, aid, due;

	bouvier.setName("McClure", bouvier.getFirstName() );

	simpson.getCharges(chg, aid);							// good
	due = chg - aid;
	if (due != simpson.getBalance())
		cout << "Error, your computer will self-destruct...";

	simpson.setCharges(0.0, 0.0);

	if (groundskeeper.getGPA() < 2.5)
		groundskeeper.setGPA(2.5);

	if (tempStudent2.getMajor() == "Error")
		tempStudent2.setMajor("UND");

// ----------------------------------------------------------------------
//  Some error testing -> all of these should be errors...

	// id errors
	student frink("Frink", "John", "L000001001", "PHY", 3.75, 2000.0, 500.0);		// valid
	frink.setID("L00012345");									// err
	frink.setID("L000012A45");									// err
	frink.setID("L000000042");									// valid

	// id errors
	student flandersR("Flanders", "Rod", "0000001254", "DAN",
								2.25, 2300.50, 1000.0);			// err
	flandersR.setID("L0002200022");								// err
	flandersR.setID("L002200022");								// valid

	student flandersT("Flanders", "Todd", "l000001254", "MUS", 3.15,
							2500.0, 1000.0);					// err
	flandersT.setID("M000110102");								// err
	flandersT.setID("L000110102");								// valid

	// gpa errors
	student hoover("Hoover", "Elizabeth", "L0000010000");		// err
	hoover.setMajor("EDU");										// valid
	hoover.setCharges(1000.0, 1000.0);							// valid
	hoover.setGPA(-2.65);										// err
	hoover.setGPA(7.65);										// err
	hoover.setGPA(4.01);										// err
	hoover.setGPA(2.01);										// valid

	// major errors
	student flandersM("Flanders", "Maude", "L000001254",
							"ERR", 4.0, 930.50, 500.50);		// err
	flandersM.setMajor("None");									// err
	flandersM.setMajor("MIL");									// valid

	// charges errors
	student flandersN("Flanders", "Ned", "L000001000", "REG", 3.0,
							99000.00, 100.00);					// err
	flandersN.setCharges(-5001.0, 0.0);							// err
	flandersN.setCharges(1000.0, 1001.00);						// err
	flandersN.setCharges(1000.0, -100.00);						// err
	flandersN.setCharges(1000.0, 100.00);						// good

// ----------------------------------------------------------------------
//  Show summaries for sudents

	simpson.showStudent();
	leonard.showStudent();
	carlson.showStudent();
	bouvier.showStudent();
	krabappel.showStudent();
	neahasapeemapetilon.showStudent();
	groundskeeper.showStudent();
	riviera.showStudent();

	tempStudent1.showStudent();
	tempStudent2.showStudent();
	tempStudent3.showStudent();
	dropOut.showStudent();

	frink.showStudent();
	flandersN.showStudent();
	flandersM.showStudent();
	flandersR.showStudent();
	flandersT.showStudent();
	hoover.showStudent();

	cout << endl;

	return	EXIT_SUCCESS;
}

// ----------------------------------------------------------------------
