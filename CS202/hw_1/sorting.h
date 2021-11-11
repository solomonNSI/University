/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Suleyman Hanyyev
 * ID: 21901009
 * Section: 
 * Assignment: 1
 * Description: description of your code
 */

#ifndef SORTING_H
#define SORTING_H
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

// additional programs
int findIndexOfLargest( const int *arr, int size);
void countingSort(int *arr, int size, int div);
void merge( int *arr, int first, int mid, int last, int &compCount, int &moveCount); 
void mergeSort2( int *arr, int first, int last,int size, int &compCount, int &moveCount);
void quickSort2( int *arr, const int low, const int high, int &compCount, int &moveCount);
int findMax( int *arr, int size);

void selectionSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort( int *arr, const int size, int &compCount, int &moveCount);
void radixSort( int *arr, const int size);

void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void performanceAnalysis( int &compCount, int &moveCount);

#endif
