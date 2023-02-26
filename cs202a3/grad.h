/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 3
	*Description: program to practice multiple class, inheritance, comp
	*Input: none
	*Output: student details(student, undergrad, grad), errors
*/
#include <string>
#include <iostream>
#include "underGrad.h"
#ifndef grad_classname
#define grad_classname

/*
	* class_identifier: details for graduate student  
	* constructors: grad() derived from undergrad
	* public functions: 
	*	bool getGAstatus() const;
    double getGradFees() const;
    void setGAstatus(bool isAssist);
    void setGradFees(double fees);
    void showStudent();
	* static members: 
	  static constexpr double MAX_FEES = 5000.0;
*/

class grad: public underGrad{
  public:
    // constructor
    grad(std::string = "", std::string = "", std::string = "", 
        std::string = "", double = 0.0,double = 0.0, double = 0.0, 
        std::string = "", sStat = NONE, 
        bool = false, double = 0.0);
    
    // function prototypes
    bool getGAstatus() const;
    double getGradFees() const;
    void setGAstatus(bool isAssist);
    void setGradFees(double fees);
    void showStudent();

  private: 
    bool isGA;
    double gradFees;
    static constexpr double MAX_FEES = 5000.0;
};

#endif