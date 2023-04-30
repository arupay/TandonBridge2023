#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class PersonNode;
class PeopleLList;

class PersonNode {
public:
    double getPaidAmount() const{return paidAmount;}
    string getPersonName() const{return personName;}
    double getOwedAmount() const{return owedAmount;}
    void setPaidAmount(double amt){paidAmount=amt;}
    void setPersonName(const string& name){personName=name;}
    void setOwedAmount(double amt){owedAmount=amt;}
    friend class PeopleLList;
    PersonNode(double amtPaid, const string& name) : paidAmount(), owedAmount(){
        setPaidAmount(amtPaid);
        setPersonName(name);
        setOwedAmount(0);
        next=nullptr;
    }
private:
    PersonNode* next;
    double paidAmount;
    string personName;
    double owedAmount;
};

class PeopleLList{
    PersonNode* head;
    PersonNode* tail;
public:
    PeopleLList(){
        head=nullptr;
        tail=nullptr;
    };
    PersonNode* front(){
        return head;
    }
    PersonNode* back(){
        return tail;
    }
    void addPersonNode(double amt, const string& name){
        PersonNode *temp = new PersonNode(amt, name);
        if (head==nullptr){
            head =temp;
            tail=temp;
        }else{
            tail->next=temp;
            tail = tail->next;
        }
    }
    void printNodes(){
        PersonNode *temp = head;
        while (temp!=nullptr){
            cout<< temp->getPaidAmount() <<"\t" <<temp->getPersonName() <<'\t'<<temp->getOwedAmount()<<endl;
            temp=temp->next;
        }
    }
    int getSize(){
        int count=0;
        PersonNode *itr = head;
        while (itr!=nullptr){
            count++;
            itr=itr->next;
        }
        return count;
    }
    double getTotalExpenses() {
        double total = 0;
        PersonNode *itr = head;
        while (itr != nullptr) {
            total += itr->getPaidAmount();
            itr = itr->next;
        }
        return total;
    }
    void printReconciliation(){
        vector<PersonNode *> overpaidVec;
        vector<PersonNode *> underpaidVec;
        PersonNode *itr = head;
        double expectedContribution = getTotalExpenses()/getSize();
        while (itr!=nullptr) {
            double balance = itr->getPaidAmount() - expectedContribution;
            itr->setOwedAmount(balance);
            if (itr->getOwedAmount() < 0) { //if owed balance is negative means you owe
                underpaidVec.push_back(itr);
            } else if (itr->getOwedAmount() >
                       0) { //if owed balance is positive, means you overpaid and need to be credited
                overpaidVec.push_back(itr);
            } else {
                cout << itr->getPersonName() << ", you don't need to do anything."<<endl;
            }
            itr = itr->next;
        }
        int owePtr=0, creditPtr=0;
        while ( owePtr<underpaidVec.size() && creditPtr < overpaidVec.size()){
            double leftOwe = abs(underpaidVec[owePtr]->getOwedAmount());
            double rightCredit = overpaidVec[creditPtr]->getOwedAmount();
            if (leftOwe < rightCredit){
                cout<<underpaidVec[owePtr]->getPersonName()<<", you should give "
                    << overpaidVec[creditPtr]->getPersonName() <<" $"<<leftOwe<<endl;
                double prevOwed = rightCredit;
                overpaidVec[creditPtr]->setOwedAmount(rightCredit- leftOwe);
                owePtr++;
            } else if (leftOwe > rightCredit){
                cout<<underpaidVec[owePtr]->getPersonName()<<", you should give "
                    << overpaidVec[creditPtr]->getPersonName() <<" $"<<rightCredit<<endl;
                double newVal = underpaidVec[owePtr]->getOwedAmount() + rightCredit;
                underpaidVec[owePtr]->setOwedAmount(newVal);
                creditPtr++;
            } else {
                cout<<underpaidVec[owePtr]->getPersonName()<<", you should give "
                    << overpaidVec[creditPtr]->getPersonName() <<" $"<<rightCredit<<endl;
                owePtr++;
                creditPtr++;
            }
        }
        cout<<"In the end, you should all have spent around $" <<expectedContribution<<endl;
    }
};



void fileOpenFunction(ifstream& infileObj){
    string userInputFileName;
    cout<<"Enter the name of the txt file you wish to open:"<<endl;
    cin>>userInputFileName;
    infileObj.open(userInputFileName);
    if (!infileObj) {
        cout << "Error, incorrect file name, please enter file name to open:" << endl;
        cin >> userInputFileName;
        infileObj.clear();
        infileObj.open(userInputFileName);
    }
;}



int main(){
    ifstream inFile;
    fileOpenFunction(inFile);
    PeopleLList ppl;
    double tempAmt;
    string tempName;
    while (inFile>>tempAmt){
        inFile.ignore(10,'\t');
        getline(inFile, tempName);
        ppl.addPersonNode(tempAmt, tempName);
    }
    ppl.printReconciliation();
    return 0;
}