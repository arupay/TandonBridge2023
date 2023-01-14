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
