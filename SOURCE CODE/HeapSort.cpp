#include <HeapSort.h>

inline void heapRebuildT(int *arr, int start, int n) {
    int left = 2 * start + 1;
    if (left >= n)
        return;
    int large = left;
    int right = 2 * start + 2;
    if (right < n) {
        if (arr[right] > arr[large])
            large = right;
    }
    if (arr[start] < arr[large]) {
        swap(arr[start], arr[large]);
        heapRebuildT(arr, large, n);
    }
}

double heapSortTime(int *a, int n) {
    auto start = high_resolution_clock::now();

    // start heap-sort:
    for (int i = (n - 1) / 2; i >= 0; i--) 
        heapRebuildT(a, i, n);
    swap(a[0], a[n - 1]);
    int heapSize = n - 1;
    while (heapSize > 1) {
        heapRebuildT(a, 0, heapSize);
        heapSize--;
        swap(a[0], a[heapSize]);
    }

    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count() * 1e6;
}

inline void heapRebuildC(int *arr, int start, int n, unsigned long long &count) {
    int left = 2 * start + 1;
    if (++count && left >= n)
        return;
    int large = left;
    int right = 2 * start + 2;
    if (++count && right < n) {
        if (++count && arr[right] > arr[large])
            swap(arr[right], arr[large]);
    }
    if (++count && arr[start] < arr[large]) {
        swap(arr[start], arr[large]);
        heapRebuildC(arr, large, n, count);
    }
}

unsigned long long heapSortCmp(int *a, int n) {
    unsigned long long numberOfCmp = 0;

    //Start heap-sort to counting comparision
    for (int i = (n - 1) / 2; ++numberOfCmp && i >= 0; i--) 
        heapRebuildC(a, i, n, numberOfCmp);
    swap(a[0], a[n - 1]);
    int heapSize = n - 1;
    while (++numberOfCmp && heapSize > 1) {
        heapRebuildC(a, 0, heapSize, numberOfCmp);
        heapSize--;
        swap(a[0], a[heapSize]);
    }

    return numberOfCmp;
}