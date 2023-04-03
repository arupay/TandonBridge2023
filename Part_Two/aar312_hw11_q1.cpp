#include <iostream>
using namespace std;

void printTriangle(int n);
void printOppositeTriangle(int n);
void printRuler(int n);

int main() {
  cout << "PRINT TRIANGLE FUNCTION" << endl;
  cout << "--------------------------" << endl;
  printTriangle(4);
  cout << "PRINT OPPOSITE SIDE FUNCTION" << endl;
  cout << "--------------------------" << endl;
  printOppositeTriangle(4);
  cout << "--------------------------" << endl;
  printRuler(4);
}

void printTriangle(int n) {
  const char star = '*';
  if (n == 1) {
    cout << star << endl;
  } else {
    for (int i = 0; i < n; i++) {
      cout << star;
    }
    cout << endl;
    printTriangle(n - 1);
  }
}

void printOppositeTriangle(int n) {
  const char star = '*';
  if (n == 1) {
    cout << star << endl;
    cout << star << endl;
  } else {
    for (int i = 0; i < n; i++) {
      cout << star;
    }
    cout << endl;
    printOppositeTriangle(n - 1);
    for (int i = 0; i < n; i++) {
      cout << star;
    }
    cout << endl;
  }
}

void printRuler(int n) {
  const char mark = '-';
  if (n < 1) {
    return;
  } else {
    printRuler(n - 1);
    for (int i = 0; i < n; i++) {
      cout << mark;
    }
    cout << endl;
    printRuler(n - 1);
  }
}