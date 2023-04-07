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

//Pseudocode
//Prompt user to enter "Check #/ Amount / 1 OR 0"
    // Insert into array of classes type Check (member variables check #, check amount (class of type Money), cashedBool)
    // User can enter "0, 0, 0" to end input sequence (Can user type "END"?)
//MoneyClass
    //IN BOOK
//CheckClass
    //Public (validateCheck, getGet#, getAmount, getCashedBool).
    //Private (check#, amount (Money), bool)
    //Friend (operator << to print check data
//Accnt Class
    //checkbook
    //total balance?

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <vector>
using namespace std;



class Money {
public:
    //Overloaded Ops
    friend Money operator+(const Money& amount1, const Money& amount2);
    //Returns the sum of values 1 & 2
    friend Money operator-(const Money& amount1, const Money& amount2);
    //Returns amount1 minus amount2
    Money& operator +=(const Money& rhs);
    //Returns the sum of a + b as as the new value of a.
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
    Money(double amount);
    // Initializes object typed in double format (i.e. $23.21)
    Money();
    //Initializes zero dollar/cents value as $0.00

    //Methods
    double get_value() const;
    //Returns the amount of money recorded in the data portion oft he calling object.
    friend istream& operator>>(istream& ins, Money& amount);
    //Overloads >> operator so it can be used to input values of type Money.
    //Notation for inputting negative amounts is as in -$100,00.
    //Precondition: If ins is a file input stream, then ins has already been connected to a file.
    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to input values of type Money
    //Precedes each output value of type money with a dollar isgn
    //Precondition: if outs is af ile type outstream, then ins has already been connected to a  file
private:
    long all_cents;
};
int digit_to_int(char c);

class Check {
public:
    friend ostream& operator<<(ostream& outs, const Check& check);
    //Overloads << operator so it can be used to output values of type Check.
    friend Money operator+(const Check& check1, const Check& check2);
    //Overloads + operator so it can be used to sum values of type Check.
    Check(int checkNumber, Money amount, int cashed);
    //Initializes a check object with valid check #, amount and cashed parameters.
    bool cashedOrNot() const;
    Money getMoneyVal() const;
private:
    int checkNumber;
    Money amount;
    bool cashed;
};

class Account{
public:
    Account(long dollars); // initializes an acct w/ int value
    //Initializes an account with a predetermined amount
    Account();
    // Initializes empty account ($0.00)
    void insertIntoCheckbook(Check& check1);
    //inserts a check into checkbook vector
    void insertIntoDeposits(Money& deposit);
    //inserts deposit into desposits//
    Money getDeposits() const;
    void setCashed(Money& amt);
    void setUncashed(Money& amt);
    Money getCashed() const;
    Money getUncashed() const;
    Money getTotalBalance() const;
    void setTotalBalance(Money priorBal);
    //cout << total deposits;
    friend ostream& operator<<(ostream& out, const Account& account);
    //Overloads << operator to output Account's checksbook
private:
    Money totalBalance=0.00;
    //balance including cashed checks and deposits taking into account past balance
    Money cashed=0.00;
    Money uncashed=0.00;
    Money deposits=0.00;
    vector <Check> checkbook;
};
void checkInputValidator(Account& acct);
void depositInputValidator(Account& acct);
int main(){
    Account myAcc;
    double userInputPriorBal, userInputNewBal;

    cout<<"Welcome to Tony's Check Balancer V1.0"<<endl;
    cout<<"To begin please your checks each in a separate line."<<endl;
    cout<<"Check MUST contain a check number, amount, and whether or not the check has been cashed."<<endl;
    cout<<"Check numbers should only be positive values, amounts in dollar/cents format (12.33, or 12), WITHOUT $ symbols."<<endl;
    cout<<"Enter '1' for cashed checks, or '0' for checks NOT cashed."<<endl;
    cout<<"Example input for a cashed check number 5, in the amount of $100.32: '5 100.32 1'"<<endl;
    cout<<"When you have entered all your checks, enter '0 0 0' to end the input sequence"<<endl;
    checkInputValidator(myAcc);
    cout<<"The sum of your cashed checks is: "<<endl;
    cout<< myAcc.getCashed();
    cout<<endl;
    cout<<"The sum of your un-cashed checks is: "<<endl;
    cout<<myAcc.getUncashed();
    cout<<endl;

    cout<<"Please enter deposits in format (12 or 12.00). Enter '-1' to end sequence:"<<endl;
    depositInputValidator( myAcc);
    cout<<"The sum of your deposits is: "<<endl;
    cout<< myAcc.getDeposits() <<endl;
    cout<<"Please enter your prior balance amount: "<<endl;
    cin>>userInputPriorBal;
    Money priorBalanceMoney(userInputPriorBal);
    myAcc.setTotalBalance(priorBalanceMoney);
    cout<<"Please enter your new balance according your account holder: "<<endl;
    cin>>userInputNewBal;
    Money newBalanceAsPerCustomerMoney(userInputNewBal);
    cout<<"The balance according to the bank is (includes only cleared checks & deposits) is: "<<endl;
    cout<< myAcc.getTotalBalance()<<endl;
    cout<<"The difference between the account holders balance of "<< newBalanceAsPerCustomerMoney <<" estimate and the bank's total of "<< myAcc.getTotalBalance()<< " is: " <<  myAcc.getTotalBalance() - newBalanceAsPerCustomerMoney<<endl;
    cout<<myAcc;

    return 0;
}


Money operator+(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}
Money operator-(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents=amount1.all_cents-amount2.all_cents;
    return temp;
}
Money & Money::operator+=(const Money& rhs) {
    this->all_cents += rhs.all_cents;
    return *this;
}
bool operator<(const Money& amount1, const Money& amount2){
    return (amount1.all_cents < amount2.all_cents);
}
bool operator==(const Money& amount1, const Money& amount2){
    return (amount1.all_cents == amount2.all_cents);
}
Money::Money(long dollars, int cents){
    if (dollars * cents <0){
        cout<<"illegal values for dollars and cents"<<endl;
        exit(1);
    }
    all_cents=dollars* 100 + cents;
}
Money::Money(long dollars) {
    all_cents=dollars*100;
}
Money::Money(double amount){
    all_cents = floor(amount * 100);
}
Money::Money() : all_cents(0){} //implied return
double Money::get_value() const {
    return all_cents * 0.01;
}

istream& operator >>(istream& ins, Money& amount){
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins>> one_char;
    if (one_char==' '){
        negative = true;
        ins >> one_char;
    } else {
        negative=false ;
    }
    ins >> dollars >> decimal_point >> digit1 >>digit2;
    if (one_char !='$' || decimal_point !='.' || !isdigit(digit1) || !isdigit(digit2)){
        cout<<"Error illegal form for money input"<<endl;
        exit(1);
    }
    cents=digit_to_int(digit1)* 10 + digit_to_int(digit2);
    amount.all_cents=dollars*100+cents;
    if (negative)
        amount.all_cents = -amount.all_cents;
    return ins;
}
ostream& operator <<(ostream& outs, const Money& amount){
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents /100;
    cents = positive_cents%100;

    if (amount.all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';
    if (cents < 10)
        outs <<'0';
    outs <<cents;
    return outs;
}

///Check Class

Check::Check(int checkNum, Money checkAmount, int cashedInt){
    if (!checkNum || checkNum <0){
        cout <<"Please enter a valid check number";
        exit(1);
    }
    if (cashedInt <0 || cashedInt >1){
        cout <<"Only values 0 (NO), and 1(YES) are allowed for cashed property";
        exit(1);
    }
    checkNumber=checkNum;
    amount=checkAmount;
    cashed= bool(cashedInt);
}

bool Check::cashedOrNot() const { return cashed;}
ostream& operator<<(ostream& outs, const Check& check){
    string cashedStr = check.cashed ? "CASHED" : "NOT CASHED";
    outs << "Check number: " << check.checkNumber <<'\t';
    outs << "For amount: " << check.amount << '\t';
    outs << cashedStr <<endl;
    return outs;
}
Money operator+(const Check& check1, const Check& check2){
    Money temp;
    temp=check1.amount + check2.amount;
    return temp;
}
Money Check::getMoneyVal() const {return amount;}


//Account Class

void Account::insertIntoCheckbook(Check& check1){
    this->checkbook.push_back(check1);
}
Account::Account(long dollars){
    totalBalance=Money(dollars);
}
Account::Account(){
    totalBalance=Money(00.00);
}

void Account::insertIntoDeposits(Money& deposit){
    this->deposits += deposit;
}
Money Account::getDeposits() const{ return this->deposits;}

void Account::setCashed(Money& amt){
    this->cashed += amt;
}
void Account::setUncashed(Money& amt){
    this->uncashed += amt;
}

void Account::setTotalBalance(Money priorBal){
    totalBalance = priorBal - cashed;
    totalBalance = totalBalance + deposits;
}
Money Account::getCashed() const{ return this->cashed;}
Money Account::getUncashed() const{return this->uncashed;}
Money Account:: getTotalBalance() const{return this->totalBalance;}

ostream& operator<<(ostream& outs, const Account& account){
    vector<Check> copy = account.checkbook;
    outs << "----------------------------------"<<endl;
    outs <<"All cashed checks listed below: "<<endl;
    for (const auto & i : copy){
        if (i.cashedOrNot())
            outs<<i;
    }
    outs << "----------------------------------"<<endl;
    outs <<"All un-cashed checks listed below: "<<endl;
    for (const auto & i : copy){
        if (!i.cashedOrNot())
            outs<<i;
    }
    return outs ;
}


int digit_to_int(char c){
    return (static_cast<int>(c) - static_cast<int>('0'));
}

void checkInputValidator(Account& acct){
    int checkNum=1, cashedOrNot=1;
    double checkAmount=1;
    bool validated = true;
    while (validated) {
        cin >> checkNum >> checkAmount >> cashedOrNot;
        if (checkNum == 0 && cashedOrNot == 0 && checkAmount == 0.00) {
            validated = false;
        } else {
            Check temp(checkNum, checkAmount, cashedOrNot);
            Money amt = temp.getMoneyVal();
                if (temp.cashedOrNot())
                    acct.setCashed(amt);
                else
                    acct.setUncashed(amt);
                acct.insertIntoCheckbook(temp);

        }
    }
}

void depositInputValidator(Account& acct) {
    double deposit=0.00;
    bool validated = true;
    while (validated) {
        cin >> deposit;
        if (deposit == -1) {
            validated = false;
        } else {
            Money temp(deposit);
            acct.insertIntoDeposits(temp);
        }
    }
}