#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

double shellSortTime(int *a, int n);
unsigned long long shellSortCmp(int *a, int n);

#endif