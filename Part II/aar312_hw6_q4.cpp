#include <cmath>
#include <iostream>
#include <string>
using namespace std;

void printDivisors(int num);

char SPACE = ' ';

int main() {
  int userInput;
  cout << "Please enter a positive intever >=2: ";
  cin >> userInput;

  printDivisors(userInput);

  return 0;
}

void printDivisors(int num) {
  string beginning = "";
  string end = "";
  for (int i = 0; i <= sqrt(num); i++) {
    if (num % i == 0) {
      int complementDivisor = num / i;
      if (i != complementDivisor) {
        beginning += to_string(i) + SPACE;
        end = to_string(complementDivisor) + SPACE + end;
      } else {
        beginning += to_string(i) + SPACE;
      }
    }
  }

  cout << beginning << end << endl;
}