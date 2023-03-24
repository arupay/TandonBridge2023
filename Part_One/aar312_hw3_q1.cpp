

#include <iostream>
#include <string>
using namespace std;

int main() {
  double firstItemPrice, secondItemPrice, taxRate, basePrice, priceAfterDiscount, finalPrice;
  char clubCard;

  cout << "Enter the price of first item:" << endl;
  cin >> firstItemPrice;
  cout << "Enter the price of second item:" << endl;
  cin >> secondItemPrice;
  basePrice = firstItemPrice + secondItemPrice;
  cout << "Does the customer have a club card? (Y/N)" << endl;
  cin >> clubCard;
  cout << "Enter tax rate, e.g. 5.5 for 5.5% tax:" << endl;
  cin >> taxRate;

  if (firstItemPrice > secondItemPrice) {
    priceAfterDiscount = firstItemPrice + (secondItemPrice / 2);
  } else {
    priceAfterDiscount = secondItemPrice + (firstItemPrice / 2);
  }
  if (clubCard == 'y' || clubCard == 'Y')
    priceAfterDiscount *= .9;

  finalPrice = priceAfterDiscount * ((taxRate / 100) + 1);

  cout.setf(ios::fixed);
  cout.precision(2);
  cout
      << "Base price: " << basePrice << "\n"
      << "Price after discounts: " << priceAfterDiscount << "\n"
      << "Total price: " << finalPrice << endl;

  return 0;
}