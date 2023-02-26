/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 8
	*Description: program for recursion, template classes, pointers 
	*Input: animals & its symbol, path, name etc      
	*Output: writing forests & animal path
*/
#include <iostream>
#include "object.h"
using namespace std;


//Template class forest with two generic types t1 and t2
template <class t1, class t2>
class forest
{
private:
	int rows;//rows of the grid
	int cols;//columns of the grid
	string ** grid;//pointer to pointer to point the dynamic 2d array of string

	t1 * obj1;//first object of the forest
	t2 * obj2;//second object of the forest

  //private member function to determine whether two objects meet
	bool doTheyMeet(int);
	int displayForest(int,int);//private function to print the forest
	

public:
	forest(int,int,t1 *,t2*);//constructor to initialize the forest.
  //function that handles all the movement, 
  //print and other operations of the forest
	void simulate();


	~forest();//destructor to deallocate the dynamic variables.

	
};

/*Implementation of constructors and member functions begins*/


 /*
* function_identifier: constructor for forest class 
* parameters: frows, cols, 2 objects 
* return value: nothing 
*/ 
template <class t1, class t2> 
forest<t1, t2>::forest(int passedRow, int passedCol,
                        t1 *passedObj1, t2 *passedObj2){
  // set
  rows = passedRow;
  cols = passedCol;

  // allocate 
  grid = new string*[rows];
  for(int i = 0; i < rows; i++){
    grid[i] = new string[cols];
  }

  // fill w X
  for(int i = 0; i < passedRow; i++){
    for(int j = 0; j < passedCol; j++){
      grid[i][j] = "X";
    }
  }
  
  // copy objects by calling object constructor 
  obj1 = new t1(passedObj1->getName(), passedObj1->getSymbol(),
                passedObj1->getPath(),passedObj1->getCurrentPosition());
  obj2 = new t2(passedObj2->getName(), passedObj2->getSymbol(),
                passedObj2->getPath(), passedObj2->getCurrentPosition());
   
}




template<class t1,class t2>
void forest<t1,t2>::simulate()
{
	cout <<"***********************************"<<endl;
	cout <<"SIMULATION BEGINS FOR FOREST WITH "<<obj1->getName()
        <<" and "<<obj2->getName()<<endl;
	obj1->move(grid,rows,cols,0);
	obj2->move(grid,rows,cols,0);

	obj1->setCurrentPosition(obj1->getStartingPosition().x,
                            obj1->getStartingPosition().y);
	obj2->setCurrentPosition(obj2->getStartingPosition().x,
                            obj2->getStartingPosition().y);
	//cout <<obj1->getCurrentPosition().x<<obj1->getCurrentPosition().y<<endl;
	//cout <<obj2->getCurrentPosition().x<<obj2->getCurrentPosition().y<<endl;

	displayForest(0,0);
	if(doTheyMeet(0))
	{
		if(obj1->getSymbol()=='T' && obj2->getSymbol()=='G')
			cout <<obj1->getName()<<" FINDS "
            <<obj2->getName()<<" but TIGER doesn't eat grass"<<endl;
		else
			cout <<obj1->getName()<<" EATS "<<obj2->getName()<<endl;
	}
	else
		cout <<obj1->getName()<< " COULDN'T FIND "<<obj2->getName()<<endl;

	cout <<"SIMULATION ENDS"<<endl;
	cout <<"***********************************"<<endl;
}

/*
* function_identifier: display forest recursively 
* parameters: rows, cols 
* return value: 0  
*/ 
template<class t1,class t2>
int forest<t1,t2>::displayForest(int row, int col){

  // check if col = # of cols 
  if(col == cols){
    // reset col 
    col = 0; 
    // move to next row 
    row++;
    // output 
    cout << endl;
    cout << endl;
    // check if row = # of rows 
    if(row == rows){
      return 0;
    }
  }

  // output 
  cout << grid[row][col] << '\t';
  // recursive call 
  displayForest(row, col+1);

  return 0;
}


/*
* function_identifier: func to check if objs meet 
* parameters: meet start index 
* return value: true if they meet, false if not  
*/ 
template<class t1,class t2>
bool forest<t1,t2>::doTheyMeet(int meetSpot){
  // declared variables
  bool meet = true; 
  
  try{
    // check if x and y of both objs same 
    if(obj1->getCurrentPosition().x ==
      obj2->getCurrentPosition().x &&
      obj1->getCurrentPosition().y ==
      obj2->getCurrentPosition().y){
      return true;
    }

    // check if went out of grid/forest
    if(obj1->getCurrentPosition().x < 0 || 
        obj2->getCurrentPosition().x >= rows ||    
        obj1->getCurrentPosition().x >= rows || 
        obj2->getCurrentPosition().x < 0 || 
        obj1->getCurrentPosition().y < 0 || 
        obj1->getCurrentPosition().y >= cols || 
        obj2->getCurrentPosition().y >= cols || 
        obj2 ->getCurrentPosition().y < 0){
        return false;
    }
    
    // get next pos  
    obj1->setCurrentPosition(obj1->getPath().at(meetSpot));
    obj2->setCurrentPosition(obj2->getPath().at(meetSpot));
    // recursive call to check again 
    meet = doTheyMeet(meetSpot + 1);

  }catch(out_of_range m){ // catch 
    return false;
  }

  // return val saved from recursive call 
  return meet;
}


template<class t1,class t2>
forest<t1,t2>::~forest()
{
	delete obj1;
	delete obj2;

	for(int i=0;i<rows;i++)
	{
		delete[] grid[i];
	}
	delete [] grid;
}
/*Implementation ends*/
