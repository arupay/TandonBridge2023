#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

int main() {
  const int NUMBEROFGUESSES = 5;
  string comparativeString = "";
  int userGuess, rangeCeil = 100, rangeFloor = 1, randomNumber;

  srand(time(0));
  randomNumber = (rand() % 100) + 1;

  cout << "I thought of a number between 1 and 100! Try to guess it" << endl;
  for (int i = NUMBEROFGUESSES, currentGuess = 1; i >= 1; i--, currentGuess++) {
    cout << "Range:[" << rangeFloor << "," << rangeCeil << "], Number of guesses left: " << i << endl;
    cout << "Your guess: ";
    cin >> userGuess;

    if (userGuess >= rangeFloor && userGuess <= rangeCeil) { /// only change range if guess is within range
      if (randomNumber > userGuess) {
        rangeFloor = userGuess + 1;
        comparativeString = "bigger";
      } else if (randomNumber < userGuess) {
        rangeCeil = userGuess - 1;
        comparativeString = "smaller";
      }
    }

    if (userGuess == randomNumber) {
      cout << "Congrats! You guess my number in " << currentGuess << " guesses." << endl; // win case
      break;
    } else if (i == 1) {
      cout << "Out of guesses! My number is " << randomNumber << endl; // out of guesses case
    } else {
      cout << "Wrong! My number is " << comparativeString << endl; // else case
    }
  }
  return 0;
}