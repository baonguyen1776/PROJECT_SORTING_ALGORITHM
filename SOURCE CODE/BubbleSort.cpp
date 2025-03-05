#include <BubbleSort.h>

double bubblesorttime(int *a, int n) {
    clock_t start = clock();

    //Start bubble sort
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

unsigned long long bubbleSortCmp(int *a, int n) {
    unsigned long long numberOfCmp = 0;

    // Start counting comparision
    for (int i = 0; ++numberOfCmp && i < n - 1; i++) {
        for (int j = 0; ++numberOfCmp && j < n - i - 1; j++) {
            if (++numberOfCmp && a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }

    return numberOfCmp;
}