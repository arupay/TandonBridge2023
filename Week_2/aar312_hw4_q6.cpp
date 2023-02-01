#include <iostream>
using namespace std;

int main() {
  int userInput, evenDigitCount = 0, oddDigitCount = 0, currEvaluating, moduloResult;

  cout << "Please input a positive integer: ";
  cin >> userInput;

  for (int x = 1; x < userInput; x++) {
    currEvaluating = x;
    while (currEvaluating != 0) {
      moduloResult = currEvaluating % 10; // separate rightmost digit
      moduloResult % 2 == 0 ? evenDigitCount++ : oddDigitCount++;
      currEvaluating = currEvaluating / 10; //
    }
    if (evenDigitCount > oddDigitCount) {
      cout << x << endl;
    }
    evenDigitCount = 0;
    oddDigitCount = 0;
  }
  return 0;
}