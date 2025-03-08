#ifndef FLASHSORT_H
#define FLASHSORT_H

#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

double flashSortTime(int *a, int n);
unsigned long long flashSortCmp(int *a, int n);

#endif