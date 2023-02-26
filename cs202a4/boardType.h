/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 4
	*Description: program to practice pointers, arrays, classes
	*Input: numbers for magic square 
	*Output: magic square according to algorithm 
*/
#include <iostream>
#ifndef boardT_classname
#define boardT_classname

/*
	* class_identifier: create board for any board type 
	* constructors: boardType(int);
	* public functions: 
	* void setCell(int, int, int);
    int getCell(int, int) const;
    int getOrder() const;
    void printGrid() const; 
	* static members: 
    static constexpr int BRD_SIZE_MIN=3;
    static constexpr int BRD_SIZE_MAX=30;

*/
class boardType{
  public:
    // constructors 
    boardType(int);
    ~boardType();

    // func prototypes 
    void setCell(int, int, int);
    int getCell(int, int) const;
    int getOrder() const;
    void printGrid() const; 

    
  protected: // access by derived class 
    // vars 
    int size;
    int **board;
  
  private: 
    // constants 
    static constexpr int BRD_SIZE_MIN=3;
    static constexpr int BRD_SIZE_MAX=30;

};

#endif