#include <iostream>
using namespace std;

double eApprox(int n);
//  calls factorial(n, denominator, sum) to update current denominator factorial value & sum.
//  returns the value of e

void factorial(int n, int &factorialDenomValue, double &sumOfFactorials);
// updates the current factorial denominator value in the sequence (factorialDenomValue)
// updates  the total sum of the sequence (sumOfFactorials)

const double E_CONSTANT = 1.0;
double sumOfFactorials;
int factorialDenomValue = 1;

int main() {
  cout.precision(30);
  for (int n = 1; n <= 15; n++) {
    cout << "n = " << n << '\t' << eApprox(n) << endl;
  }
  return 0;
}

double eApprox(int n) {
  factorial(n, factorialDenomValue, sumOfFactorials);
  double e = E_CONSTANT + sumOfFactorials;
  return e;
}

void factorial(int num, int &factorialDenomValue, double &sumOfFactorials) {
  factorialDenomValue *= num;
  sumOfFactorials += (E_CONSTANT / factorialDenomValue);
}
