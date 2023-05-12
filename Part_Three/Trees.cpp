/*WHAT IS A TREE?
 *
 * Tree - a data structure designed to hold items in hiearchical pattern
 * Trees are often used for searching.
 * Every node, has one and ONLY ONE parent node. (This gives us the hiearchical pattern)
 * The only node w/o a parent, is the ROOT NODE!!
 * Not every node has children, but can.
 *
 * The accessable pointer is the highest node the tree, THE ROOT.
 * Every node looks like a tree by itself -- this lends itself to recursion
 * In recursive function we treat every node as if it were its own tree.
 *
 * TREE DEFINITIONS
 *
 * Binary Tree -> A tree with MAX of 2 CHILDREN, LEFT & RIGHT child
 * Size - > The # of nodes in a tree
 * Height -> The distance from ROOT -> TO FARTHEST CHILD NODE
 *          (height of null = -1, height of root w/ no children is ZERO, root node has only ONE child, and the height is 1)
 * Depth -> Distance from "this" node to root
 * Leaf Node -> Node without children
 * Full Node -> Node w/ maximum number of children.


TREE STORAGE?
 * For trees w/ unlimited number of chlidren, the child storage points are stored as an
   array or as a linked list
*Parent-Multi-Child ->  Struct where the parent node has an array of child nodes pointers
 * Parent-Child-Sibling -> Struct where Parent points to *fav* child and that child point to sibling and...
 * Unlimited children tree storage is rare --often max children trees structures are the norm.
 *
 *

 BINARY SEARCH TREE

 *In a binary search tree, each node contains only a left and right pointer
 * It also has an ORDER property.
 *---> All values on the left are LESS than the value of the node
 *---> All values on the right point to values GREATER (or equal if allowed) than the node.
 *--->Often equal values are prohibited.


 Why do we need BSTs?

 A BST provides search in O(log N)
   Each time we look at a node, we can eliminate half the possibilities (left or right)
   Insertion is O(log N)
   Deletion is O(log N)
We can use in order storage for any item that can be compared with a less than operator
Very efficient for in-order storage!



 * */
#include<iostream>
#include <queue>
template <class T>
class BSTNode;

using namespace std;

template <class T>
class BST{
    BSTNode<T>* root;
public:
    void printInOrder(BSTNode<T>* node);
    void printPreOrder(BSTNode<T>* node);
    void printPostOrder(BSTNode<T>* node);
    void printLevelOrder();
    void insert(T item);

};
template <class T>
class BSTNode{
    T data;
    BSTNode<T>* parent;
    BSTNode<T>* rightChild;
    BSTNode<T>* leftChild;
public:
    BSTNode(T newData=T(), BSTNode<T>* newParent = nullptr, BSTNode<T>* newRight = nullptr, BSTNode<T>* newLeft = nullptr)
    : data(newData), parent(newParent), rightChild(newRight), leftChild(newLeft){}
    friend class BST<T>;
    int getSize() const;
};

template <class T>
int BSTNode<T>::getSize() const{
    int count =1;
    if (leftChild!=nullptr)
        count+= leftChild->getSize();
    if (rightChild!= nullptr){
        count+=rightChild->getSize();
    }
    return count;
}

//Tree Traversals
//Traversals are going through every node in the trees
/* -->In-Order -->Process left nodes recursively first, then we process "this" node, then the right nodes.
 * -->Pre-Order-->This node first, then left, then right.
 * -->Post-Order-->Left nodes recursively first, then right nodes, then this node
 * -->Level-Order-->Breadth-first search / we are going outward on the levels of a tree.
 * */


template <class T>
void BST<T>::printPreOrder(BSTNode<T>* node){
    if (node!=nullptr){
        cout<<node->data<<",";
        printPreOrder(node->leftChild);
        printPreOrder(node->rightChild);
    }
}
//Pre-Order  20 5 3 10 30 25
template <class T>
void BST<T>::printPostOrder(BSTNode<T> *node) {
    if (node!=nullptr){
        printPostOrder(node->leftChild);
        printPostOrder(node->rightChild);
        cout<<node->data<<",";
    }
}
//In Order 3 5 10 20 25 30
template <class T>
void BST<T>::printInOrder(BSTNode<T>* node){
    if (node!=nullptr){
        printInOrder(node->leftChid);
        cout<<node->data   <<",";
        printInOrder(node->rightChild);
    }
}
// 3 10 5 25 30 20


//preorder root prints in first
//in order root prints at middle
//post order root prints last

//LEVEL ORDER TRAVERSAL BREADTH FIRST
template <class T>
void BST<T>::printLevelOrder() {
    queue<BSTNode<T>*> q;
    q.push(root);
    while (!q.empty()){
        BSTNode<T>* temp = q.front(); // first first element (oldest element)
        q.pop(); //remove that element
        cout<<temp->data<<","; //print tempt, previously was q.front
        if (temp->leftChild!=nullptr)
            q.push(temp->leftChild); //recursively do this left
        if (temp->rightChild!= nullptr)
            q.push(temp->rightChild); //recursive do this right
    }
}
//20 5 30 3 10 25 BREADTH FIRST or LEVEL

///TRAVERSAL DIAGRAM
/*              20
 *          5       30
 *      3   10  25
 *
 * Preorder - 20, 5, 3, 10, 30 25
 * InOrder - 3,5,10,20,25,30
 * Post Order - 3,10,5,25,30,20
 * Level (BREADTH FIRST)- 20,5,30,3,10,25
 *
 * */

/*INSERTION INTO TREES*/

template <class T>
void BST<T>::insert(T item){
    if (root==nullptr){ //no root exists
        root=new BSTNode<T>(item);//construct new item on heap make it root
        return;
    }
    BSTNode<T>* temp =root;
    BSTNode<T>* prev = root;
    while (temp!=nullptr){
        //temp traverses to tree to find insertion point
        //eventually temp becomes nullptr, but prev holds temps last position
        prev=temp;
        if(item < temp->data)
            temp = temp->left;
        else
            temp=temp->right;
    }
    //now, we decide if to insert right or left
    if (item < prev->data)
        prev->left= new BSTNode<T>(item, prev);
    else
        prev->right=new BSTNode<T>(item, prev);
}

//
//Remove operation
//
//-->change parent to temp->parent


//When BSTs FAIL
/*In best case scenarios BST result in O(log N) time for everything.
 * Unfortunately, if insertions into the tree are already in order...
 * ----Everything gets inserted right and we get unbalanced!
 5
    10
        15
            20
                25
 *An unbalanced tree increases the time it takes to look for an item, if we have 1 million items
 * there are one million iterations, as we do not get to halve our search pool at every step.
 *
 * BALANCING BINARY SEARCH TREES
 *
 * Balanced BST ensure O(log N) search time
 * There are two popular types of balanced binary search trees
 *
 *
 * AVL Trees (RESTRICTED HEIGHTS TREES!)
 *--Named after their creators
 *--Each tree records its own HEIGHT (can differ by NO MORE THAN 1)
 *--When heights differ by more than one, the tree must be ROTATED
 *--Rotation requires assining a NEW ROOT.
 *
 *GOOD AVL TREE
 *          10 h=2
 *      5 h=1     20 h=0
 *  3 h=0
 *
 *
 *
 * Given a grandparent, parent , child which is unbalanced
 * If the left parent's left subchild (or right parent's right subchild)
 * is greater than the left parents right subchild , or the right parents left subschild.
 *
 * Single rotation -- make the parent the new grandparent and the grandparent and the child become
 * the new children!
 *
 *
 *Double rotations are dont with two calls to the single rotation problem
 *
 *
 *
 * Red-Black Trees
 * STL Has two trees, a set and a map.
 * STL Set, and Map are implemented as Red-Black Trees
 *
 *
 *
 * */

