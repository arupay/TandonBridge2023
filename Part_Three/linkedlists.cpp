//
// Created by Augusto Rupay on 4/27/23.
//
/*Linked list is a fundamental DS
 * -->It has two parts it's made up of nodes and each node has a data, and a next pointer
 *-->Linked list insertion of O(1).  Where as array insertion is O(n)
 *
 *
 TEMPLATE
 * In C++ we can use template when we don't know what the datat type will be for an element
 *Before each funciton or classs, we put "template <class T>"
 *C++ replaces "T" in that function with an actual data type when it knows what that data type it would be.
 *
 * T cannot be mixed and matched (cannot be both an int and a str), it will have to be T consistently whatever data type it is.
 *     template <class T>
 * */
//#include <iostream>
//using namespace std;
//
//template <class T>
//
//void mySwap(T& a, T& b){
//    T temp = a;
//    a= b;
//    b=temp;
//}

//In the above code we swap two items, and three copy operations.  The real takeaway is we can use any data type fo this
//my swap function.  We do not need to rewrite this fn numerous times simply to change the data type.


/*
 * When we templace a class, its name changes to include the data type which is templated
 *
 * in main, this class would be the following:
 *
 * SomeVal<int> varName;
 * SomeVal<char> varName;
 *
 *
 *
 *
 *
 * Designing A Linked List Node
 *
 * */
//
template <class T>
class LListNode{
    T data;
    LListNode<T>* next;
public:
    LListNode(T newdata= T(), LListNode<T>* newNext=nullptr): data (newdata), next(newNext){}
    friend class LListNode <T>;
};
//

template <class T>
class LList {
    LListNode<T>*head;
    LListNode<T>* recursiveCopy(LListNode<T>* rhs);
public:
    LList(): head(nullptr){}
    LList(const LList& rhs) : head(nullptr) {*this=rhs;}
    LList<T>& operator=(const LList<T>& rhs);
    ~LList() { clear(); }
    void insertAtHead(T newdata);
    T removeFromHead();
    bool isEmpty() const{return head== nullptr;}
    void clear();
    void insertAtEnd(T newdata);

    void insertAtPoint(LListNode<T>* ptr, T newData);
    int size() const;
};

//WHEN DO WE STOP WHEN TRAVERSIN A LINKED LIST

//STOPPING AT THE END means we want to run while loop as long as the next pointer is not == to nullptr;
    //requires keeping track of current pointer, and we are careful that we have at least one node
    //while (temp->next!nullptr) / THis one is good for INSERTION CAUSE WE STOP AT LAST NODE
//Going off the end: while (temp!=nullptr)
//GOOD FOR COUNT CAUSE WE STOP AT LAST PTR WHICH IS NULLPTR