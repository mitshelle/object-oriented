/*
    * Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 8
    * Description: recursive reverse string
    * Input: Define in main
    * Output: Results to console
*/

#include <iostream>
using namespace std;

void reverse(string &,int left,int right);

// ****************************************************************
// recursively print string backwards 
void reverse(string &str,int left,int right){
  // temp for character
  char temp; 
  // check if crosses each other
  if(left > right){
    return;
  }
  // swap 
  temp = str[left];
  str[left] = str[right];
  str[right] = temp;
  // recursive call 
  reverse(str, left+1, right-1);
}


// *********************************************************
//  Basic tests

int main()
{
    string  strArr[] = {
                "hello",
                "racecar",
                "tattarrattat",
                "some long string",
                "animal loots foliated detail of stool lamina"
            };
    int strSize = sizeof(strArr)/sizeof(strArr[0]);

	cout << "Recursion Problem 2 - Reverse String" << endl << endl;

    for (int i=0; i < strSize; i++) {
       	cout << i <<": " << strArr[i] << endl;
    	reverse(strArr[i], 0, strArr[i].size()-1);
	    cout << "R: " << strArr[i] << endl << endl;
    }

	return	EXIT_SUCCESS;
}
