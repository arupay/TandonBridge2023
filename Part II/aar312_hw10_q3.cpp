#include <iostream>
#include <vector>
using namespace std;

int main1();
int *intArrayBuilder(int &userInputInt, int &updateArrSize);
void searchArch(int arr[], int arrSize, int elementToSearch);
int main2();
vector<int> vectorBuilder(int userInput);
void searchVector(vector<int> numVec, int x);

int main() {
  int selectedFunctionToTest;
  cout << "Please enter 1 to test non-vector function, or 2 to test vector function" << endl;
  cin >> selectedFunctionToTest;
  selectedFunctionToTest == 1 ? main1() : main2();
  return 0;
}

int main1() {
  int userInputInt, userInputSearchInt;
  int newArrSize;
  int *userInputArr;
  cout << "Please enter a sequence of positive integers, each in a separate line. " << endl;
  cout << "End your input by typing -1." << endl;
  userInputArr = intArrayBuilder(userInputInt, newArrSize);
  cout << "Please enter the number you want to search." << endl;
  cin >> userInputSearchInt;
  searchArch(userInputArr, newArrSize, userInputSearchInt);

  return 0;
}
int *intArrayBuilder(int &userInputInt, int &updateArrSize) {
  int *userArr;
  int currInputCount = 0, maxUserArrSize = 1;
  bool continueSequence = true;
  userArr = new int[1];
  while (continueSequence) {
    cin >> userInputInt;
    if (userInputInt == -1) {
      continueSequence = false;
    } else if (userInputInt <= 0) {
      cout << "Please enter a positive integer or -1 to end the sequence." << endl;
    } else {
      if (currInputCount == maxUserArrSize) {
        int *largerIntArr;
        largerIntArr = new int[maxUserArrSize * 2];
        for (int i = 0; i < currInputCount; i++) {
          largerIntArr[i] = userArr[i];
        }
        delete[] userArr;
        userArr = largerIntArr;
        maxUserArrSize *= 2;
      }
      userArr[currInputCount] = userInputInt;
      currInputCount++;
    }
  }
  updateArrSize = maxUserArrSize;
  return userArr;
}

void searchArch(int arr[], int arrSize, int elementToSearch) {
  int foundCount = 0;
  int *foundArr;
  for (int i = 0; i < arrSize; i++) // Search for element occurrence
    if (arr[i] == elementToSearch)
      foundCount++;

  if (foundCount > 0) { // only build array if element was found
    foundArr = new int[foundCount];
    for (int i = 0, j = 0; i < arrSize; i++) {
      if (arr[i] == elementToSearch) {
        foundArr[j] = i + 1;
        j++;
      }
    }
    cout << elementToSearch << " shows in lines ";
    for (int i = 0; i < foundCount; i++) {
      cout << foundArr[i] << " ";
    }
    cout << endl;
    delete[] foundArr;
    foundArr = NULL;
  } else {
    cout << elementToSearch << " does not show in this sequence.";
  }
}

int main2() {
  int userInputInt, userInputSearchInt;
  int newArrSize;
  vector<int> userInputVec;
  cout << "Please enter a sequence of positive integers, each in a separate line. " << endl;
  cout << "End your input by typing -1." << endl;

  userInputVec = vectorBuilder(userInputInt);
  for (int i = 0; i < userInputVec.size(); i++) {
    cout << userInputVec[i] << ' ';
  }
  cout << endl;
  cout << "Please enter the number you want to search." << endl;
  cin >> userInputSearchInt;
  searchVector(userInputVec, userInputSearchInt);
  return 0;
}

vector<int> vectorBuilder(int userInput) {
  vector<int> userInputVec;
  bool continueSequence = true;
  while (continueSequence) {
    cin >> userInput;
    if (userInput == -1) {
      continueSequence = false;
    } else {
      userInputVec.push_back(userInput);
    }
  }
  return userInputVec;
}

void searchVector(vector<int> numVec, int x) {
  vector<int> foundAtLineVec;
  for (int i = 0; i < numVec.size(); i++) {
    if (numVec[i] == x) {
      foundAtLineVec.push_back(i + 1);
    }
  }
  if (foundAtLineVec.size() > 0) {
    cout << x << " shows in lines ";
    for (int i = 0; i < foundAtLineVec.size(); i++) {
      cout << foundAtLineVec[i] << " ";
    }
    cout << endl;
  } else {
    cout << x << " does not show in this sequence.";
  }
}