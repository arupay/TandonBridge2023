#include <iostream>
using namespace std;

int main() {
  int userInput, binaryEquiv = 0, base = 1, remainder;

  cout << "Enter a decimal number: " << endl;
  cin >> userInput;

  int currNumber = userInput;

  while (currNumber > 0) {
    int remainder = currNumber % 2;
    binaryEquiv = binaryEquiv + (remainder * base); // will effectly only add to binary if remainder > 0
    base = base * 10;                               // increase base by * 10 every loop (every time currNum can be divided by 2)
    currNumber = currNumber / 2;                    // update currNum
  }

  cout << "The binary representation of " << userInput << " is " << binaryEquiv << endl;

  return 0;
}
