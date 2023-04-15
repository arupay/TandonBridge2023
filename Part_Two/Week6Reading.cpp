// #include <ctime>
// #include <iostream>
// using namespace std;

// int main() {

//   srand(time(0));

//   int die = rand() % 100 + 1;

//   cout
//       << die << endl;
// }

// #include <iostream>
// using namespace std;

// int factorial(int num);

// int main() {
//   int n, k, i, k_comb, nFact, kFact, n_kFact;
//   cout << "Please enter n and k (n>=k)" << endl;
//   cin >> n >> k;

//   nFact = factorial(n);
//   kFact = factorial(k);
//   n_kFact = factorial(n - k);
//   k_comb = nFact / (kFact * n_kFact);

//   cout << n << " choose " << k << " is ";
//   cout << k_comb << endl;

//   return 0;
// }

// int factorial(int num) {
//   int factRes, i;
//   factRes = 1;
//   for (i = 1; i <= num; i++) {
//     factRes *= i;
//   }
//   return factRes;
// }

// #include <iostream>
// using namespace std;

// int analyzeDigits(int num, int &outSum);

// int main() {

//   int num, countDigs, sumDigs;

//   cout << "Please enter a positive integer:" << endl;
//   cin >> num;

//   countDigs = analyzeDigits(num, sumDigs);

//   cout << num << " has " << countDigs << " digits and their sum is " << sumDigs << endl;
//   return 0;
// }

// int analyzeDigits(int num, int &outSum) {
//   int count, sum;
//   int currDig;

//   count = 0;
//   sum = 0;

//   while (num > 0) {
//     currDig = num % 10;
//     count++;
//     sum += currDig;
//     num = num / 10;
//   }
//   outSum = sum;
//   return count;
// }
// week 6

#include <iostream>
using namespace std;