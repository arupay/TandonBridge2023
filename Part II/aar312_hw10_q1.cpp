#include <iostream>
#include <string>

using namespace std;

string *createWordsArray(string sentence, int &outWordsArrSize);
// function takes in a string sentence, and an int outWordsArrSize.  It creates & returns an array of strings with all the words in the sentence and updates the int outWordsArrSize.
void printArray(string[], int size);

int main() {
  string userInputString;
  cout << "Please enter a sentence to print an array of words: " << endl;
  getline(cin, userInputString);
  string *tempArray;
  string *tempArray_two;

  int sentence_size;
  cout << "--------------------------------------" << endl;
  tempArray = createWordsArray(userInputString, sentence_size);
  printArray(tempArray, sentence_size);
  delete[] tempArray;

  return 0;
}

void printArray(string arr[], int size) {
  cout << "[";
  for (int i = 0; i < size; i++) {
    i != size - 1 ? cout << "\"" << arr[i] << "\", " : cout << "\"" << arr[i] << "\"";
  }
  cout << "]" << endl;
}

string *createWordsArray(string sentence, int &outWordsArrSize) {
  string *splitSentenceArr = NULL;
  int wordCount = 1;

  for (int i; i < sentence.length(); i++) {
    if (sentence[i] == ' ')
      wordCount++;
  }

  splitSentenceArr = new string[wordCount];
  int index = 0;
  for (int i = 0, j = 0; i < sentence.length(); i++) {
    if (sentence[i] == ' ') {
      splitSentenceArr[index] = sentence.substr(j, i - j);
      index++;
      j = i + 1;
    } else if (i == sentence.length() - 1) {
      splitSentenceArr[index] = sentence.substr(j);
    }
  }
  outWordsArrSize = index + 1;
  return splitSentenceArr;
}