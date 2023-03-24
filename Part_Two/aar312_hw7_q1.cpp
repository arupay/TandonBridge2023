#include <iostream>
#include <string>
using namespace std;

int printMonthCalendar(int numOfDays, int startingDay);
void printYearCalender(int year, int startingDay);
bool leapYearChecker(int year);

const string MONDAY = "Mon \t";
const string TUESDAY = "Tue \t";
const string WEDNESDAY = "Wed \t";
const string THURSDAY = "Thr \t";
const string FRIDAY = "Fri \t";
const string SATURDAY = "Sat \t";
const string SUNDAY = "Sun";

const string JAN = "January ";
const string FEB = "February ";
const string MAR = "March ";
const string APR = "April ";
const string MAY = "May ";
const string JUN = "June ";
const string JUL = "July ";
const string AUG = "August ";
const string SEP = "September ";
const string OCT = "October ";
const string NOV = "November ";
const string DEC = "December ";

const int THIRTY_DAYS = 30;
const int THIRTYONE_DAYS = 31;
const int NON_LEAP_FEB = 28;
const int LEAP_FEB = 29;

int userInputYear, userInputStartDay;
int daysInCurrentMonth;

int main() {
  cout << "Please input a year, and the number of the first day of that year separated with a space to generate a calendar: " << endl;
  cout << "For example for the year 2000, starting on Sunday, ('2000 7'):" << endl;
  cin >> userInputYear >> userInputStartDay;

  printYearCalender(userInputYear, userInputStartDay);
  return 0;
}

bool leapYearChecker(int year) {
  return ((year % 4 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

void printYearCalender(int year, int startingDay) {
  for (int month = 0; month < 12; month++) {
    switch (month) {
    case 0:
      cout << JAN << year << endl;
      daysInCurrentMonth = THIRTYONE_DAYS;
      break;
    case 1:
      cout << FEB << year << endl;
      daysInCurrentMonth = leapYearChecker(userInputYear) ? LEAP_FEB : NON_LEAP_FEB;
      break;
    case 2:
      cout << MAR << year << endl;
      daysInCurrentMonth = THIRTYONE_DAYS;
      break;
    case 3:
      cout << APR << year << endl;
      daysInCurrentMonth = THIRTY_DAYS;
      break;
    case 4:
      cout << MAY << year << endl;
      daysInCurrentMonth = THIRTYONE_DAYS;
      break;
    case 5:
      cout << JUN << year << endl;
      daysInCurrentMonth = THIRTY_DAYS;
      break;
    case 6:
      cout << JUL << year << endl;
      daysInCurrentMonth = THIRTYONE_DAYS;
      break;
    case 7:
      cout << AUG << year << endl;
      daysInCurrentMonth = THIRTYONE_DAYS;
      break;
    case 8:
      cout << SEP << year << endl;
      daysInCurrentMonth = THIRTY_DAYS;
      break;
    case 9:
      cout << OCT << year << endl;
      daysInCurrentMonth = THIRTYONE_DAYS;
      break;
    case 10:
      cout << NOV << year << endl;
      daysInCurrentMonth = THIRTY_DAYS;
      break;
    default:
      cout << DEC << year << endl;
      daysInCurrentMonth = THIRTYONE_DAYS;
      break;
    }
    // prints out the current calendar and updates the staringDay value for the next iteration.
    startingDay = printMonthCalendar(daysInCurrentMonth, startingDay) % 7 + 1;
  }
}

int printMonthCalendar(int numOfDays, int startingDay) {
  int week, currentDay, lastDayOfMonth, dayOfMonth = 1;

  // calculates the number of total spaces (empty or numbered) needed for the current month
  int totalDaySpacesNeeded = startingDay + numOfDays - 1;

  // calculates the number of weeks (rows) needed to accodomate totalDaySpacesNeeded
  int numberOfWeeks = totalDaySpacesNeeded % 7 == 0 ? totalDaySpacesNeeded / 7 : (totalDaySpacesNeeded / 7) + 1;

  cout << MONDAY << TUESDAY << WEDNESDAY << THURSDAY << FRIDAY << SATURDAY << SUNDAY << endl;

  for (week = 0; week < numberOfWeeks; week++) {
    for (currentDay = 1; currentDay <= 7; currentDay++) {
      if ((currentDay < startingDay && week == 0) || dayOfMonth > numOfDays) {
        // if during the first week, the currentDay is not yet the first day of the month
        // or the dayOfMonth > numberOfDays allowed for this month, do not print a dayOfMonth.
        cout << " \t";
      } else {
        cout << dayOfMonth << '\t';
        // if we're at the last day of the month, save this current currentDay value (1-7) to lastDayOfMonth;
        lastDayOfMonth = (dayOfMonth == numOfDays) ? currentDay : 0;
        dayOfMonth++;
      }
    }
    cout << endl;
  }
  cout << endl;
  return lastDayOfMonth;
}
