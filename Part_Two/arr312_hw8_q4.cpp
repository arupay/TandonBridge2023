#include <ctime>
#include <iostream>
using namespace std;

const int HARDCODED_PIN[5] = {1, 2, 3, 4, 5};
const int PAD_LIMIT = 10;
int SCRAMBLED_PINPAD[PAD_LIMIT];

void fillScrambledPad(int arr[], int arrSize);
void readArray(int arr[], int arrSize);
int encryptedPin(int arr[], int arrSize);

int main() {
  int userInput;
  srand(time(0));
  fillScrambledPad(SCRAMBLED_PINPAD, PAD_LIMIT);

  cout << "Please enter your PIN according to the following mapping" << endl;
  cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << endl;
  cout << "NUM: ";
  readArray(SCRAMBLED_PINPAD, PAD_LIMIT);
  cin >> userInput;
  if (userInput == encryptedPin(SCRAMBLED_PINPAD, PAD_LIMIT)) {
    cout << "Your PIN is correct" << endl;
  } else {
    cout << "Your PIN is not correct" << endl;
  }
  return 0;
}

void fillScrambledPad(int arr[], int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    int randomNumber = rand() % 3 + 1;
    arr[i] = randomNumber;
  }
}

void readArray(int arr[], int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int encryptedPin(int arr[], int arrSize) {
  int encrypted = 0;
  for (int i = 0; i < 5; i++) {
    encrypted = encrypted * 10 + arr[HARDCODED_PIN[i]];
  }
  return encrypted;
}