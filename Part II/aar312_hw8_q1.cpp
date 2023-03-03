// 1. Implement the function: int minInArray(int arr[], int arrSize)
// This function is given arr, an array of integers, and its logical size, arrSize. When called,
// it returns the minimum value in arr.

// Write a program that reads from the user a sequence of 20 integers (unnecessarily different
// from one another) into an array, and outputs the minimum value, and all the indices it
// appears in the array.
// Your program should interact with the user exactly as it shows in the following example:
// Please	enter	20	integers	separated	by	a	space:
// 14			5			12			5			6			14			5			12			14			12			14			6			8			7			5			136			9			2189			10			6
// The	minimum	value	is	5,	and	it	is	located	in	the	following	indices:	1			3			6			14
// Note: You may want to define additional functions for your program to use.

#include <iostream>
using namespace std;

const int MAX_ARR_SIZE = 20;
int minInArray(int arr[], int arrSize);

int main() {
  int userInputArr[MAX_ARR_SIZE];
  int currInt, minInt;
  cout << "Please enter 20 integers separated by a space: " << endl;
  for (int ind = 0; ind < MAX_ARR_SIZE; ind++) {
    cin >> currInt;
    userInputArr[ind] = currInt;
  }
  minInt = minInArray(userInputArr, MAX_ARR_SIZE);
  cout << "The minimum value is" << minInt << ", and it is located in the following indices: ";
  for (int ind = 0; ind < MAX_ARR_SIZE; ind++) {
    if (userInputArr[ind] == minInt) {
      cout << ind << " ";
    }
  }
  cout << endl;

  return 0;
}

int minInArray(int arr[], int arrSize) {
  int smallestNum = arr[0];
  for (int ind = 0; ind < arrSize; ind++) {
    if (arr[ind] < smallestNum) {
      smallestNum = arr[ind];
    }
  }
  return smallestNum;
}
