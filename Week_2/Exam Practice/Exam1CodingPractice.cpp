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

// int main() {
//   int userInput, remainder, currEvaluating, sum = 0, innerProduct, digitFactorial;

//   cout << "Please enter a positive integer: " << endl;
//   cin >> userInput;

//   currEvaluating = userInput;

//   while (currEvaluating > 0) {
//     innerProduct = 1;
//     digitFactorial = currEvaluating % 10; // current digit to get factorial for
//     while (digitFactorial > 0) {
//       innerProduct *= digitFactorial;
//       digitFactorial--;
//     }
//     sum += innerProduct;
//     currEvaluating = currEvaluating / 10;
//   }

//   if (userInput == 0) {
//     cout << userInput << " is not a factorian" << endl;
//   } else if (userInput == sum) {
//     cout << userInput << " is a factorian" << endl;
//   } else {
//     cout << userInput << " is not a factorian" << endl;
//   }
//   return 0;
// }

// int main() {

// write  a program that reads a lower case inLetter, and prints a shape of an isosceles triangle, the first letter always lower case a,
// up to the letter inputed alternating between lowercase and uppcase

// example for input 'd'
//_ _ _ a
//_ _ B B B
//_ c c c c c
// D D D D D D D
//   int LOWERCASE_START = 97;
//   int UPPERCASE_START = 65;

//   char inputLetter, space;
//   int lineLimit, starLimit, spaceLimit, currentLetter;
//   cout << "Please enter a lowercase letter" << endl;
//   cin >> inputLetter;

//   space = ' ';

//   currentLetter = LOWERCASE_START;
//   lineLimit = int(inputLetter + 1) - LOWERCASE_START; // +1 because i want to include that letter.

//   spaceLimit = lineLimit - 1;
//   starLimit = 1;

//   for (int j = 0; j < lineLimit; j++) {
//     for (int i = 0; i < spaceLimit; i++) {
//       cout << space;
//     }
//     for (int i = 0; i < starLimit; i++) {
//       cout << char(currentLetter);
//     }
//     spaceLimit--;
//     starLimit += 2;
//     j % 2 == 0 ? currentLetter -= 31 : currentLetter += 33;
//     cout << endl;
//   }
// }

// int main() {

//   int ONE_FOOT = 12; // inches
//   int ONE_YARD = 36; // inches

//   int day = 1, sumInInches = 0, yards, feet, inches, userInput;

//   do {
//     cout << "Enter the number of inches the snail traveled on day #" << day << " , or type -1 if they reached their destination: " << endl;
//     cin >> userInput;
//     if (userInput > 0) {
//       sumInInches += userInput;
//       day++;
//     }
//   } while (userInput != -1);
//   day = day - 1;

//   yards = sumInInches / ONE_YARD;
//   sumInInches %= ONE_YARD;
//   feet = sumInInches / ONE_FOOT;
//   sumInInches %= ONE_FOOT;
//   inches = sumInInches;

//   cout << "In " << day << " days, the snail traveled " << yards << " yards, " << feet << " feet and " << inches << " inches." << endl;

//   return 0;
// }