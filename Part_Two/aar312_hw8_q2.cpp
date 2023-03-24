#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main() {
  string userInputString;

  cout << "Please enter a word:" << endl;
  cin >> userInputString;

  if (isPalindrome(userInputString)) {
    cout << userInputString << " is a palindrome." << endl;
  } else {
    cout << userInputString << " is not a palindrome." << endl;
  }

  return 0;
}

bool isPalindrome(string str) {
  string strReverse;
  for (int indx = str.length() - 1; indx >= 0; indx--) {
    strReverse += str[indx];
  }
  return strReverse == str;
}
