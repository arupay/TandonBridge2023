#include <iostream>
using namespace std;

const int MININDAY = 60 * 24;
const int MININHOUR = 60;

int main()
{
    int johnDays, johnHours, johnMinutes, billDays, billHours, billMinutes, totalMinutes, days, hours, minutes;

    cout
        << "Please enter the number of days John has worked:" << endl;
    cin >> johnDays;
    cout << "Please enter the number of hours John has worked:" << endl;
    cin >> johnHours;
    cout << "Please enter the number of minutes John has worked:" << endl;
    cin >> johnMinutes;
    cout << "Please enter the number of days Bill has worked:" << endl;
    cin >> billDays;
    cout << "Please enter the number of hours Bill has worked:" << endl;
    cin >> billHours;
    cout << "Please enter the number of minutes Bill has worked:" << endl;
    cin >> billMinutes;

    totalMinutes = johnMinutes + billMinutes + (johnHours * MININHOUR) + (billHours * MININHOUR) + (johnDays * MININDAY) + (billDays * MININDAY);

    days = totalMinutes / MININDAY;
    totalMinutes %= (MININDAY * days);

    hours = totalMinutes / MININHOUR;
    totalMinutes %= (MININHOUR * hours);

    minutes = totalMinutes;

    cout << "The total time both of them worked together is: " << days << ", " << hours << ", and " << minutes << "." << endl;
    return 0;
}