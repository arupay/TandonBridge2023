// #include <ctime>
// #include <iostream>
// using namespace std;

// int main() {

//   srand(time(0));

//   int die = rand() % 100 + 1;

//   cout
//       << die << endl;
// }

#include <iostream>
using namespace std;

int factorial(int num);

int main() {
  int n, k, i, k_comb, nFact, kFact, n_kFact;
  cout << "Please enter n and k (n>=k)" << endl;
  cin >> n >> k;

  nFact = factorial(n);
  kFact = factorial(k);
  n_kFact = factorial(n - k);
  k_comb = nFact / (kFact * n_kFact);

  cout << n << " choose " << k << " is ";
  cout << k_comb << endl;

  return 0;
}

int factorial(int num) {
  int factRes, i;
  factRes = 1;
  for (i = 1; i <= num; i++) {
    factRes *= i;
  }
  return factRes;
}