#include <iostream>
using namespace std;

int *findMissing(int arr[], int n, int &resArrSize);
void printArr(int arr[], int size);
int main() {
  const int arr_size = 6;
  int arr_one[arr_size] = {3, 1, 3, 0, 6, 4}; // Missing 2,5

  const int arr_size_two = 6;
  int arr_two[arr_size_two] = {1, 1, 1, 1, 1, 1}; // Missing 0,2,3,4,5,6

  const int arr_size_three = 10;
  int arr_three[arr_size_three] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10}; // Missing 9

  int *testArr = NULL;
  int newSize;

  cout << "Original array1 is {3, 1, 3, 0, 6, 4}" << endl;
  testArr = findMissing(arr_one, arr_size, newSize);
  printArr(testArr, newSize);
  delete[] testArr;

  cout << "Original array2 is {1, 1, 1, 1, 1, 1}" << endl;
  testArr = findMissing(arr_two, arr_size_two, newSize);
  printArr(testArr, newSize);
  delete[] testArr;

  cout << "Original array3 is {0, 1, 2, 3, 4, 5, 6, 7, 8, 10}" << endl;
  testArr = findMissing(arr_three, arr_size_three, newSize);
  printArr(testArr, newSize);
  delete[] testArr;
  return 0;
}

void printArr(int arr[], int size) {
  cout << "This findMissing array contains the " << size << " missing values" << endl;
  for (int i = 0; i < size; i++) {
    cout << "At index: " << i << ", the value is: " << arr[i] << endl;
  }
  cout << "--------------------------------------" << endl;
}

int *findMissing(int arr[], int n, int &resArrSize) {
  int *tempArr;
  int *missingNumsArr;
  int missingNumsArrSize = n + 1;
  tempArr = new int[n + 1];
  for (int i = 0; i < n; i++) {
    if (tempArr[arr[i]] == 0) {
      tempArr[arr[i]] = 1;
      missingNumsArrSize--;
    }
  }
  missingNumsArr = new int[missingNumsArrSize];

  for (int i = 0, idx = 0; i < n + 1; i++) {
    if (tempArr[i] < 1) {
      missingNumsArr[idx] = i;
      idx++;
    }
  }
  delete[] tempArr;
  resArrSize = missingNumsArrSize;
  return missingNumsArr;
}
