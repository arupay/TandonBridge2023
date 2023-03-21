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
// #include <iostream>
// using namespace std;

// int main() {
//   int userInput;
//   string starLine;
//   cout << "Please enter a number and I will draw a hourglass" << endl;
//   cin >> userInput;

//   userInput = (2 * userInput) - 1;

//   starLine = "";

//   for (int i = 1; i <= userInput; i++) {
//     starLine += "\n";
//     for (int j = 1; j <= userInput; j++) {
//       if (j < i || j > userInput) {
//         starLine += " ";
//       } else {
//         starLine += "*";
//       }
//     }
//   }
//   cout << starLine << endl;
//   return 0;
// }

// 2/28 LECTURE

//
// #include <iostream>
// using namespace std;

// int search(int arr[], int logicalSize, int x);
// int main() {
//   int testArr[6] = {10, 20, 03, 5, 1, 100};
//   int x;
//   cout << "Enter a search: ";
//   cin >> x;
//   cout << search(testArr, 6, x) << endl;
//   return 0;
// }
// int search(int arr[], int logicalSize, int x) {
//   for (int i = 0; i < logicalSize; i++) {
//     if (x == arr[i]) {
//       return i;
//     }
//   }
//   return -1;
// }

// ASCENDING ORDER SCENARIO

// #include <iostream>
// using namespace std;

// int searchAscending(int arr[], int logicalSize, int x);
// int main() {
//   int testArr[6] = {10, 20, 30, 40, 50, 60};
//   int x;
//   cout << "Enter a search: ";
//   cin >> x;
//   cout << searchAscending(testArr, 6, x) << endl;
//   return 0;
// }
// int searchAscending(int arr[], int logicalSize, int x) {
//   for (int i = 0; i < logicalSize && arr[i] <= x; i++) {
//     if (arr[i] == x) {
//       return i;
//     }
//   }
//   return -1;
// }
// #include <iostream>
// using namespace std;
// int main() {
//   int arr[5] = {10, 20, -3, 4, 6};

//   cout << arr[3] << endl;
//   cout << arr << endl;
//   return 0;
// }

// #include <iostream>
// using namespace std;

// void resizeArray(int *&arr, int currentSize, int newSize) {
//   // must pass the array pointer by reference because we will CHANGE it
//   int *temp = new int[newSize];
//   for (int i = 0; i < currentSize; i++) {
//     temp[i] = arr[i];
//   }
//   delete[] arr;
//   arr = temp;
// }

// int main() {
//   int size = 10;
//   int *arr = new int[size];
//   for (int i = 0; i < size; i++) {
//     arr[i] = i * 10;
//   }
//   // How can we add one more elment into this array if it is full?
//   // Lets write a funciton to resize this array.
//   int oneMore = 110;
//   int newSize = size * 2;
//   resizeArray(arr, size, newSize);
//   arr[size++] = oneMore;
//   size = newSize;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//   vector<int> v;
//   // declaration fo a vector!
//   for (int i = 0; i < 100; i++) {
//     v.push_back(i * 100);
//   }
//   // for (int i = 0; i < v.size(); i++) {
//   //   cout << v[i] + 1 << endl;
//   // }
//   for (int i : v)
//     cout << i << endl;

//   // v.size() is the size property of the vector!!
// }

// Webinar -3/01 Pointers & Heap Storage

// #include <iostream>
// using namespace std;

// int main() {
//   int x;
//   int *px;
//   x = 5;
//   px = &x;
//   // cout << x << endl;
//   // cout << px << endl;
//   // cout << *px << endl;
//   // cout << &px << endl;

//   x = 7;
//   *px = 9;
//   cout << x << endl;
//   cout << px << endl;
//   cout << *px << endl;
// }
// #include <iostream>
// using namespace std;

// int main() {
//   int x = 5;
//   int *px;
//   px = &x;
//   cout << *px << endl;  // 5
//   cout << px << endl;   // 5000 (PX HOLDS THE MEMORY ADDRESS OF X)
//   cout << ++px << endl; // 5004 (ADDS 4 BYTES TO PX--> Pointers knows to increment by int size val )
// }

// USE CASES FOR POINTERS

// 1) Extend the sytanx we have to work with arrays
//-- Call By Ref/ Call By Value
// 2) Alternate way to change the values of variables that are out of active scope.
// 3) Dynamic memory allocation
// 4) Organizing data in memory in linked structures.(Linked Lists & Trees)

// 1)EXTEND THE SYNTAX WE HAVE TO WORK WITH ARRAYS

// #include <iostream>
// using namespace std;

// void func1(int *pn) {
//   *pn = *pn + 1;
// }

// int main() {
//   int n = 5;
//   func1(&n);
//   cout << n << endl;
//   return 0;
// }

// Dynamic Memory Allocation

// #include <iostream>
// using namespace std;

// int main() {
//   int *ptr = NULL;
//   ptr = new int;

//   *ptr = 5;

//   cout << *ptr << endl;

//   delete ptr;
//   ptr = NULL;

//   return 0;
// }

// #include <iostream>
// using namespace std;
// int main() {

//   int *arr = NULL;
//   int n;
//   cout << "How many numbers do you need? " << endl;
//   cin >> n;
//   arr = new int[n];
//   for (int i = 0; i < n; i++) {
//     *(arr + i) = i * 10;
//     cout << arr[i];
//   }
//   delete[] arr;
//   arr = NULL;
// }

// #include <iostream>

// using namespace std;

// int main() {
//   double *ptr1 = new double[8]; // ptr1  points at heap array of doubles
//   for (int i = 0; i < 8; i++)
//     ptr1[i] = (i + 55) * 1.0;

//   double *ptr2 = NULL;
//   ++ptr1;                      // shifts pointer 1 head to point at 11.0
//   ptr2 = ptr1--;               // ptr2 points at 11/ ptr1 decrements by 1 ,points to 10
//   ++ptr2;                      // increments ptr2 to point at 12
//   cout << ptr2 - ptr1 << '\n'; // prints out 2 (INDEX 2 - INDEX 0)//OR TWO STEPS

//   return 0;
// }

// #include <iostream>
// using namespace std;

// // Suppose we have 3 versions of the SWAP fn()
// void swap(int *a, int *b) {
//   int x = *a;
//   *a = *b;
//   *b = x;
//   cout << "a: " << *a << "b: " << *b << endl;
// }

// int main() {
//   int n1 = 12, n2 = 5;
//   cout << "n1:  " << n1 << ", n2: " << n2 << endl;
//   swap(&n1, &n2);
//   cout << "AFTER SWAP FUNCTION: " << endl;
//   cout << "n1:  " << n1 << ", n2: " << n2 << endl;
//   return 0;
// }
// #include <iostream>
// using namespace std;

// int main() {
//   unsigned int i;
//   char *x;
//   char *a = new char[4];
//   for (i = 0; i < 4; ++i) {
//     a[i] = char(i + int('p'));
//   }
//   for (i = 0; i < 4; ++i)
//     cout << "A[" << i << "]==" << a[i] << endl;

//   x = a++; // X = A , THEN A IS INCREMEMENTED.
//   cout << *x << ' ' << a[0] << endl;
//   x = ++a; // A IS INCREMENTED, THEN ASSIGNED TO X.
//   cout << *x << ' ' << a[1] << endl;

//   delete[] a;
//   a = NULL;
//   return 0;
// }

// Recursion and Mathematical induction both conbine smaller instances to prove larger instances
// If we look at how we proof by induction we use an assumption of p on smalle rvalues in order to show that P is true on a larger value
// When we want to design a recursive algo:
//  Base Step
// SOLVE the problem for the smallest possibel input (Mirrors Induction)
// Inductive/Recursive Step
// Assume that when we call the funciton on smaller inputs it does its job
// Based on this assumption, find how to combine calls for msaller instances
// in order to solve problems for a smaller input

#include <iostream>
using namespace std;

void printAsc(int start, int end);
int main() {
  printAsc(1, 4);
}

void printAsc(int start, int end) {
  if (start == end) {
    cout << start << endl;
  } else {
    printAsc(start, end - 1);
    cout << end << endl;
  }
}
// printAsc(1,4) => 1 2 3 4 (With line Breaks.)