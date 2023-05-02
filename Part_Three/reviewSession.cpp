/*371
 *
 *
 * 4. Write a program that will compute the average word length (average num- ber of characters per word) for a file that contains some text. A word is defined to be any string of symbols that is preceded and followed by one of the following at each end: a blank, a comma, a period, the beginning of a line, or the end of a line. Your program should define a function that is called with the input-file stream as an argument. This function should also work with the stream cin as the input stream, although the function will not be called with cin as an argument in this program. If this is being done as a class assignment, obtain the file names from your instructor.# 4*/

//getting the texfile name and checking it exists
//counter for letters or words
//Ideas: char alphabet, if alphabet===a-z or A-Z
//letter counter++
//if (alphabet == space or punctuation)
//word++;
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <iomanip>
//using namespace std;
//
//string trimWhileSpace(string str){
//    int i=0;
//    while (str[i]==' '){
//        i++;
//    }
//    return str.substr(i);
//}
//
//int main(){
//    ofstream oFile;
//    oFile.open("input.txt  ");
//
//    ifstream iFile;
//    iFile.open("output.txt");
//
//    vector <string> C;
//    char token;
//
//    string currStr;
//    while( iFile.get(token) ){
//        currStr+=token;
//        if(token== '\n') {
//            C.push_back(currStr);
//            currStr = "";
//        }
//    }
//    C.push_back(currStr);
//
//    for(int i = 0; i<C.size(); i++){
//        cout <<i+1<<" "<<  trimWhileSpace(C[i]);
//    }
//    return 0;
//}
//


//Winter 2021 #8
//
//#include <iostream>
//#include <vector>
//#include <numeric>
//write3 classes, SinglePercentDiscount, SingleValueDiscount, MultiDiscount;
//SinglePecentDisc is applied After value discount if BOTH are to be applied
//The Order class will keep track of the discount applied to each item.
//Each of the 3 discount classes will need a constructor that takes the AMOUNT and PERCENT/VAL off and a function
//called double calculateFinalDiscount(double originalPrice);
//using namespace std;
//class Discount;
//class SinglePercentDiscount;
//class MultiDiscount;
//class SingleValueDiscount;
//
//
//class Discount{
//public:
//    virtual double calculateFinalDiscount(double num)const =0;
//};
//
//class SinglePercentDiscount: public Discount{
//public:
//    SinglePercentDiscount(double disc){
//        discountPercent=disc;
//    };
//    virtual double calculateFinalDiscount(double num) const{
//        return num * discountPercent;
//    }
//private:
//    double discountPercent;
//};
//
//class SingleValueDiscount: public Discount{
//public:
//    SingleValueDiscount(double disc){
//        discountValue=disc;
//    }
//     double calculateFinalDiscount() const{
//        return discountValue;
//    }
//    virtual double calculateFinalDiscount(double num) const{
//        return discountValue;
//    }
//private:
//    double discountValue;
//};
//
//class MultiDiscount: public Discount{
//public:
//    MultiDiscount(double perc, double val){
//        discountPercent=perc;
//        discountValue=val;
//    }
//    virtual double calculateFinalDiscount(double num) const{
//        return ((discountValue) + (num*discountPercent) );
//    }
//private:
//    double discountPercent;
//    double discountValue;
//};
//
//class Order{
//public:
//    double totalCost() {
//        double sum = accumulate(originalPrices.begin(), originalPrices.end(), 0.0);
//        double discounts=0;
//        for (int i=0; i<parallelDiscounts.size(); i++){
//            if (parallelDiscounts[i]==nullptr)
//                continue;
//            discounts+= parallelDiscounts[i]->calculateFinalDiscount(originalPrices[i]);
//        }
//        return sum-discounts;
//    }
//    void addItem(double price, Discount *assocPtr){
//         SingleValueDiscount temp(0.0);
//        originalPrices.push_back(price);
//        parallelDiscounts.push_back(assocPtr);
//    }
//    vector <double> originalPrices;
//    vector <Discount*> parallelDiscounts;
//};
//
//
//int main(){
//    Order firstOrder;
//    SingleValueDiscount svd10(10);
//    SinglePercentDiscount spd5(.5);
//    MultiDiscount md(.102, 5.5);
//    firstOrder.addItem(20, &svd10);
//    firstOrder.addItem(100, &spd5);
//    firstOrder.addItem(20, &md);
//    firstOrder.addItem(20, nullptr);
//    cout<<firstOrder.totalCost();
//    return 0;
//}
//

//Doubly Linked List Corrupt
////Winter 2021 #7
//
//template< class T>
//class LListNode{
//public:
//    T data;
//    LListNode* next;
//    LListNode* prev;
//    void fixCorruption(LListNode<T>& firstNode){
//        LListNode<T> *itr=firstNode;
//        LListNode<T> *lastNodeSeen = nullptr;
//        while (itr->next != nullptr){
//            if (itr->next == lastNodeSeen){
//                LListNode<T> *realNext=itr->prev;
//                LListNode<T> *realPrev=itr->next;
//                itr->next=realNext;
//                itr->prev=realPrev;
//            }
//            lastNodeSeen = itr;
//            itr=itr->next;
//        }
//    };
//};
//
//int main(){
//    return 0;
//}


//Winter 2021 #6
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//vector <double> getBusLineInfo(string busLine) {
//    return {14, 0, 5.2, 5.8, 7};
//}
//
//bool bussesTooClose(string& busLine){
//    vector<double> busLineOne = getBusLineInfo(busLine);
//    std::sort(busLineOne.begin(), busLineOne.end());
//
//    for (int i=0; i<busLineOne.size()-1; i++)
//        if (busLineOne[i+1]-busLineOne[i] < 1.0)
//            return true;
//    return false;
//}
//
//
//int main(){
//    string line= "Q59";
//    cout<< boolalpha<< bussesTooClose(line);
//    return 0;
//}

//Winter 2023 #8

/*
 * */

//#include <iostream>
//#include <queue>
//#include <stack>
//using namespace std;
//
//
//template <class T>
//queue<T> line {3,5,1,3};
//
//template <class T>
//void reverseQueue(queue<T>& q) {
//    // Step 1: Create a stack to temporarily hold the elements of the queue
//    stack<T> s;
//    // Step 2: Push all elements from queue onto stack
//    while (!q.empty()) {
//        // Take the front element of the queue and push it onto the top of the stack
//        s.push(q.front());
//        // Remove the front element from the queue
//        q.pop();
//    }
//    // Step 3: Pop all elements from stack and enqueue back onto queue
//    while (!s.empty()) {
//        // Take the top element of the stack and enqueue it to the back of the queue
//        q.push(s.top());
//        // Remove the top element from the stack
//        s.pop();
//    }
//}
