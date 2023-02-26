/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 4
	*Description: program to practice pointers, arrays, classes
	*Input: numbers for magic square 
	*Output: magic square according to algorithm 
*/
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include "magicSquareType.h"
using namespace std;


 /*
* function_identifier: constructor for magic square class 
* parameters: size of board, title string 
* return value: nothing 
*/ 
magicSquareType::magicSquareType(int brdSize, string ttl = "Magic Square") :
                                boardType(brdSize){ // call to board class 
  
  // set 
  title = ttl;
}

//*********************************************
 /*
* function_identifier: return values 
* parameters: nothing 
* return value: nothing 
*/ 
int magicSquareType::magicNumber() const{
  // formula for normal magic num 
  double magicNum = size*(size*size+1)/2.0;
  return magicNum;
}


string magicSquareType::getTitle() const{
  return title;
}
//*********************************************


/*
* function_identifier: set title 
* parameters: string 
* return value: nothing 
*/ 
void magicSquareType::setTitle(string passedTitle){
  title = passedTitle;
}

/*
* function_identifier: read in title, values for square 
* parameters: nothing 
* return value: nothing 
*/ 
void magicSquareType::readMagicSquare(){

  // output 
  cout << "Enter " << size << "x" << size << " Magic Square.";
  cout << endl << endl;

  
  do{ // prompt for title until not empty

    cout << "Enter title: ";
    // get whole line 
    getline(cin, title);

  }while(title == "");
  
  // read in nums 
  cout << endl << "Enter Magic Square Values (";
  cout << size << "x" << size << ")" << endl;
  // loop until size 
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      // read in 1 by 1 
      cin >> board[i][j];
    }
  }

}

/*
* function_identifier: reset all cell s
* parameters: nothing 
* return value: nothing 
*/ 
void magicSquareType::clearMagicSquare(){
    // reset title 
    title = "";

    // just return if board is null 
    if(board == nullptr){
      return;
    }

    // set all cell entries to 0 
    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        board[i][j] = 0;
      }
    } 
}


/*
* function_identifier: print nice magic square 
* parameters: nothoing  
* return value: nothing 
*/ 
void magicSquareType::printMagicSquare() const{
  // format 
  const char* bold = "\033[1m"; 
  const char* unbold = "\033[0m";

  // output 
  cout << bold << "CS 202 - Magic Squares" << endl;
  cout << "  Title: " << title << endl;
  cout << "  Magic Square, order: " << size << endl;
  cout << "  Magic Number: " << magicNumber() << unbold << endl;

  // call to boardType func
  boardType::printGrid();
  
}

/*
* function_identifier: make magic sqr according to size & algorithm
* parameters: nothing 
* return value: nothing 
*/ 
void magicSquareType::createMagicSquare(){
  // declared vars 
  int subG = 0;
  int numOfCols = 0;
  int counter = 1;
  int temp1, temp2, temp3, temp4;
  int row = 0;
  int col = 0;
  int number = 1;

  // for odd numbers 
  if(size%2 != 0){
      row = 0;
      col = size/2;

      for(int num = 1; num <= size*size; num++){
      // set w 1 in middle
      board[row][col] = num;
      row--;
      col++;

      // if row goes out 
      if(row < 0){
        row = size - 1;
        //col++;
      }

      // if col goes out 
      if(col >= size){
        col = 0;
      }
      
      // if already filled 
      if(board[row][col] != 0 ){
        // add 2 
        row = row + 2 ;

        //if big than size go to 1st row 
        if(row >= size){
          row = 0;
        }

        // decrement col 
        col = col - 1;

        // if col smaller than go to last col 
        if(col < 0){
          col = size - 1;
        }
      }
      // top right corner & its already filled 
      if(row == 0 && col == size -1 
        && board[row][col] != 0){
        row = row + 1; 
      }
    }
  }else if (size % 4 == 0){ // for mulitple of 4, remain needs to = 0 when /4
    for(int r = 0; r < size; r++){
      for(int c =0; c < size; c++){
        // if diagnal from left 
        if(r%4 == c%4){
          board[size - 1 - r][size - 1 - c] = number;
        }

        // if not diagnal from left & i not = j
        if(r%4 != c%4 && !(r%4 + c%4 == 3)){
          board[r][c] = number;
        }

        // if sum of i & j = size - 1 
        if(r%4 + c%4 == 3){
          board[size- 1 - r][size - 1 - c] = number;
        }

      // increment 
      number++;
      }
    }
  }else if(size % 2 == 0 
          && size % 4 != 0){ // for multiple of 2 but not 4
    
    // for grids 
    subG = size/2;
    row = 0;
    col = subG/2.0;
    numOfCols = subG/2;

    //*************************************************************
    // for subgrid A 
    for(int a = 0; a <= subG*subG - 1; a++){

      // odd number algorithm 
      board[row%subG][col%subG] = counter;
      col++;
      row +=subG-1;

      // filled & upper right corner 
      if(board[row%subG][col%subG] != 0 || 
      (row%subG == subG - 1 &&  col%subG == 0)){
        col--;
        row-=2*(subG -1 );
      }
      counter++;
    }

    //*************************************************************   
    // for subgrid B 
    for(int b = 0; b <= subG*subG - 1; b++){
      // odd number algorithm 
      board[row%subG+subG][col%subG+subG] = counter;
      col++;
      row +=subG-1;

      // filled & upper right corner 
      if(board[row%subG+subG][col%subG+subG] != 0 || 
      (row%subG+subG == subG - 1 &&  col%subG+subG == 0)){
        col--;
        row-=2*(subG -1 );
      }
      counter++;
    }

    //*************************************************************
    // for subgrid C 
    for(int c = 0; c <= subG*subG - 1; c++){
      // odd number algorithm 
      board[row%subG][col%subG+subG] = counter;
      col++;
      row +=subG-1;

      // filled & upper right corner 
      if(board[row%subG][col%subG+subG] != 0 || 
      (row%subG == subG - 1 &&  col%subG+subG == 0)){
        col--;
        row-=2*(subG -1 );
      }
      counter++;
    }

    //*************************************************************
    // for subgrid D  
    for(int c = 0; c <= subG*subG - 1; c++){
      // odd number algorithm 
      board[row%subG+subG][col%subG] = counter;
      col++;
      row +=subG-1;

      // filled & upper right corner 
      if(board[row%subG+subG][col%subG] != 0 || 
      (row%subG+subG == subG - 1 &&  col%subG == 0)){
        col--;
        row-=2*(subG -1 );
      }
      counter++;
  }

    //*************************************************************

    /*
    
      swap columns

    */

    // switch 2 from a & d 
    for(int i = 0; i <= subG - 1; i++){
      for(int j = 0; j <= numOfCols - 1; j++){
        // save in temp 
        temp1 = board[i][j];
        board[i][j] = board[i+subG][j];
        board[i+subG][j] = temp1;
      }
    }

    // check if not 0 
    if(numOfCols - 1 > 0){
      // switch col from c & b
      for(int i = 0; i <= subG - 1; i++){
        for(int j = 1; j <= numOfCols - 1; j++){
          temp2 = board[i][size-j];
          board[i][size-j] = board[i+subG][size-j];
          board[i+subG][size-j] = temp2;
        }
      }
    }

    // switch mid num in col 0 
    temp3 = board[numOfCols][0];
    board[numOfCols][0] = board[numOfCols+subG][0];
    board[numOfCols+subG][0] = temp3;

    // switch mid num in mid col 
    temp4 = board[numOfCols][numOfCols];
    board[numOfCols][numOfCols] = board[numOfCols+subG][numOfCols];
    board[numOfCols+subG][numOfCols] = temp4;

  }else{
    cout << "NO" << endl;
  }
}

/*
* function_identifier: make sure row, cols, diag = magic number 
* parameters: nothing 
* return value: bool true/false 
*/ 
bool magicSquareType::validateMagicSquare() const{
  // declared vars 
  bool answer = true;
  int magicNumber = magicSquareType::magicNumber(); // call to get magic num
  int sumR = 0, sumC = 0, sumD1 = 0, sumD2 = 0;
  sumD1 = 0;

    // check if not null 
    if(board == nullptr){
      return false;
    }

    // sum of rows 
    for(int r = 0; r < size; r++ ){ // loop through rows 
      sumR = 0;
      for(int c = 0; c < size; c++){ // loop through columns & sum 
        sumR = sumR + board[r][c];
      }
      // check if each row is =
      if(sumR != magicNumber){
        answer = false;
      }
    }

    // sum of cols 
    for(int col = 0; col < size; col++ ){ // loop through cols
      sumC =0; 
      for(int row = 0; row < size; row++){ // loop through rows & sum 
        sumC = sumC + board[col][row];
      }
      // check if each col is = 
      if(sumC != magicNumber){
        answer = false;
      }
    }

    // upper left diagonal to right 
    for(int i = 0; i < size; i++ ){
      sumD1 = sumD1 + board[i][i]; // sum 
    }

    // upper right to left diagnal
    for(int i = 0; i < size; i++){
      sumD2 = sumD2 + board[i][size-1-i]; // sum 
    }
  

    // check if both diagonals = 
    if(sumD1 != magicNumber || sumD2 != magicNumber){
      answer = false;
    }
    
    return answer;
}
