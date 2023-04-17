//
// Created by Augusto Rupay on 4/17/23.
//

//Binary Search -
    //Given an integer X and integers A0...An-1, which are SORTED, find i such that Ai=X or return i= -1 if X is not in the input

/*int binarySearch(const vector<Comparable> & a, const Comparable & x);
 *
 * int low = 0;
 * int high = a.size()-1;
 *
 * while (low<=high){
 *     int mid = (low + high ) / 2;
 *     if (a[mid]>x){
 *      high = mid-1;
 *     } else if (a[mid] < x){
 *      low=mid+1;
 *     }else {
 *     return mid; //ITEM FOUND
 *     }
 *     return -1 (NOT_FOUND);
 * }
 * //LOGIC : Check if X is the middle element, if so, found, otherwise, if x is smaller tha middle, we look at the right half, otherwise look at the left half.
 *
 */


//Eucledian Algorythm

/*Repeatedly perform long division to find most common divisor
 *
 * Find gcd(1785, 546) // FIND GREATEST COMMON DIVISOR OF 1785 and 546
 *
 * 1785 / 546 = Quotient 3 with Remainder of 147.
 *
 * 546/147 = Quotient 3 Remainder of 105
 *
 * 147/105 = Quotient 1 Remainder of 42
 *
 * 105/42 = Quotient of 2 Remainder of 21
 *
 * 42/21 = Quotient of 2 Remainder of 0 --> STOP REMAINDER OF 0.  The last non zero remainder is the greatest common divisor: 21
 *
 * */

//should return an index in arr, where val first appears or -1 if val is not one of arr's element
//int search(int arr[], int arrSize, int val){
//}; //Search is linear,as it would take arrSize to traverse through array in worst case where -1 is to be returned.

//Sorted Search Problem
//We can take advantage of the sorted nature of the array by testing the middle value and deciding to go left or right depending on middle value.
//#include <iostream>
//using namespace std;
//int sortedSearch (const int startArr[], int srtArrSize, int val){
//    int low = 0;
//    int high = srtArrSize-1;
//    bool found= false;
//    int mid;
//    while (low<=high){
//        mid = (low + high)/2; // Because all vals are ints c++ takes a natural floor when doing division giving us real indices.
//        if (startArr[mid]> val){
//            high = mid-1;
//        }else if (startArr[mid]<val){
//            low = mid+1;
//        }else {
//            found = true;
//            return mid;
//        }
//    }
//    return -1;
//}
//
//int main(){
//    int sortedArray[10]={1,2,3,4,5,6,7,8,9,10};
//    cout<<sortedSearch(sortedArray, 10, 2);
//
//}

//Binary search is theta of log_2_n time complexity as it reduces the size of the input by /2 every incrememnt
//comparing the value of n vs the value of log2(n)
//2 --> log2(2) = 1;
//4 --> log2(2^2_ = 2;
//8 --> log (2^3) = 3;
//2^10--> log(2^10) = 10;
//2^32--> log(2^32) = 32;
//2^1000-> log (2^1000) = 1000;  2^1000 greater than the total number of practicals int eh universe, takes infinite time to execute
// but a logarithmic operation on the other hand basically needs to execute only 1000;


//Sorting Algos
    //Selection Sort & Merge Sort


//#include <iostream>
//using namespace std;
//int findIndexOfMin(int arr[], int low, int high){
//    int min=arr[low], minInd=low;
//    for (int i =low+1; i<high; i++){
//        if (arr[i]<min){
//            min=arr[i];
//            minInd=i;
//        }
//    }
//    return minInd;
//}
//
//void selectionSort(int arr[], int arrSize){
//    int i, minInd;
//    for (i =0; i < arrSize; i++){
//        minInd= findIndexOfMin(arr, i, arrSize );
//        swap(arr[i], arr[minInd]);
//    }
//}
//int main(){
//   int numArr[10]= {2,5,6,2,1,4,7,8,8,3};
//    selectionSort(numArr, 10);
//    for (int i=0; i<10; i++){
//        cout<<numArr[i]<<" ";
//    }
//    return 0;
//}


//Runtime Analsyis of findIndexOfMin()-->  Size of input N is (number of elements in range of searching for index of min).
    // Let n = high-low + 1
    //T(n) = O(n)
//Runtime Analysis of Selection Sort
    // Let n = high-low+1 (size input)
    //The loop is O(n-i), each time one item less
    //pay N for 1st call, N-1 for second, N-2 for third etc..
    //Quadratic Running time O(N^2)
//[5,14,10,8,13,1,18,3,4,2,10,3,4,]
//0,1,2,3,4,5,6,7,8,9,10,11,12]
//We search for the minimum element and swap the minimum with teh first index with the minFound
//Then we do the same for the second index with the shortened range, and again swap.

//MERGE SORT (RECURSIVE)

/*step 1 (Sort (recursively) the first half
 * {14,5,8,10,13,1,18,3} = {5,8,10,14,-,-,-,-}
 * step 2 (Sort (recursively) the second half
 * * {14,5,8,10,13,1,18,3} = {-,-,-,-,1,3,13,18}
 * step 3 Merge two halves together into one sorted sequence
 * {5,8,10,14,1,3,13,18} = {1,3,5,8,10,13,14,18}
 * */

//IMPLEMENTATION OF MERGE SORT
#include <iostream>
using namespace std;

void merge (int arr[], int lowLeft, int highLeft, int highRight){
    int lowRight = highLeft+1;
    int *mergedArr;
    int iRight, iLeft, iRes;
    int size = highRight-lowLeft +1;
    mergedArr = new int[size];

    iLeft = lowLeft;
    iRight=lowRight;
    iRes=0;

    while (iLeft <= highLeft && iRight <= highRight){
        if (arr[iLeft]<arr[iRight]){
            mergedArr[iRes]=arr[iLeft];
            iLeft++;
            iRes++;
        } else {
            mergedArr[iRes]=arr[iRight];
            iRight++;
            iRes++;
        }
    }
    while (iLeft<=highLeft){
        mergedArr[iRes]=arr[iLeft];
        iLeft++;
        iRes++;
    }
    while (iRight<=highRight) {
        mergedArr[iRes] = arr[iRight];
        iRight++;
        iRes++;
    }
    for (int i=0, iArr=lowLeft; i<size ;i++, iArr++){
        arr[iArr] = mergedArr[i];
    }
    delete []mergedArr;
}

void mergeSort(int arr[], int low, int high){
    int mid;
    if (low == high){
        return ;
    }else {
        mid=(low+high) /2 ;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge (arr, low, mid, high);
    }
}
 int main(){
    int arr[10]={3,6,3,4,8,10,43,2,3,4};
     mergeSort(arr, 0, 9);
     for (int i =0; i<10; i++){
         cout<< arr[i] << " ";
     }
    return 0;
 }
 //HOW DOES IT WORK? // RUNTIME ANALYSIS
//Analyzed in RECURSIVE TREE MODEL

 /* call to array of size N
  * Each calls to array of size N/2
  * Each calls to array of size N/4
  * Each calls to array of size.... at the very end it gets to a SINGLE element
  * We examine to COST OF EACH CALL (the cost of merge
  *Relate the level #, the # oc calls, the cost of each calls, and multipel to get total cost
  *THETHA(N) )(nlog2(n))
  * */
