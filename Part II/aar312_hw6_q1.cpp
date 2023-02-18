#include <iostream>
using namespace std;

int fib(int n);

int main() {
  int userInput, fibElementByPosition;

  cout << "Please enter a positive integer: " << endl;
  cin >> userInput;

  fibElementByPosition = fib(userInput);

  cout << fibElementByPosition << endl;
  return 0;
}

int fib(int n) {
  int i, numA = 1, numB = 1, temp, fibNum;
  if (n < 3) {
    return numA;
  }
  for (i = 3; i <= n; i++) {
    fibNum = numA + numB;
    temp = numB;
    numB = fibNum;
    numA = temp;
  }
  return fibNum;
}