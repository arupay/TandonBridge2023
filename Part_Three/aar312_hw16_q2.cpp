#include <iostream>
#include <vector>

using namespace std;

//templated queue item class
template <class T>
class queueItem{
public:
    queueItem(T newData = T()): data(newData){}
    T data;
};

//Q class w/ list vector, w/ built in functions for queue, dequeue, print, size, empty();
template <class T>
class Queue{
    vector<queueItem<T>> list;
    int start=0;
public:
    void enqueue(queueItem<T>& item);
    void dequeue();
    void printQueue();
    int size();
    bool empty();
};

template <class T>
void Queue<T>::enqueue(queueItem<T>& item){
    list.push_back(item);
}
template <class T>
void Queue<T>::dequeue(){
    start++;
    if (start>=list.size()){
        list.clear();
        start=0;
    }
}
template <class T>
void Queue<T>::printQueue(){
    if (list.size()==0) cout<<"Nothing to print, list is empty";
    for (int i=start; i<list.size(); i++){
        cout<<list[i].data<<" ";
    }
    cout<<endl;
}

template <class T>
bool Queue<T>::empty(){
    return list.size()==0;
}

template <class T>
int Queue<T>::size(){
    return list.size()-start;
}
int main(){
    //Instance of queue class list, and 5 queueItems (one, two, three);
    Queue<int> list;
    queueItem one(1);
    queueItem two(2);
    queueItem three(3);
    queueItem four(4);
    queueItem five(5);

    //Five items enqueued
    cout<<"Lets enqueue numbers 1, 2, 3, 4, 5 into our queue" <<endl;
    list.enqueue(one);
    list.enqueue(two);
    list.enqueue(three);
    list.enqueue(four);
    list.enqueue(five);
    cout<<"The current queue of size "<< list.size()<<" contains: ";
    list.printQueue();

    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Now let's dequeue two items"<<endl;
    list.dequeue();//2,3,4,5
    list.dequeue();//3,4,5
    cout<<"The current queue of size "<< list.size()<<" contains: ";
    list.printQueue();


    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Now let's dequeue three more items"<<endl;
    list.dequeue();//4,5
    list.dequeue();//5
    list.dequeue();//NO ITEMS LEFT
    cout<<"The current queue of size "<< list.size()<<" contains: ";
    list.printQueue();

    //PROOF OF RESET VECTOR WHEN EMPTY
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Is the underlying vector empty ? "<<boolalpha<< list.empty()<<endl;


    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Now let's queue 3 items"<<endl;
    list.enqueue(one);
    list.enqueue(two);
    list.enqueue(three);

    cout<<"The current queue of size "<< list.size()<<" contains: ";
    list.printQueue();


return 0;
}
