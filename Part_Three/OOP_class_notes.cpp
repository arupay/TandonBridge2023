#include <iostream>
using namespace std;
/**
 //The concept of OOP came about in 1980's to bring together data and functions that operate on data.
 //OOP, creates in code an idea that exists in real life.
 //It protects the data from outside changes and allows for multiple operations to to be performed with a single atomic call
 //Enforces the idea that the designer know best what to do and what not to do w/ the data
 //Parallel : card shuffler, a dealer may take cards in and cards out as to prevent counting cards, what happens inside is a black box,
 and only the designer of the system truly know.

 ENCAPSULATION - We want to avoid anyone from outside the class creation to be able to access data inside the class.  Code written
 outside the class has a greater access than code written inside the class.  We allow controlled access to items we want accessed
 and restrict access to items we want to keep secure. (i.e. an architect creates a blueprint, sets room locations dimensions and can modify,
 but a plumber should only have access to rooms but should not be able to modify the blueprint).


 Class vs Object -
    //A Class is an abstract datatype - used for creating a more complex data type by combining simple data types and adding capability;
    //A Class serves as a framework to build multiple similar objects (i.e. House blueprint)
    // An Object is an instance of a class (instantiation of a class, i.e. house)

 Creating a class:

 class Date{
    public: <---incorrect
    int day;
    int month;
    int year;
};

 WARNING : type int range is 2^31-1, there cannot be a month, day or year 2.1 billion, by setting our clas to public we are allowing unrestricted
 inputs into our data pool -- we should protect our class and set our values private.  By default any values inside a class not set private or public
 are private.

class Date{
 private: //<---correct
 int day;
 int month;
 int year;
}

 // Unfortunately the private keyword revokes outside access to the variables, however we can create mutators and accessors to help us change data.

 //Note of how we create the setDay and setMonth functions outside our class for clarity.  Dont overload class definitions with code as it makes it
 difficult to read.

 class Date{
 private: //<---correct
 int day;
 int month;
 int year;

 public:
 void setDate(int newDay);
 void setMonth(int newMonth);
 void setYear (int newYear) {year=newYear:}
 };

 void Date::setDay(int newDay) {
 if (newDay>0 && dewDay<=31)
 day=newDay;
 };
 void Date::setMonth(int newMonth){
 if(newMonth>0 && newMonth <=12)
 month=newMonth;
 };

ACCESSING DATA:

//If we are ACCESSING data, but NOT changing it, then we should create "CONST" functions to access it.



 class Date{
 private: //<---correct
 int day;
 int month;
 int year;

 public:
 void setDate(int newDay);
 void setMonth(int newMonth);
 void setYear (int newYear) {year=newYear:}
 int getDay() const {return day; }  ==> CORRECT ACCESS w/ CONST
 int getMonth() const {return month; } ==> CORRECT ACCESS w/ CONST
 };



**/


