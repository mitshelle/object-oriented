/*
	*Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 7
	*Description: program to practice template classes, pointers, friend func
	*Input: nothing, writing vals 
	*Output: buffer values
*/

#ifndef RBUFFER_H
#define RBUFFER_H
#include <iostream>

// class declaration
template <class T>
class rBuffer {
    T *buffer_p;
    T *read_p;
    T *write_p;
    int size;
    bool full;
    bool empty;
public:
    rBuffer(int=8);
    rBuffer(const rBuffer<T> &);
    ~rBuffer();
    T read();
    void write(T);
    bool resize(int);
    void clear();
    void print() const;
    template <class A, class B>
    friend rBuffer<A> joinBuffers(const rBuffer<A> &, const rBuffer<B> &);
};


// DO NOT CHANGE THE PRINT FUNCTION.
template <class T>
void rBuffer<T>::print() const{ 
    std::cout << " | ";
    for (int i = 0; i < size; i++) {
        if (buffer_p + i == read_p) 
            std::cout << "*";
        if (buffer_p + i == write_p)
            std::cout << "+";
        std::cout << buffer_p[i] << " | ";
    }
    std::cout << "\n";
}

//**************************************************

 /*
* function_identifier: constructor for rBuffer class 
* parameters: size of buffer
* return value: nothing 
*/ 
template <class T> 
rBuffer<T>::rBuffer(int passedSize){
  // check size 
  if(passedSize < 1){
    // set if less than 1
    size = 8;
  }
  if(passedSize >= 1){
    // set size to passed in 
    size = passedSize;
    // set 
    empty = true;
    full = false;

    // allocate memory
    buffer_p = new T[size];
    // set  everything to 0
    for(int i = 0; i < size; i++){
      buffer_p[i] = 0;
    }
    // point to where buffer_p points
    read_p = buffer_p;
    write_p = buffer_p;
  }
}

//destructor 
template <class T> 
rBuffer<T>::~rBuffer(){
  // check if null 
  if(buffer_p != nullptr){
    // delete allocated memory
    delete [] buffer_p;

    // reset vars 
    size = 0;
    buffer_p = nullptr;
    read_p = nullptr;
    write_p = nullptr;
    empty = true;
    full = false;
  }

}


 /*
* function_identifier: deep copy constructor 
* parameters: object ot be copied
* return value: nothing 
*/ 
template <class T> 
rBuffer<T>::rBuffer(const rBuffer<T> &oldObj){
  // copy 
  size = oldObj.size;
  full = oldObj.full;
  empty = oldObj.empty;
  read_p = oldObj.buffer_p;
  write_p = oldObj.buffer_p;
  
  // allocate new & copy  
  buffer_p = new T[size];
  for(int i = 0; i < size; i++){
    buffer_p[i] = oldObj.buffer_p[i];
  }

}

//**************************************************
 /*
* function_identifier: func to write val to buffer 
* parameters: value to be written 
* return value: nothing 
*/ 
template <class T>
void rBuffer<T>::write(T value){
  // declared vars
  
  // if buffer not point to anything 
  if(buffer_p == nullptr){
    return;
  }
  
  // give it the value passed
  *write_p = value;
  // no longer empty
  empty = false;
 
  // check write pointer @ end of buffer 
  if(write_p == buffer_p +  size - 1){
    // means it is full 
    full = true; 
    // sets it back to beginning
    write_p = buffer_p;
  }else{ // increment 
    write_p++;
  }
}

/*
* function_identifier: func to read val from buffer 
* parameters: nothing
* return value: value read  
*/ 
template <class T>
T rBuffer<T>::read(){
  T temp; 
  // if buffer doesnt have a val 
  if(empty){
      throw "Cannot read from empty buffer!";
  }
  
  
  // if write & read pointer @ same location & read @ end of buffer 
  if(write_p == read_p && read_p == buffer_p){
    // last value of pointer 
    return *(buffer_p + size -1);
  }
  // check if read pointer is @ same location of write 
  if(write_p == read_p){
    // previous val 
    return *(read_p - 1);
  }

  // set 
  temp = *(read_p);
  
  // end of buffer 
  if(read_p == buffer_p + size - 1){
    // go back to beginning 
    read_p = buffer_p;
  }else{ // increment 
    read_p++;
  }
  return temp; 
}

/*
* function_identifier: func to resize buffer
* parameters: resize size 
* return value: true if resize worked, false if did not resize
*/ 
template <class T>
bool rBuffer<T>::resize(int resizeVal){
  // declared vars 
  int readLocation = 0, writeLocation =0;
  T *temp = nullptr;

  // check if size smaller than 1
  if(resizeVal < 1){
    return false;
  }
  // if it equals size
  if(resizeVal == size){
    return true;
  }
  
  // check if full & no shrink 
  if(resizeVal < size && full == true){
    return false;
  }

  // find distance for write & read
  writeLocation = write_p - buffer_p;
  readLocation = read_p - buffer_p;

  // if resize size is less than write pointer 
  if(resizeVal < writeLocation){
    return false;
  }

  // allocate new memory
  temp = new T[resizeVal];

  // set  everything to 0
  for(int i = 0; i < resizeVal; i++){
    temp[i] = 0;
  }

  // check if resize val is less than size & not full 
  if(resizeVal < size && !full){
    // copy into temp 
    for(int i = 0; i < writeLocation; i++){
      temp[i] = buffer_p[i];
    }
    // delete orig buffer
    delete [] buffer_p;
    // point to temp
    buffer_p = temp;
    // set location of read
    read_p = buffer_p + readLocation;

    // check if write equal to resize size
    if(writeLocation == resizeVal){
      write_p = buffer_p + writeLocation - 1;
    }else{
      write_p = buffer_p + writeLocation;
    }
    // set
    size = resizeVal;
  }

  // check if resize val is greater than size
  if(resizeVal > size){
    // copy into temp 
    for(int i = 0; i < size; i++){
      temp[i] = buffer_p[i];
    }
    // delete orig buffer
    delete [] buffer_p;
    // point to temp
    buffer_p = temp;
    // set location of read
    read_p = buffer_p + readLocation;

    // check if write pointer is at the end
    if(writeLocation == size - 1){
      // puts it one over 
      write_p = buffer_p + writeLocation + 1;
    }else{
      // puts it in same spot 
      write_p = buffer_p + writeLocation;
    }

    // not full anymore since made it bigger
    full = false;
    // set
    size = resizeVal;

  }

  return true;
}

/*
* function_identifier: func to clear val from buffer
* parameters: nothing
* return value: nothing
*/ 
template <class T>
void rBuffer<T>::clear(){
  // declared vars 
  T *temp = nullptr;

  // new buffer that has nothing in it 
  temp = new T[size];
  // set  everything to 0
  for(int i = 0; i < size; i++){
    temp[i] = 0;
  }

  // delete allocated mem
  delete [] buffer_p;

  // reset vars 
  full = false; 
  empty = true;

  // set to point to temp
  buffer_p = temp;
  read_p = temp;
  write_p = temp;
  
}

/*
* function_identifier: FRIEND! func to combine 2 buffers 
* parameters: 2 buffers to be joined 
* return value: the combined buffer 
*/ 
template <class A, class B>
rBuffer<A> joinBuffers (const rBuffer<A> &buffA, const rBuffer<B> &buffB){
  // declared vars
  int resize = 0;
  int writeLocA = 0, writeLocB = 0;

  // size of 2 buffers 
  resize = buffA.size + buffB.size;
  // temp to hold joined buffs
  rBuffer<A> temp(resize);


  // check if not empty
  if(buffA.empty == false){
    // then check if full 
    if(buffA.full == true){
      // loop thru buffer of buffA & write it to temp
      for(int i = 0; i < buffA.size; i++){
        temp.write(buffA.buffer_p[i]);
      } 
    }else{ // if not full 
      // find location of write pointer 
      writeLocA = buffA.write_p - buffA.buffer_p;
      // loop thru buffer of buffA & write it to temp
      for(int i = 0; i < writeLocA; i++){
        temp.write(buffA.buffer_p[i]);
      }
    }
  }

  // check if not empty
  if(buffB.empty == false){
    // then check if full 
    if(buffB.full == true){
      // loop thru buffer of buffB & write it to temp
      for(int i = 0; i < buffB.size ; i++){
        temp.write(buffB.buffer_p[i]);
      } 
    }else{ // if not full 
      // find location of write pointer 
      writeLocB = buffB.write_p - buffB.buffer_p;
      // loop thru buffer of buffB & write it to temp
      for(int i = 0; i < writeLocB; i++){
        temp.write(buffB.buffer_p[i]);
      }
    }
  }

  return temp;
}












#endif
