#include <SelectionSort.h>
using namespace std;
using namespace std::chrono;

double selectionSortTime(int *a, int n) {
    auto start = high_resolution_clock::now();

    // start selection sort
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }

    auto end = high_resolution_clock::now();
    return (duration<double>(end - start).count()) * 1e6;
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