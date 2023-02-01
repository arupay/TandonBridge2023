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
  string one = "I", five = "V", ten = "X", fifty = "L", oneHundred = "C", fiveHundred = "D", oneThousand = "M", romanEquivalent;

  cout << "Enter a decimal number: " << endl;
  cin >> userInput;

  romanEquivalent = "";
  currNumber = userInput;

  while (currNumber > 0) {
    if (currNumber >= 1000) {
      romanEquivalent += "M";
      currNumber -= 1000;
    } else if (currNumber >= 500) {
      romanEquivalent += "D";
      currNumber -= 500;
    } else if (currNumber >= 100) {
      romanEquivalent += "C";
      currNumber -= 100;
    } else if (currNumber >= 50) {
      romanEquivalent += "L";
      currNumber -= 50;
    } else if (currNumber >= 10) {
      romanEquivalent += "X";
      currNumber -= 10;
    } else if (currNumber >= 5) {
      romanEquivalent += "V";
      currNumber -= 5;
    } else {
      romanEquivalent += "I";
      currNumber -= 1;
    }
  }

  cout << userInput << " is " << romanEquivalent << endl;

  return 0;
}
