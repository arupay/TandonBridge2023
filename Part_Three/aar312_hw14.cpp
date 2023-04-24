/*The following divide-and-conquer algorithm is proposed for finding the simultaneous maximum and minimum: If there is one item, it is the maximum and minimum, and if there are two items, then compare them, and in one comparison you can find the maximum and minimum.


 Otherwise, split the input into two halves, divided as evenly as possibly (if N is odd, one of the two halves will have one more element than the other). Recursively find the maximum and minimum of each half, and then in two additional comparisons produce the maximum and minimum for the entire problem.

Write the above function which will take in a vector and solve the problem, producing a vector of two elements, the min and max.*/

#include <vector>
#include <iostream>
using namespace std;


vector<int> findMinMaxRecursive(vector<int>& nums, int firstIndex, int lastIndex) {
    if (firstIndex==lastIndex){
        return {nums[firstIndex], nums[firstIndex]};
    } else if (lastIndex-firstIndex==1){
        if (nums[firstIndex]> nums[lastIndex]) //check order is {min, max}
            return {nums[lastIndex], nums[firstIndex]}; //reverse if not ascending
        else
            return {nums[firstIndex], nums[lastIndex]}; //keep as is
    } else {
        int middle = (firstIndex + lastIndex) / 2;
        vector<int> left = findMinMaxRecursive(nums, firstIndex, middle);
        vector<int> right = findMinMaxRecursive(nums, middle + 1, lastIndex);
        int smallestAtZero = left[0] <= right[0] ? left[0] : right[0]; // ternary eval
        int smallestAtOne = right[1] >left[1] ? right[1] : left[1]; //ternary eval
        return { smallestAtZero, smallestAtOne };
    }
}


int main(){
    vector<int> test = {8,2,9,6,5,3,7,4}; //max=500, min=1
    vector<int> ret = findMinMaxRecursive(test, 0, 7);
    cout<<ret[0]<<" "<<ret[1]<<endl;
    vector<int> test2 = {91, 99, 51, 91, 56, 55 ,30, 36}; //30, 99
    vector<int> ret2 = findMinMaxRecursive(test2, 0, 7);
    cout<<ret2[0]<<" "<<ret2[1]<<endl;
    vector<int> test3 = {63, 8, 28, 33, 81, 77, 24, 34}; //8,81
    vector<int> ret3 = findMinMaxRecursive(test3, 0, 7);
    cout<<ret3[0]<<" "<<ret3[1]<<endl;
    vector<int> test4 = {96, 61, 2, 29, 74, 81, 90, 51}; //2,96
    vector<int> ret4 = findMinMaxRecursive(test4, 0, 7);
    cout<<ret4[0]<<" "<<ret4[1]<<endl;
    vector<int> test5 = {-50, -22, -6, -48, 16, -38, 12, 21}; //-50,21
    vector<int> ret5 = findMinMaxRecursive(test5, 0, 7);
    cout<<ret5[0]<<" "<<ret5[1]<<endl;
    vector<int> test6 ={40, 1, 48, -6, 3, 23, -37, -22}; //-37, 48
    vector<int> ret6 = findMinMaxRecursive(test6, 0, 7);
    cout<<ret6[0]<<" "<<ret6[1]<<endl;
}