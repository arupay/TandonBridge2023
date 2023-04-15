//2. Give a definition for a class SmartBut that is a derived class of the base class Smart, which we reproduce for you here. Do not bother with #include directives or namespace details.
//class Smart {
//public:
//    Smart( );
//    void print_answer( ) const; protected:
//    int a;
//    int b; };
//This class should have an additional data field, crazy, that is of type bool, one additional member function that takes no arguments and returns a value of type bool, and suitable constructors. The new function is named is_crazy. You do not need to give any implementations, just the class definition.

#include <iostream>
using namespace std;
class Smart {
public:
    Smart( );
    void print_answer( ) const; protected:
    int a;
    int b;
    bool
private:
    bool crazy;
};

int main(){
    return 0;
}