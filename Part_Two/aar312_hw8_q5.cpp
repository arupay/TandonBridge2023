#include <iostream>
#include <string>
using namespace std;

int main() {
  string firstName, middleName, lastName;

  cout << "Please enter a first, middle, and last name to format -- all separated by a space: " << endl;
  cin >> firstName >> middleName >> lastName;
  middleName = middleName.substr(0, 1) + ". ";

  cout << lastName << ", " << firstName << " " << middleName << endl;

  return 0;
}

