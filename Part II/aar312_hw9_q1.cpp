#include <iostream>
#include <string.h>
using namespace std;

void fillArrWithZeros(int *arr, int arrSize);
// sets all array values to 0 prior to count;
void incrementArrLetterPosition(int arr[], char letter, int &wordcount);
// evalutes a letter and increments the value of its corresponding index in alphabet array (i.e 'a' => arr[0]= 1)
void printOccurrences(int arr[], int arrSize, int wordcount);
// prints table of letter frequency, alphabetically-- skips unseen letters;

int main() {
  const int ALPHABET_SIZE = 26;
  int alphabetFrequencyArr[ALPHABET_SIZE];
  string userInputStr = "";
  int wordCount = 1;

  cout << "Please enter a line of text: " << endl;
  getline(cin, userInputStr);

  fillArrWithZeros(alphabetFrequencyArr, ALPHABET_SIZE);
  for (int i = 0; i < userInputStr.length(); i++) {
    incrementArrLetterPosition(alphabetFrequencyArr, userInputStr[i], wordCount);
  }

  if (userInputStr.length() > 0) {
    printOccurrences(alphabetFrequencyArr, ALPHABET_SIZE, wordCount);
  } else {
    cout << "You must enter a line of text to continue." << endl;
  }
  return 0;
}

void fillArrWithZeros(int *arr, int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    *(arr + i) = 0;
  }
}

void incrementArrLetterPosition(int arr[], char letter, int &wordcount) {
  int asciiVal = letter;
  if (asciiVal >= int('a') && asciiVal <= int('z')) {
    asciiVal = asciiVal - int('a');
    arr[asciiVal]++;
  } else if (asciiVal >= int('A') && asciiVal <= int('Z')) {
    asciiVal = asciiVal - int('A');
    arr[asciiVal]++;
  } else if (asciiVal == int(' ')) {
    wordcount++;
  }
}

void printOccurrences(int arr[], int arrSize, int wordcount) {
  wordcount > 1 ? cout << wordcount << '\t' << "words" << endl : cout << wordcount << '\t' << "word" << endl;
  for (int i = 0; i < arrSize; i++) {
    if (arr[i] > 0) {
      char letter = i + int('a');
      cout << arr[i] << '\t' << letter << endl;
    }
  }
}