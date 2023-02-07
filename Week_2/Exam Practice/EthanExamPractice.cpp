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
        if (j == x || j + x == userInput - 1) {
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

// int main() {

/*
 *
 ***
 *****
 */
// int userInput;

// cout << "Enter an input" << endl;
// cin >> userInput;

// int spaceCount = userInput - 1;
// int starCount = 1;

// for (int rows = 0; rows < userInput; rows++) {
//   for (int k = 0; k < spaceCount; k++) {
//     cout << " ";
//   }
//   for (int k = 0; k < starCount; k++) {
//     if (rows == userInput - 1) {
//       cout << "*";
//     } else {
//       if (k == 0 || k == starCount - 1) {
//         cout << "*";
//       } else {
//         cout << " ";
//       }
//     }
//   }
//   spaceCount--;
//   starCount += 2;
//   cout << endl;
// }
// return 0;
// }

// int main() {
//   int userInput, rowTimesColum;
//   cout << "Please enter a positive integer: " << endl;
//   cin >> userInput;

//   int rows = userInput * 2;

//   int stars = (userInput * 2) - 1;
//   int spaces = 0;

//   for (int x = 0; x < rows; x++) {
//     for (int k = 0; k < spaces; k++) {
//       cout << "_";
//     }
//     for (int j = 0; j < stars; j++) {
//       cout << "*";
//     }
//     cout << "STARS:" << stars << "SPACES:" << spaces;
//     if (x < userInput - 1) {
//       stars = stars - 2;
//       spaces++;
//     } else if (x > userInput - 1) {
//       stars = stars + 2;
//       spaces--;
//     }
//     cout << endl;
//   }
// }

int main() {

  int userInput = 5;

  int spaceLimit = 4;
  int letterLimit = 1;

  for (int x = 0; x < userInput; x++) {
    for (int y = 0; y < spaceLimit; y++) {
      cout << "_";
    }
    for (int y = 0; y < letterLimit; y++) {
      if (y == 0 || y == letterLimit - 1) {
        cout << "*";
      } else {
        cout << "_";
      }
    }
    spaceLimit--;
    letterLimit += 2;
    cout << endl;
  }
}