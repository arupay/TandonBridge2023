#include <fstream>
#include <iostream>
#include <list>
#include <string>

using namespace std;

void openInStream(ifstream &fileObj) {
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
}

int main() {
  ifstream objFile;
  openInStream(objFile);
  return 0;
}
