/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 9
	*Description: program for linked lists, pointers, template classes 
	*Input: ordered & unordered values of diff types from main 
	*Output: ordered & unordered values in list form 
*/

#include <iostream>
#include "linkedListType.h"
#ifndef ordered_class
#define ordered_class 

// template class for ordered linked lists 
template <class myType> 
class orderedLinkedList : public linkedListType<myType>{
  public: // the virtual funcs 
    bool search(const myType&) const; 
    void insert(const myType&);
    void insertLast(const myType&);
    void deleteNode(const myType&);

  protected: // from linkedListType 
    using linkedListType<myType>::count;
    using linkedListType<myType>::first;
    using linkedListType<myType>::last;

};

/*
* function_identifier: find specific value 
* parameters: passed type value  
* return value: bool - true = found, false !found 
*/  
template <class myType>
bool orderedLinkedList<myType>::search
(const myType &value) const{
  // loop thru arr 
  for(nodeType<myType> *i = first; i != nullptr; i = i->link){
    // check if node info is val 
    if(value == i->info){
      return true;
    }
    // check if next node info bigger than val
    if(i->link->info > value){
      return false;
    }
  }
  return false;
}

/*
* function_identifier: insert val in right spot 
* parameters: passed type value  
* return value: nothing
*/  
template <class myType>
void orderedLinkedList<myType>::insert(const myType &value){
  // declared vars 
  nodeType<myType> *temp;
  nodeType<myType> *i;
  
  // allocate 
  temp = new nodeType<myType>;

  // set
  temp->info = value;
  temp->link = nullptr;

  // check if only 1 thing in list 
  if(first == nullptr){
    first = temp;
    last = temp;
  }else if(value < first->info){ // check if val less than first thing
    temp->link = first;
    first = temp;
  }else if(value > last->info){ // check if val greater than last thing
    last->link = temp;
    last = temp;
  }else{ // check for middle
    // set i to first 
    i = first;
    // loop thru while value is greater than next node
    while(value > i->link->info){
      // set to next node 
      i = i->link;
    }
    // save to temp 
    temp->link = i->link;
    // point to val now 
    i->link = temp;
  }

  // increment
  count++;
}

/*
* function_identifier: insert val, call insert() to keep order
* parameters: passed type value  
* return value: nothing
*/  
template <class myType>
void orderedLinkedList<myType>::insertLast(const myType& value){
  // call to insert func to keep order 
  insert(value);
}

/*
* function_identifier: delete specific val 
* parameters: passed type value  
* return value: nothing 
*/  
template <class myType>
void orderedLinkedList<myType>::deleteNode(const myType& value){
  // declared vars
  nodeType<myType> *temp;
  nodeType<myType> *toDelete;

  // check if list empty
  if(first == nullptr){
    std::cout << "Cannot delete from an empty list." << std::endl;
    return;
  }
  
  // set 
  temp = first;

  // check if val to delete is beginning
  if(first->info == value){
    // if 1 item 
    if(first == last){
      first = nullptr;
      last = nullptr;
    }else{ 
      // set to next node 
      first = first->link;
      // delete temp
      delete temp;
      // decrement 
      count--;
    }
  }else if(last->info == value){ // check if val to delete is last
    while(temp->link != nullptr){
      // set to next node
      temp = temp->link;
      delete last;
      // set 
      last = temp;
      // last link is null
      last->link = nullptr;
      // decrement 
      count--;
    }
  }else{ // check if val to delete is in mid
    // until reaches end of list 
    while(temp != last && value > temp->info){
      if(temp->link->info == value){
        // set to next node 
        toDelete = temp->link;
        temp->link = toDelete->link;
        delete toDelete;
        // decrement 
        count--;
        // leave 
        return;
      }
      // set to next 
      temp = temp->link;
    }
    // if not found 
    std::cout << "The item to be deleted is not in the list." << std::endl;
  }
}


#endif

