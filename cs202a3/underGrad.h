/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 3
	*Description: program to practice multiple class, inheritance, comp
	*Input: none
	*Output: student details(student, undergrad, grad), errors
*/
#include <string>
#include <iostream>
#include "student.h"
#ifndef Under_classname
#define Under_classname

// user created 
enum sStat{PROBATION, GOOD, SPECIAL, NONE};

/*
	* class_identifier: details for undergrad student  
	* constructors: undergrad derived from student 
	* public functions: 
	*	std::string getAdvisor() const;
    sStat getStatus() const;
    void setAdvisor(std::string);
    void setStatus(sStat);
    void showStudent();
	* static members: 
	  none 
*/

class underGrad: public student{
  public:
    // constructor
    underGrad(std::string = "", std::string = "", std::string = "", 
              std::string = "", double = 0.0, double = 0.0, double = 0.0, 
              std::string = "", sStat = NONE);

    // fucntion prototypes
    std::string getAdvisor() const;
    sStat getStatus() const;
    void setAdvisor(std::string);
    void setStatus(sStat);
    void showStudent();



  private: // only accessible to class 
    std::string advisor;
    sStat sStatus;
};

#endif