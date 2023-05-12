/*
 *
 *
 * */

//#include <list>
//
//using namespace std;
//
//class BSTNode{
//public:
//    int data;
//    BSTNode* left;
//    BSTNode* right;
//    BSTNode* parent;
//};
//
////ASSUMPTION THAT ALL BST ABIDES BY PRINCIPLES OF LEFTNODE->val < ROOT->val > RIGHT NODE->val
//void createListFromBST(BSTNode* root, list<int>&listOfNums, int& target){
//    if (root==nullptr){
//        return;
//    }
//    createListFromBST(root->left, listOfNums, target);
//    if (target<=root->data) listOfNums.push_back(root->data);
//    createListFromBST(root->right, listOfNums, target);
//}
//
//
//
//int main(){
//    list<int> values;
//
//}

#include <iostream>
using namespace std;

class Exam{ //Pure virtual Abstract
public:
    Exam(){};
    virtual int getResults()=0;
};

class WrittenExam: public Exam{
public:
    WrittenExam() : Exam(){};
    virtual int getResults(){
        return 1;
    };
};



class Practical: public Exam{
public:
    Practical() : Exam(){};
    virtual int getResults(){
        return -1;
    };
};

int main(){
    return 0;
}
