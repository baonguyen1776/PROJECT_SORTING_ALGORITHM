#include <ShellSort.h>

//https://www.geeksforgeeks.org/shell-sort/

double shellSortTime(int *a, int n) {
    auto start = high_resolution_clock::now();

    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int tmp = a[i];
            int j;            
            for (j = i; j >= gap && a[j - gap] > tmp; j -= gap) 
                a[j] = a[j - gap];
            a[j] = tmp;
        }
    }

    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count() * 1e6;
}

unsigned long long shellSortCmp(int *a, int n) {
    unsigned long long numberOfCmp = 0;

    for (int gap = n/2; ++numberOfCmp && gap > 0; gap /= 2) {
        for (int i = gap; ++numberOfCmp && i < n; i += 1) {
            int tmp = a[i];
            int j;            
            for (j = i; (++numberOfCmp && j >= gap) && (++numberOfCmp && a[j - gap] > tmp) ; j -= gap) 
                a[j] = a[j - gap];
            a[j] = tmp;
        }
    }

    return numberOfCmp;
}