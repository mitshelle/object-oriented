/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 4
	*Description: program to practice pointers, arrays, classes
	*Input: numbers for magic square 
	*Output: magic square according to algorithm 
*/
#include <iostream>
#include "boardType.h"
#include <iomanip>

using namespace std;

 /*
* function_identifier: constructor for board class  
* parameters: size of board 
* return value: nothing 
*/ 
boardType::boardType(int boardSize){
  // error check for size 
  if(boardSize >= BRD_SIZE_MIN && 
      boardSize <= BRD_SIZE_MAX){
    // set size to passed param 
    size = boardSize;

    // allocate arr 
    board = new int *[size];
    // loop until size for cols 
    for (int i=0; i < size; i++){
        board[i] = new int[size];
    }

    // loop through to set each element to 0
    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        board[i][j] = 0;
      }
    } 

  }else{ // output error 
    cout << "Error, invalid board size." << endl;
    cout << "No board created." << endl;
    board = nullptr;
    size = 0;
  }

}

// destructor
boardType::~boardType(){

  // delete dynamically 2d arr 
    if (board != nullptr) {
      for (int i=0; i<size; i++){
            delete [] board[i];
      }
      delete [] board;
      board = nullptr;
    }
  
}

//*****************************************
 /*
* function_identifier: return values 
* parameters: nothing 
* return value: nothing 
*/ 
int boardType::getOrder() const{
  return size;
}

int boardType::getCell(int row, int col) const{
  // declared vars 
  int cellContent = 0;

  // error check, make sure arr not out of bounds 
  if(row >= size || col >= size){
    cout << "Error, invalid board location." << endl;
    return EXIT_SUCCESS;
  }
  
  // return specific cell 
  cellContent = board[row][col]; 

  return cellContent;
}

//*****************************************

 /*
* function_identifier: set specific cell 
* parameters: row, column, value  
* return value: nothing 
*/ 
void boardType::setCell(int rowCnt, int colCnt, int val){
  // error check, make sure arr not out of bounds 
  if(rowCnt >= size || colCnt >= size || rowCnt < 0 || colCnt < 0){
    cout << "Error, invalid board location." << endl;
  }else{
     // set cell to value 
    board[rowCnt][colCnt] = val;
  }
  
}

 /*
* function_identifier: print nice grid 
* parameters: nothing 
* return value: nothing 
*/ 
void boardType::printGrid() const{
  
  // box top 
  cout << "   ";
  for(int h = 0; h < size; h++){
    cout <<  " _____";
  } 

  for(int i = 0; i < size; i++){

    // top line where just space 
    cout << endl;
    cout << setw(4) << "|";
    for(int k = 0; k < size; k++){
      cout << setw(6) << "|";
    }

    // middle line w num 
    cout << endl;
    cout << setw(4) << "|";
    for(int m =0; m < size; m++){
      // middle line
      cout << setw(4) << board[i][m] << " |" ;
    }

    // bottom line w just space 
    cout << endl;
    cout << setw(4) << "|";
    for(int l = 0; l < size; l++){
      // bottom line
      cout <<  "_____";
      cout << "|";
    }
   
  }
  cout << endl;
  cout << endl;
  cout << endl;
  
}