#include <ctype.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
  const double PEAK_HOUR_RATE = .40;
  const double OFF_PEAK_HOUR_RATE = .25;
  const double WEEKEND_RATE = .15;
  int hour24, minutes24, callLength;
  char temp;
  string dayOfTheWeek;
  double longDistanceCost;

  cout << "Please enter the first two letters of day of the week the call was made (i.e. 'Mo' if Monday): " << endl;
  cin >> dayOfTheWeek;
  cout << "Please enter the time the call was started in 24 hr format (i.e. 16:30): " << endl;
  cin >> hour24 >> temp >> minutes24;
  cout << "Please enter the the length of the call in minutes: " << endl;
  cin >> callLength;

  if (dayOfTheWeek == "Mo" || dayOfTheWeek == "Tu" || dayOfTheWeek == "We" || dayOfTheWeek == "Th" || dayOfTheWeek == "Fr") {
    if ((hour24 >= 8 && hour24 <= 17) || (hour24 == 18 && minutes24 == 0)) {
      longDistanceCost = PEAK_HOUR_RATE * callLength;
    } else {
      longDistanceCost = OFF_PEAK_HOUR_RATE * callLength;
    }
  } else if (dayOfTheWeek == "Sa" || dayOfTheWeek == "Su") {
    longDistanceCost = WEEKEND_RATE * callLength;
  } else {
    longDistanceCost = -1; // day could not be matched
  }

  cout.setf(ios::fixed);
  cout.precision(2);
  if (longDistanceCost == -1) {
    cout << "Invalid Inputs. Please review your inputs." << endl;
  } else {
    cout << "This call cost: $" << longDistanceCost << endl;
  }

  return 0;
}