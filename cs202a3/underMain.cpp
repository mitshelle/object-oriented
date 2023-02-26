//  CS 202
//  Assignment #3 - Provided Main
//  Uses and tests various functions from the underGrad class

#include <iostream>
#include <string>

#include "student.h"
#include "underGrad.h"

using namespace std;

int main()
{
// ----------------------------------------------------------------------
//  Display a simple header...

	string	bars;
	bars.append(70,'-');
	string	stars;
	stars.append(70,'*');
	double	chg, aid, due;

	cout << endl << bars << endl;
	cout << "CS 202 - Assignment #6" << endl;
	cout << "underGrad Class -> Test Program." << endl << endl;

// ----------------------------------------------------------------------
//  Declare some students.

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

	underGrad bouvier1;
  
	underGrad burns("Burns", "Charles", "L000017254", "UND", 1.0, 10000.0,
								10000.0, "Smatresk", PROBATION);
	underGrad chalmers("Chalmers", "Gary", "L000001254", "HOA", 2.1,
								1000.0, 500.0, "Vasko", GOOD);
	underGrad quimby("Quimby", "Joe", "L000127318", "POS", 1.77, 7120.5,
								800.0, "Gewali", NONE);
	underGrad hibbert("Hibbert", "Julius", "L000087346", "PBH", 3.7,
								1112.5, 1000.0, "Vasko", GOOD);
	underGrad meyers("Meyers", "Roger", "L000134341", "", 3.41, 1300.75,
								350.0, "Bien", NONE);
	underGrad monroe;
	underGrad wiggum("Wiggum", "Clancy");
	underGrad ziff("Ziff", "Artie", "L001201101", "CS", 4.0, 9500.5, 2000.0);

// ----------------------------------------------------------------------
//  Enter test data for temp students

	monroe.setName("Monroe", "Marvin");
	monroe.setID("L000120001");
	monroe.setMajor("ART");
	monroe.setGPA(1.0);
	monroe.setCharges(3700.75, 1000.0);
	monroe.setAdvisor("Vasko");
	monroe.setStatus(PROBATION);

	wiggum.setID("L000000007");
	wiggum.setMajor("CRJ");
	wiggum.setGPA(0.23);
	wiggum.setCharges(2300.5, 0.0);
	wiggum.setAdvisor("Vasko");
	wiggum.setStatus(PROBATION);

	ziff.setAdvisor("Yfantis");
	ziff.setStatus(NONE);

// ----------------------------------------------------------------------
//  Change name (due to marriage).
//  Accepted -> student becomes underGrad

	bouvier.setName("McClure", bouvier.getFirstName() );

	bouvier1.setName(bouvier.getLastName(), bouvier.getFirstName());
	bouvier1.setID(bouvier.getID());
  //right here is the error
  
	bouvier1.setMajor(bouvier.getMajor());
	bouvier1.setGPA(bouvier.getGPA());
	bouvier.getCharges(chg, aid);
	bouvier1.setCharges(chg, aid);
	bouvier1.setAdvisor("Vasko");
	bouvier1.setStatus(GOOD);

// ----------------------------------------------------------------------
//  make some changes...

	simpson.getCharges(chg, aid);						// good
	due = chg - aid;
	if (due != simpson.getBalance())
		cout << "Error, your computer will self-destruct...";

	simpson.setCharges(0.0, 0.0);

	if (groundskeeper.getGPA() < 2.5)
		groundskeeper.setGPA(2.5);

// ----------------------------------------------------------------------
//  Some error testing -> most of these should be errors...

	// misc errors
	student prince("Prince", "Martin");						// valid

	prince.setID("L0001234A");								// err
	prince.setID("L00001245A");								// err
	prince.setID("L001230042");								// valid
	prince.setMajor("Business");							// err
	prince.setMajor("UNK");									// err
	prince.setMajor("BUS");									// valid
	prince.setGPA(-1.65);									// err
	prince.setGPA(7.00);									// err
	prince.setGPA(4.00);									// valid
	prince.setCharges(11000.0, 1001.00);					// err
	prince.setCharges(1000.0, -100.00);						// err
	prince.setCharges(9000.0, 5000.00);						// good

	// misc errors
	underGrad powers;										// valid
	powers.setName("Powers", "Ruth");						// valid
	powers.setID("L0007234A");								// err
	powers.setID("L00007245A");								// err
	powers.setID("L007030042");								// valid
	powers.setMajor("EDUCA");								// err
	powers.setMajor("EDUD");								// err
	powers.setMajor("EDU");									// valid
	powers.setGPA(-2.65);									// err
	powers.setGPA(4.01);									// err
	powers.setGPA(2.95);									// valid
	powers.setCharges(10000.01, 1000.00);					// err
	powers.setCharges(1000.0, 1100.00);						// err
	powers.setCharges(2000.0, 2000.00);						// good
	powers.setAdvisor("Pederson");							// good
	powers.setStatus(GOOD);									// good

// ----------------------------------------------------------------------
//  Show summaries for students

	cout << endl << stars << endl;
	cout << "Student Summary" << endl;

	simpson.showStudent();
	leonard.showStudent();
	carlson.showStudent();
	bouvier.showStudent();
	krabappel.showStudent();
	neahasapeemapetilon.showStudent();
	groundskeeper.showStudent();
	riviera.showStudent();
	prince.showStudent();

	// ----------
	cout << endl << stars << endl;
	cout << "Undergraduate Summary" << endl;

	burns.showStudent();
	chalmers.showStudent();
	quimby.showStudent();
	hibbert.showStudent();
	meyers.showStudent();
	monroe.showStudent();
	wiggum.showStudent();
	ziff.showStudent();
	bouvier1.showStudent();
	powers.showStudent();

	cout << endl << stars << endl;

	return EXIT_SUCCESS;
}

// ----------------------------------------------------------------------
