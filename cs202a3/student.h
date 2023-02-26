/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 3
	*Description: program to practice multiple class, inheritance, comp
	*Input: none
	*Output: student details(student, undergrad, grad), errors
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "money.h"
#ifndef student_classname
#define student_classname

/*
	* class_identifier: details for any student 
	* constructors: student(std::string = "", std::string = "",
                          std::string = "", std::string = "",
                          double = 0.0, double = 0.0, double = 0.0);
	* public functions: 
	*	std::string getLastName() const;
    std::string getFirstName() const;
    std::string getID() const;
    std::string getMajor() const;
    double getGPA() const;
    void setName(std::string last, std::string first);
    void setID(std::string id);
    void setMajor(std::string major);
    void setGPA(double gradePoint);
    void showStudent();
    void getCharges(double &, double &);
    double getBalance() const;
    void setCharges(double, double);
	* static members: 
	  static constexpr int MAX_MAJORS = 250;
    static constexpr double MAX_GPA = 4.0;
*/

class student{
  public: // accessible to all 
    // constructor
    student(std::string = "", std::string = "", std::string = "", 
            std::string = "",double = 0.0, double = 0.0, double = 0.0);
    ~student();

    // function prototypes 
    std::string getLastName() const;
    std::string getFirstName() const;
    std::string getID() const;
    std::string getMajor() const;
    double getGPA() const;
    void setName(std::string last, std::string first);
    void setID(std::string id);
    void setMajor(std::string major);
    void setGPA(double gradePoint);
    void showStudent();
    void getCharges(double &, double &);
    double getBalance() const;
    void setCharges(double, double);
    

  private: // accessible only to class
    std::string lastName, firstName;
    std::string studentID, major;
    double gpa, ch, finAid;
    std::ifstream majorsFile;
    int majorsCodeCount;
    static constexpr int MAX_MAJORS = 250;
    static constexpr double MAX_GPA = 4.0;
    std::string majorCodes[MAX_MAJORS];
    bool checkID(std::string) const;
    std::string expandMajorCode(std::string major);
    money finances;
  
};

#endif