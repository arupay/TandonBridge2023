#include <iostream>
using namespace std;

// DEF RETURN TO THIS PROBLEM

int main() {
  int userInput, rows;
  string starLineTop, starLineBottom, hourglassShape;
  cout << "Please enter a positive integer to recieve an hourglass text image: " << endl;
  cin >> userInput;

  int amount_letters = userInput;
  int amount_spaces = 0;

  for (int i = 0; i < userInput; ++i) // as many rows as there are letters
  {
    for (int j = 0; j < amount_spaces; ++j) // print spaces
      std::cout << ' ';

    for (int k = 0; k < amount_letters; ++k) // print letters
      std::cout << 'A';

    if (i < userInput / 2) // top half of the hourglass
    {
      amount_letters -= 2; // decrease letters
      amount_spaces += 1;  // increase space
    }

    else // bottom half of the hourglass
    {
      amount_letters += 2; // increase letters
      amount_spaces -= 1;  // decrease space
    }

    std::cout << std::endl; // print newline
  }
  return 0;
}