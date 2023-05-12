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
//queue<T> q {3,5,1,3};
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
//
//
//
//
//#include <iostream>
//#include <stack>
//#include<list>
//#include<fstream>
//#include <string>
//#include <vector>
//using namespace std;
//
//void openfile(ifstream &fileObj) {
//    string pathName;
//    cout << "Enter pathname to pascal file" << endl;
//    cin >> pathName;
//    fileObj.open(pathName);
//    if (!fileObj) {
//        cout << "Error, double check pathname and reenter" << endl;
//        cin >> pathName;
//        fileObj.clear();
//        fileObj.open(pathName);
//    }
//}
//
//void readingFile(ifstream& file, list<string>& tags){
//    string word;
//    char temp;
//    while (file>>temp){
//        if (temp=='<'){
//            getline(file,word,'>');
//            tags.push_back(word);
//        }
//    }
//}
//
//bool validMarkUp(list<string>& tags){
//    stack<string> stackWords;
//    while (!tags.empty()){
//        string temp = tags.front();
//        if(temp[0]!= '/'){
//            stackWords.push(tags.front());
//            tags.pop_front();
//        } else if (temp[0]=='/'){
//            if (temp == '/' + stackWords.top()){
//                stackWords.pop();
//                tags.pop_front();
//            } else {
//                return false;
//            }
//        }
//    }
//    return stackWords.empty();
//}
//
//int main(){
//    ifstream file;
//    openfile(file);
//    list<string> tags;
//    readingFile(file, tags);
//    cout<<boolalpha<< validMarkUp(tags);
//    return 0;
//}


//Ellipsis Problem
//
//#include <iostream>
//#include <fstream>
//#include <string>
//
//
//using namespace std;
//
//void fileReader(ifstream& file){
//    string fileAddress;
//    cout<<"Please enter file address:"<<endl;
//    cin>>fileAddress;
//    file.open(fileAddress);
//    if (!file){
//        cout<<"Error, please enter address once more"<<endl;
//        cin>>fileAddress;
//        file.clear();
//        file.open(fileAddress);
//    }
//}
//
//int ellipsesCounter(ifstream& file){
//    char currChar;
//    int count=0;
//    string ellipStr;
//    while (file>>currChar) {
//        if (currChar == '.'){
//            while (currChar == '.' && !file.eof()){
//                ellipStr += currChar;
//                file.get(currChar);
//            }
//            if (ellipStr=="...")
//                count++;
//        }
//        ellipStr="";
//    }
//    return count;
//}
//
//int main(){
//    ifstream file;
//    fileReader(file);
//    cout<<"THE NUMBER OF ELLIPSES IS!"<<endl;
//    cout<<ellipsesCounter(file);
//    return 0;
//}


//STRANGE SORT PROBELM

//#include <stack>
//#include <vector>
//#include <iostream>
//using namespace std;
//
//vector<int> strangeSort(vector<int>& inputVec){
//    stack<int> oddStack;
//    vector<int> returnVector;
//    for (auto num: inputVec)
//        if (num%2==0)
//            returnVector.push_back(num);
//        else
//            oddStack.push(num);
//    while (!oddStack.empty()){
//        returnVector.push_back(oddStack.top());
//        oddStack.pop();
//    }
//    return returnVector;
//}
//
//void reader(vector<int>& vec){
//    for (auto i: vec){
//        cout<<i<<" ";
//    }
//    cout<<endl;
//}
//int main(){
//    vector<int> test1 {1,7,3,4,2,8};
//    vector<int> sortedTest1 = strangeSort(test1);
//    reader(sortedTest1);
//}
//

//#include <list>
//#include<iostream>
//using namespace std;
//
//
//template <class T>
//class Stack {
//public:
//   list<T> data;
//   void push(T item);
//   void pop();
//   Stack<T> operator-();
// };
//
//template <class T>
//void Stack<T>::push(T item){data.push_back(item);}
//
//template<class T>
//void Stack<T>::pop(){data.pop_back();}
//
//template<class T>
//Stack<T> Stack<T>::operator-(){
//    list<T> prev = data;
//    Stack<T> temp;
//    while (!prev.empty()){
//        temp.push(prev.back());
//        prev.pop_back();
//    }
//    return temp;
//}
//
//
//int main(){
//    // create a new stack
//    Stack<int> myStack;
//
//    // push some items onto the stack
//    myStack.push(1);
//    myStack.push(2);
//    myStack.push(3);
//
//    // test the stack before reversal
//    cout << "Before reversal: ";
//    for (int item : myStack.data) {
//        cout << item << " ";
//    }
//    cout << endl;
//
//    // reverse the stack
//    Stack<int> reversedStack = -myStack;
//
//    // test the stack after reversal
//    cout << "After reversal: ";
//    for (int item : reversedStack.data) {
//        cout << item << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

//PROBLEM 10 EMPLOYEES
//#include <iostream>
//#include <vector>
//#include <fstream>
//using namespace std;
//
//class Employee{
//public:
//    Employee(char empType, string empName){ type=empType, name=empName;}
//    char type;
//    string name;
//    virtual double totalCompensation()=0;
//};
//class HourlyEmp: public Employee{
//public:
//    HourlyEmp(char empType, string empName, double rate, double workedHours) : Employee(empType, empName) { hourly=rate, hoursWorked = workedHours;}
//    virtual double totalCompensation();
//    double hourly;
//    double hoursWorked;
//}
//;
//
//class SalaryEmp: public Employee{
//public:
//    SalaryEmp(char empType, string empName, double pay) : Employee(empType, empName){ salary=pay;}
//    virtual double totalCompensation();
//    double salary;
//};
//
//void reader(vector<Employee*> vec){
//    for (auto employee: vec){
//       cout<<  employee->name << " should be paid $ " << employee->totalCompensation()<<"."<<endl;
//    }
//}
//
//double HourlyEmp::totalCompensation() {
//    if (hoursWorked <40){
//        return hoursWorked * hourly;
//    }else {
//        double overtime = hoursWorked-40.0;
//        double overtimePay = overtime   * (hourly * 1.5);
//        double regularPay = 40 * hourly;
//        return (regularPay + overtimePay);
//    }
//}
//
//double SalaryEmp::totalCompensation() {
//    return salary;
//}
//
//
//vector<Employee*> readFile(ifstream &file){
//    vector<Employee*> employeeVec;
//    string fileName;
//    cout<<"enter file name"<<endl;
//    cin>>fileName;
//    file.open(fileName);
//    if (!file){
//        cout<<"please enter correct name"<<endl;
//        cin>>fileName;
//        file.clear();
//        file.open(fileName);
//    }
//    char employeeType;
//    while (file>>employeeType){
//        if (employeeType== 'S'){
//            string name;
//            double salary;
//            file>>salary;
//            file.ignore(9999,'\t');
//            getline(file,name);
//            SalaryEmp* employee = new SalaryEmp('S', name, salary);
//            employeeVec.push_back(employee);
//        }else {
//            string name;
//            double hourlyRate;
//            double hoursWorked;
//            file>>hourlyRate;
//            file.ignore(9999,'\t');
//            file>>hoursWorked;
//            file.ignore(9999,'\t');
//            getline(file,name);
//            HourlyEmp* employee = new HourlyEmp('H', name, hourlyRate, hoursWorked);
//            employeeVec.push_back(employee);
//        }
//    }
//    return employeeVec;
//}
//int main(){
//    ifstream employeeFile;
//    vector<Employee*> employees;
//    employees = readFile(employeeFile);
//    reader(employees);
//
//}
//
//
//#include <iostream>
//
//template <class T>
//class LListNode{
//    T data;
//    LListNode<T>* next;
//    LListNode<T>* prev;
//};
//
//template <class T>
//class LList{
//    LListNode<T>* head;
//    void corruptListFixer(LListNode<T> *ptr);
//};
//
//template <class T>
//void LList<T>::corruptListFixer(LListNode<T> *ptr) {
//    LListNode<T> *temp = ptr;
//    LListNode<T> *lastNode = nullptr;
//    while (temp->next!=nullptr){
//        if (temp->next == lastNode){
//            temp->next=temp->prev;
//            temp->prev=lastNode;
//        }
//        lastNode=temp;
//        temp=temp->next;
//    }
//}


//CRYPTOGRAPHY Q8
//
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <map>
//
//using namespace std;
//
//string fileReader (ifstream& file){
//    string userInput;
//    cout<<"please enter file name: ";
//    cin>>userInput;
//    file.open(userInput);
//    if (!file){
//        cout<<"please enter file name again: ";
//        cin>>userInput;
//        file.clear();
//        file.open(userInput);
//    }
//    string letters;
//    char currChar;
//    while (file>>currChar){
//        if (int(currChar) >= 65 && int(currChar) <= 90 ){
//            currChar= currChar+32;
//        }
//        if (int(currChar) >= 97 && int(currChar) <= 122 ){
//            letters+=currChar;
//        }
//    }
//    return letters;
//}
//
//map<char,int> createMap(string& str){
//    map<char,int> newMap;
//    for (int i=0; i<str.length(); i++){
//        if (newMap.find(str[i])== newMap.end()){
//            newMap.insert({str[i], 1});
//        }else {
//            newMap[str[i]] = newMap[str[i]]+1;
//        }
//    }
//    return newMap;
//}
//int main(){
//    ifstream obj;
//    string letters;
//    map <char,int> mapOfFreq;
//    letters = fileReader(obj);
//    mapOfFreq =  createMap(letters);
//    for (auto const & x: mapOfFreq){
//        cout<<x.first<<" :"<<x.second<<endl;
//    }
//}

//Q11 SPRING 2020
//#include <iostream>
//#include <vector>
//#include  <string>
//
//using namespace std;
//
//class Gift{
//    string name;
//    double price;
//public:
//    Gift(string newName, double newPrice=0){name=newName, price=newPrice;}
//    Gift();
//    string getName()const { return name;}
//    void setPrice(double newPrice){price=newPrice;}
//    double getPrice()const {return price;}
//    friend ostream& operator<<(ostream &out, Gift &gift);
//};
//
//ostream& operator<<(ostream &out, Gift &gift) {
//    out << "Gift: " << gift.getName() <<": $"<< gift.getPrice();
//    return out;
//}
//
//
//
//class RealGift: public Gift{
//public:
//    RealGift(string desc, double val=0);
//    void breakFn();
//};
//
//void RealGift::breakFn(){
//
//    double newPrice = getPrice()/2;
//    setPrice(newPrice);
//}
//
//RealGift::RealGift(string desc, double val) : Gift(desc, val){}
//
//class MoneyGift: public Gift{
//    MoneyGift(double value): Gift("Money", value) {}/*CALL TO CONSTRUCTOR*/
//};
//
//
//int main(){
//    Gift newGift("Car", 2300.00);
//    cout<<newGift;
//}

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//void readfile(ifstream& obj){
//    string userInput;
//    cout<<"Please enter file path"<<endl;
//    cin>>userInput;
//    obj.open(userInput);
//    while (!obj){
//        cout<<"Please enter correct file path"<<endl;
//        cin>>userInput;
//        obj.clear();
//        obj.open(userInput);
//    }
//}
//
//vector<int> intVec (ifstream& obj){
//    vector<int> numVec;
//    int num;
//    while (obj>>num){
//        numVec.push_back(num);
//    }
//    return numVec;
//}
//
//int findMedian (vector<int>& vec){
//    sort(vec.begin(), vec.end());
//}
//
//int main(){
//    ifstream file;
//    readfile(file);
//    vector<int> numVec= intVec(file);
//    sort(numVec.begin(), numVec.end());
//    for (auto i: numVec){
//        cout<<i<<" ";
//    }
//    cout<<endl;
//}




/**/
//#include <iostream>
//using namespace std;
//
//class Package;
//class Box;
//class Envelope;
//
//class Package{
//public:
//    double weight;
//    Package(){};
//    Package(double inputWeight){weight=inputWeight;}
//    double effectiveWeight();
//};
//
//class Box: public Package{
//public:
//    Box(){}
//    Box(double inputWeight, double inputCubicArea) : Package(inputWeight) {cubicArea=inputCubicArea;}
//    double effectiveWeight();
//    double cubicArea;
//};
//
//class Envelope: public Package{
//public:
//    Envelope(){}
//    Envelope(double inputWeight): Package(inputWeight) {};
//    double effectiveWeight();
//};
//
//double Envelope::effectiveWeight() {
//    return weight;
//}
//
//double Box::effectiveWeight() {
//    return cubicArea>= weight ? cubicArea : weight;
//}
//
//
//int main(){
//    Envelope envie(10.0);
//    cout<<envie.weight;
//    cout<<endl;
//    Box boxie(110.0,5.0);
//    cout<<boxie.weight<<" "<<boxie.cubicArea;
//    cout<<endl;
//    cout<<envie.effectiveWeight()<<endl;
//    cout<<boxie.effectiveWeight()<<endl;
//}


//#include <iostream>
//using namespace std;
//
//void push_back(LlistNode<T>* someNode){
//    if (head==nullptr){
//        head=someNode;
//        head->next=head;
//    }else {
//        LlistNode <T> *itr = head;
//        while (itr->next != head) {
//            itr = itr->next;
//        }
//        itr->next = someNode;
//        someNode->next = head;
//    }
//}
//
//#include<iostream>
//#include <queue>
//
//template <class T>
//class BSTNode;
//
//using namespace std;
//
//template <class T>
//class BST{
//    BSTNode<T>* root;
//public:
//    void insert(T item);
//
//};
//template <class T>
//class BSTNode{
//public:
//    T data;
//    BSTNode<T>* parent;
//    BSTNode<T>* rightChild;
//    BSTNode<T>* leftChild;
//    BSTNode(T newData=T(), BSTNode<T>* newParent = nullptr, BSTNode<T>* newRight = nullptr, BSTNode<T>* newLeft = nullptr)
//            : data(newData), parent(newParent), rightChild(newRight), leftChild(newLeft){}
//    friend class BST<T>;
//    int getSize() const;
//};
//
//template <class T>
//int BSTNode<T>::getSize() const{
//    int count =1;
//    if (leftChild!=nullptr)
//        count+= leftChild->getSize();
//    if (rightChild!= nullptr){
//        count+=rightChild->getSize();
//    }
//    return count;
//}
//
//template <class T>
//bool is_height_tree(BSTNode<T>*& root, int currLevel=1){
//    if (root== nullptr){
//        return false;
//    }
//    if (root->data!=currLevel){
//        return false;
//    }
//    bool Left = is_height_tree(root->leftChild, currLevel+1);
//    bool Right  =  is_height_tree(root->rightChild, currLevel+1);
//
//    return Left==true && Right==true;
//}
//
//template <class T>
//int getHeight(BSTNode<T>* root){
//    if (root==nullptr){
//        return 0;
//    }
//    int leftHeight = getHeight(root->leftChild );
//    int rightHeight= getHeight(root->rightChild );
//    return 1+ max(leftHeight, rightHeight);
//}
//
//
//
//int main(){
//    BSTNode<int>* root = new BSTNode<int>(1);
//    root->leftChild = new BSTNode<int>(2);
//    root->rightChild = new BSTNode<int>(2);
//    root->leftChild->leftChild = new BSTNode<int>(3);
//    root->leftChild->rightChild = new BSTNode<int>(3);
//    root->rightChild->leftChild = new BSTNode<int>(3);
//    root->rightChild->rightChild = new BSTNode<int>(3);
////
//    int height = getHeight(root);
//    cout<<height; // returns 3
//    cout <<boolalpha<< is_height_tree(root);
//}

//#8 NANP PROBLEM
//#include <iostream>
//using namespace std;
//
//class E164Number;
//class NANPNNumber {
//    int areaCode=999;
//    int firstThree=999;
//    int lastFour=9999;
//public:
//    NANPNNumber(){}
//    NANPNNumber(int newArea, int newFirstThree, int newLastFour){
//      if (  validThreeDigit(newArea))
//          areaCode=newArea;
//      if (validThreeDigit(newFirstThree))
//          firstThree=newFirstThree;
//      if (validFourDigit(newLastFour))
//          lastFour=newLastFour;
//    }
//    bool validThreeDigit(int &num){
//        if (num>=100 && num<=999)
//            return true;
//        else
//            return false;
//    }
//    bool validFourDigit(int &num){
//        if (num>=1000 && num<=9999)
//            return true;
//        else
//            return false;
//    }
//    friend ostream& operator <<(ostream& out, NANPNNumber& thing){
//        out << thing.areaCode << "-"<< thing.firstThree  << "-"<<thing.lastFour;
//        return out;
//    }
//    friend E164Number;
//};
//
//class E164Number : public NANPNNumber{
//public:
//    E164Number(const NANPNNumber& rhs){
//        areaCode= rhs.areaCode;
//        firstThree=rhs.firstThree;
//        lastFour=rhs.lastFour;
//    };
//
//    E164Number(int area, int firstthree, int lastfour) : NANPNNumber(area, firstthree, lastfour) {
//    }
//
//    friend ostream& operator <<(ostream& out, E164Number& thing){
//        out << '+' << 1 <<" "<< thing.areaCode << "-"<< thing.firstThree  << "-"<<thing.lastFour;
//        return out;
//    }
//};
//void dialNumber(E164Number num){
//    cout<<num;
//}
//
//
//
//
//int main(){
//    NANPNNumber newNum(516,323,4423);
//    dialNumber(newNum);
//    E164Number secNum(555,222,2222);
//    cout<<secNum;
//
//}
/*Sorting doubly linked list.
 *
 * I would use insertion sort -- in insertion sort we assume the first node is already sorted. if there is only one node in our linked list
 * we return it, as it's already sorted.
 * We then continue iterating to the next element k, and compare it to our left element(or elements).  We place it in its correct position
 * in our already sort left side. we do thi continously until we evaluate every element and place it in its correct position
 * if our elements are already sorted, runtime would be o(N)
 * and if is sorted opposite of the direction we wish, it would be O(N^2).
 * big theta is worst oN^2, best O(N)
 * */

//if data is +, only left child allowed (right child FALSE)
//if data is -, only right child allowed (left child FALSE)
//if data is 0, left && right allowed, null && null allowed (null && left FALSE, right && null FALSE);
//#include <iostream>
//using namespace std;
//
//class PLNRNode{
//public:int data;
//    PLNRNode* left;
//    PLNRNode* right;
//    PLNRNode* parent;
//};
//
//bool isValidPLNR(PLNRNode* root){
//    if (root==nullptr) return true;
//    if (root->data > 0){
//        if (root->right!=nullptr) return false;
//        return isValidPLNR(root->left);
//    }else if  (root->data < 0){
//        if (root->left!=nullptr) return false;
//        return isValidPLNR(root->right);
//    } else {
//        if ((root->right == nullptr && root->left== nullptr)||(root->right != nullptr && root->left!= nullptr)){
//            return isValidPLNR(root->left) && isValidPLNR(root->right);
//        } else {
//            return false;
//        }
//    }
//}

//int main(){
//    PLNRNode* root = new PLNRNode();
//    root->data = 0;
//
//    PLNRNode* node1 = new PLNRNode();
//    node1->data = 1;
//
//    PLNRNode* node2 = new PLNRNode();
//    node2->data = -2;
//
//    PLNRNode* node3 = new PLNRNode();
//    node3->data = 3;
//
//    PLNRNode* node4 = new PLNRNode();
//    node4->data = 0;
//
//    PLNRNode* node5 = new PLNRNode();
//    node5->data = 0;
//
//    root->left = node1;
//    root->right = node2;
//    node1->left = node3;
//    node2->right = node4;
//
//    bool isValid = isValidPLNR(root);
//    cout<<boolalpha<< isValid;
//}



/*Given an already sorted vecotr of ints, and an implementation of the HBinary Search Tree Class BST<int>
 * write a function that will insert the nodes from the vector into theb st in a way that keeps the tree balanced
 *
*/

//#include <queue>
//using namespace std;
//
//template <class T>
//class Stack{
//public:
//    queue<T> myQueue;
//    void push(T data);
//    void pop(T data);
//    int size();
//    void top();
//};
//
//template<class T>
//int Stack<T>::size(){
//    return myQueue.size();
//}
//
//template<class T>
//void Stack<T>::pop(T data) {
//    queue<T> tempStack; //temp queue
//    while (myQueue.size()>0){ //stop when there is one element left
//        T val = myQueue.front(); // copy of front() element
//        myQueue.pop(); //pop front element
//        tempStack.push(val); //push element to temporary queue
//    }
//    myQueue=tempStack; //set queue[1-10] = tempstack [1-9]
//}
//
//template<class T>
//void Stack<T>::push(T data) {
//    myQueue.push(data);
//}
//template<class T>
//void Stack<T>::top(){
//    myQueue.back(data);
//}
//
//int main(){
//
//}
//
//
//
//
//
//
//
//
//
//

//
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//string read(ifstream & obj){
//    string userInput;
//    string longNum;
//    cin>>userInput;
//    char n;
//    obj.open(userInput);
//    while (obj>>n){
//        longNum+=n;
//    }
//    return longNum;
//}
//
//
//
//int main(){
//    ifstream numFileOne;
//    ifstream numFileTwo;
//    string longNumOne =  read(numFileOne);
//    string longNumTwo =  read(numFileOne);
//    for (int i=longNumOne.length(); i>0;i--){
//
//    }
//    return 0;
//}
//
//
//
//


/* set up ifstream obj
 * read in words
 * use map
 * itereate map to print
 *
 * */

//#include <iostream>
//#include <map>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//
//void fileReader(ifstream& obj){
//    string input;
//    cout<<"Enter filename to read"<<endl;
//    cin>>input;
//    obj.open(input);
//    while (!obj){
//        cout<<"ERROR. Enter filename to read."<<endl;
//        cin>>input;
//        obj.clear();
//        obj.open(input);
//    }
//};
//
//map<string, int> mapBuilder(ifstream& obj) {
//    map<string, int> map;
//    string currWord;
//    while (obj >> currWord) {
//        if (map.find(currWord) == map.end()) {
//            map.insert_or_assign(currWord, 1);
//        } else {
//            int accrue = map[currWord]+1;
//            map.insert_or_assign(currWord, accrue);
//        }
//    }
//    return map;
//}
//
//int main(){
//    ifstream file;
//    fileReader(file);
//    map<string, int> wordMap = mapBuilder(file);
//    for (auto &x: wordMap){
//            std::cout<<x.first<<" : "<<x.second<<endl;
//        }
//    return 0;
//}


/*To sort a stack (lets callit MAIN) I would create a temporary stack which we can call TEMP. I would pop the first element from MAIN and push it onto TEMP if its larger than TEMP.top(), or if TEMP is empty.  I would then pop a second element from MAIN, I would again evluate if this elmeent is larger than TEMP.TOP(), if so I would push it onto TEMP.  If its SMALLER than TEMP.TOP(), i would POP() TEMP repeatedly (pushing every popped value onto MAIN()), until I found a value smaller, and then finally push onto temp.  Doing this repeated creates a sorted TEMP stack.  My stopping condition would be when MAIN stack is empty.   Runtime of this condition is N if the Main stack is already sorted, and N^2 if its unsorted (worst case if its reversely sorted).
 * Benefits of this approach is space complexity is N and uses only true stack methods.
 * */
//#include <vector>
//using namespace std;
//class BST;
//class BSTNode {
//public:
//    int data;
//    BSTNode* left;
//    BSTNode* right;
//    BSTNode* parent;
//};
//
//class BST{
//    BST* root;
//public:
//    void insertIntoTree(BSTNode* nodeToInsert);
//    bool isCorrect(BSTNode* rootPtr){
//        if (rootPtr==nullptr)
//            return true;
//        if (rootPtr->left->parent != rootPtr || rootPtr->right->parent != rootPtr)
//            return false;  //SEGMENTATION FAULT POSSIBILITY IF ROOT->left- IS NULLPTR. ALWAYS CHECK!!!
//            /* if (rootPtr->left != nullptr && rootPtr->left->parent != rootPtr)
//             *  return false
//             *if (rootPtr->right != nullptr && rootPtr->right->parent != rootPtr)
//             *  return false
//             * */
//        else
//            return isCorrect(rootPtr->left) && isCorrect(rootPtr->right);
//    }
//    void insertWithSortedVec(vector<int>& sortedVec, int left, int right){
//        if (left>right){
//            return;
//        }
//        int mid = (left+right)/2;
//         insert(sortedVec[mid]);
//         insertWithSortedVec(sortedVec, left, mid-1);
//        insertWithSortedVec(sortedVec, mid+1, right);
//    }
//};
//
//void BST::insertIntoTree(BSTNode *nodeToInsert) {
//}

//ABOVE
//(15 pts) Given an already sorted vector of integers and an implementation of the Binary Search Tree class (BST <int>; note this is unbalanced), write a function which will insert the nodes from the vector into BST in a way that keeps the tree balanced

//print elements in a sorted array using merge sort
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void mergePrint(vector<int>& nums, int start,int end){
//    if (start>end)
//        return;
//    int middle = (start + end) /2;
//    cout<<nums[middle]<<" ";
//    mergePrint(nums, start, middle-1 );
//    mergePrint(nums, middle+1, end );
//}
//int main(){
//    vector<int> nums = {1,2,3,4,5,6,7};
//    mergePrint(nums, 0, nums.size()-1);
//    return 0;
//}


//Expression Tree//

//class Node{
//public:
//    Node(int value){val=value;};
//    virtual int calculateValue()=0;
//    int val;
//    Node* left=nullptr;
//    Node* right=nullptr;
//};
//
//class OperandNode: public Node{
//public:
//    OperandNode(int value): Node (value){};
//    virtual int calculateValue(){
//        return val;
//    };
//};
//
//class OperatorNode: public Node{
//    char operatorChar;
//public:
//    OperatorNode(int value, char operationType) : Node(value) { operatorChar= operationType;};
//    virtual int calculateValue(){
//        switch (operatorChar) {
//            case 'x': return left->val*right->val;
//            case '+': return left->val+right->val;
//            case '/': return left->val/right->val;
//            case '-': return left->val-right->val;
//            default: return 0;
//        }
//    };
//};
//
//class ExpressionTree{
//    Node* root;
//public:
//    int CalculateValue(Node* ptrRoot) {
//        //should be in order traversal to sum up left right then middle (parent), left right then middle (parent).
//        if (ptrRoot == nullptr) {
//            return 0;
//        }
//        return root->calculateValue();
//    }
//};

//Given a binary tree where only poinetrs and data value is stored in each node, explain how you determine in Theta(N) time that three is balanced.

/*I would do a breadth first approach at solution.  I would stipulate that a diference in height of no more than 1 is acceptable for a tree to be considered balanced and for my funciton to return true.
 *
 * I would create a queue, that holds tree nodes.
 * I would create a variable called DIFFERENCE initiated at zero.
 * I would start at the root and pop the root and store it in the queue,
 * i would create a while loop that runs only if my queue has items, I would traverse the queue, diassembling left and right and nodes and pushing them back in the queue,
 * if i ever traversed a node with only one child, i would add one to DIFFERENCE;
 * if difference is ever more than 1, i break and return false.
 * if the queue execuse and the count is less than or equal to one I return true.
 * */
//template <class T>
//class LListNode{
//public:
//    LListNode<T>* next;
//    T data;
//};
//
//
//
//template<class T>
//LListNode<T>* concatenateTwoLists(const LListNode<T>* listOne, const LListNode<T>* listTwo){
//    if (listOne==nullptr && listTwo==nullptr) return nullptr;
//    //Must refactor for case when one is null ptr but other isnt.
//
//    LListNode<T>* newList = new LListNode<T>(listOne->data);
//    LListNode<T>* head = newList; //return this at the end.
//    LListNode<T>* itr = newList->next;
//        while (itr!=nullptr) {
//            LListNode<T>* newNode = new LListNode<T>(itr->data);
//            newList->next = newNode;
//            newList=newList->next;
//            itr = itr->next;
//        }
//    LListNode<T>* itr2 = listTwo; //second node
//        while (itr2!=nullptr){
//            LListNode<T>* newNode = new LListNode<T>(itr2->data);
//            newList->next = newNode;
//            newList=newList->next;
//            itr2 = itr2->next;
//        }
//        return head;
//}
//
//#include <iostream>
//#include <fstream>
//#include <set>
//#include <string>
//using namespace std;
//
//void openFile(ifstream& file){
//    string path;
//    cout<<"please enter file name"<<endl;
//    cin>>path;
//    file.open(path);
//    while (!file){
//        cout<<"ERROR, please enter file name"<<endl;
//        cin>>path;
//        file.clear();
//        file.open(path);
//    }
//}
//
//void readFile(ifstream& file, set<string>& idSet){
//    string id;
//    while (file>>id){
//        idSet.insert(id);
//    }
//}
//
//void writeOutResults(ofstream& outFile, set<string>& idSet){
//    for (auto& x: idSet){
//        outFile<<x<<endl;
//    }
//}
//int main(){
//    const string outputPath = "output.txt";
//    ifstream NYU_File;
//    openFile(NYU_File);
//    set<string> NYUIdSet;
//    readFile(NYU_File, NYUIdSet);
//    ofstream outFileNYU;
//    outFileNYU.open(outputPath);
//    writeOutResults(outFileNYU, NYUIdSet);
//    return 0;
//}

//using namespace std;
//
//class Solution {
//public:
//    vector<string> summaryRanges(vector<int>& nums) {
//        vector<string> retVec;
//        vec<int> tempVec;
//        const string arrow="->";
//        int firstPtr =0;
//        for (int i = 0; i<=nums.size();i++){
//            if (tempVec.empty() || tempVec[tempVec.size()-1] +1 == retVec[i] ){
//                tempVec.push_back(nums[i])
//            } else {
//                string range = tempVec.size()>1 ? tempVec[0] + arrow + tempVec[tempVec.size()-1]
//            }
//        }
//        return vec;
//    }
//};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* newHead = head->next;
        ListNode* itr = head;

        return head;
    }
};