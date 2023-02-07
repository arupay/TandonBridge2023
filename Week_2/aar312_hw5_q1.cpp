#include <iostream>
using namespace std;

int main() {
  int userInput, rowTimesColum;
  cout << "Please enter a positive integer: " << endl;
  cin >> userInput;

  for (int row = 1; row <= userInput; row++) {
    for (int col = 1; col <= userInput; col++) {
      int rowTimesCol = row * col;
      cout << rowTimesCol << "\t";
    }
    cout << '\n';
  }
  return 0;
}