// I  V  X   L   C    D    M
// 1  5  10  50  100  500  1000
//  No Limit on M
//  D, L, V at most once
//  C X I at most 4 times

// 18 -> XVIII
// 518 -> DXVIII
#include <iostream>
#include <string>
using namespace std;

int main() {
  int userInput, currNumber;
  char one = 'I', five = 'V', ten = 'X', fifty = 'L', oneHundred = 'C', fiveHundred = 'D', oneThousand = 'M';
  string romanEquivalent;

  cout << "Enter a decimal number: " << endl;
  cin >> userInput;

  romanEquivalent = "";
  currNumber = userInput;

  while (currNumber > 0) {
    if (currNumber >= 1000) {
      romanEquivalent += oneThousand;
      currNumber -= 1000;
    } else if (currNumber >= 500) {
      romanEquivalent += fiveHundred;
      currNumber -= 500;
    } else if (currNumber >= 100) {
      romanEquivalent += oneHundred;
      currNumber -= 100;
    } else if (currNumber >= 50) {
      romanEquivalent += fifty;
      currNumber -= 50;
    } else if (currNumber >= 10) {
      romanEquivalent += ten;
      currNumber -= 10;
    } else if (currNumber >= 5) {
      romanEquivalent += five;
      currNumber -= 5;
    } else {
      romanEquivalent += one;
      currNumber -= 1;
    }
  }

  cout << userInput << " is " << romanEquivalent << endl;

  return 0;
}
