#include <QuickSortVer2.h>

inline int sortFirstMiddleLastT(int *arr, int first, int last) {
    int mid = (first + last) / 2;
    if (arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    if (arr[mid] > arr[last])
        swap(arr[mid], arr[last]);
    if (arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    return mid;
}

inline int partitionT(int *arr, int first, int last) {
    int pivotIdx = sortFirstMiddleLastT(arr, first, last);
    swap(arr[pivotIdx], arr[last - 1]);
    pivotIdx = last - 1;
    int pivot = arr[pivotIdx];
    int idxLeft = first + 1, idxRight = last - 2;
    bool flag = false;
    while (!flag) {
        //Locate first entry on left that is >= pivot
        while (arr[idxLeft] < pivot) idxLeft++;
        //Locate first entry on left that is <= pivot
        while (arr[idxRight] > pivot) idxRight--;
        //Swap
        if (idxLeft < idxRight) {
            swap(arr[idxLeft], arr[idxRight]);
            idxLeft++, idxRight--;
        }
        else 
            flag = true;
    }
    swap(arr[pivotIdx], arr[idxLeft]);
    pivotIdx = idxLeft;
    return pivotIdx;
}

void insertionSortTime(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

inline void _QuickTime(int * arr, int first, int last) {
    if ((last - first + 1) < 10)
        insertionSortTime(arr, (last - first + 1));
    else {
        int pivotIdx = partitionT(arr, first, last);
        _QuickTime(arr, first, pivotIdx - 1);
        _QuickTime(arr, pivotIdx + 1, last);
    }
}

double quickSortVer2Time(int *a, int n) {
    auto start = high_resolution_clock::now();
    
    //Call function 
    _QuickTime(a, 0, n - 1);

    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count() * 1e6; 
}

/*------------------------***----------------------*/

inline int sortFirstMiddleLastC(int *arr, int first, int last, unsigned long long &count) {
    int mid = (first + last) / 2;
    if (++count && arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    if (++count && arr[mid] > arr[last])
        swap(arr[mid], arr[last]);
    if (++count && arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    return mid;
}

inline int partitionC(int *arr, int first, int last, unsigned long long &count) {
    int pivotIdx = sortFirstMiddleLastC(arr, first, last, count);
    swap(arr[pivotIdx], arr[last - 1]);
    pivotIdx = last - 1;
    int pivot = arr[pivotIdx];
    int idxLeft = first + 1, idxRight = last - 2;
    bool flag = false;
    while (!flag) {
        //Locate first entry on left that is >= pivot
        while (++count && arr[idxLeft] < pivot) idxLeft++;
        //Locate first entry on left that is <= pivot
        while (++count && arr[idxRight] > pivot) idxRight--;
        //Swap
        if (++count && idxLeft < idxRight) {
            swap(arr[idxLeft], arr[idxRight]);
            idxLeft++, idxRight--;
        }
        else 
            flag = true;
    }
    swap(arr[pivotIdx], arr[idxLeft]);
    pivotIdx = idxLeft;
    return pivotIdx;
}

void insertionSortCmp(int *arr, int n, unsigned long long &count) {
    for (int i = 1; ++count && i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (++count && j >= 0 && ++count && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

inline void _QuickCmp(int * arr, int first, int last, unsigned long long &count) {
    if (++count && (last - first + 1) < 10)
        insertionSortCmp(arr, (last - first + 1), count);
    else {
        int pivotIdx = partitionC(arr, first, last, count);
        _QuickCmp(arr, first, pivotIdx - 1, count);
        _QuickCmp(arr, pivotIdx + 1, last, count);
    }
}

unsigned long long quickSortVer2Cmp(int *a, int n) {
    unsigned long long numberOfCmp = 0;

    //Call function
    _QuickCmp(a, 0, n - 1, numberOfCmp);

    return numberOfCmp;
}