#include <iostream>
using namespace std;

int sumOfSquare(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
int main(){
    int squaresArr[5]={1,2,3,4,5}; //==> 55
    cout<< "The sum of the squares of {1,2,3,4,5} is " << sumOfSquare(squaresArr,5)<<endl;
    cout<<"--------------------------------"<<endl;
    int sortedArr[5] = {5,6,7,8,9}; // True
    int unsorted[5] = {9,3,5,6,2}; // False
    int unsortedArr[5] = {5,2,3,7,4}; // False
    cout<<boolalpha<< "Is array { 5,6,7,8,9 } is sorted ascending? "<<isSorted(sortedArr,5)<<endl;
    cout<< "Is array { 5,2,3,7,4 } is sorted ascending? "<< isSorted(unsortedArr,5)<<endl;
    cout<< "Is array { 9,3,5,6,2 } is sorted ascending? "<< isSorted(unsorted,5)<<endl;

    return 0;
}
int sumOfSquare(int arr[], int arrSize){
    if (arrSize==0){
        return 0;
    } else {
        return (arr[arrSize-1] * arr[arrSize-1]) + sumOfSquare(arr, arrSize-1);
    }
}

bool isSorted(int arr[], int arrSize){
    if (arrSize<1) {
        return true;
    }
    if ( arr[arrSize-1] < arr[arrSize-2])
        return false;
    else
        return isSorted(arr, arrSize-1);
}