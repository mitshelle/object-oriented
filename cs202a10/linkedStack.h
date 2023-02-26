/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 10
	*Description: program for linked stacks and queues, makefile, 
	*Input: audio file to be reversed and output file to write to 
	*Output: reversed audio file 
*/

#include <iostream>
#ifndef LINKEDSTACK_CLASS
#define LINKEDSTACK_CLASS
using namespace std;

// node struct def 
template <class myType>
struct nodeType {
  myType *dataSet;
  unsigned int top;
  nodeType<myType> *link;
};

// template class for linked stack 
template <class myType>
class linkedStack{
  public:
    // de/construct
    linkedStack(unsigned int = ARR_DEFAULT);
    ~linkedStack();
    // func
    bool isEmptyStack() const;
    void initializeStack();
    unsigned int stackCount();
    void push(const myType& newItem);
    myType top() const;
    void pop();

  private: 
    nodeType<myType> *stackTop;
    unsigned int size;
    unsigned int count;
    // constantly has memory 
    static constexpr unsigned int ARR_MIN = 5;
    static constexpr unsigned int ARR_MAX = 96000;
    static constexpr unsigned int ARR_DEFAULT = 22050;
};


//****************************************************************
/*
* function_identifier: constructor for linked stack class 
* parameters: nothing
* return value: nothing 
*/ 
template <class myType>
linkedStack<myType>::linkedStack(unsigned int passedSize){
  // check size in btwn 5 & 960000
  if(passedSize < ARR_MIN || passedSize > ARR_MAX){
    // set to default size 
    size = ARR_DEFAULT;
  }else{ // if size good 
    size = passedSize;
  }

  // set 
  stackTop = nullptr; 
  count = 0; 
}

// deconstructor
template <class myType>
linkedStack<myType>::~linkedStack(){
  // declared vars 
  nodeType<myType> *temp;
  
  // loop until top is null
  while(stackTop != nullptr){
    // set
    temp = stackTop;
    // set to node before 
    stackTop = stackTop->link;
    // delete arr 
    // maybe take out of loop??? if no work 
    delete [] temp->dataSet;
    // delete whole thing 
    delete temp;
  }
}

//****************************************************************

//****************************************************************
/*
* function_identifier: get count of stack 
* parameters: nothing
* return value: count  
*/  
template <class myType>
unsigned int linkedStack<myType>::stackCount(){
  return count;
}

/*
* function_identifier: create a new stack  
* parameters: nothing
* return value: nothing 
*/ 
template <class myType>
void linkedStack<myType>:: initializeStack(){
  // declared vars 
  nodeType<myType> *temp;

  // loop until null 
  while(stackTop != nullptr){
    // set 
    temp = stackTop;
    // set to node before 
    stackTop = stackTop->link;
    // delete arr 
    delete [] temp->dataSet;
    // delete whole thing 
    delete temp;
  }

  // allocate
  stackTop = new nodeType<myType>;
  // allocate size for arr 
  stackTop->dataSet = new myType[size];
  // set 
  stackTop->top = 0;
  stackTop->link = nullptr;
}

/*
* function_identifier: check if stack is empty
* parameters: nothing
* return value: true if empty, false if not  
*/ 
template <class myType>
bool linkedStack<myType>::isEmptyStack() const{
  // check if there is nothing 
  if(stackTop == nullptr){
    return true;
  }

  // if there is nothing after stack top 
  if(stackTop->link == nullptr && stackTop->top == 0){
    return true;
  }

  return false;
}

/*
* function_identifier: get the top of stack
* parameters: nothing
* return value: passed type value on top 
*/  
template <class myType>
myType linkedStack<myType>::top() const{
  // declared vars
  bool empty = isEmptyStack();

  // check if stack empty 
  if(empty){
    return 0;
  }
  // arr so get the element of size -1 
  return stackTop->dataSet[stackTop->top-1];
}

/*
* function_identifier: add value to top of stack 
* parameters: passed type value
* return value: nothing
*/  
template <class myType>
void linkedStack<myType>::push(const myType &itemToAdd){
  // declared vars 
  nodeType<myType> *temp;
  // check if stack empty 
  if(stackTop == nullptr){
    // call to func to create new stack 
    initializeStack();
  }

  // if top is in last spot of arr 
  if(stackTop->top == size){
    // allocate 
    temp = new nodeType<myType>;
    temp->dataSet = new myType[size];
    // set to item below it 
    temp->link = stackTop;
    // set top to one being added 
    stackTop = temp; 
    // new arr spot 
    stackTop->top = 0;
  }

  // set to new item 
  stackTop->dataSet[stackTop->top] = itemToAdd;
  // increment 
  stackTop->top++;
  count++;
}

/*
* function_identifier: remove from top of stack 
* parameters: nothing 
* return value: nothing
*/  
template <class myType>
void linkedStack<myType>::pop(){
  // declared vars 
  bool empty = isEmptyStack();
  nodeType<myType> *temp;

  // check if empty 
  if(empty){
    return;
  }

  // decrement
  stackTop->top--;
  
  // check if top nothing
  if(stackTop->top == 0){
    // set 
    temp = stackTop;
    // set top now to node before 
    stackTop = stackTop->link;
    // delete arr 
    delete [] temp->dataSet;
    // delete whole thing
    delete temp;
  }
  
  // decrement
  count--;
}




#endif
