#include <iostream>
using namespace std;

int main() {
  int userInput, evenCount = 0, oddCount = 0, currEvaluating, moduloResult;

  cout << "Please input a positive integer: ";
  cin >> userInput;

  for (int x = 1; x < userInput; x++) {
    currEvaluating = x;
    while (currEvaluating != 0) {
      moduloResult = currEvaluating % 10;
      currEvaluating = currEvaluating / 10;
      moduloResult % 2 == 0 ? evenCount++ : oddCount++;
    }
    if (evenCount > oddCount) {
      cout << x << endl;
    }
    evenCount = 0;
    oddCount = 0;
  }
  return 0;
}