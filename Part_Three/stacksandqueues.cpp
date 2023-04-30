/*Stacks
 *
 *--Think of a stack of plates at a buffer, the only plate you can grab is the top plate
 * --> this ist he purposes of a stack, you cannot access arbitrary information
 * -->once you put things intot he stack, you can access only the LAST THING that's been put in
 * --> LIFO->> LAST IN, is the FIRST OUT
 *Functions we use on a stack, is PUSH to add, POP tor emove top element from stack
 *Supplemental functions may do other purposes (clear, isEmpty, size)
 *
 * //PUSH-->> adds to FRONT of the stack
 * //POP -->> removes from front of stack
 * //also valid if both do the same operation form back of stack, cannot mix and match
 * //Supplemental functions need to be provided as well as Big 3 if applicable.
 *
 * Stack can take form in list or array
 *
 * In List, push operation is constant time operation
 * in an Array,  push operation is O(1)/O(N), depends on how much space we have in array (do we have to expand it?)
 * Pop is always O(1) IN BOTH array and list
 * to access top is always O(1) in BOTH!
 * clear will always be O(N) in LIST, O(1) in Array.
 * isEmpty is O(1) in both!
 * Size ? Array have built in size param, in List we can update size on every POP and call size when we need to.
 *
 *
 * It's not clear immediately if we should use a list or an array, but we should evaluate what we are trying to do
 * In a situation where we are unlikely to use clear (O(n) time in list but O(1)in array), we should use a linked list
 * since its O(1) for every other method.
 *
 * Use built in STL list class!!! (ALRAEDY WRITTEN, already has big 3 methods if using dynamic data)
 *
 * PUSH-->> push_front
 * POP--->> pop_front
 *
 * */

//#include <iostream>
//#include <list>
//
//using namespace std;
//
//template<class T>
//class Stack{
//    list<T> data;
//public:
//    void push(T newItem){data.push_front(newItem);}
//    T pop(){return data.pop_front();}
//    T top()const { return *data.begin(); } /// begin if pop/push_front otherwise end if pop/push_end
//                                            //data.begin is an ITERATOR so we have to DEREFERENCE IT!
//    bool isEmpty() const {return data.size()==0;}
//    int size() const {return data.size();}
//    void clear(){return data.clear();}
// };

//int main(){
//    int arr[]={2,3,4,5};
//    cout<<arr[myfunc()] << endl;
//}




//How do we use the stack? What do we use it for?

/*--> THE COMPILER!
 *         -->Pattern matching! Compilers must make sure that all opening { are } and all " are closed with ",
 *         --> We are not just couting how many there are, because simply counting doens't show validity
 *         --> We must also know the ORDER IS CORRECT!
 *         --> Solution: We create a stack, when we see an opening, we can push on the opening symbol to the stack
 *         --> When an open is encountered it is pushed
 *         --> When we find a closing, we compare it to TOP of the stack, if its a match, we POP the stack!!
 *         --> The stack is used to do the pushes and pop to make sure the last thing we see is the first thing that
 *         we see in the clsing
 * --> Math Infix to post-fix conversion;
 *         --> If we have a simpel task like (2+3*4) we recognizes from a math perspective that the 3x4 must be done before
 *              2+3 because that is orders of operations.  The computer does not know this hwover because it scans left to right
 *         --> post fix notation takes the operators and pushes them on the stack, does not push lower prescence on top of higher prescence
 *         --> IN the post fix conversion we use stack to store operators
 *         --> in post fix to value valuation, we use stack to store OPERANDS.
 *         -->numbers are pushed to stack at the end, teh top number at the actual value.
 *
 * */

/*
 QUEUE
 *
 * First in, FIRST OUT, data structure
 * The first item which is ENQUEUED is the first item DEQUEUED.
 * Often used for buffering information
 *
 * Push, pop and top are often the accessor funcitons, however it may enqueue, dequeue and top.
 * Same sumplemental functions (clear, isEmpty, size)
 *Elements are inserted to BACK of queue, and removed from the FRONT of the queue.
 *
 HOW DOES IT WORK?
 * ENQUEUED adds to the end
 * DEQUEUE removes from front
 * could also be reversed
 *
 *
 *
 * --------->List                 or                Array?
 * PUSH     O(1)                                    O(1)/O(N) //IF we run out of space its O(N)
 * POP      O(1)                                    O(N)--> REMOVING zero element, we move all other elements by one
 * TOP      O(1)                                    O(1)
 * Clear    O(N)                                    O(1)
 * isEmpty  O(1)                                    O(1)
 * size     O(1)                                    O(1)
 *
 * Removing the front element of an array is very expensive so it is more efficient to store this as a LINKED LIST!!
 * */

//Much more obvious that we must used a linked list here, implementation is similar to stack
//-->Enqueue will add to the end of the queue
//-->Dequeue will remove from the front
//-->Necesary to make sure the listhas BOTH HEAD AND TAIL POINTERS TO KEEP O(1) insertion and removal

//STL List class makes it easier, but it is a double linked list, we can create our own if want to save space.

#include <iostream>
#include <list>

using namespace std;
template <class T>
class Queue{
    list<T> data;
public:
    void enqueue(T newItem){data.push_back(newItem);}
    T dequeue(){return data.pop_front();}
    T top()const {return *data.begin();}
    bool isEmpty()const{return data.size()==0;}
    int size()const{return data.size();}
    void clear(){return data.clear();}
};

/*WHAT DO WE USE QUEUES FOR?
 *
 * Storage Buffer --> If wea re bringing information in
 * -->IOSTREAM --> If we bring in a large amount of data, and slowly feeding into a data program
 * -->Because reading data from sec storage devise is expensive, we grab large portion of file, we store it temporarily
 * -->ina  structure in main emory and as a program can slowly feed it in
 *
 * We can also use it operating syste,s with memory manage, and removing the oldest page of memory management
 * -->We can keep a FIFO list queue of all pages in main memory and we throw away front of queue where we have gto throw
 *
 * --> FIRST IN FIRST OUT PROPERTY THAT REQUIRES AND ORDERED LIST!! USE A QUEUE!!!
 *
 * */


