#include <iostream>
using namespace std;

int jumpItSolver(int arr[],int arrSize);
int main(){
   int jumpIt[6]={0,3,80,6,57,10};
    cout<< jumpItSolver(jumpIt, 6)<<endl;
    return 0;
}

int jumpItSolver(int arr[], int arrSize){
    if (arrSize == 2) return arr[arrSize-1] ;
    if (arrSize==1) return 0;

    if (arr[1] < arr[2] && arrSize > 3){
        return arr[1] + jumpItSolver(arr+1, arrSize-1);
    } else {
        return arr[2] + jumpItSolver(arr+2, arrSize-2);
    };
}

