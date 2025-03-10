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


//All function sort to count comparision


//All data generation from teacher
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

#endif 
