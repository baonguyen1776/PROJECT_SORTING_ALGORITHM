#include <SelectionSort.h>

double selectionSortTime(int *a, int n) {
    clock_t start = clock();

    // start selection sort
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

unsigned long long selectionSortCmp(int *a, int n) {
    unsigned long long numberOfCmp = 0;

    //Start counting comparision
    for (int i = 0; ++numberOfCmp && i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; ++numberOfCmp && j < n; j++) {
            if ( ++numberOfCmp && a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }

    return numberOfCmp;
}