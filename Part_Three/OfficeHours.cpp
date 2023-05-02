//#include <iostream>
//using namespace std;
//
//class Pet{
//private:
//    int _age;
//    string _name;
//    double _weight;
//public:
//    Pet(){
//        _age=0;
//    }
//
//    void incrementAge(){
//        if (_age != NULL){
//            _age++;
//        }
//    }
//    void setAge(int newAge){
//        _age=newAge;
//    }
//    void setName(string newName){
//        _name=newName;
//    }
//    string getName(){
//        return _name;
//    }
//
//    virtual void speak(){ //Virtual Function
//        cout<<"DEFAULT NOISE"<<endl;
//    }
//
////    virtual void speak()=0;  PURE Virtual Function -- Forces all subclasses to have a speak fn.
//};
//
//class Dog: public Pet{
//private:
//    int _barkLoudness;
//    int _cuteness;
//
//public:
//    Dog(){
//        this->setAge(0);
//    }
//    Dog(string newName, int cuteness){
//        this->setName(newName);
//        setCuteness(cuteness);
//    }
//    void setCuteness(int newCuteness){
//        if (newCuteness > 10){
//            cout<<"Too cute, 10 is the highest value possible";
//            _cuteness=10;
//        } else {
//            _cuteness = newCuteness;
//        }
//    }
//    int getCuteness() const{ return _cuteness; }
//
//    void speak(){
//        cout<<"WOOF"<<endl;
//    }
//    friend ostream &operator<<(ostream &os, Dog &pet);
//
//    Pet& operator++(){
//        this->incrementAge();
//        return *this;
//    }
//};
//
//
//ostream &operator<<(ostream &os, Dog &pet){
//    string name= pet.getName();
//    os << name;
//    return os;
//}
//class Cat: public Pet{
//private:
//    int clawSize;
//    int stealthMode;
//    int scariness;
//public:
//    Cat(string newName){
//        this->setName(newName);
//    }
//    void speak(){
//        cout<<"MEOW"<<endl;
//    }
//
//};
//
////class Bird: public Pet{
////}; // cannot be instantiated WITHOUT the pure virtual class (speak())
//
//int main(){
//    Dog crunchy("crunchy", 10);
//    Cat shnook("Shnook");
//    crunchy.speak();
//    shnook.speak();
//    cout << crunchy;
//    ++crunchy;
//    return 0;
//}

//overloding comes into play when for example we want to print a dog (crunchy) to the console "<<cruchy", we will have to overload<<

//
//#include <iostream>
//#include <fstream>
//#include <vector>
//using namespace std;
//
//void basicReadIn(){
//    ifstream file;
//    string filePath="this is a filepath";
//    file.open(filePath);
//    char c;
//    vector<char> v;
//
//    while (file.get(c)){
//        v.push_back(c);
//    }
//    file.close();
//}
//
//
//int main(){
//    ifstream in_stream; //READ IN
//    ofstream out_stream; //WRITE OUT
//    string filePath="this is a filepath";
//    string outfilePath = "new file path ehre";
//    in_stream.open(filePath);
//    //BEST PRACTICES
//    //Check to make sure the opening of a file did not fail.
//    if (!in_stream){
//        cout<<"FAIL";
//    }
//    char c;
//    while (in_stream){
//        c=in_stream.get();
//        //do whatever you want with this here!
//    }
//    ///if we want to write it to another file
//    out_stream<<"This is some output";
//}

//LINKED LIST

//ALWAYS PROTOTYPE ALL YOUR CLASSES!!
//
//#include <iostream>
//using namespace std;
//
//class Expense;
//class AprilExpenses;
//
//class Expense{
//private:
//    int _data{};
//public:
//    string _name;
//    bool cool{};
//    Expense *_next{};
//    Expense *_prev{};
//    int setData(int n){
//        _data=n;
//    }
//    int getData() const{
//        return _data;
//    }
//};
//
//class AprilExpenses{
//private:
//    Expense *_head;
//    Expense *_tail;
//public:
//    AprilExpenses(){
//        _head=nullptr;
//        _tail=nullptr;
//    }
//    Expense* front(){
//        return _head;
//    }
//    Expense* back(){
//        return _tail;
//    }
//
//    void addNodeNoTail(int n, string newName){
//        Expense *temp=new Expense;
//        temp->setData(n);
//        temp->_name = newName;
//        if (_head==nullptr){
//            _head=temp;
//        } else {
//            Expense *cycle = _head;
//            while (cycle->_next!= nullptr){
//                cycle=cycle->_next;
//            }
//            cycle->_next=temp;
//            temp->_next= nullptr;
//        }
//    }
//
//    void addNode(int n, string newName){
//        Expense *temp= new Expense;
//        temp->setData(n);
//        temp->_name = newName;
//
//        if (_head == nullptr){
//            _head=temp;
//            _tail=temp;
//        }else {
//            _tail->_next= temp;
//            _tail=_tail->_next;
//        }
//    }
//    void addNode(int n){
//        Expense *temp = new Expense;
//        temp->setData(n);
//        temp->_next = nullptr;
//
//        if (_head==nullptr){
//           _head=temp;
//           _tail=temp;
//        }else {
//            _tail->_next = temp; //ADD NODE
//            _tail = _tail->_next;//UPDATE THE TAIL
//        }
//    }
//    void display(){
//        Expense *temp = _head;
//        while (temp!= nullptr){
//            cout<< temp->getData()<<endl;
//            temp = temp->_next;
//        }
//    }
//    void displayRecursive(Expense *tmp){
//        //base case
//        if (tmp !=nullptr){
//            cout<<_head->getData()<<endl;
//            displayRecursive(tmp->_next);
//        }
//    }
//    bool didIBuyShoesThisMonth(){
//        Expense *temp = _head;
//        while (temp!= nullptr){
//            if (temp->_name== "shoes") return true;
//            temp = temp->_next;
//        }
//        return false;
//    }
//
//    int howManyDidIBuy(string item){
//        Expense *temp=_head;
//        int count=0;
//        while (temp != nullptr){
//            if (temp->_name==item){
//                count++;
//            } else {
//                temp=temp->_next;
//            }
//        }
//        return count;
//    }
//
//};
//
////There are situations where we dont know what the data type we will take is, template allows us to say
////there will be a class T, we will pass it and return it's own type, all arguments passed will be also that type.
//template <class T>
//T add (T x, T y){
//    return x + y;
//}
//
//template <class T, class L>
//class Dog{
//public:
//    T data;
//    Dog(T n){
//        data = n;
//    }
//    L name;
//    Dog(T n,L x) {
//        data = n;
//        name=x;
//    }
//};
//
//template <class T>
//class TemplateClass {
//public:
//    T data;
//    string name;
//    TemplateClass(T n, string newName) {
//        data = n;
//        name = newName;
//    }
//};
//
//
//int main(){
//
//
//    TemplateClass<int> newClass(5, "Shoes");
//    TemplateClass<int> newClass2(10,"purse");
//    cout<<newClass.data <<newClass2.data;
//    return 0;
//}

//Reading in and reading out files

#include <iostream>
#include <fstream>//reading in and out library
#include <vector>

using namespace std;

int basicReadIn(){
    ifstream file;
    string filePath ="directory/filepath";
    file.open(filePath);

    if (!file){
        cout<<"Error!";
        return 1;
    } //if its not open /file does nto exist

    char c;
    vector<char> vec;
    while (file.get(c)){
        vec.push_back(c);
    }
    file.close();//close file.
}

int main(){
    ifstream inStream;
    ofstream outStream;
   string path="infilepath.txt";
   string outPath= "output.txt";
   inStream.open(path);
   outStream.open(outPath);


   if (!inStream){
       cout<<"Error";
       return 1;
   }

   char c;

   string currLine;
   while (getline(inStream, currLine)){
       for (int i=2; i<currLine.length(); i++){
           if (currLine[i]!=' '){
               outStream << currLine[i];
           }
       }
       outStream << "\n";
   }
   return 0;
}