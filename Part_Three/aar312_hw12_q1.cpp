/** CH12 #7: Write a checkbook balancing program. The program will read in, from the console, the following for all checks that were not cashed as of the last time you balanced your checkbook:

 * the number of each check (int),
 * the amount of the check (double),
 * and whether or not it has been cashed (1 or 0, boolean in the array).

Use an array with the class as the type. The class should be a class for a check. There should be three member variables to record the check number, the check amount, and whether or not the check was cashed.

The class for a check will have a member variable of type Money (as defined on page 662 in the book; Display 11.9) to record the check amount.
So, you will have a class used within a class. The class for a check should have accessor and mutator functions as
well as constructors and functions for both input and output of a check.
In addition to the checks, the program also reads all the deposits (from the console; cin), the old and the new account balance (read this in from the user at the console cin). You may want another array to hold the deposits. The new account balance should be the old balance plus all deposits, minus all checks that have been cashed.

 The program outputs the total of the checks cashed, the total of the deposits, what the new balance should be, and how much this figure differs from what the bank says the new balance is. It also outputs two lists of checks: the checks cashed since the last time you balanced your checkbook and the checks still not cashed. [ edit: if you can, Display both lists of checks in sorted order from lowest to highest check number.] **/

//Prompt user to enter "Check #/ Amount / 1 OR 0"
    // Insert into array of classes type Check (member variables check #, check amount (class of type Money), cashedBool)
    // User can enter "0, 0, 0" to end input sequence (Can user type "END"?)
//MoneyClass
    //IN BOOK
//CheckClass
    //Public (validateCheck, getGet#, getAmount, getCashedBool).
    //Private (check#, amount (Money), bool)
    //Friend (operator << to print check data)

#include <iostream>
using namespace std;



class Money {
private: long all_cents;
public:
    //Overloaded Ops
    friend Money operator+(const Money& amount1, const Money& amount2);
    //Returns the sum of values 1 & 2
    friend Money operator-(const Money& amount1, const Money& amount2);
    //Returns amount1 minus amount2
    friend Money operator-(const Money& amount);
    //Returns the negative of the value of the amount
    friend bool operator==(const Money& amount1, const Money& amount2);
    //Returns true if amount1 and amount true have the same value, otherwise false
    friend bool operator<(const Money& amount1, const Money& amount2);
    //Returns true if amount1 is less than amount2, false otherwise.

    //Constructors
    Money(long dollars, int cents);
    //Initializes object w/ dollars and cells as per arguments.
    // If negative, both dollars and cents should be negative
    Money(long dollars);
    //Initializes object so its value is $xx.00
    Money();
    //Initializes zero dollar/cents value as $0.00

    //Methods
    double get_value() const;
    //Returns the amount of money recorded in the data portion oft he calling object.
    friend istream& operator>>(istream& ins, Money& amount);
    //Overloads >> operator so it can be used to input values of type Money.
    //Notation for inputting negative amounts is as in -$100,00.
    //Precondition: If ins is a file input stream, then ins has already been connected to a file.
    friend istream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to input values of type Money
    //Precedes each output value of type money with a dollar isgn
    //Precondition: if outs is af ile type outstream, then ins has already been connected to a  file
};

int main(){

    cout<<"Welcome to Tony's Check Balancer V1.0"<<endl;
    cout<<"To begin please your checks each in a separate line, with each check containing 3 fields:"<<endl;
    cout<<"The check number, the check amount, and whether or not the check has been cashed."<<endl;
    cout<<"Check numbers should only be positive values"<<endl;
    cout<<"Do NOT include currency characters ($) when entering check amount."<<endl;
    cout<<"Enter '1' for cashed checks, or '0' for uncashed checks"<<endl;
    cout<<"Example input for a cashed check of check-number 5, in the amount of $100.32: '5 100.32 1'"<<endl;
    cout<<"When you have entered all your checks, enter '0 00.00 0' to end the input sequence"<<endl;


    return 0;
}