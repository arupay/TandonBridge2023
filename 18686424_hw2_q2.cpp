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