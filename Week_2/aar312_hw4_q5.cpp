#include <iostream>
using namespace std;

int main() {
  int userInput;
  cout << "Please enter a positive integer to recieve an hourglass text image: " << endl;
  cin >> userInput;

  char star = '*';
  char space = ' ';
  int lineLimit = userInput;
  int bottomSpacesLimit = userInput - 1;
  int bottomStarLimit = 1;
  int topSpacesLimit = 0;
  int topStarLimit = (userInput * 2) - 1;

  for (int k = 0; k < lineLimit; k++) {
    for (int j = 0; j < topSpacesLimit; j++) {
      cout << space;
    }
    for (int j = 0; j < topStarLimit; j++) {
      cout << star;
    }
    cout << endl;
    topSpacesLimit++;
    topStarLimit -= 2;
  }

  for (int i = 0; i < lineLimit; i++) {

    for (int j = 0; j < bottomSpacesLimit; j++) {
      cout << space;
    }

    for (int j = 0; j < bottomStarLimit; j++) {
      cout << star;
    }
    cout << endl;
    bottomSpacesLimit--;
    bottomStarLimit += 2;
  }
  return 0;
}