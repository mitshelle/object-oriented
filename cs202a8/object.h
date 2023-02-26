/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 8
	*Description: program for recursion, template classes, pointers 
	*Input: animals & its symbol, path, name etc in main  
	*Output: writing forests & animal path
*/

#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>

using namespace std;

//Struct position to hold x and y position within the grid
struct position
{
	int x;
	int y;
};

//object class that will be the base class of three objects. Tiger, deer and grass
class object
{
private:
	string name;//name of the object
	string path;//path of the object
	char symbol;//symbol of the object
	position currentPosition;//current position of the object
	position startingPosition;//starting position of the object
public:
  //constructor to initialize the object with name, 
  //symbol, path and starting position
	object(string,char,string, position);
  

	object(object&);//copy constructor

	void move(string** &,int,int,int);//move function that traces the movement of objects

	/*Getter functions*/
	string getName();
	char getSymbol();
	string getPath();
	position getCurrentPosition();
	position getStartingPosition();
	/*****************************/

	/*Mutator function to set the current position.*/
	void setCurrentPosition(int,int);

	void setCurrentPosition(char);
	/*********************************************/
};

//Tiger class
class tiger: public object
{
public:
	tiger(string n,char s,string p,position pos): object(n,s,p,pos){}
};

//Deer class
class deer: public object
{
public:
	deer(string n,char s,string p,position pos): object(n,s,p,pos){}

};

//Grass class
class grass: public object
{
public:
	grass(string n,char s,string p,position pos):object(n,s,p,pos){}

	//grass(grass& g): object(g){}
};


/*Implementation of constructors and member functions of object class*/
object::object(string n,char s,string p, position pos)
{
	name=n;
	path=p;
	symbol=s;
	currentPosition=pos;
	startingPosition=pos;
}

object::object(object& obj)
{
	name=obj.name;
	path=obj.path;
}

/*
* function_identifier: move func to move objects 
* parameters: forest grid, rows, cols, starting index 
* return value: nothing 
*/ 
void object::move(string **&gridPassed, int row, int col, int pathIndex){
  // string throw var 
  string thrownStr = getName() + " went out of the forest";
  
  try{
    // check if went out of boundaries of arr 
    if(currentPosition.x >= row || currentPosition.y >= col
     || currentPosition.x < 0 || currentPosition.y < 0){
      // print 
      throw thrownStr;
     }
    
    // check if has X 
    if(gridPassed[currentPosition.x][currentPosition.y] == "X"){
      // set it to symbol 
      gridPassed[currentPosition.x][currentPosition.y] = getSymbol();
    }else{ // if not X, then just add symbol to it
      gridPassed[currentPosition.x][currentPosition.y] += getSymbol();
    }

    // start path 
    path.at(pathIndex);
    // output 
    cout << getName() << " is moving" << endl;
    // set currentPosition
    setCurrentPosition(path.at(pathIndex));
  
  }catch(out_of_range e){ 
    // print 
    cout << getName() << " finished moving" << endl;
    return;
  }catch(string str){ // if it is a string 
    // output that string 
    cout << str << endl;
    return;
  }

  // move animal 
  move(gridPassed, row, col, pathIndex+1);
  return;

}

  
//*******************************************************
// getter & setter funcs 

string object::getName()
{
	return name;
}

char object::getSymbol()
{
	return symbol;
}

string object::getPath()
{
	return path;
}

position object::getCurrentPosition()
{
	return currentPosition;
}

position object::getStartingPosition()
{
	return startingPosition;
}

void object::setCurrentPosition(int x,int y)
{
	currentPosition.x=x;
	currentPosition.y=y;
}

void object::setCurrentPosition(char nextDirection)
{
	switch(nextDirection)
	{
		case 'U':
			--currentPosition.x;
			break;
		case 'D':
			++currentPosition.x;
			break;
		case 'L':
			--currentPosition.y;
			break;
		case 'R':
			++currentPosition.y;
	}
}

#endif