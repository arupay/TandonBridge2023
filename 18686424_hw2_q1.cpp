#include <iostream>
using namespace std;

int main()
{
    int quarters, dimes, nickels, pennies, sum, dollarSum, leftoverCents;

    cout << "Please enter number of coins:" << endl;
    cout << "# of quarters:" << endl;
    cin >> quarters;
    cout << "# of dimes:" << endl;
    cin >> dimes;
    cout << "# of nickels:" << endl;
    cin >> nickels;
    cout << "# of pennies:" << endl;
    cin >> pennies;

    sum = pennies + (nickels * 5) + (dimes * 10) + (quarters * 25);
    dollarSum = sum / 100;     // type coercion
    leftoverCents = sum % 100; // remainder

    cout << "The total is " << dollarSum << " dollars and " << leftoverCents << " cents" << endl;
    return 0;
}