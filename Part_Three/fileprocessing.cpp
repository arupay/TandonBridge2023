
/* How can we access data on the file system?
 * Input-> Reading data into the program
 * Output ->Writing data out from the program
 *
 *Files & Locks
 *-------------
 * Files all contain a name, the extension tells the OS what might inside the file, what program may be useful to access.
 *(.txt .xls .doc)// They may be hidden
 *You must specify a directory when opening a file or the operating system assumes the current directory.
 *Two programs at once cannot use at file. There is a LOCK to prohibit reading of a file that's being written to.
 *
 *
 *Objects
 * -------
 *C++ Has an INTERNAL REPRESENTATION for a file
 *The datatype differs if we're discussing an input file or an output file
 * INPUT -> ifstream                OUTPUT -> ofstream
 *
 *Steps to Creating
 * ----------------
 *First you must "#include <fstream>" in your program
 *You must create an object of the type appropriate to the action you wish to perform
 *You must "open" the connection to the file on the storage system
 *--> This amy fail, YOU SHOULD ALWAYS CHECK
 * Once opened, feel free to use for input or output in the same way you'd use cin/cout
 *
 * Passing to a Function
 * ----------------------
 * ifstream and ofstream objects may be passed to and returned from a function
 * when passing, they MUST BE PASSED (or RETURNED) by REFERENCE
 *      --The act of writing to or reading from one of these objects changes the object.
 *       --Specifically we have inside the file object , a POINTER to how far into the file we've been working with
 *       so when we read in, we read in from where we last left of.
 *       -Any read in or write out will change the POINTER.
 *
 *
 * cin and cout
 * cin and cout are ALSO objects
 * cin's datatype is istream, cout's datatype is ostream
 * ifstream is a derived class of istream, so we can setup our functions to use "istream&" and it can accept either cin
 * or a file stream!
 *
 * Every ifstream, can be treated like an istream obj and ostream like if it were ofstream
 * --> functions designed to accept ifstream or ofstream can reverse accept derived class too!
 *
 * C++ MAKES IT EASY
 * -----------------
 * create object (ofstream outFile)
 * open it! (outFile.open("filename.txt"))
 * You can also use the constructor of ofstream class (ofstream outFile("filename.txt") default constructor
 * Rarely will it fail, but double check!! (Full drive errors, no permission errors)
 * Once you open it you can output the file exactly as you would on the screen
 * outfile<<"HELLO WORLD"<<endl;
 *
 * When opening a file,
 *  --If the file does exist, it will be overwritten!
 *  --If the file doesn't exist, it will be created
 *
 * When you are done, call the CLOSE function on the file
 *
 * Realize that there is a buffer for the output so the actual writing of the file may not happen UNTIL you call close.
 *If ostream falls out of scope and is destroyed, or the program ends, then you don't have to close, but CLSOE TO BE SAFE.
 *
 */
//CREATES A FILE AND WRITES INTO IT
//---------
//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int main(){
//    ofstream outFile; //ofstream outFile("outfile.txt);
//    outFile.open("infilepath.txt");
//    outFile<<"Hello World"<<endl;
//    outFile.close();
//};


/*Just like ofstream, ifstream is for READING information
 *      ifStream inFile("file.txt"); or you can use .open just like ofstream.
 *ifstream objects are more likely to fail when opening
 *       Usually due to bad filename or the lack of existence
 *
 * ifstream includes a bool member that allows us to check the validility of the file, we should couple it
 * with a WHILE loop
 *
 * If you try opening the file again, you must clear the flag using .clear
 *
 * Process, we attempt to open file, if it fails we enter while statement, then we check to see if it has failed to open,
 * we call clear to clear flags, and open to open it again.  This way if it opens the 2nd time, the flags SHOULD CLEAR.
 *
 * CODE BELOW-
 * */

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//using namespace std;
//
//void openInputFile(ifstream& inFile){
//    string filename;
//    cout<<"What filename? ";
//    cin>>filename;
//    inFile.open(filename); //first we try to open
//    while (!inFile){  //while loop if the file failed to open, !inFile
//        cout<<"File failed to open!"<<endl;
//        cout<<"What filename? ";
//        cin>>filename;
//        inFile.clear(); // must CLEAR flag, what we are testing for is a flag that shows failure, even if we have a success
//        //the previous failure will cause the flag to remain.
//        inFile.open(filename);
//    }
//
//}
//
//int main(){
//    ifstream inFile;
//    openInputFile(inFile);
//    vector<int> v;
//    int temp;
//    while (inFile>>temp){//DO NOT USE EOF to read files, instead do THIS!!
//        v.push_back(temp);
//    }
//    double sum=0;
//    for (int item: v)
//        sum+= item;
//    cout<<"The average of the integers in teh file is :"<<sum/v.size() <<endl;
//}

//while(inFile>>temp)
//The while look has a two step process that does the read in operation and the test to see if it was sucessful. Optimal solution
//The >> operator will skip over all white space characters in C++
//It stops when it reaches trailing whitesapces or INVALID characters
//IN A LOOP: This reads valid chars, and stops at whitespaceds.

//WHATS VALID?

//What is valid always depends on the data type.
// the data type of TEMP DEFINES the valid character type


//if STRING --> ANYTHING
//if ints --> WHOLE NUMBERS  (no periods)
//if double --> NUMBERS AND ONE PERIOD (second period invalid/stop)
//char --> ONE CHAR --> (second char invalid/stop)


//But how can we read a whole line of text ?  USE GETLINE!

//We can use the getline function to get everything up to the end of the line, or '\n' char
//              --> getLine(inFile, myString);
//This is a great way to get a lot of data off a file!

//WHAT DOES IGNORE DO?

//If we want to skip over a set of characters we can use the ignore function.  We specicy how many chars we to skip,
//and we specify where to stop at!

//--> inFile.ignore(9999,'\n') --> TAKES ignore(how many chars to ignore, delimiter)
//-------> this skips up to 9,999 chars or the fist return char that you see.


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void openAndWrite(ifstream& obj){
    string userInputFileName;
    cout<<"Enter file name";
    cin>> userInputFileName;
    obj.open(userInputFileName);
    while(!obj){
        cout<<"Error, wrong filename please re-enter";
        cin>>userInputFileName;
        obj.clear(); //clear flag
        obj.open(userInputFileName);
    }
}

struct Student{
    int id;
    double testScore;
    string name;
};

int main(){
    ifstream thisFile;
    openAndWrite(thisFile);
    vector<Student> studentVec;
    Student temp;
    while (thisFile>>temp.id){
        thisFile>>temp.testScore;
        thisFile.ignore(9999,'\t'); //IGNORE TAB CHARS AFTER TEST SCORE!!
        getline(thisFile, temp.name);
        studentVec.push_back(temp); // DONT FORGE TTO PUSH INTO VEC;
    }
    for (Student v: studentVec){
        if (v.testScore >90){
            cout<<v.name;
        }
    }
}


//SEEKG
/* is a function in c++ that is used to set the position of the file pointer in an input file stream (ifstream)
 * ALLOWS YOU TO MOVE THE FILE POINTER TO SPECIFIC POSITION AND READ DATA FROM THAT POSITION!!!
 *
If we hare reached the end of marker (EOF) where the file is in a failed space, using seekG to the beginning
 does NOT CLEAR THOSE FLAGS.  make sure you call Clear!!!
 */

//What if we want to both READ AND WRITE!!!???

/*It is actually strange to do both at the same time -- not usual nor recommended!
 * --->usually we will read entire file
 * --->make changes to memory
 * --->write the file to the disk!
 * */


//APPENDING!!

//We can always add data to the end of a file
//Appending leaves the contents fo the file alone, and we add on to the end of the file.

//We pass a second parameter to the open file

//When passed as a second parameter to .open, ios::app is a way to tell C++ that you want to append to the file, and not overwrite it
//If the file doesn't exist it will be created;

