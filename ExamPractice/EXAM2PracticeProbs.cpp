
#include <iostream>
#include <vector>
using namespace std;

// EXAM March 2nd 2023

// #include <iostream>
// using namespace std;

// int findMaxElement(int S[], int length, int &frequencyOfMax);
// int main() {
//   int freq = 0;
//   int freq2 = 1;
//   int numArr[8] = {-1, -2, -3, -4, -5, -6, -1, -1};
//   int numArr2[10] = {10, 20, 30, 40, 50, 60, 70, 80, 80, 80};

//   cout << findMaxElement(numArr, 8, freq) << endl;
//   cout << "-----------------" << freq << endl;
//   cout << findMaxElement(numArr2, 10, freq2) << endl;
//   cout << "-----------------" << freq2 << endl;
//   return 0;
// }

// int findMaxElement(int S[], int length, int &frequencyOfMax) {
//   frequencyOfMax = 1;
//   int max;
//   if (length == 1) {
//     return S[length - 1];
//   }

//   max = findMaxElement(S, length - 1, frequencyOfMax);

//   if (max > S[length - 1]) {
//     return max;
//   } else if (max == S[length - 1]) {
//     frequencyOfMax++;
//     return max;
//   } else {
//     frequencyOfMax = 1;
//     return S[length - 1];
//   }
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// void mergeSortedArrays(int S1[], int S2[], int n1, int n2, vector<int> &mergedArray);

// int main() {
//   int S1[6] = {-1, 5, 15, 17, 26, 44};
//   int S2[5] = {-10, 5, 24, 30, 50};
//   int n1 = 6;
//   int n2 = 5;
//   vector<int> mergedArray;

//   mergeSortedArrays(S1, S2, n1, n2, mergedArray);
//   for (int i = 0; i < mergedArray.size(); i++) {
//     cout << mergedArray[i] << " ";
//   }
// }

// void mergeSortedArrays(int S1[], int S2[], int n1, int n2, vector<int> &mergedArray) {

//   int j = 0;
//   int k = 0;
//   // int *largerArr = S1[n1 - 1] >= S2[n2 - 1] ? S1 : S2;
//   // cout << *largerArr << " IS LARGER" << endl;

//   while (j + k < n1 + n2) {
//     cout << S1[j] << " " << S2[k] << endl;
//     if (j != n1 && k != n2) {
//       if (S1[j] > S2[k]) {
//         mergedArray.push_back(S2[k]);
//         k++;
//       } else if (S1[j] == S2[k]) {
//         mergedArray.push_back(S1[j]);
//         j++;
//         k++;
//       } else {
//         mergedArray.push_back(S1[j]);
//         j++;
//       }
//     } else {
//       if (j == n1) {
//         mergedArray.push_back(S2[k]);
//         k++;
//       } else {
//         mergedArray.push_back(S1[j]);
//         j++;
//       }
//     }
//   }
// }

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// vector<string> inputStringVec(string &userString, int &specialChars, int &lowerCase);
// int main() {
//   string userInputStr = "1";
//   vector<string> userInputVec;
//   int specialCharsOnly = 0, lowercaseOnly = 0;
//   cout << "Enter a non-tempty sequence of Strings.  Each string should be in a separate line and consists only of lowercase English letters and/or special characters @, #, $, !, &. To indicate the end of the input, enter an empty string in one line. " << endl;
//   userInputVec = inputStringVec(userInputStr, specialCharsOnly, lowercaseOnly);

//   for (int i = 0; i < userInputVec.size(); i++) {
//     cout << userInputVec[i] << endl;
//   }
//   cout << "Special characters: " << specialCharsOnly << endl;
//   cout << "Lowercaseonly characters: " << lowercaseOnly << endl;

//   return 0;
// }

// vector<string> inputStringVec(string &userString, int &specialChars, int &lowerCase) {
//   vector<string> inputVec;
//   string filteredStr = "";
//   while (userString.length()) {
//     getline(cin, userString);
//     if (userString.length() > 0) {
//       for (int i = 0; i < userString.length(); i++) {
//         if (int(userString[i]) >= 'a' && int(userString[i]) <= 'z') {
//           filteredStr += userString[i];
//         }
//       }
//       if (filteredStr.length() > 0 && filteredStr.length() == userString.length()) {
//         lowerCase++;
//         inputVec.push_back(filteredStr);
//         filteredStr = "";
//       } else if (filteredStr.length() == 0) {
//         specialChars++;
//       } else {
//         inputVec.push_back(filteredStr);
//         filteredStr = "";
//       }
//     }
//   }
//   return inputVec;
// }

// #include <iostream>
// using namespace std;

// int findIndex(int S[], int x, int left, int right);
// int main() {
//   int numArr[8] = {10, 15, 20, 25, 28, 40, 55, 90};
//   int foundOrNot;

//   foundOrNot = findIndex(numArr, 90, 0, 7);

//   cout << foundOrNot << endl;
// }
// int findIndex(int S[], int x, int left, int right) {
// int newRight;
// if (S[right] > x && S[left] < x) {
//   return -1; // out of range
// }
// if (left == right) {
//   return S[left] == x ? left : -1;
// }
// newRight = findIndex(S, x, left, right - 1);
// if (S[right] == x) {
//   return right;
// } else {
//   return newRight;
// }
//   int mid;
//   if (left > right) {
//     return -1;
//   } else {
//     mid = (left + right) / 2;
//     if (x == S[mid]) {
//       return mid;
//     } else if (x > S[mid]) {
//       return findIndex(S, x, mid + 1, right);
//     } else {
//       return findIndex(S, x, left, mid - 1);
//     }
//   }
// }
// REVISE TO RECURSIVE BINARY SEARCH
// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> createStudentIdVec(int &studentId, int &grade, int &highestGrade);

// int main() {
//   vector<int> highestGradesIDVec;
//   int studentId, grade, highestGrade;
//   cout << "Please enter a non-empty sequence of lines. Each line should have a student ID and their grade (0-100), separated by a space, to indicate the end of input pleae enter -1 as student ID" << endl;

//   highestGradesIDVec = createStudentIdVec(studentId, grade, highestGrade);

//   for (int i = 0; i < highestGradesIDVec.size(); i++) {
//     cout << highestGradesIDVec[i] << " ";
//   }
//   cout << endl;
//   return 0;
// }
// vector<int> createStudentIdVec(int &studentId, int &grade, int &highestGrade) {
//   int currMax = 0;
//   vector<int> topStudentsIdVec;
//   bool continueSeq = true;
//   while (continueSeq) {
//     cin >> studentId;
//     if (studentId == -1) {
//       continueSeq = false;
//     } else {
//       cin >> grade;
//       if (grade > currMax) {
//         topStudentsIdVec.clear();
//         currMax = grade;
//         topStudentsIdVec.push_back(studentId);
//       } else if (grade == currMax) {
//         topStudentsIdVec.push_back(studentId);
//       }
//     }
//   }
//   highestGrade = currMax;
//   return topStudentsIdVec;
// }

// int palindromeDistance(int *arr, int n);
// int main() {
//   int paliDis;
//   int numArr[6] = {1, 3, 6, 6, 3, 1};
//   paliDis = palindromeDistance(numArr, 6);
//   cout << paliDis << endl;
//   return 0;
// }

// int palindromeDistance(int *arr, int n) {
//   cout << *arr++ << endl;
//   cout << *arr++ << endl;
//   cout << *arr++ << endl;

//   return 0;
// }

// void printAscending(int start, int end);

// int main() {
//   printAscending(1, 10);
// }

// void printAscending(int start, int end) {
//   if (start == end) {
//     cout << start << endl;
//   } else {
//     int mid = (start + end) / 2;
//     printAscending(start, mid);
//     printAscending(mid + 1, end);
//   }
// }
// int factorial(int n);
// int main() {
//   cout << factorial(4) << endl;
//   return 0;
// }
// int factorial(int n) {
//   if (n == 1) {
//     return 1;
//   } else {
//     return n * factorial(n - 1);
//   }
// }

// bool areAllEven(int arr[], int n);
// int main() {
//   int arr[5] = {3, 5, 2, 2};
//   cout << areAllEven(arr, 5);
//   return 0;
// }
// bool areAllEven(int arr[], int n) {
//   bool res;
//   if (n == 1) {
//     return (arr[0] % 2 == 0);
//   } else {
//     res = areAllEven(arr, n - 1);
//     if (res == true) {
//       return arr[n - 1] % 2 == 0;
//     } else {
//       return false;
//     }
//   }
// }

// int findSumDigits(int n);
// int main() {
//   cout << findSumDigits(5) << endl;
// }
// int findSumDigits(int n) {
//   if (n < 10) {
//     return n;
//   } else {
//     int temp;
//     temp = findSumDigits(n / 10);
//     return temp + n % 10;
//   }
// }

// int sumArray(int *arr, int logicalSize);
// int main() {
//   int size = 10;
//   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   cout << sumArray(arr, size) << endl;
// }
// int sumArray(int *arr, int logicalSize) {
//   if (logicalSize == 1) {
//     return arr[logicalSize - 1];
//   } else {
//     int temp = sumArray(arr + 1, logicalSize - 1);
//     return arr[0] + temp;
//   }
// }

// int powerFunction(int a, int n);
// int main() {
//   cout << powerFunction(2, 5);
// }

// int powerFunction(int a, int n) {
//   if (n == 1) {
//     return a;
//   }
//   if (n == 0) {
//     return 1;
//   }
//   if (n % 2 == 0) {
//     int temp = powerFunction(a, n / 2);
//     return temp * temp;
//   } else {
//     int temp = powerFunction(a, (n - 1) / 2);
//     return temp * temp * a;
//   }
// }

// void printTriangle(int n) {
//   const char star = '*';
//   if (n == 1) {
//     cout << star << endl;
//   } else {
//     for (int i = 0; i < n; i++) {
//       cout << star;
//     }
//     cout << endl;
//     printTriangle(n - 1);
//   }
// }

// void printOppositeTriangles(int n) {
//   const char star = '*';
//   const int height = 2;
//   const int totalHeight = n * 2;
//   bool ascending = false;
//   if (n == 1) {
//     cout << "printing 1 the value of " << n << endl;
//     ascending = true;
//     cout << star << endl;
//   } else {
//     for (int i = 0; i < n; i++) {
//       cout << star;
//     }
//     cout << endl;
//     printOppositeTriangles(n - 1);
//   }
//   if (ascending == true) {
//     cout << "We are here finally" << n << endl;
//     if (n == 1) {
//       cout << star << endl;
//     } else {
//       printOppositeTriangles(n - 1);
//       for (int i = 0; i < n; i++) {
//         cout << star;
//       }
//       cout << endl;
//     }
//   }
// }

// int main() {
//   printOppositeTriangles(4);
//   return 0;
// }

// int main() {
//   // count =1
//   // nxtidx = 0
//   const int arrSize = 6;
//   int arr[arrSize] = {0, 0, 2, 2, 0, 0};

//   int lastIndexReplaced;
//   ;
//   for (int i = 0, j = 0; i < arrSize; i++) {
//     if (arr[i] > 0) {
//       arr[j] = arr[i];
//       j++;
//     }
//     lastIndexReplaced = j;
//   }
//   cout << lastIndexReplaced << "HERE" << endl;

//   while (lastIndexReplaced < arrSize) {
//     arr[lastIndexReplaced] = 0;
//     lastIndexReplaced++;
//   }

//   for (int i = 0; i < arrSize; i++) {
//     cout << arr[i] << endl;
//   }
//   return 0;
// }

// int maxZeroLength(int arr[], int arrSize, int startIdx) {
//   if (startIdx == arrSize) {
//     return 0;
//   }
//   int currLargest = 0;
//   while (startIdx < arrSize && arr[startIdx++] == 0) {
//     currLargest++;
//   }
//   return max(currLargest, maxZeroLength(arr, arrSize, startIdx));
// }

// int main() {

//   int arr[6] = {0, 0, 1, 0, 0, 0};

//   cout << maxZeroLength(arr, 6, 0) << endl;
// }

// bool sortedOrNot(int arr[], int arrLength) {
//   if (arrLength <= 1)
//     return true;

//   if (arr[arrLength - 1] < arr[arrLength - 2]) {
//     return false;
//   } else {
//     return sortedOrNot(arr, arrLength - 1);
//   }
// }

// bool sortedOrNotEthan(int arr[], int arrLength) {
//   if (arrLength == 1 || arrLength == 0)
//     return true;
//   if (arr[0] <= arr[1])
//     return sortedOrNotEthan(arr + 1, arrLength - 1);

//   return false;
// }

// int main() {
//   int arr[5] = {1, 2, 3, 4, 5};
//   cout << "MINE" << boolalpha << sortedOrNot(arr, 5) << endl;
//   cout << "ETHAN" << boolalpha << sortedOrNotEthan(arr, 5) << endl;
//   return 0;
// }

// int fib(int n) {
//   if (n <= 1) {
//     return n;
//   }
//   return fib(n - 1) + fib(n - 2);
// }
