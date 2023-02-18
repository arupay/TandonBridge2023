#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

const char SPACE_SYMBOL = ' ';

int main() {
  int height, m;
  char symbol;
  cout << "Please enter your tree height and the symbol you wish to use separated by a space (i.e. '5 %')" << endl;
  cin >> height >> symbol;

  printPineTree(height, symbol);
  return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
  int width = (n * 2) - 1;
  int spaces = n - 1;

  for (int row = 0; row < n; row++) {
    for (int shift = 0; shift < m; shift++) {
      cout << SPACE_SYMBOL;
    }
    for (int col = 0; col < width; col++) {
      if (col >= spaces && col <= width - spaces - 1) {
        cout << symbol;
      } else {
        cout << SPACE_SYMBOL;
      }
    }
    spaces--;
    cout << endl;
  }
}

void printPineTree(int n, char symbol) {
  int i, base;
  int distanceM = n - 1;
  for (i = n, base = 2; i > 0; i--, base++) {
    printShiftedTriangle(base, distanceM, symbol);
    distanceM--;
  }
}