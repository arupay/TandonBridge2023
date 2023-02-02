// Write a program that reads an integer greater or equal to 2, n and prints a shape of an-line hollow inverted pyramid of stars.

#include <iostream>
using namespace std;

// int main() {
//   int userInput;
//   cout << "Enter a number >= 2 to receive an inverted hollow pyramid image";
//   cin >> userInput;

//   char star = '*';
//   char space = ' ';
//   int lineLimit = userInput;
//   int topStarLimit = (userInput * 2) - 1;
//   int topSpaceLimit = 0;

//   for (int i = 0; i < userInput; i++) {
//     for (int j = 0; j < topSpaceLimit; j++) {
//       cout << space;
//     }
//     for (int j = 0; j < topStarLimit; j++) {
//       if (i == 0) {
//         cout << star;
//       } else {
//         if (j == 0 || j == topStarLimit - 1) {
//           cout << star;
//         } else {
//           cout << space;
//         }
//       }
//     }
//     cout << endl;

//     topSpaceLimit++;
//     topStarLimit -= 2;
//   }

//   return 0;
// }

int main() {
  int userInput, remainder, currEvaluating, sum = 0, innerProduct, digitFactorial;

  cout << "Please enter a positive integer: " << endl;
  cin >> userInput;

  currEvaluating = userInput;

  while (currEvaluating > 0) {
    innerProduct = 1;
    digitFactorial = currEvaluating % 10; // current digit to get factorial for
    while (digitFactorial > 0) {
      innerProduct *= digitFactorial;
      digitFactorial--;
    }
    sum += innerProduct;
    currEvaluating = currEvaluating / 10;
  }

  if (userInput == 0) {
    cout << userInput << " is not a factorian" << endl;
  } else if (userInput == sum) {
    cout << userInput << " is a factorian" << endl;
  } else {
    cout << userInput << " is not a factorian" << endl;
  }
  return 0;
}