#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int &arrSize);
void splitParity(int arr[], int arrSize);
void swapElements(int &x, int &y);
void printArray(int arr[], int arrSize);

int main() {
  int arr1[10] = {9, 2, 14, 12, -3};
  int arr1Size = 5;

  int arr2[10] = {21, 12, 6, 7, 14};
  int arr2Size = 5;

  int arr3[10] = {3, 6, 4, 1, 12};
  int arr3Size = 5;

  reverseArray(arr1, arr1Size);
  printArray(arr1, arr1Size);

  removeOdd(arr2, arr2Size);
  printArray(arr2, arr2Size);

  splitParity(arr3, arr3Size);
  printArray(arr3, arr3Size);

  return 0;
}

void printArray(int arr[], int arrSize) {
  int i;
  for (i = 0; i < arrSize; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

void swapElements(int &x, int &y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
}

void reverseArray(int arr[], int arrSize) {
  int idx, temp;
  for (idx = 0; idx < arrSize / 2; idx++) {
    swapElements(arr[arrSize - 1 - idx], arr[idx]);
  }
}

void removeOdd(int arr[], int &arrSize) {
  int currSize = 0, idx;
  for (idx = 0; idx < arrSize; idx++) {
    if (arr[idx] % 2 == 0 || arr[idx] % 2 == -0) {
      arr[currSize] = arr[idx];
      currSize++;
    }
  }
  arrSize = currSize;
}

void splitParity(int arr[], int arrSize) {
  for (int i = 0, j = 0; j < arrSize; j++) {
    if (arr[j] % 2 != 0) {
      swapElements(arr[j], arr[i]);
      i++;
    }
  }
}