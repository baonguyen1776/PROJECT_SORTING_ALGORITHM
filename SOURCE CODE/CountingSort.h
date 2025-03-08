#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;
using namespace std::chrono;

double countingSortTime(int *a, int n);
unsigned long long countingSortCmp(int *a, int n);

#endif