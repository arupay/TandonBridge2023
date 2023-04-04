#include <iostream>
using namespace std;

class Pet{
private:
    int _age;
    string _name;
    double _weight;
public:
    Pet(){
        _age=0;
    }

    void incrementAge(){
        if (_age != NULL){
            _age++;
        }
    }
    void setAge(int newAge){
        _age=newAge;
    }
    void setName(string newName){
        _name=newName;
    }
    string getName(){
        return _name;
    }

    virtual void speak(){ //Virtual Function
        cout<<"DEFAULT NOISE"<<endl;
    }

//    virtual void speak()=0;  PURE Virtual Function -- Forces all subclasses to have a speak fn.
};

class Dog: public Pet{
private:
    int _barkLoudness;
    int _cuteness;

public:
    Dog(){
        this->setAge(0);
    }
    Dog(string newName, int cuteness){
        this->setName(newName);
        setCuteness(cuteness);
    }
    void setCuteness(int newCuteness){
        if (newCuteness > 10){
            cout<<"Too cute, 10 is the highest value possible";
            _cuteness=10;
        } else {
            _cuteness = newCuteness;
        }
    }
    int getCuteness() const{ return _cuteness; }

    void speak(){
        cout<<"WOOF"<<endl;
    }
    friend ostream &operator<<(ostream &os, Dog &pet);

    Pet& operator++(){
        this->incrementAge();
        return *this;
    }
};


ostream &operator<<(ostream &os, Dog &pet){
    string name= pet.getName();
    os << name;
    return os;
}
class Cat: public Pet{
private:
    int clawSize;
    int stealthMode;
    int scariness;
public:
    Cat(string newName){
        this->setName(newName);
    }
    void speak(){
        cout<<"MEOW"<<endl;
    }

};

//class Bird: public Pet{
//}; // cannot be instantiated WITHOUT the pure virtual class (speak())

int main(){
    Dog crunchy("crunchy", 10);
    Cat shnook("Shnook");
    crunchy.speak();
    shnook.speak();
    cout << crunchy;
    ++crunchy;
    return 0;
}

//overloding comes into play when for example we want to print a dog (crunchy) to the console "<<cruchy", we will have to overload<<