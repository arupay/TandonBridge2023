#include <iostream>
using namespace std;

void oddKeepsEvensFlip(int arr[], int arrSize);
void printArr(int arr[], int arrSize);

int main() {
  const int SIZE = 6;

  // Interpreted part 2 requirements as user prompt testing in main() -- if hard testing was intended, comment out 12-19, and uncomment 21-35

  int userInputArr[SIZE], currInt;
  cout << "Please enter 6 integers separated by a space: " << endl;
  for (int index = 0; index < SIZE; index++) {
    cin >> currInt;
    userInputArr[index] = currInt;
  }
  oddKeepsEvensFlip(userInputArr, SIZE);
  printArr(userInputArr, SIZE);

  // int testArr1[SIZE] = {1, 2, 3, 4, 5, 6};
  // oddKeepsEvensFlip(testArr1, SIZE);
  // printArr(testArr1, SIZE);

  // int testArr2[SIZE] = {10, 11, 20, 21, 30, 31};
  // oddKeepsEvensFlip(testArr2, SIZE);
  // printArr(testArr2, SIZE);

  // int testArr3[SIZE] = {5, 2, 11, 7, 6, 4};
  // oddKeepsEvensFlip(testArr3, SIZE);
  // printArr(testArr3, SIZE);

  // int testArr4[SIZE] = {-5, -2, -11, -7, -6, -4};
  // oddKeepsEvensFlip(testArr4, SIZE);
  // printArr(testArr4, SIZE);

  return 0;
}

void printArr(int arr[], int arrSize) {
  cout << "Here is the array after oddsKeepEvensFlip" << endl;
  for (int i = 0; i < arrSize; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

void oddKeepsEvensFlip(int arr[], int arrSize) {
  int *temp = new int[arrSize];
  int evenPosition = arrSize - 1;
  int oddPosition = 0;
  for (int i = 0; i < arrSize; i++) {
    if (arr[i] % 2 == 1 || arr[i] % 2 == -1) {
      temp[oddPosition] = arr[i];
      oddPosition++;
    } else {
      temp[evenPosition] = arr[i];
      evenPosition--;
    }
  }

  for (int i = 0; i < arrSize; i++) {
    arr[i] = temp[i];
  }
  delete[] temp;
}
