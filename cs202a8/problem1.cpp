/*
    * Name: Michelle McGowan, 2001813382, CS 202-1004, Assignment 8
    * Description: recursive largest smaller than K
    * Input: Define in main
    * Output: Results to main
*/

#include <iostream>
using namespace std;
int largestSmallerThanK(int[],int, int, int);


// ****************************************************************
//  recursively find which val is the biggest smaller than k 
int largestSmallerThanK(int arr[],int l, int u, int k){
  // declared vars 
  int max = 0; 
  // check if went out of arr 
  if(l > u){
    return -1;
  }

  // recursive call 
  max = largestSmallerThanK(arr, l+1, u, k);
  
  // check if arr[0] is big than max & small than k 
  if(arr[l] > max && arr[l] < k){ 
    return arr[l];
  }

  // return max if not  
  return max;
}


// ****************************************************************
//  Simple main for testing.

int main()
{
	int     arr1[6] = {1, 4, 3, 8, 7, 6};
    int     k1 = 5;
    int     size1 = sizeof(arr1)/sizeof(arr1[0]);

	int     arr2[19] = {0};
    int     k2 = 50;
    int     size2 = sizeof(arr2)/sizeof(arr2[0]);

	int     arr3[12] = {0};
    int     k3 = 10;
    int     size3 = sizeof(arr3)/sizeof(arr3[0]);

    // random values for second array
    for (int i=0; i < size2; i++) {
        arr2[i] = rand() % 100;
    }

    // random values for third array
    for (int i=0; i < size3; i++) {
        arr3[i] = rand() % 100;
    }

	cout << "Recursion Problem 1 - Largest Smaller than K" << endl << endl;

    cout << "Test 1:" << endl;
    for (int i=0; i < size1-1; i++)
        cout << arr1[i] << ", ";
    cout << arr1[size1-1] << endl;
    cout << "Largest Smaller than " << k1 << " is "
            << largestSmallerThanK(arr1, 0, size1-1, k1) << endl;

    cout << endl;
    cout << "Test 2:" << endl;
    for (int i=0; i < size2-1; i++)
        cout << arr2[i] << ", ";
    cout << arr2[size3-1] << endl;
    cout << "Largest Smaller than " << k2 << " is "
	        << largestSmallerThanK(arr2, 0, size2-1, k2) << endl;

    cout << endl;
    cout << "Test 3:" << endl;
    for (int i=0; i < size3-1; i++)
        cout << arr3[i] << ", ";
    cout << arr3[size3-1] << endl;
    cout << "Largest Smaller than " << k3 << " is "
	        << largestSmallerThanK(arr3, 0, size3-1, k3) << endl;

	return  EXIT_SUCCESS;
}