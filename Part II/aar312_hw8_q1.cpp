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

  cout << "The minimum value is " << minInt << ", and it is located in the following indices: ";
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
