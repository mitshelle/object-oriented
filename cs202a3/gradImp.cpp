/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 3
	*Description: program to practice multiple class, inheritance, comp
	*Input: none
	*Output: student details(student, undergrad, grad), errors
*/
#include "grad.h"
#include <string>
#include <iomanip>

using namespace std;

/*
* function_identifier: constructor for grad
* parameters: student parameters + undergrad parm + string advise bool ga
* return value: nothing 
*/ 
grad::grad(string lName, string fName, string iD, string majorCd, 
          double gradeP, double charge, double fnAid, 
          string advise, sStat stat, bool isAssist, double fee)
          :underGrad(lName, fName, iD, majorCd, 
          gradeP, charge, fnAid, advise, stat){

  // set 
  isGA = isAssist;

  // error check for grad fees 
  if(fee >= 0 && fee <= MAX_FEES){
    gradFees = fee;
  }else{
    cout << "Error, invalid graduate fees." << endl;
    gradFees = 0;
  }
  
}


//********************************************************
 /*
* function_identifier: return values 
* parameters: nothing 
* return value: nothing 
*/ 
bool grad::getGAstatus() const{
  return isGA;
}

double grad::getGradFees() const{
  return gradFees;
}

//********************************************************

/*
* function_identifier: set values 
* parameters: passed bool or passsed double  
* return value: nothing 
*/ 
void grad::setGAstatus(bool isAssist){
  // set to passed book
  isGA = isAssist;
}

void grad::setGradFees(double fees){
  // error check bwtn 0 & 5000
  if(fees >= 0 && fees <= MAX_FEES){
    gradFees = fees;
  }else{
    cout << "Error, invalid graduate fees.";
    gradFees = 0;
  }
}

 /*
* function_identifier: output student details + undergrad deets + grad deets 
* parameters: nothing 
* return value: nothing 
*/ 
void grad::showStudent(){
  underGrad::showStudent();
  string indent(5, ' ');
  cout << "   Grad Fees: " << fixed << setprecision(2) << gradFees << indent;
  cout << indent << indent << "    Graduate Assistant: ";
  
  // error check 
  if(isGA){ // call to func to see if ga 
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
 
}
