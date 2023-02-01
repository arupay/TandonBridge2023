// Write two versions of a program that reads a sequence of positive integers from the user
// calculates their geometric mean, and prints the geometric mean.
// How can we input validate only positive numbers?

#include <cmath>
#include <iostream>
using namespace std;

int main() {

  int lengthOfSequence, inputNumberA, sequenceProductA = 1;
  double geometricMean;

  cout << "Please enter the length of the sequence" << endl;
  cin >> lengthOfSequence;

  for (int i = 1; i <= lengthOfSequence; i++) {
    cout << "Please enter your sequence: " << endl;
    cin >> inputNumberA;
    sequenceProductA = sequenceProductA * inputNumberA;
  }

  geometricMean = pow(sequenceProductA, 1.0 / lengthOfSequence);
  cout << "The geometric mean is: " << geometricMean << endl;

  cout << "-------------------------------------------------------------------\n";

  int inputNumberB, sequenceLengthB, sequenceProductB;
  bool signalEndOfSequence;
  double geometricMeanB;

  cout << "Please enter a non-empty sequence of positive integers, each one in a seaprate line. End your sequence by typing -1:" << endl;

  signalEndOfSequence = false;
  sequenceLengthB = 0;
  sequenceProductB = 1;

  while (signalEndOfSequence == false) {
    cin >> inputNumberB;
    if (inputNumberB == -1) {
      signalEndOfSequence = true;
    } else {
      sequenceProductB *= inputNumberB;
      sequenceLengthB++;
    }
  }

  geometricMeanB = pow(sequenceProductB, 1.0 / sequenceLengthB);
  cout << "The geometric mean is : " << geometricMeanB << endl;

  return 0;
}
