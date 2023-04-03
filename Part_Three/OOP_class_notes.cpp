
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

//If we are ACCESSING data, but NOT changing it, then we should create "CONST" functions to access it. const member functions
 cannot change data and are the only functions that can be called if the object is a const.



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


Other useful functions:

 Perhaps we could add a printDate fn to print a formatted date: (day/month/year)
 void displayDate() const { cout << day << "/" <<month << "/" << year; } <-- CONSTified because it's nto changing data

 Or a validate function to check if date is valid
 bool validate() const;



Creating and working w/ Objects

 --Working with objects requires reference with "dot operator"
 --We will not have access to private members!

 int main(){
 Date d1; <--obj instantiation
 d1.setDay(6);
 d1.setMonth(8);
 d1.setYear(1991);
 }

 What if we created a class and forgot to set values ?  Well , we just introduced into our data pool an instance of the class
 Date with GARBAGE values!  How can we avoid this from happening? Constructors!

CONSTRUCTORS
  -- A function given the name exactly the same as the name of the class without a return type and no parameters
  -- Constructors are called automatically when objects are created, and sets default values as we decide them to be.

 Member Initialization List Example:
class Date{
 private:
    int day;
     int month;
    int year;
 public:
    Date() : day(1), month(1), year(1979) {}

 W/O Member initialization Example:

 class Date{
 private:
    int day;
     int month;
    int year;
 public:
    Date(){
    day =1;
    month =1;
    year = 1970;
    }
  }

  Now we can instantiate new objects and set dates as single line commands

  Date d2(6,8,1991);

 An important Pointer!
    Every object has a pointer, which looks like a data member, called 'this'
    The this pointer points to the calling object
    Though not always necessary, you can always use this.
 void setYear (int newYear) { this -> year = newYear;}



 Operator Overloading (C++ ONLY)

 Allows us to take two objects and add them together.
    Types of Operators (These are actually functions)
    (Unary Operator) -> Only work on one operand (++, --)
    (Binary Operator) -> Works on 2 operands (+,-,*,/,%, +=, <, [])
    (Ternary Operators) -> Conditional Operators

Some operators cannot be overloaded (., *., ?:..)
Some can only be overloaded as a member
    = (assignment operator)
    [] (array index operator)
Some also, cannot be overloaded as a member,
    <<, >>, ...

Choosing Member vs Non-Member
 Remember that members have access to private

 A function defined as a "fried" in the class is NOT a member, btu will have access
 to private values/info. (Way of sidestepping private restrictions in C++, but rarely used)

 Otherwise, there is only one difference
        -- a+ bw ill work in either case
        --a + 5 (obj vs constant) will work if there is a constuctor
        which can take 5 and construct an object to add to a
        --5+a (constant + object) will only work if the above constructor exists AND
        operator+ is a non-member.
        -- make them members is easier but not safest


 What to RETURN?
 - The value returned depends onw hat the operator should do (i.e the + operator should return a new value, not update current values)
 - the return data type depends on what is being returned
        - if the item was created inside the fn, MUST RETURN BY VALUE (temp= a+b, return temp)
        - if the item was passed as a parameter, or you are returning the 'this' pointer, you can return
        by reference. (+= operator).
 - Returning by reference is preferred (but to do this the object that we are returning ahs to have existed prior)
 - SUMMARY: IF WE CREATE RETURN BY VALUE, if it was passed RETURN BY REFERENCE

An Odd Case

How to differentiate overloading ++ when it can be PRE and POST increment ?
 The preincrement operator overload format:
    Date& operator++(); ==> will change the value, then return a ref to exisiting obj. (RETURN BY REFERENCE)
 the post-increment operator overload format:
     Date operator++(int)  ==> will copy the object, then change the value and return the COPY (RETURN BY VALUE)
      -- note how the post-inc. operator is passed an (int) -> the value of the int is not important.


Classes that contain DYNAMIC MEMORY
    -All classes have an assignment operator and constructor which can copy an existing object, this is
    a left over of C's structs and is useful.
    -Unfortunately when pointers are involved (pointers point at heap memory, dynamic memory vars) these built in operators
    instead copy the pointers and not at what they are pointing to. (SHALLOW COPY)
    - this creates MEMORY LEAK!

Avoiding Memory Leaks When working w/ Dynamic Memory (THE BIG THREE) :
 -Copy operations need to copy the DATA, NOT THE POINTERS.
 -Since we are creating memory in the constructor, we need to destroy that memory when the object falls out of scope.
 -The Big 3 are three functions that, if you need any of them, you need them ALL
    - DESTRUCTOR, COPY CONSTRUCTOR, ASSIGNMENT OPERAT OR
    Destructor- Called automatically when an object calls out of scope
    Copy Constructor - constructs an obj based on an existing one
    Assignment Operator - copies on object to another (DEEP COPY)
        -- Make sure to avoid x=x (self assignment must use 'if(this==&rhs)')

 class Thing{
    int *value ; <==POINTER
  public:
    Thing(int newVal=0) :value(new int(newVal)){}
    ~Thing() {delete value;} <===DESTRUCTOR
    Thing (const Thing& rhs) {value = new int(*rhs.value);}    <====Copy constructor
    Thing& operator=(const Thing& rhs) { *value = *rhs.value;}    <===== Assignment operator
 }

 Inheritance

    Allows us to create complex classes out of simple ones.
    During inheritance, the existing class (base class) is enlarged to form a DERIVED CLASS
    All items (fns, data) which exist in the base class will be in the derived class automatically
    We can add material to the derived class
    We can override fns in the base class
    MEMBER FUNCTIONS OF A DERIVED CLASS CANNOT ACCESS PRIVATE DATA IN THE BASE CLASS (IMPORTANT)

Pets & Cats Code Snippet

class Pet{
 string name;
 int PETid;
public: Pet(int newID=0){petID=newID;}
        string getName() const {return name;}
        void setName (string newName) {name = newName;}
        void speak() const{}
};

 class Cat:public Pet {<===== DERIVED CLASS
       double whiskerLength;
 public:
    Cat() : Pet(10000){} // explicit call to BASE CONSTRUCTOR
    void speak() const |cout<<"MEOW!"<<endl;
    void setLength (double newLength);
    double getLength() const {return whiskerLength;}
    void setName(string newName);
    Cat& operator=(const Pet&);

OVERRIDING FUNCTIONS

    -- To override you just create a function in the derived with the same name and parameters as int he abse
    --if you need to call the base version, use the scope resolution operator ::

  void Cat::setName(string newName){
    whiskerLength =0;
    Pet::setName(newName);
 }

 What if derived SHOULD access the BASE stuff?

 -Items listed as 'protected' in base can be accessed from derived. USE THIS SPARINGLY.


POLYMORPHISM

 -Since every cat is a pet, we SHOULD be able to copy data between cats and pets
 -Since every cat is a pet, every cat will contain all the functions inside pet
        -Though, not necessarily the same versions.

 -Polymorphism allows us to copy data from a derived class into a base class, (only base items copy over -- SLICING)
 -Overloading the assignment operator can allow us to copy base->derived. (overloading)
 -Since every derived object contains everything in base, a bse pointer can also point to a derived object.
 -There is no guarantee that the base contains everything in derived, so derived pointer can never point to base.
 Summary: Base point to derived TRUE, derived point to base FALSE.

int main(){
 Pet p;
 Pet* pptr;
 Cat c;
 Cat* cptr;
 p=c; ===> Always Allowed !
 c=p; ===> Allowed if overloaded operator exists
 pptr = &c; ===>Always allowed, POLYMORPHISM
 cptr = &p; ===> NOT ALLOWED!!


 VIRTUAL FUNCTIONS
    If a base pointer is used to point to a derived object, by default the functions will the BASE versions of the fns.
        -- this can eb catastrophic if the derived fnd oes something different than base
    The solution is mark the base function as "virtual"
        -this employs late binding (DYNAMIC BINDING) // Rather than make the static binding decision, which version to call at
        compile time, we do late or dynamic binding where we choose where to call at RUN-TIME.
        -The version fo the function called depends ont eh type of object, not the type of pointer;

 PURE VIRTUAL
    If the base class should contain a function, but doesn't know what the function should actually do, the function can be
    marked as pure virtual "=0" (Pets should have speak fn, but all derived classes speak differently, so we dont know yet)


 class Pet {
 string name;
 int petID;

 public:
    Pet(int newId=0){petID=newID;}
    string getName() const {return name;}
    virtual void setName(string newName) {name=newName;}
    virtual void speak() const=0; <===PURE VIRTUAL FUNCTION
};
 class Cat : public Pet {
      double whiskerLength;

 public:
    Cat() :Pet(1000) {}
    void speak() const {cout<<'MEOW!"<<endl;}
    void setLength(double newLength);
    double......
 };

 --In the code above the cat calss overrides the speak function, now we have the ability to have a pet pointer
 point to a Cat object and call the speak() fn int hat cat object.

 RESTRICTIONS:  Because the Pet class now has virtual fn's it is an ABSTRACT CLASS.  IT CANNOT BE INSTANTIATED
                NO OBJECT OF TYPE PET CAN BE CREATED (speak fn() cannot be defined, no virtual fn allowed )


                BUT, we can create pointers and derive from this class, so PET is still useful as a bse class, even
                if we can't create objs of this class explicitly.

                 We can create an obj of cat class and have a PET PTR point to it. (PET IS BASE CLASS USE ONLY THROUGH POINTER)

 END OF MODULE SLIDES
**/

/**
 WEBINAR 3/30 PROF KATZ
 1st Hour Informational Session Takeaway
       - Week # Tasks/Readings released Thursday Morning
       - Webinars Thursdays 8PM EST
       - Tandon bridge cohort success high relative to non-bridge
       - Make sure to do practice problems in book post chapter.
       - Very little coding after exam 3
**/

//Student Question : When we overload an operator are we only changing it to the scope of the class or are we changing it
//whenever it it used?
    //Anywhere where we know there is a 'Thing' then we can add two things together. (C++ will evaluate lhr and rhs)
    //It's scope is limited to anywhere we 'know' about the 'Thing'.
    //If we do (int + int) , we will still be able to add accordingly.
    //The meaning operator is defined FOR THE CLASS. YOU CAN DECIDE WHAT IT DOES.


//Question 2: When do we want to use const modifier  'int getNum()const {num=100;return num;}'
    //When we want to restrict potential changing any variables for use in the function
    //This becomes vital when we use a function that take a 'Thing', and pass it by value
    //a constified function is a contract with the compiler that we will not change the object we pass


//Question 3:  How do we define our operator override fn ? Do we do this as a member or nonmember? If i do it as a member do I give it friend access?

#include <iostream>
using namespace std;

class Thing {
    int num;
public:
    Thing(int new_num = 0): num(new_num) {} //CONSTRUCTOR
    int getNum() const {return num;}
    void setNum(int new_num) { num = new_num ;}
    Thing operator+(const Thing& rhs) const ; //Member operator override only needs one parameter because ->this obj is left hand side and we can access.
    Thing& operator ++(); //pre-increment;
    Thing operator++(int); //post-increment;
};
Thing& Thing::operator++(){
    num++;
    return *this; //DEREFERENCE THIS is this object
}

Thing Thing::operator++(int){
    Thing temp=*this; //COPY OF THIS OBJECT
    num++;
    return temp; //Return the original.  Cannot return by reference, because the memory will be cleared when fn ends, MUST RETURN BY VALUE.
}

Thing operator-(const Thing& lhs, const Thing& rhs) {  //Here we need two parameters, we dont have access to this (nonmember fn)
    return lhs.getNum() - rhs.getNum();
}

void func(const Thing& x){
    x.getNum(); //unexpected;
    Thing three = x+5;
}
Thing Thing::operator+(const Thing& rhs)const {
    return num + rhs.num;  //Is this an int primitive or an instance of a Thing class? It appears tobe an int as this.num is an int and rhs.num is an int but we declared the fn as type Thing?
                            //Answer: When we do num +rhs.num, there is an IMPLICIT CALL TO CONSTRUCTOR AND WE ARE PASSING IN THE VALUE !!
                            //We are implicitly creating a new obj by calling the contructor w/ the value returned by this function
                            //We can give the constructor an "explicit" keyword to only allow explicit calls such as thing one and thing two.
}
int main(){
    Thing one(1);
    cout<< one.getNum() <<endl;
    Thing two(2);
    Thing three;
    three= one + two; // Function call: three.operator=(one.operator+(two));
    cout<<three.getNum()<<endl;
    func(two);

    ++++two; // double pre-increment!
    ++(++two); //same as the previous line;
    (two.operator++()).operator++();//still the same as previous line

    two++; //works
//    (two++)++// DOES NOT WORK ? WHY?  What's returned by 2++, its a value.

    Thing four;
    four = two-one;
    cout<<four.getNum()<<endl;


}