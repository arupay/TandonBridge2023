#include <fstream>
#include <iostream>
#include <string>
#include<stack>

using namespace std;

string openInStream(ifstream &fileObj) {
  string pathName;
  cout << "Enter pathname to pascal file" << endl;
  cin >> pathName;
  fileObj.open(pathName);
  if (!fileObj) {
    cout << "Error, double check pathname and reenter" << endl;
    cin >> pathName;
    fileObj.clear();
    fileObj.open(pathName);
  }
    string allChars;
    char currChar;
    while (fileObj>>currChar){
        allChars+=currChar;
    }
    return allChars;
}

bool pascalSyntaxChecker(string& symbols){
    /*CHECKING FOR VALID BEGIN END CRITERIA*/
    size_t startIdx = symbols.find("begin");
    size_t endIdx= symbols.find("end");
    if (startIdx==string::npos || endIdx==string::npos){
        cout<<"Invalid. This string does not have proper begin or end syntax."<<endl; // if there is no begin or no end, code is invalid.
        return false;
    } else {
        startIdx+=5;// moves pointer 5 spaces to the end of word begin.
    }
    int codeLength = endIdx-startIdx;
    symbols= symbols.substr(startIdx, codeLength);

    /*CHECKING FOR SYMBOLS BALANCE*/
    const pair<char, char> parenthesis={'(',')'};
    const pair<char,char> brackets={'[',']'};
    const pair <char,char> curly={'{','}'};
    stack<char> symbolStack;
    for (int i=0; i<symbols.length(); i++){
        char currSymbol = symbols[i];
        if (currSymbol==parenthesis.first ||currSymbol==brackets.first || currSymbol==curly.first){
            symbolStack.push(currSymbol);
        }
        if (currSymbol == parenthesis.second){
            if (!symbolStack.empty() && symbolStack.top()==parenthesis.first ){
                symbolStack.pop();
            }else {
                return false;
            }
        }
        if (currSymbol == curly.second){
            if (!symbolStack.empty() && symbolStack.top()==curly.first ){
                symbolStack.pop();
            }else {
                return false;
            }
        }
        if (currSymbol == brackets.second){
            if (!symbolStack.empty() && symbolStack.top()==brackets.first ){
                symbolStack.pop();
            }else {
                return false;
            }
        }
    }
    return symbolStack.empty();
}

int main() {
    char userInput;
    cout<<"Please enter 1 to test with file, or 2 to run auto tests."<<endl;
    cin>>userInput;
    if (userInput=='1'){
        string pascalChars;
        ifstream objFile;
        pascalChars = openInStream(objFile);
        cout<< boolalpha<<"Is the string valid? " <<endl;
        cout << pascalSyntaxChecker(pascalChars);
    } else {
        string testOne= "begin {}{}{} end";
        cout<<"The following pascal code should return true : "<< testOne<<endl;
        cout<<boolalpha<< pascalSyntaxChecker(testOne)<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        string testTwo= "begin {[]}{x=y}{[]} end";
        cout<<"The following pascal code should return true : "<< testTwo<<endl;
        cout<<boolalpha<< pascalSyntaxChecker(testTwo)<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        string testThree= "begin ({[(()())]}) end";
        cout<<"The following pascal code should return true : "<< testThree<<endl;
        cout<<boolalpha<< pascalSyntaxChecker(testThree)<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        string testFour= "begin ({}(]) end";
        cout<<"The following pascal code should return false : "<< testFour<<endl;
        cout<<boolalpha<< pascalSyntaxChecker(testFour)<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        string testFive= "{}{}{}";
        cout<<"The following pascal code should return false : "<< testFive<<endl;
        cout<<boolalpha<< pascalSyntaxChecker(testFive)<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        string testSix= "begin ((((( end";
        cout<<"The following pascal code should return false : "<< testSix<<endl;
        cout<<boolalpha<< pascalSyntaxChecker(testSix)<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        string testSeven= "begin ))))))) end";
        cout<<"The following pascal code should return false : "<< testSeven<<endl;
        cout<<boolalpha<< pascalSyntaxChecker(testSeven)<<endl;
        cout<<"----------------------------------------------------------------"<<endl;

    }
  return 0;
}
