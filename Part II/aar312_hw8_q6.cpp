#include <iostream>
#include <string.h>

using namespace std;

bool stringDigitChecker(string word);
string replaceWithEncryption(string str);

int main() {
  string userInputStr;
  int userInputStrElements = 0;
  cout << "Please enter a line of text: " << endl;
  getline(cin, userInputStr);

  for (int i = 0; i < userInputStr.length(); i++) {
    if (userInputStr[i] == ' ')
      userInputStrElements++;
  }

  string wordArr[userInputStrElements + 1];

  for (int currLetter = 0, wordLength = 0, idx = 0; currLetter < userInputStr.length(); currLetter++) {
    if (userInputStr[currLetter] == ' ' || currLetter == userInputStr.length() - 1) {
      string isolatedWord = currLetter == userInputStr.length() - 1 ? userInputStr.substr(currLetter - wordLength, wordLength + 1) : userInputStr.substr(currLetter - wordLength, wordLength);
      wordArr[idx] = stringDigitChecker(isolatedWord) ? replaceWithEncryption(isolatedWord) : isolatedWord;
      wordLength = 0;
      idx++;
    } else {
      wordLength += 1;
    }
  }

  for (int i = 0; i < userInputStrElements + 1; i++) {
    cout << wordArr[i] << " ";
  }
  cout << endl;
  return 0;
}

bool stringDigitChecker(string word) {
  int countingLetters = 0;
  for (int i = 0; i < word.length(); i++) {
    if (word[i] >= '0' && word[i] <= '9')
      countingLetters++;
  }
  return countingLetters == word.length();
}

string replaceWithEncryption(string word) {
  for (int i = 0; i < word.length(); i++)
    word[i] = 'x';
  return word;
}
