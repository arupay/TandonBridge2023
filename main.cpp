// FIRST INTRO PROGRAM
//
//  #include <iostream>
//  using namespace std;
//  int main()
//  {
//      int num1; // will hold first input
//      int num2; // will hold second input
//      int sum;  // will hold the sum

//     cout << "Please enter two numbers separated by a space:" << endl;
//     cin >> num1 >> num2;
//     sum = num1 + num2;
//     cout << num1 << " + " << num2 << " = " << sum << endl;
//     return 0;
// }44
//
// PROMPT WRITE A PROGRAM THAT DETERMINES # OF WEEKS + Leftover days after a days input
// #include <iostream>
// const int DAYS_IN_A_WEEK = 7;
// using namespace std;
// int main()
// {
//     int daysTraveled;
//     int fullWeeks, remainingDays;

//     cout << "Please enter the number of days you traveled:" << endl;482
//     cin >> daysTraveled;
//     fullWeeks = daysTraveled / DAYS_IN_A_WEEK;
//     remainingDays = daysTraveled % DAYS_IN_A_WEEK;
//     cout << daysTraveled << " days are " << fullWeeks << " weeks and " << remainingDays << " days." << endl;
//     return 0;
// }

/// WRITE FROM A PROGRAM THAT DETERMINES AREA OF CIRCLE AFTER READING RADIUS FROM THE USER

// #include <iostream>
// #include <cmath>
// using namespace std;

// int main()
// {
//     double radiusInput;
//     double areaOfCircle;

//     cout << "Please input the radius of your cicle: " << endl;
//     cin >> radiusInput;
//     areaOfCircle = M_PI * pow(radiusInput, 2);
//     cout << "Your area of a circle with a radius of " << radiusInput << " is " << areaOfCircle << endl;
//     return 0;
// }

// WRITE A PROGRAM THAT TAKES IN A LETTER AND RETURNS AN ASCII VALUE

// #include <iostream>
// using namespace std;

// int main()
// {
//     char inputChar;
//     int asciiVal;

//     cout
//         << "Pleaes enter a character: " << endl;
//     cin >> inputChar;
//     asciiVal = (int)inputChar;
//     cout << "The ASCII value of " << inputChar << " is " << asciiVal << endl;
//     return 0;
// }
// WRITE A PROGRAM THAT TAKES IN A lowercase LETTER and CONVERTS to UPPERCASE letter

// #include <iostream>
// using namespace std;

// int main()
// {
//     char lowerCaseChar;
//     char upperCaseEquivalent;
//     int offset;
//     cout << "Please enter a character to convert to uppercase:";
//     cin >> lowerCaseChar;

//     offset = (int)(lowerCaseChar - 'a');
//     upperCaseEquivalent = (char)('A' + offset);
//     ////FIND THE DISTANCE BETWEEN LETTER AND LOWER CASE A, AND ADD IT TO UPPERCASE A TO GET UPPERCASE
//     // EQUIVALENT.
//     // type casting int when saving offset is not necessary but good practice (would be coerced by default)
//     // type casting char when saving uppercase equivalent is NECESSARY

//     cout << "The Uppercase of " << lowerCaseChar << " is " << upperCaseEquivalent << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int userInput, absValue;
//     cout << "Please enter an integer:" << endl;
//     cin >> userInput;
//     absValue = userInput;
//     if (userInput < 0)
//         absValue = userInput * (-1);
//     cout << "|" << userInput << "| =" << absValue << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int userInput;
//     cout << "Please enter a positive integer:" << endl;
//     cin >> userInput;

//     if (userInput % 2 == 0)
//     {
//         cout << userInput << " is even." << endl;
//     }
//     else
//     {
//         cout << userInput << " is odd." << endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     char userCh;
//     cout << "Please enter a character:" << endl;
//     cin >> userCh;

//     if (userCh >= 'a' && userCh <= 'z')
//         cout << userCh << " is a lower case lettter" << endl;
//     else if (userCh >= 'A' && userCh <= 'Z')
//         cout << userCh << " is an upper case letter" << endl;
//     else if (userCh >= '0' && userCh <= '9')
//         cout << userCh << " is a digit" << endl;
//     else
//         cout << userCh << " is not alpha-numeric character" << endl;

//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     int hour24, minutes24;
//     int hour12, minutes12;
//     char temp;
//     string period;
//     cout << "Please enter the time in a 24 hour format" << endl;
//     cin >> hour24 >> temp >> minutes24;
//     minutes12 = minutes24;
//     if (hour24 >= 0 && hour24 <= 11)
//     {
//         period = "am";
//         if (hour24 == 0)
//             hour12 = 12;
//         else
//             hour12 = hour24;
//     }
//     else
//     {
//         period = "pm";
//         if (hour24 == 12)
//             hour12 = 12;
//         else
//             hour12 = hour24 - 12;
//     }
//     cout << hour24 << ":" << minutes24 << " is " << hour12 << ":" << minutes12 << " " << period << endl;
//     return 0;
// }

// Write a program that reads from a user a simple  mathetical expression (operators allowed +, -, / * and prints its value.)

// #include <iostream>
// using namespace std;

// int main()
// {
//     double arg1, arg2, res;
//     char op;

//     cout << "Please enter an expression in the form arg op arg2" << endl;
//     cin >> arg1 >> op >> arg2;

//     switch (op)
//     {
//     case '+':
//         res = arg1 + arg2;
//         cout << res << endl;
//         break;
//     case '-':
//         res = arg1 - arg2;
//         cout << res << endl;
//         break;
//     case '/':
//         if (arg2 != 0)
//         {
//             res = arg1 / arg2;
//             cout << res << endl;
//         }
//         else
//             cout << "illegal expression!" << endl;
//         break;
//     case '*':
//         res = arg1 * arg2;
//         cout << res << endl;
//         break;
//     default:
//         cout << "Illegal expression!" << endl;
//         break;
//     }
// }

// week 4 Iterative Statements

// int main() {

//   int userInput, count = 1;

//   cout << "Please enter a positive integer: " << endl;
//   cin >> userInput;

//   while (count <= userInput) {
//     cout << count << endl;
//     count++;
//   }
// }

// int main() {
//   int userInput;
//   cout << "Please enter a number: " << endl;
//   cin >> userInput;

//   for (int i = 1; i <= userInput; i++) {
//     cout << i << endl;
//   }
//   return 0;

// int main() {
//   int userInput, sum = 0, countDigits;
//   cout << "Enter a number and I shall return the sum of its parts: " << endl;
//   cin >> userInput;

//   countDigits = 0;

//   while (userInput > 0) {
//     sum += userInput % 10;
//     countDigits++;
//     userInput /= 10;
//   }
//   cout << "The sum is: " << sum << " and number of digits is: " << countDigits << endl;
//   return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {

//   int numOfStudents, gradeInput, sumOfGrades = 0;
//   double average;

//   cout << "Please enter the number of students in this class: \n";
//   cin >> numOfStudents;
//   cout << "Now enter the grades of each student: \n";

//   for (int count = 1; count <= numOfStudents; count++) {
//     cin >> gradeInput;
//     sumOfGrades += gradeInput;
//   }
//   average = (double)sumOfGrades / (double)numOfStudents; // MUST TYPE CAST
//   cout << average << endl;
// }

// #include <iostream>
// using namespace std;

// int main() {
//   bool seenEndOfInput; // When we choose flag name, must be a statement that can have yes or no answer.
//   int sum, numOfStudents;
//   int curr;
//   double average;

//   cout << "Enter the grades separated by a space" << endl;
//   cout << "end the sequence by typing -1" << endl;
//   sum = 0;
//   numOfStudents = 0;

//   seenEndOfInput = false;
//   while (!seenEndOfInput) {
//     cin >> curr;
//     if (curr == -1) {
//       seenEndOfInput = !seenEndOfInput;
//     } else {
//       sum += curr;
//       numOfStudents++;
//     }
//   }
//   average = double(sum) / double(numOfStudents);
//   cout << average << endl;
//   return 0;
// }
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//   int userInput;
//   string binaryRepresentation;

//   cout << "Please enter a positive number: \n";
//   cin >> userInput;
//   binaryRepresentation = "";

//   int leftover = userInput;

//   while (leftover > 0) {
//     int remainder = leftover % 2;
//     binaryRepresentation = to_string(remainder) + binaryRepresentation;
//     leftover = leftover / 2;
//   }

//   cout << binaryRepresentation << endl;
//   return 0;
// }

// #include <iostream>
// #include <time.h>
// using namespace std;

// int main() {

//   int secretNumber, userInput;

//   srand(time(NULL));
//   secretNumber = rand() % 20 + 1;

//   cout << "Please guess a secret number between 1-20: " << endl;
//   cin >> userInput;

//   while (userInput != secretNumber) {
//     if (userInput < secretNumber) {
//       cout << "The secret number is greater than the input. Guess again: " << endl;
//       cin >> userInput;
//     } else {
//       cout << "The secret number is smaller than the input. Guess again: " << endl;
//       cin >> userInput;
//     }
//   }
//   cout << "You got it! Congrats, it was " << secretNumber << endl;
// }
#include <iostream>
using namespace std;

int main() {
  int userInput;
  string starLine;
  cout << "Please enter a number and I will draw a hourglass" << endl;
  cin >> userInput;

  userInput = (2 * userInput) - 1;

  starLine = "";

  for (int i = 1; i <= userInput; i++) {
    starLine += "\n";
    for (int j = 1; j <= userInput; j++) {
      if (j < i || j > userInput) {
        starLine += " ";
      } else {
        starLine += "*";
      }
    }
  }
  cout << starLine << endl;
  return 0;
}