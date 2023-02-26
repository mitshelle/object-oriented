/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 10
	*Description: program for linked stacks and queues, makefile, 
	*Input: audio file to be reversed and output file to write to 
	*Output: reversed audio file 
*/

#include <iostream>
#ifndef LINKEDQUEUE_CLASS
#define LINKEDQUEUE_CLASS
using namespace std;

// node struct def 
template <class myType>
struct queueNode{
  myType *dataSet;
  unsigned int front, back;
  queueNode<myType> *link;
};

// template class for linked queue 
template <class myType>
class linkedQueue{
  public:
    // de/constructor 
    linkedQueue(unsigned int=ARR_DEFAULT);
    ~linkedQueue();
    // functions 
    bool isEmptyQueue() const;
    void initializeQueue();
    void addItem(const myType& newItem);
    myType front() const;
    myType back() const;
    void deleteItem();
    unsigned int queueCount();
    void printQueue();

  private: 
    queueNode<myType> *queueFront;
    queueNode<myType> *queueRear;
    unsigned int size;
    unsigned int count;
    // constantly has memory 
    static constexpr unsigned int ARR_MIN = 5;
    static constexpr unsigned int ARR_MAX = 96000;
    static constexpr unsigned int ARR_DEFAULT = 22050;
  
};

//****************************************************************
/*
* function_identifier: constructor for linked queue class 
* parameters: nothing
* return value: nothing 
*/ 
template <class myType>
linkedQueue<myType>::linkedQueue(unsigned int passedSize){
  // check if size btwn min & max size 
  if(passedSize < ARR_MIN || passedSize > ARR_MAX){
    size = ARR_DEFAULT;
  }else{ // if size good 
    size = passedSize;
  }
  
  // set 
  queueFront = nullptr;
  queueRear = nullptr;
  count = 0;
}

//deconstrutctor
template <class myType>
linkedQueue<myType>::~linkedQueue(){
  // declared vars
  queueNode<myType> *temp;

  // loop until null
  while(queueFront != nullptr){
    // set 
    temp = queueFront;
    // set front to node after it 
    queueFront = queueFront->link;
    // delete arr 
    delete [] temp->dataSet;
    // delete whole thing 
    delete temp;
  }
}


//****************************************************************


//****************************************************************

/*
* function_identifier: get count of queue
* parameters: nothing
* return value: count  
*/ 
template <class myType>
unsigned int linkedQueue<myType>::queueCount(){
  return count;
}

/*
* function_identifier: create a new queue 
* parameters: nothing
* return value: nothing 
*/ 
template <class myType>
void linkedQueue<myType>::initializeQueue(){
  // declared vars 
  queueNode<myType> *temp;

  // loop until null 
  while(queueFront != nullptr){
    // set 
    temp = queueFront;
    // set to node after 
    queueFront = queueFront->link;
    // delete arr 
    delete [] temp->dataSet;
    // delete whole thing 
    delete temp;
  }

  // allocate
  queueFront = new queueNode<myType>;
  queueRear = queueFront;
  // allocate size for arr 
  queueFront->dataSet = new myType[size];
  // set 
  queueFront->front = 0;
  queueFront->back = 0;
  queueRear->link = nullptr;
}

/*
* function_identifier: check if queue is empty
* parameters: nothing
* return value: true if empty, false if not  
*/ 
template <class myType>
bool linkedQueue<myType>::isEmptyQueue() const{
  // nothing in there?
  if(queueFront == nullptr){
    return true;
  }

  // check if both point to same thing 
  if(queueFront->front == queueFront->back){
    return true;
  }

  return false; 
}

/*
* function_identifier: get the first thing in queue
* parameters: nothing
* return value: passed type value 
*/ 
template <class myType>
myType linkedQueue<myType>::front() const{
  bool empty = isEmptyQueue();
  if(empty){
    return 0;
  }
  // get the front data 
  return queueFront->dataSet[queueFront->front];
}

/*
* function_identifier: get the thing in back of queue 
* parameters: nothing
* return value: passed type value 
*/ 
template <class myType>
myType linkedQueue<myType>::back() const{
  // if there is nothing 
  if(queueRear == nullptr){
    return 0;
  }

  // get the back of data but -1 bc arr 
  return queueRear->dataSet[queueRear->back-1];
}

/*
* function_identifier: add value to back of queue 
* parameters: passed type value
* return value: nothing
*/  
template <class myType>
void linkedQueue<myType>::addItem(const myType &itemToAdd){
  // check if queue has nothing
  if(queueFront == nullptr){
    // call to func to create new queue
    initializeQueue();
  }

  // if last thing in queue is in last spot of arr 
  if(queueRear->back == size){
    // allocate 
    queueRear->link = new queueNode<myType>;
    // set to next item in queue
    queueRear = queueRear->link;
    // point to nothign bc last one in queue
    queueRear->link = nullptr;
    // allocate arr 
    queueRear->dataSet = new myType[size];
    // set 
    queueRear->front = 0;
    queueRear->back = 0;
  }

  // set back to new item 
  queueRear->dataSet[queueRear->back] = itemToAdd;
  // increment 
  queueRear->back++;
  count++;
}

/*
* function_identifier: remove from front of queue 
* parameters: nothing
* return value: nothing
*/ 
template <class myType>
void linkedQueue<myType>::deleteItem(){
  // declared vars 
  bool empty = isEmptyQueue();
  queueNode<myType> *temp; 

  // check if nothing in queue
  if(empty){
    return;
  }
  // increment
  queueFront->front++;
  // if front is at max spots 
  if(queueFront->front == size){
    // set 
    temp = queueFront;
    // set front to node after 
    queueFront = queueFront->link;
    // delete arr 
    delete [] temp->dataSet;
    // delete whole thing 
    delete temp;
  }
  // decrement
  count--;
}

/*
* function_identifier: print queue 
* parameters: nothing
* return value: nothing 
*/ 
template <class myType>
void linkedQueue<myType>::printQueue(){
  // loop thru nodes until at end null 
  for(queueNode<myType> *i = queueFront; i != nullptr; i= i->link){
    // loop thru using int to get actual data 
    for(unsigned int j = i->front; j < i->back; j++){
      cout << i->dataSet[j] << " ";
    }
  }
}


#endif

