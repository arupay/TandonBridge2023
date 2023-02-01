#include <iostream>
using namespace std;

// DEF RETURN TO THIS PROBLEM

int main() {
  int userInput, rows;
  string starLineTop, starLineBottom, hourglassShape;
  cout << "Please enter a positive integer to recieve an hourglass text image: " << endl;
  cin >> userInput;

  for (int i = userInput; i >= 1; i--) {
    for (int j = 1; j <= userInput - i; j++) {
      cout << "  ";
    }
    for (int k = 1; k <= 2 * i - 1; k++) {
      cout << " *";
    }
    cout << endl;
  }
  for (int i = 1; i <= userInput; i++) {
    for (int j = 1; j <= userInput - i; j++) {
      cout << "  ";
    }
    for (int k = 1; k <= 2 * i - 1; k++) {
      cout << " *";
    }
    cout << endl;
  }

  return 0;
}