#include <iostream>
using namespace std;

int *getPosNums1(int *arr, int arrSize, int &outPosArrSize);
// returns the base address of the array (containing the positive numbers), and updates the output parameter outPosArrSize with the array’s logical size.

int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr);
//  returns the base address of the array (containing the positive numbers), and uses the pointer outPosArrSizePtr to update the array’s logical size.

void getPosNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize);
// updates the output parameter outPosArr with the base address of the array (containing the positive numbers), and the output parameter outPosArrSize with the array’s logical size.

void getPosNums4(int *arr, int arrSize, int **outPosArrPtr, int *outPosArrSizePtr);
// uses the pointer outPosArrPtr to update the base address of the array (containing the positive numbers), and the pointer outPosArrSizePtr to update the array’s logical size.
void printArr(int arr[], int arrSize);

int main() {
  const int ARR_SIZE = 6;
  int numArr[6] = {3, -1, -3, 0, 6, 4};

  int posNumsOneSize;
  int *posNumsOne = getPosNums1(numArr, ARR_SIZE, posNumsOneSize);
  cout << "Original Array:  ";
  printArr(numArr, ARR_SIZE);
  cout << "Array *getPosNums1 function: ";
  printArr(posNumsOne, posNumsOneSize);

  cout << "------------------------------" << endl;

  int posNumsTwoSize;
  int *posNumsTwo = getPosNums2(numArr, ARR_SIZE, &posNumsTwoSize);
  cout << "Original Array:  ";
  printArr(numArr, ARR_SIZE);
  cout << "Array *getPosNums2 function: ";
  printArr(posNumsTwo, posNumsTwoSize);

  cout << "------------------------------" << endl;

  int posNumsThreeSize;
  int *posNumsThree;
  getPosNums3(numArr, ARR_SIZE, posNumsThree, posNumsThreeSize);
  cout << "Original Array:  ";
  printArr(numArr, ARR_SIZE);
  cout << "Array *getPosNums3 function: ";
  printArr(posNumsThree, posNumsThreeSize);

  cout << "------------------------------" << endl;

  int posNumsFourSize;
  int *posNumsFour;
  getPosNums4(numArr, ARR_SIZE, &posNumsFour, &posNumsFourSize);
  cout << "Original Array:  ";
  printArr(numArr, ARR_SIZE);
  cout << "Array *getPosNums4 function: ";
  printArr(posNumsFour, posNumsFourSize);

  cout << "------------------------------" << endl;

  delete[] posNumsOne;
  posNumsOne = nullptr;
  delete[] posNumsTwo;
  posNumsTwo = nullptr;
  delete[] posNumsThree;
  posNumsThree = nullptr;
  delete[] posNumsFour;
  posNumsFour = nullptr;

  return 0;
}

void printArr(int arr[], int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}
int *getPosNums1(int *arr, int arrSize, int &outPosArrSize) {
  int currPosIndex = 0;
  int *posArr = new int[arrSize];
  for (int i = 0; i < arrSize; i++) {
    if (arr[i] > 0) {
      posArr[currPosIndex] = arr[i];
      currPosIndex++;
    }
  }
  outPosArrSize = currPosIndex;
  return posArr;
}

int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr) {
  int currPosIndex = 0;
  int *posArr = new int[arrSize];
  for (int i = 0; i < arrSize; i++) {
    if (arr[i] > 0) {
      posArr[currPosIndex] = arr[i];
      currPosIndex++;
    }
  }
  *outPosArrSizePtr = currPosIndex;
  return posArr;
}

void getPosNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize) {
  int currPosIndex = 0;
  int *posArr = new int[arrSize];
  for (int i = 0; i < arrSize; i++) {
    if (arr[i] > 0) {
      posArr[currPosIndex] = arr[i];
      currPosIndex++;
    }
  }
  outPosArr = posArr;
  outPosArrSize = currPosIndex;
}

void getPosNums4(int *arr, int arrSize, int **outPosArrPtr, int *outPosArrSizePtr) {
  int currPosIndex = 0;
  int *posArr = new int[arrSize];
  for (int i = 0; i < arrSize; i++) {
    if (arr[i] > 0) {
      posArr[currPosIndex] = arr[i];
      currPosIndex++;
    }
  }
  *outPosArrPtr = posArr;
  *outPosArrSizePtr = currPosIndex;
}