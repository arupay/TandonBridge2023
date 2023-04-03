#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);
int main(){
    const int arrSize=10;
    int nums[arrSize]={9,-2,14,12,3,6,2, 1,-9,15};
    cout <<"nums = {9,-2,14,12,3,6,2,1,-9,15}"<<endl;
    cout <<"--------------------------"<<endl;
    cout <<"1st function minInArray(nums,10) ==> -9"<<endl;
    cout<<minInArray(nums, arrSize)<<endl;
    cout <<"1st function minInArray(nums+2,4)==> 3"<<endl;
    cout<<minInArray(nums+2, 4)<<endl;
    cout <<"2nd function minInArray2( 0,9) ==>-9"<<endl;
    cout<< minInArray2(nums,0,9)<<endl;
    cout <<"2nd function minInArray2( 2,5)==> 3"<<endl;
    cout<< minInArray2(nums,2,5)<<endl;
    return 0;
}
int minInArray(int arr[], int arrSize){
    if (arrSize==1) {
        return arr[0];
    }
    if (arr[arrSize-1] < minInArray(arr,arrSize-1)){
        return arr[arrSize-1];
    } else {
        return minInArray(arr,arrSize-1);
    }
}

int minInArray2(int arr[], int low, int high){
    if (low==high){
        return arr[low];
    }
    if (arr[low] < minInArray2(arr, low+1, high)){
        return arr[low];
    } else {
        return minInArray2(arr,low+1,high);
    }
}
