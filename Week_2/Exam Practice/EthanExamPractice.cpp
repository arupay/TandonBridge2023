#include <iostream>
using namespace std;

/// make a hollowed out diamond made up of in order alphabet letters below is an example when n=5

//_ _ _ _ a
//_ _ _ b   b
//_ _ c       c
//_ d           d
// e              e
//_ d           d
//_ _ c       c
//_ _ _ b   b
//_ _ _ _ a

int main() {
  const char FIRSTLETTER = 'a';

  char space = '_', letter = FIRSTLETTER;
  int userInput, rows, letterLimit, spaceLimit;
  cout << "Please enter an integer > 2: ";
  cin >> userInput;

  rows = userInput * 2 - 1;
  spaceLimit = userInput - 1;
  letterLimit = 1;

  for (int i = 0; i < rows; i++) {
    for (int k = 0; k < spaceLimit; k++) {
      cout << space;
    }
    for (int k = 0; k < letterLimit; k++) {
      if (k == 0 || k == letterLimit - 1) {
        cout << letter;
      } else {
        cout << space;
      }
    }
    if (i < 4) {
      letter += 1;
      spaceLimit--;
      letterLimit += 2;
    } else {
      letter -= 1;
      spaceLimit++;
      letterLimit -= 2;
    }
    cout << endl;
  }
}
