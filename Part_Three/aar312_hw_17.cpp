/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions.
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c==0)?1:0;
}

template <class T>
class RBTNode {
    RBTNode<T> *parent, *left, *right;
    T data;
    int color;

public:
    RBTNode(T data)
            : data(data),
              color(RED),
              parent(nullptr),
              left(nullptr),
              right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);
    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T> *node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T> *node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T> *root;
    void singleCCR(RBTNode<T> *&point);
    void doubleCR(RBTNode<T> *&point);
    void singleCR(RBTNode<T> *&point);
    void doubleCCR(RBTNode<T> *&point);

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parent);
    void prettyPrint() const { root->prettyPrint(0); }
    void dfsRotate(RBTNode<T>* &point);
    int height() const { return root->height(); }
};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T> *&point) {
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T> *&point) {
    singleCCR(point->left);
    singleCR(point);
}

template <class T>
void RBT<T>::singleCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->left;

    grandparent->left = parent->right;
    if (parent->right != nullptr) {
        parent->right->parent = grandparent;
    }

    parent->parent = grandparent->parent;
    if (grandparent->parent == nullptr) {
        root = parent;
    } else {
        grandparent == grandparent->parent->left ?
            grandparent->parent->left = parent :
            grandparent->parent->right = parent;
    }
    parent->right = grandparent;
    grandparent->parent = parent;
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->right;

    grandparent->right = parent->left;
    if (parent->left != nullptr) {
        parent->left->parent = grandparent;
    }

    parent->parent = grandparent->parent;
    if (grandparent->parent == nullptr) {
        root = parent;
    } else {
        grandparent == grandparent->parent->left  ?
            grandparent->parent->left = parent :
            grandparent->parent->right = parent;
    }
    parent->left = grandparent;
    grandparent->parent = parent;
}

template <class T>
void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {
    if (point == nullptr) {               // leaf location is found so insert node
        point = new RBTNode<T>(toInsert); // modifies the pointer itself since *point
        // is passed by reference
        point->parent = parent;
        // TODO: ADD RBT RULES HERE
        //Every node has a color red or black
        //root is always black (*Easy fix)
        //if a node is red, children must be black (*IMPORTANT)
        //Every path from a node to a null must traverse the same number of black nodes

        //New nodes must be red
            //parent is black = done
            //parent is red= problem (identified situation where rotation is necessary)
                //in AVL grandparent node is faulty node, in the R&B tree its the grandchild.
                //if uncle is black ( null is black)
                    //if new node is outside -> single rotation (grandparet)
                    //if new node is inside -> double rotation (grandparent
                // if uncle is red -- AVOID//IMPOSSIBLE.
         //As you go down to find the insertion if you encounter a black parent
        //with two red childnre, recolor to red parent with two black children. if grandparent
        //is red, ROTATE!.
        if (parent != nullptr)
            (toInsert < parent->data) ? parent->left = point : parent->right = point;
        RBTNode<T> *curr_node = point; // curr_node will be set appropriately when walking up the tree
        if (parent == nullptr){
            root=point;
            point->color = BLACK;
        } else{
            dfsRotate(curr_node);
        }
    } else if (toInsert < point->data) { // recurse down the tree to left to find correct leaf location
        insert(toInsert, point->left, point);
    } else { // recurse down the tree to right to find correct leaf location
        insert(toInsert, point->right, point);
    }
}
template <class T>
void RBT<T>::dfsRotate(RBTNode<T>* &point){
    if (point == root){
        point->color = BLACK; // easy fix root must always be black.
    }
    RBTNode<T>* parent = nullptr;
    RBTNode<T>* grandparent = nullptr;
    while (getColor(point->parent)== RED) {
        parent = point->parent;
        grandparent = parent->parent;
        if (grandparent->left == parent) {
            if (getColor(grandparent->right) == RED) {  //uncle is red (right side uncle)
                parent->color = BLACK;
                grandparent->right->color = BLACK; //change uncle's color
                grandparent != root ? grandparent->color = RED: grandparent->color = BLACK; //update gp color, unless gp is root
                point = grandparent; //update point
            } else {
                point == parent->left ? singleCR(grandparent) : doubleCR(grandparent); //inside single outside double
                swapColor(grandparent); // eliminate adjacent red
                swapColor(parent);
                point = parent;//update point
            }
        } else {
            if (getColor(grandparent->left)== RED) { //uncle is red (left side uncle)
                parent->color = BLACK;
                grandparent->left->color = BLACK; //change uncle's color
                if (grandparent != root)
                    grandparent->color = RED; //update grandparents color
                point = grandparent; //update point
            } else {
               point == parent->left ? doubleCR(grandparent) : singleCCR(grandparent); //inside double outside single
                swapColor(grandparent);// eliminate adjacent red
                swapColor(parent);
                point = parent; //update point
            }
        }
    }
}

template <class T>
void RBT<T>::insert(const T &toInsert) {
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }

    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */

    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
}
