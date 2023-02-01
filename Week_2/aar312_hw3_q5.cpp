#include <iostream>
using namespace std;

int main() {
  const double POUND_TO_KILO = 0.453592;
  const double INCH_TO_METER = 0.0254;
  const double NORMAL_THRESHHOLD = 18.5;
  const double OVERWEIGHT_THRESHOLD = 25;
  const double OBESE_THRESHHOLD = 30;

  double weight, height, bodyMassIndex;

  cout << "Please enter weight (in pounds): " << endl;
  cin >> weight;
  cout << "Please enter height (in inches): " << endl;
  cin >> height;

  weight = weight * POUND_TO_KILO;
  height = height * INCH_TO_METER;
  bodyMassIndex = weight / (height * height);

  if (bodyMassIndex < 18.5)
    cout << "The weight status is: Underweight" << endl;
  else if (bodyMassIndex < 25)
    cout << "The weight status is: Normal";
  else if (bodyMassIndex < 30)
    cout << "The weight status is: Overweight";1
  else
    cout << "The weight status is: Obese";
}