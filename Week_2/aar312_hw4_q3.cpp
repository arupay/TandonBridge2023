#include <iostream>
#include <string>
using namespace std;

int main() {
  int userInput;
  string binaryRepresentation;

  cout << "Enter a decimal number: " << endl;
  cin >> userInput;
  binaryRepresentation = "";

  int currNumber = userInput;

  while (currNumber > 0) {
    int remainder = currNumber % 2;
    binaryRepresentation = to_string(remainder) + binaryRepresentation;
    currNumber = currNumber / 2;
  }

  cout << "The binary representation of " << userInput << " is " << binaryRepresentation << endl;

  return 0;
}
