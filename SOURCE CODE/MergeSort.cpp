#include <MergeSort.h>

inline void merge(int *arr, int *leftArr, int *rightArr, int n) {
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

inline void mergeSort(int *arr, int n) {
    if (n <= 1)
        return;
    int nLeft = n / 2, nRight = n - nLeft;
    int *arrLeft = new int[nLeft], *arrRight = new int[nRight];
    for (int i = 0; i < nLeft; i++)
        arrLeft[i] = arr[i];
    for (int i = nLeft; i < n; i++)
        arrRight[i - nLeft] = arr[i];
    
    // Call recursion to split array
    mergeSort(arrLeft, nLeft);
    mergeSort(arrRight, nRight);
    merge(arr, arrLeft, arrRight, n);

    //Free up to memory
    delete[] arrLeft;
    delete[] arrRight;
}

double mergeSortTime(int *a, int n) {
    clock_t start = clock();

    // Call merge-sort
    mergeSort(a, n);

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

inline void merge(int *arr, int *leftArr, int *rightArr, int n, unsigned long long count) {
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

inline void mergeSort(int *arr, int n, unsigned long long count) {
    if (++count && n <= 1)
        return;
    int nLeft = n / 2, nRight = n - nLeft;
    int *arrLeft = new int[nLeft], *arrRight = new int[nRight];
    for (int i = 0; ++count && i < nLeft; i++)
        arrLeft[i] = arr[i];
    for (int i = nLeft; ++count && i < n; i++)
        arrRight[i - nLeft] = arr[i];
    
    // Call recursion to split array
    mergeSort(arrLeft, nLeft);
    mergeSort(arrRight, nRight);
    merge(arr, arrLeft, arrRight, n, count);

    //Free up to memory
    delete[] arrLeft;
    delete[] arrRight;
}

unsigned long long mergeSortCmp(int *a, int n) {
    unsigned long long numberOfCmp = 0;

    // Start merge-sort to counting comparision
    mergeSort(a, n, numberOfCmp);

    return numberOfCmp;
}
