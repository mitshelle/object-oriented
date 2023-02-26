/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 3
	*Description: program to practice multiple class, inheritance, comp
	*Input: none
	*Output: student details(student, undergrad, grad), errors
*/
#include <iostream>
#ifndef money_classname
#define money_classname

/*
	* class_identifier: money details for student
	* constructors: money(double charge = 0.0, double aid = 0.0);
	* public functions: 
	*	void getCharges(double& charges, double& financialAid) const;
    double getBalance() const;
    void setCharges(double charge, double aid);
	* static members: 
	  static constexpr double MAX_CHARGES = 10000.0;
*/


class money{
  public:
    // constructor 
    money(double charge = 0.0, double aid = 0.0);

    // function prototypes
    void getCharges(double& charges, double& financialAid) const;
    double getBalance() const;
    void setCharges(double charge, double aid);

  private:
    double charges, financialAid, balance;
    static constexpr double MAX_CHARGES = 10000.0;

};

#endif