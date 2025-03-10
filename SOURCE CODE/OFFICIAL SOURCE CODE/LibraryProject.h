#ifndef LIBRARYSORT_H
#define LIBRARYSORT_H

#include <iostream>
#include <cmath>
#include <chrono>
#include <string> 
#include <cstring>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <time.h>

struct Record {
    unsigned long long comparision;
    double time; //Đơn vị là micro giây
};

Record getRecord(int arr[], int n, void (*sortFunctionTime)(int [], int), void (*sortFunctionComp) (int [], int, unsigned long long &));

//Copy form array to new array
void copyArray(int oldArr[], int newArr[], int n);

//All function sort to count time
void selectionSortTime(int a[], int n);
void insertionSortTime(int a[], int n);
void bubbleSortTime(int a[], int n);
void binaryInsertionSortTime(int a[], int n);
void shakerSortTime(int a[], int n);
void shellSortTime(int a[], int n);
void heapSortTime(int a[], int n);
void quickSortVer2Time(int a[], int n);
void mergeSortTime(int a[], int n);
void radixSortTime(int arr[], int n);
void countingSortTime(int a[], int n);
void flashSortTime(int a[], int n);

//All function sort to count comparision
void selectionSortCmp(int a[], int n, unsigned long long &numberOfCmp);
void insertionSortCmp(int a[], int n, unsigned long long &numberOfCmp);
void bubbleSortCmp(int a[], int n, unsigned long long &numberOfCmp);
void binaryInsertionSortCmp(int a[], int n, unsigned long long &numberOfCmp);
void shakerSortCmp(int a[], int n, unsigned long long &numberOfCmp);
void shellSortCmp(int a[], int n, unsigned long long &numberOfCmp);
void heapSortCmp(int a[], int n, unsigned long long &numberOfCmp);
void quickSortVer2Cmp(int a[], int n, unsigned long long &numberOfCmp);
void mergeSortCmp(int a[], int n, unsigned long long &numberOfCmp);
void radixSortCmp(int arr[], int n, unsigned long long &numberOfCmp);
void countingSortCmp(int a[], int n, unsigned long long &numberOfCmp);
void flashSortCmp(int a[], int n, unsigned long long &numberOfCmp);

//All data generation from teacher
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

//Processing commadline 
void processArg(int argc, char *argv[]);

#endif 
