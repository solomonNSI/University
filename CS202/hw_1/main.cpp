/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Name Surname
 * ID: 21000000
 * Section: 1
 * Assignment: 1
 * Description: main file that tests my sorting algorithms as well as performance analysis
 */

#include "sorting.h"
#include <iostream>

int main(){
    
//Initialization
    int size = 16;
    int array[] = {12,7,11,18,19,9,6,14,21,3,17,20,5,12,14,8};
    int array1[] = {12,7,11,18,19,9,6,14,21,3,17,20,5,12,14,8};
    int array2[] = {12,7,11,18,19,9,6,14,21,3,17,20,5,12,14,8};
    int array3[] = {12,7,11,18,19,9,6,14,21,3,17,20,5,12,14,8};
   
// There is also a way to copy every element in the for loop, but I thought
// this one is much faster
    
    int compCount = 0;
    int moveCount = 0;   

// Printing Unsorted Array
    cout<< "............Unsorted Array......"<<endl;
    for(int i = 0; i < size; i++){
       cout<< array[i]<< "  ";
    }
    cout<<" Move Count: "<< moveCount << "  Comp Count:  "<< compCount<<"\n";  
    cout<<"\n";
// Printing Array after Selection Sort
    cout<< ".............Selection Sort......."<<endl;

    selectionSort( array, size, moveCount, compCount);
    displayArray(array,size);
    cout<<" Move Count: "<< moveCount << "  Comp Count:  "<< compCount<<"\n";  
    cout<<"\n";

// Merge Sort
    moveCount = 0;
    compCount = 0;
    cout<< "............Merge Sort........."<<endl;
    mergeSort(array1,size,compCount,moveCount);
    displayArray(array1, size);
    cout<<" Move Count: "<< moveCount << "  Comp Count:  "<< compCount<<"\n";  
    cout<<"\n";
// Quick Sort
    moveCount = 0;
    compCount = 0;
    cout<< "............Quick Sort........."<<endl;
    quickSort(array2, size, compCount, moveCount);
    displayArray(array2, size);
    cout<<" Move Count: "<< moveCount << "  Comp Count:  "<< compCount<<"\n";  
    cout<<"\n";
// Radix Sort
    moveCount = 0;
    compCount = 0;
    cout<< "..........Radix Sort........."<<endl; 
    radixSort(array3, size);
    displayArray(array3, size);
    cout<<"\n";

   
// Performance Analysis
   cout<< " Performance Analysis "<<endl;

    moveCount = 0;
    compCount = 0;
    performanceAnalysis(compCount, moveCount);
    return 0;
}
