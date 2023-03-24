#include <iostream>
#include <string>
using namespace std;
int main() {
  int graduationYear, currentYear, yearsUntilGraduation;
  string studentName;

  cout << "Please enter your name: " << endl;
  cin >> studentName;
  cout << "Please enter your graduation year: " << endl;
  cin >> graduationYear;
  cout << "Please enter current year: " << endl;
  cin >> currentYear;

  yearsUntilGraduation = graduationYear - currentYear;

  if (yearsUntilGraduation <= 0)
    cout << studentName << " you are a Graduated.\n";
  else if (yearsUntilGraduation == 1)
    cout << studentName << " you are a Senior.\n";
  else if (yearsUntilGraduation == 2)
    cout << studentName << " you are a Junior.\n";
  else if (yearsUntilGraduation == 3)
    cout << studentName << " you are a Sophmore.\n";
  else if (yearsUntilGraduation == 4)
    cout << studentName << " you are a Freshman.\n";
  else
    cout << studentName << " you are a not in college yet.\n";

  return 0;
}