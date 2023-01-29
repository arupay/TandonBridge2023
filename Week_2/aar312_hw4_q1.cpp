// Question	1:
// Write	two versions of	a	program	that	reads	a	positive	integer	n,	and	prints	the	first	n even	numbers.
// a) In	the	first,	use	a	while loop.
// b) In	the	second,	use	a	for loop.
// Each	section	should	interact	with	the	user	exactly as	it	shows	in	the	following	example:
// Please	enter	a	positive	integer: 3
// 2
// 4
// 6

#include <iostream>
using namespace std;

int main() {
  int userInputOne, count;
  cout << "PART A)" << endl;

  cout << "Please enter a positive integer: \n";
  cin >> userInputOne;

  count = 2;
  while (userInputOne > 0) {
    cout << count << endl;
    count += 2;
    userInputOne--;
  }

  cout << "------------------------------------" << endl;
  cout << "PART B)" << endl;

  int userInputTwo, counter;
  cout << "Please enter a positive integer: \n";
  cin >> userInputTwo;

  for (counter = 1; counter <= userInputTwo; counter++) {
    cout << counter * 2 << endl;
  }

  return 0;
}
