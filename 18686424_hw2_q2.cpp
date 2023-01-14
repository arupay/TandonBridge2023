/*
Write a program that asks the user to enter an amount of money in the format of dollars andremaining cents. The program should calculate and print the minimum number of coins (quarters, dimes, nickels and pennies) that are equivalent to the given amount.

Your program should interact with the user exactly as it shows in the following example: Please enter your amount in the format of dollars and cents separated by a space:
4 37
4 dollars and 37 cents are:
17 quarters, 1 dimes, 0 nickels and 2 pennies
*/

#include <iostream>
using namespace std;

int main()
{
    int dollars, cents, quarters, dimes, nickels, pennies, totalInCents;

    cout << "Please enter the amount in the format of dollars and cents separated by a space:" << endl;
    cin >> dollars >> cents;

    totalInCents = (dollars * 100) + cents;

    quarters = totalInCents / 25;
    totalInCents %= 25;

    dimes = totalInCents / 10;
    totalInCents %= 10;

    nickels = totalInCents / 5;
    totalInCents %= 5;

    pennies = totalInCents;
    cout
        << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, and " << pennies << " pennies" << endl;
    return 0;
}