#include <cmath>
#include <iostream>
#include <string>
using namespace std;

void analyzeDividors(int num, int &outCountDivs, int &outSumDivs);
bool isPerfect(int num);

int totalDivisors, totalSum, userInputM;

int main() {
  string perfectNumStr = "";
  string amicableNumStr = "";

  cout << "Please enter a number >=2 to generate a list of perfect numbers and amicable numbers up until that number." << endl;
  cin >> userInputM;

  for (int i = 1; i <= userInputM; i++) {
    analyzeDividors(i, totalDivisors, totalSum);
    if (isPerfect(i))
      perfectNumStr += to_string(i) + " ";
    if (totalSum < userInputM && totalSum > i) {
      int tempNum = totalSum, tempTotalDivisors, tempTotalSum;
      analyzeDividors(tempNum, tempTotalDivisors, tempTotalSum);
      if (tempTotalSum == i) {
        amicableNumStr += "(" + to_string(i) + ", " + to_string(tempNum) + ") ";
      }
      tempTotalDivisors = 0, tempTotalSum = 0;
    }
    totalDivisors = 0, totalSum = 0;
  }
  cout << perfectNumStr << endl;
  cout << amicableNumStr << endl;

  return 0;
}

void analyzeDividors(int num, int &outCountDivs, int &outSumDivs) {
  for (int i = 1; i <= sqrt(num); i++) {
    if (num % i == 0) {
      outCountDivs++;
      outSumDivs += i;
      int complementDivisor = num / i;
      if (num != complementDivisor) {
        outCountDivs++;
        outSumDivs += complementDivisor;
      }
    }
  }
}

bool isPerfect(int num) {
  return num == totalSum;
}