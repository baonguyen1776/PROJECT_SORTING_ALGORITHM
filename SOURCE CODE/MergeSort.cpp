#include <MergeSort.h>
using namespace std;
using namespace std::chrono;

inline void mergeT(int *arr, int *leftArr, int *rightArr, int n) {
    int nLeft = n / 2;
    int nRight = n - nLeft;
    int idxLeft = 0, idxRight = 0, idx = 0;
    while (idxLeft < nLeft && idxRight < nRight) {
        if (leftArr[idxLeft] <= rightArr[idxRight]) 
            arr[idx++] = leftArr[idxLeft++];
        else 
            arr[idx++] = rightArr[idxRight++];
    }
    while (idxLeft < nLeft)
        arr[idx++] = leftArr[idxLeft++];
    while (idxRight < nRight)
        arr[idx++] = leftArr[idxRight++];
}

inline void mergeSortT(int *arr, int n) {
    if (n <= 1)
        return;
    int nLeft = n / 2, nRight = n - nLeft;
    int *arrLeft = new int[nLeft], *arrRight = new int[nRight];
    for (int i = 0; i < nLeft; i++)
        arrLeft[i] = arr[i];
    for (int i = nLeft; i < n; i++)
        arrRight[i - nLeft] = arr[i];
    
    // Call recursion to split array
    mergeSortT(arrLeft, nLeft);
    mergeSortT(arrRight, nRight);
    mergeT(arr, arrLeft, arrRight, n);

    //Free up to memory
    delete[] arrLeft;
    delete[] arrRight;
}

double mergeSortTime(int *a, int n) {
    auto start = high_resolution_clock::now();

    // Call merge-sort
    mergeSortT(a, n);

    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count() * 1e6;
}

inline void mergeC(int *arr, int *leftArr, int *rightArr, int n, unsigned long long count) {
    int nLeft = n / 2;
    int nRight = n - nLeft;
    int idxLeft = 0, idxRight = 0, idx = 0;
    while ((++count && idxLeft < nLeft) && (++count && idxRight < nRight)) {
        if (++count && leftArr[idxLeft] <= rightArr[idxRight]) 
            arr[idx++] = leftArr[idxLeft++];
        else 
            arr[idx++] = rightArr[idxRight++];
    }
    while (++count && idxLeft < nLeft)
        arr[idx++] = leftArr[idxLeft++];
    while (++count && idxRight < nRight)
        arr[idx++] = leftArr[idxRight++];
}

inline void mergeSortC(int *arr, int n, unsigned long long count) {
    if (++count && n <= 1)
        return;
    int nLeft = n / 2, nRight = n - nLeft;
    int *arrLeft = new int[nLeft], *arrRight = new int[nRight];
    for (int i = 0; ++count && i < nLeft; i++)
        arrLeft[i] = arr[i];
    for (int i = nLeft; ++count && i < n; i++)
        arrRight[i - nLeft] = arr[i];
    
    // Call recursion to split array
    mergeSortC(arrLeft, nLeft, count);
    mergeSortC(arrRight, nRight, count);
    mergeC(arr, arrLeft, arrRight, n, count);

    //Free up to memory
    delete[] arrLeft;
    delete[] arrRight;
}

unsigned long long mergeSortCmp(int *a, int n) {
    unsigned long long numberOfCmp = 0;

    // Start merge-sort to counting comparision
    mergeSortC(a, n, numberOfCmp);

    return numberOfCmp;
}
