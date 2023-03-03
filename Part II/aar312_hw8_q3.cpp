#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int &arrSize);
void splitParity(int arr[], int arrSize);
void swapElements(int &x, int &y);

int main() {
  int arr1[10] = {9, 2, 14, 12, -3};
  int arr1Size = 5;

  removeOdd(arr1, arr1Size);

  for (int i = 0; i < arr1Size; i++) {
    cout << arr1[i] << ' ';
  }
  cout << endl;

  return 0;
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
    if (arr[idx] % 2 == 1 || arr[idx] % 2 == -1) {
      arr[currSize] = arr[idx];
      currSize++;
    }
  }
  arrSize = currSize + 1;
}

void splitParity(int arr[], int arrSize) {
  for (int i = 0, j = 0; j < arrSize; i++) {
    if (arr[j] % 2 == 1 || arr[j] == -1) {
      swapElements(arr[i], arr[j]);
      i++;
    }
  }
}
