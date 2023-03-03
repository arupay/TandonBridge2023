#include <iostream>
using namespace std;

int main() {
  const int FLOOR_ROUND = 1;
  const int CEILING_ROUND = 2;
  const int ROUND = 3;

  int operationType;
  double userInput;
  int finalValue;
  cout << "Please enter a Real number: " << endl;
  cin >> userInput;
  cout << " Choose your rounding method: \n 1. Floor round \n 2. Ceiling round \n 3. Round to the nearest whole number " << endl;
  cin >> operationType;

  switch (operationType) {
  case FLOOR_ROUND:
    userInput > 0 ? finalValue = int(userInput) : finalValue = int(userInput - .9999);
    cout << int(userInput) << endl;
    break;
  case CEILING_ROUND:
    userInput > 0 ? finalValue = int(userInput + .99999) : finalValue = int(userInput);
    cout << finalValue << endl;
    break;
  case ROUND:
    userInput > 0 ? finalValue = int(userInput + .50) : finalValue = int(userInput - .50);
    cout << finalValue << endl;
  default:
    cout << "Please enter a valid operation" << endl;
    break;
  }

  return 0;
}