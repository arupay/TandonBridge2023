#include <iostream>
#include <string.h>
using namespace std;

void fillArrWithZeros(int *arr, int arrSize);
// fills all values in alphabet array with zeros
void incrementOrDecrementAlphIndex(int arr[], char letter, bool);
// increments or decrements corresponding alphabet array based on letter ascii value, and boolean argument. True for increment, false for decrement.
bool balancedArrayChecker(int arr[], int arrSize);
// a 'balanced' array is one where every letter incremented by the first string, has been subsequently decremented by the second string -- effectively 'zeroing' out every value in the array.

int main() {
  const int ALPHABET_SIZE = 26;
  int alphabetFrequencyArr[ALPHABET_SIZE];
  fillArrWithZeros(alphabetFrequencyArr, ALPHABET_SIZE);
  string firstUserInput = "", secondUserInput = "";

  cout << "This program will check to see if two sentences are anagrams." << endl;
  cout << "Please enter your first sentence: " << endl;
  getline(cin, firstUserInput);
  cout << "Please enter your second sentence: " << endl;
  getline(cin, secondUserInput);

  for (int i = 0; i < firstUserInput.length(); i++) {
    incrementOrDecrementAlphIndex(alphabetFrequencyArr, firstUserInput[i], true);
  }

  for (int i = 0; i < secondUserInput.length(); i++) {
    incrementOrDecrementAlphIndex(alphabetFrequencyArr, secondUserInput[i], false);
  }

  if (balancedArrayChecker(alphabetFrequencyArr, ALPHABET_SIZE))
    cout << "Yes, the two sentences are anagrams" << endl;
  else
    cout << "No, the two sentences are not anagrams" << endl;

  return 0;
}

void fillArrWithZeros(int *arr, int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    *(arr + i) = 0;
  }
}

void incrementOrDecrementAlphIndex(int arr[], char letter, bool command) {
  int asciiVal = letter;
  if (asciiVal >= int('a') && asciiVal <= int('z')) {
    asciiVal = asciiVal - int('a');
    command == true ? arr[asciiVal]++ : arr[asciiVal]--;
  } else if (asciiVal >= int('A') && asciiVal <= int('Z')) {
    asciiVal = asciiVal - int('A');
    command == true ? arr[asciiVal]++ : arr[asciiVal]--;
  }
}

bool balancedArrayChecker(int arr[], int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    if (arr[i] != 0) {
      return false;
    }
  }
  return true;
}