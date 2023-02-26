/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 9
	*Description: program for linked lists, pointers, template classes 
	*Input: ordered & unordered values of diff types from main 
	*Output: ordered & unordered values in list form 
*/

#include <iostream>
#ifndef linkedList_class
#define linkedList_class

// list link struct 
template <class myType> 
struct nodeType {
  myType info; // data 
  nodeType<myType> *link; 
};

// template class for linked list 
template <class myType>
class linkedListType{
  public:
    // constructor
    linkedListType();
    // copy constructor 
    linkedListType(const linkedListType<myType>&);
    // destructor
    ~linkedListType();

    // functions 
    void initializeList();
    bool isEmptyList() const;
    void print() const;
    void reversePrint() const;
    int length() const;
    void destroyList();
    myType front() const;
    myType back() const;
    nodeType<myType> *firstPtr() const;
    // abstract func - to be implemented in derived classes
    virtual bool search(const myType&) const = 0;
    virtual void insert(const myType&) = 0;
    virtual void insertLast(const myType&) = 0;
    virtual void deleteNode(const myType&) = 0;

  private: 
    void copyList(const linkedListType<myType>&); 
    void recursiveReversePrint(nodeType<myType> *) const;
  
  public: // vars 
    int count;
    nodeType<myType> *first;
    nodeType<myType> *last;
};


//***********************************************
/*
* function_identifier: constructor for linked list class 
* parameters: nothing
* return value: nothing 
*/ 
template <class myType> 
linkedListType<myType>::linkedListType(){
  // set
  first = nullptr;
  last = nullptr;
  count = 0;

}

// destructor
template <class myType>
linkedListType<myType>::~linkedListType(){
  // call to func to delete allocated mem
  destroyList();
}

/*
* function_identifier: copy constructor (deep)
* parameters: list obj
* return value: nothing 
*/  
template <class myType>
linkedListType<myType>::linkedListType
(const linkedListType<myType> &passedList){
  // set
  count = passedList.length();
  first = nullptr;
  last = nullptr;
  
  // check not empty
  if(!passedList.isEmptyList()){
    // call to copy func 
    copyList(passedList);
  }
}
//***********************************************


/*
* function_identifier: reset list 
* parameters: nothing 
* return value: nothing 
*/ 
template <class myType> 
void linkedListType<myType>::initializeList(){
  // call to func to delete allocated mem
  destroyList();
}


/*
* function_identifier: check if list is empty 
* parameters: nothing 
* return value: nothing 
*/ 
template <class myType>
bool linkedListType<myType>::isEmptyList() const{
  // check if there is 1 thing in list 
  if(first == nullptr){
    return true;
  }

  return false;
}



/*
* function_identifier: get length of list
* parameters: nothing 
* return value: nothing 
*/ 
template <class myType>
int linkedListType<myType>::length() const{
  // how many nodes are in list 
  return count;
}


/*
* function_identifier: print in reverse recursively
* parameters: nothing 
* return value: nothing 
*/ 
template <class myType>
void linkedListType<myType>::reversePrint() const{
  // call to recursive func to print in reverse
  recursiveReversePrint(first); 
  std::cout << std::endl;
}


/*
* function_identifier: return 1st node
* parameters: nothing 
* return value: copy of first pointer 
*/ 
template <class myType>
nodeType<myType> *linkedListType<myType>::firstPtr() const{
  return first;
}


/*
* function_identifier: return val in first
* parameters: nothing 
* return value: passed type info 
*/  
template <class myType>
myType linkedListType<myType>::front() const{
  // check if there is val in first 
  if(first != nullptr){
    return first->info;
  }

  return 0;
}


/*
* function_identifier: return val in last 
* parameters: nothing 
* return value: passed type info 
*/  
template <class myType>
myType linkedListType<myType>::back() const{
  // check if there is val in last 
  if(last != nullptr){
    return last->info;
  }
  
  return 0;
}


/*
* function_identifier: print list 
* parameters: nothing 
* return value: nothing 
*/  
template <class myType>
void linkedListType<myType>::print() const{
  // loop thru list 
  for(nodeType<myType> *i = first; i != nullptr; i = i->link){
    std::cout << i->info << " ";
  }
  
}

 
/*
* function_identifier: delete whole list & reset
* parameters: nothing 
* return value: nothing 
*/  
template <class myType>
void linkedListType<myType>::destroyList(){
  // declared vars 
  nodeType<myType> *temp;
  // check if theres nothing in there 
  if(first == nullptr){
    return;
  }

  // loop until first is at the end 
  while(first != last){
    // save link into temp 
    temp = first->link;
    // delete 
    delete first;
    // set next link 
    first = temp;
  }

  // delete 
  delete first;

  // set 
  first = nullptr;
  last = nullptr;
  count = 0;
}

/*
* function_identifier: copy whole list 
* parameters: list 
* return value: nothing 
*/  
template <class myType>
void linkedListType<myType>::copyList(const linkedListType<myType> &list){
  // declared vars 
  nodeType<myType> *originalList;
  nodeType<myType> *copy;
  // allocate & set 
  first = new nodeType<myType>;
  first->link = nullptr;

  // set orginal to point to first of the pass l ist
  originalList = list.first;
  // copy points to first 
  copy = first;
  // copy info set to original info 
  copy->info = originalList->info;
  // orignal points to nxt node 
  originalList = originalList->link;

  while(originalList != nullptr){
    // allocate & set copy to nxt node
    copy->link = new nodeType<myType>;
    copy = copy->link;

    // set copy to original data 
    copy->info = originalList->info;
    // set original to nxt node 
    originalList = originalList->link;
  }

  // set to null once end 
  copy->link = nullptr;
  last = first;
  
  // loop until last points to null 
  while(last->link != nullptr){
    // set last to nxt node 
    last = last->link; 
  }
}

/*
* function_identifier: recursively print in reverse 
* parameters: list 
* return value: nothing 
*/  
template <class myType>
void linkedListType<myType>::recursiveReversePrint(nodeType<myType> *list) 
const{
  // base case - empty list 
  if(list == nullptr){
    return;
  }

  // recursive call to print next link 
  recursiveReversePrint(list->link);
  // output 
  std::cout << list->info << " ";
}

#endif 


