/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 4
	*Description: program to practice pointers, arrays, classes
	*Input: numbers for magic square 
	*Output: magic square according to algorithm 
*/
#include <string>
#include <iostream>
#include "boardType.h"
#ifndef magicSquare_classname
#define magicSquare_classname

/*
	* class_identifier: create magic square according to algorithm 
	* constructors: magicSquareType(int, std::string);
	* public functions: 
	*	void createMagicSquare();
    void printMagicSquare() const;
    void readMagicSquare();
    bool validateMagicSquare() const;
    void clearMagicSquare();
    int magicNumber() const;
    std::string getTitle() const;
    void setTitle(std::string);
	* static members: none 
*/
class magicSquareType: public boardType{
  public:
    // constructor
    magicSquareType(int, std::string);

    // func prototypes 
    void createMagicSquare();
    void printMagicSquare() const;
    void readMagicSquare();
    bool validateMagicSquare() const;
    void clearMagicSquare();
    int magicNumber() const;
    std::string getTitle() const;
    void setTitle(std::string);

    private:
      std::string title;
};

#endif