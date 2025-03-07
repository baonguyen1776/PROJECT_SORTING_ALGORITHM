#include <InsertionSort.h>

double insertionSortTime(int *a, int n) {
    auto start = high_resolution_clock::now();

    // Start insertion sort
    for (int i = 1; i < n; i++) {
        int keyValue = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > keyValue) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = keyValue;
    }

    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count() * 1e6;
}

unsigned long long insertionSortCmp(int *a, int n) {
    unsigned long long numberOfCmp = 0;

    // Start counting comparision
    for (int i = 1; ++numberOfCmp && i < n; i++) {
        int keyValue = a[i];
        int j = i - 1;
        while (++numberOfCmp && j >= 0 && ++numberOfCmp && a[j] > keyValue) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = keyValue;
    }

    return numberOfCmp;
}