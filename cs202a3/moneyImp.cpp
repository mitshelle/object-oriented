/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 3
	*Description: program to practice multiple class, inheritance, comp
	*Input: none
	*Output: student details(student, undergrad, grad), errors
*/
#include <iostream>
#include "money.h"


using namespace std;

//********************************************************
 /*
* function_identifier: constructor for money 
* parameters: double charge & financial aid  
* return value: nothing 
*/ 
money::money(double chrg, double fincAid){

  // error check for charges 
  if(chrg >= 0 && chrg <= MAX_CHARGES){
    charges = chrg;
  }else{
    cout << "Error, invalid charges amount." << endl;
    charges = 0.0;
  }

  // error check for financial aid
  if(fincAid >= 0 && fincAid <= chrg){
    financialAid = fincAid;
  }else{
    cout << "Error, invalid financial aid amount." << endl;
    financialAid = 0.0;
  }

  // find balance from charges & aid
  balance = charges - financialAid;
}

//********************************************************


// return values
void money::getCharges(double& chrg, double& fAid) const{
  chrg = charges;
  fAid = financialAid;
}


double money::getBalance() const{
  return balance;
}

//********************************************************

// set values 
void money::setCharges(double charge, double aid){
  // error check for charges 
  if(charge >= 0 && charge <= MAX_CHARGES){
    charges = charge;
  }else{
    cout << "Error, invalid charges amount." << endl;
    charges = 0.0;
  }

  // error check for financial aid
  if((aid >= 0 && aid <= charge) || (aid >= charge && aid <= 0)){
    financialAid = aid;
  }else{
    cout << "Error, invalid financial aid amount." << endl;
    financialAid = 0.0;
  }
  // find balance from charges & aid
  balance = charges - financialAid;
}