//#include  <iostream>
//
//using namespace std;
//
//void printLine(int num){
//    for (int i=0; i< num; i++){
//        cout<<'\t';
//        cout<<num;
//    }
//
//}
//
//void printManyLine(int num){
//    for (int i=0; i<1000; i++)
//        printLine(num);
//}
//
//void createThread(int num){
//    printManyLine(num);
//    ///this fn creates a kernel level thread
//    //and calls printManyLines passing it num
//}
//
//int main(){
//    for (int i =0; i<5; i++){
//        createThread(i);
//    }
//}


//template <class T>
//class LList;
//
//template <class T>
//class LListNode {
//    T data;
//    LListNode<T>* next;
//public:
//    LListNode(const T& item = T(), LListNode<T>* newnext=nullptr){
//        data=item;
//        next=newnext;
//    }
//    friend class LList < T >;
//};
//
//template <class T>
//class LList {
//    LListNode<T>* head ;
//    LListNode<T>* recursiveCopy(LListNode<T>* rhsHead);
//public:
//    LList(): head(nullptr){}
//    ~LList() {clear();}
//    LList(const LList<T>&rhs):head(nullptr) {*this =rhs}
//    LList& operator=(const LList&rhs);
//    void insertAtHead(const T&item);
//    T removeFromHead();
//    bool isEmpty() {return head==nullptr;}
//    void clear() { while (!isEmpty()) removeFromHead();}
//    int size()const;
//    LList& operator *( int rhs){
//
//    }
//};
//
//

#include <iostream>
using namespace std;

template <class T>
class ExpressionTreeNode{
public:
    ExpressionTreeNode(T val){
        data=val;
        leftChild = nullptr;
        rightChild = nullptr;
    }
    T data;
    ExpressionTreeNode* leftChild;
    ExpressionTreeNode* rightChild;
    int getValue(){
        if (data == '*')
            return leftChild->getValue() * rightChild->getValue();
        else if (data == '+')
            return leftChild->getValue() + rightChild->getValue();
        else
          return data;
    }
};



template <class T>
class ExpressionTree {
public:
    ExpressionTreeNode<T>* root;
    T getValue(){
        return root->getValue();
    }
};


int main() {
cout <<int('5') + int('5');

    return 0;
}