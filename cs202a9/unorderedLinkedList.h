/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 9
	*Description: program for linked lists, pointers, template classes 
	*Input: ordered & unordered values of diff types from main 
	*Output: ordered & unordered values in list form 
*/

#include <iostream>
#include "linkedListType.h"
#ifndef unordered_class
#define unordered_class

// template class for ordered linked lists 
template <class myType> 
class unorderedLinkedList : public linkedListType<myType>{
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
* function_identifier: search for specific value 
* parameters: passed type value  
* return value: bool - true = found, false !found 
*/  
template <class myType>
bool unorderedLinkedList<myType>::search(const myType &value) 
const{
  // loop thru list until nullptr
  for(nodeType<myType> *i = first; i != nullptr; i=i->link){
    // check if val found 
    if(value == i->info){
      return true;
    }
  }
  return false;
}

/*
* function_identifier: insert val in at beginning of list 
* parameters: passed type value  
* return value: nothing
*/ 
template <class myType>
void unorderedLinkedList<myType>::insert(const myType &value){
  // declared vars
  nodeType<myType> *temp;
  // allocate
  temp = new nodeType<myType>;
  // set temp to value 
  temp->info = value;
  // set temp link to first bc inserting @ beginning
  temp->link = first;
  // set first to temp 
  first = temp;

  // check if last is null 
  if(last == nullptr){
    last = first;
  }

  // increment count bc adding to list 
  count++;
}

/*
* function_identifier: insert val in at end of list 
* parameters: passed type value  
* return value: nothing
*/ 
template <class myType>
void unorderedLinkedList<myType>::insertLast(const myType &value){
  // declared vars 
  nodeType<myType> *temp;
  // allocate 
  temp = new nodeType<myType>;
  // set temp to value
  temp->info = value;
  // set link to null bc adding to end of list 
  temp->link = nullptr;

  // check if last 
  if(last == nullptr){
    first = temp;
    last = temp;
  }else{
    // set to temp 
    last->link = temp;
    last = temp;
  }

  // increment count bc adding to list 
  count++;
}

/*
* function_identifier: delete specific val 
* parameters: passed type value  
* return value: nothing 
*/ 
template <class myType>
void unorderedLinkedList<myType>::deleteNode(const myType& value){
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
    }
    // delete temp
    delete temp;
    // decrement 
    count--;
  }else if(last->info == value){ // check if val to delete is last
    while(temp->link != last){
      // set to next node
      temp = temp->link;
    }
    delete last;
    last = temp;
    last->link = nullptr;
    count--;
  }else{ // check if val to delete is in mid
    // until reaches end of list 
    while(temp != last){
      if(temp->link->info == value){
        // set 
        toDelete = temp->link;
        temp->link = toDelete->link;
        delete toDelete;
        // decrement 
        count--;
        // leave 
        return;
      }
      temp = temp->link;
    }
    // if not found 
    std::cout << "The item to be deleted is not in the list." << std::endl;
  }
}


#endif 