/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 3
	*Description: program to practice multiple class, inheritance, comp
	*Input: none
	*Output: student details(student, undergrad, grad), errors
*/
#include <iostream>
#include "underGrad.h"
#include <iomanip> 
#include <string>
#include <cstring>


using namespace std;

/*
* function_identifier: constructor for undergrad
* parameters: student parameters + string & enum 
* return value: nothing 
*/ 
underGrad::underGrad(string lName, string fName, string iD, string majorCo, 
                    double GPA, double chrg, double fAid, 
                    string advise, sStat stat)
                    :student(lName, fName, iD, majorCo, GPA, chrg, fAid){
  // set 
  advisor = advise;
  sStatus = stat;
}


//********************************************************
 /*
* function_identifier: return values 
* parameters: nothing 
* return value: nothing 
*/ 
string underGrad::getAdvisor() const{
  return advisor;
}

sStat underGrad::getStatus() const{
  return sStatus;
}

//********************************************************

/*
* function_identifier: set values 
* parameters: passed string or passsed enum 
* return value: nothing 
*/ 
void underGrad::setAdvisor(string ad){
  advisor = ad;
}

void underGrad::setStatus(sStat stat){
  sStatus = stat;
}


 /*
* function_identifier: output student details + undergrad deets
* parameters: nothing 
* return value: nothing 
*/ 
void underGrad::showStudent(){
  // call to student class func
  student::showStudent();
  // declared vars 
  string stat;
  double badGPA = 1.7;
  double gpa = student::getGPA();

  string indent(5, ' ');
  cout << indent << "Advisor: " << left << setw(17) << advisor; 
  cout << indent << " Status: ";

  // check status from enum 
  if(sStatus == PROBATION){
    stat = "PROBATION";
  }
  if(sStatus == GOOD){
    stat = "GOOD";
  }
  // if gpa is below & status is none 
  if(gpa <= badGPA && sStatus == NONE){
    sStatus = PROBATION;
    stat = "PROBATION";
  }
  // no status default is good 
  if(sStatus == NONE){
    stat = "GOOD";
  }
  
  cout << stat << endl;
}




