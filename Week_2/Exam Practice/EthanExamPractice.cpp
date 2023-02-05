#include <iostream>
#include <string>
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

// int main() {

//   char space = '_', letter = 'a';
//   int userInput, rows, letterLimit, spaceLimit;
//   cout << "Please enter an integer > 2: ";
//   cin >> userInput;

//   rows = userInput * 2 - 1;
//   spaceLimit = userInput - 1;
//   letterLimit = 1;

//   for (int i = 0; i < rows; i++) {
//     for (int k = 0; k < spaceLimit; k++) {
//       cout << space;
//     }
//     for (int k = 0; k < letterLimit; k++) {
//       if (k == 0 || k == letterLimit - 1) {
//         cout << letter;
//       } else {
//         cout << space;
//       }
//     }
//     if (i < 4) {
//       letter += 1;
//       spaceLimit--;
//       letterLimit += 2;
//     } else {
//       letter -= 1;
//       spaceLimit++;
//       letterLimit -= 2;
//     }
//     cout << endl;
//   }
// }

int main() {
  int userInput;
  char money = '$', hash = '#';
  cout << "Please enter an integer positive: " << endl;
  cin >> userInput;
  int separation = 1;

  for (int x = 0; x < userInput; x++) {
    for (int j = 0; j < userInput; j++) {
      if (x == 0 || x == userInput - 1) {
        cout << hash;
      } else if (j == 0 || j == userInput - 1) {
        cout << hash;
      } else {
        if (j == separation - 1 || j == userInput - (separation)) {
          cout << money;
        } else {
          cout << "_";
        }
      }
    }
    cout << endl;
    separation++;
  }
}

// int main() {
//   const string FIZZ = "Fizz";
//   const string BUZZ = "Buzz";
//   const string FIZZBUZZ = "Fizzbuzz";

//   int userInput;
//   string output;
//   cout << "Please enter a number";
//   cin >> userInput;

//   for (int i = 1; i <= userInput; i++) {
//     if (i % 3 == 0 && i % 5 == 0) {
//       cout << FIZZBUZZ;
//     } else if (i % 3 == 0) {
//       cout << FIZZ;
//     } else if (i % 5 == 0) {
//       cout << BUZZ;
//     } else {
//       cout << i;
//     }
//     cout << endl;
//   }
//   return 0;
// }