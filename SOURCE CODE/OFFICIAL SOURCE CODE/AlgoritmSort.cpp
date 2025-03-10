#include <LibrarySort.h>
using namespace std;
using namespace std::chrono;

void copyArray(int oldArr[], int newArr[], int n) {
    for (int i = 0; i < n; i++)
        newArr[i] = oldArr[i];
}

Record getRecord(int arr[], int n, void (*sortFunctionTime)(int [], int), void (*sortFunctionComp) (int [], int, unsigned long long &)) {
    Record data;
    data.comparision = data.time = 0;
    int* newArr = new int[n];
    copyArray(arr, newArr, n);
    auto start = high_resolution_clock::now();
    sortFunctionTime(arr, n);
    auto end = high_resolution_clock::now();
    data.time = duration<double>(end - start).count() * 1e6;
    sortFunctionComp(newArr, n, data.comparision);
    delete[] newArr;
    return data;
}

//-------------------------------------------------
//1. Selection sort

void selectionSortTime(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
}

void selectionSortCmp(int a[], int n, unsigned long long &numberOfCmp) {
    for (int i = 0; ++numberOfCmp && i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; ++numberOfCmp && j < n; j++) {
            if ( ++numberOfCmp && a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
}

//-------------------------------------------------
//2. Insertion sort

void insertionSortTime(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int keyValue = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > keyValue) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = keyValue;
    }
}

void insertionSortCmp(int a[], int n, unsigned long long &numberOfCmp) {
    for (int i = 1; ++numberOfCmp && i < n; i++) {
        int keyValue = a[i];
        int j = i - 1;
        while (++numberOfCmp && j >= 0 && ++numberOfCmp && a[j] > keyValue) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = keyValue;
    }
}

//-------------------------------------------------
//3.Bubble sort

void bubbleSortTime(int a[], int n) {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

void bubbleSortCmp(int a[], int n, unsigned long long &numberOfCmp) {
    for (int i = 0; ++numberOfCmp && i < n - 1; i++) {
        for (int j = 0; ++numberOfCmp && j < n - i - 1; j++) {
            if (++numberOfCmp && a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

//-------------------------------------------------
//4.BinaryInsertion Sort

void binaryInsertionSortTime(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int keyValue = a[i];
        int left = 0, right =  i - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (keyValue < a[mid]) 
                right = mid - 1;
            else 
                left = mid + 1;
        }
        for (int j = i - 1; j >= left; j--) 
            a[j + 1] = a[j];
        a[left] = keyValue;
    }
}   

void binaryInsertionSortCmp(int a[], int n, unsigned long long &numberOfCmp) {
    for (int i = 1; ++numberOfCmp && i < n; i++) {
        int keyValue = a[i];
        int left = 0, right = i - 1;
        while (++numberOfCmp && left <= right) {
            int mid = (left + right) / 2;
            if (++numberOfCmp && keyValue < a[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int j = i - 1; ++numberOfCmp && j >= left; j--)
            a[j + 1] = a[j];
        a[left + 1] = keyValue;
    }
}

//------------------------------------------------
//5 Shaker Sort

void shakerSortTime(int a[], int n) {
    int left = 0, right = n - 1, k = 0;
    while (left < right) {
        bool isSwapped = false;
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                k = i;
                isSwapped = true;
            }
        }
        if (!isSwapped) break;
        right = k;

        isSwapped = false;
        for (int i = right; i > left; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                k = i;
                isSwapped = true;
            }
        }
        if (!isSwapped) break;
        left = k;
    }
}

void shakerSortCmp(int a[], int n, unsigned long long &numberOfCmp) {
    int left = 0, right = n - 1, k = 0;
    while (++numberOfCmp && left < right) {
        bool isSwapped = false;
        for (int i = left; ++numberOfCmp && i < right; i++) {
            if (++numberOfCmp && a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                k = i;
                isSwapped = true;
            }

            if (++numberOfCmp && !isSwapped) break;
            right = k;

            isSwapped = false;
            for (int i = right; ++numberOfCmp && i > left; i--) {
                if (++numberOfCmp && a[i] < a[i - 1]) {
                    swap(a[i], a[i - 1]);
                    k = i;
                    isSwapped = true;
                }
            }

            if (++numberOfCmp && !isSwapped) break;
            left = k;
        }
    }
}

//--------------------------------------------------
//6. Shell Sort

void shellSortTime(int a[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int tmp = a[i];
            int j;            
            for (j = i; j >= gap && a[j - gap] > tmp; j -= gap) 
                a[j] = a[j - gap];
            a[j] = tmp;
        }
    }
}

void shellSortCmp(int a[], int n, unsigned long long &numberOfCmp) {
    for (int gap = n/2; ++numberOfCmp && gap > 0; gap /= 2) {
        for (int i = gap; ++numberOfCmp && i < n; i += 1) {
            int tmp = a[i];
            int j;            
            for (j = i; (++numberOfCmp && j >= gap) && (++numberOfCmp && a[j - gap] > tmp) ; j -= gap) 
                a[j] = a[j - gap];
            a[j] = tmp;
        }
    }
}

//---------------------------------------------------
//7. Heap Sort

inline void _heapRebuildT(int arr[], int start, int n) {
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
        _heapRebuildT(arr, large, n);
    }
}

void heapSortTime(int a[], int n) {
    for (int i = (n - 1) / 2; i >= 0; i--) 
        _heapRebuildT(a, i, n);
    swap(a[0], a[n - 1]);
    int heapSize = n - 1;
    while (heapSize > 1) {
        _heapRebuildT(a, 0, heapSize);
        heapSize--;
        swap(a[0], a[heapSize]);
    }
}

inline void _heapRebuildC(int arr[], int start, int n, unsigned long long &count) {
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
        _heapRebuildC(arr, large, n, count);
    }
}

void heapSortCmp(int a[], int n, unsigned long long &numberOfCmp) {
    for (int i = (n - 1) / 2; ++numberOfCmp && i >= 0; i--) 
        _heapRebuildC(a, i, n, numberOfCmp);
    swap(a[0], a[n - 1]);
    int heapSize = n - 1;
    while (++numberOfCmp && heapSize > 1) {
        _heapRebuildC(a, 0, heapSize, numberOfCmp);
        heapSize--;
        swap(a[0], a[heapSize]);
    }
}

//---------------------------------------------------
//8. Quick Sort

inline int _sortFirstMiddleLastT(int arr[], int first, int last) {
    int mid = (first + last) / 2;
    if (arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    if (arr[mid] > arr[last])
        swap(arr[mid], arr[last]);
    if (arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    return mid;
}

inline int _partitionT(int arr[], int first, int last) {
    int pivotIdx = _sortFirstMiddleLastT(arr, first, last);
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

inline void _QuickTime(int arr[], int first, int last) {
    if ((last - first + 1) < 10)
        insertionSortTime(arr, (last - first + 1));
    else {
        int pivotIdx = _partitionT(arr, first, last);
        _QuickTime(arr, first, pivotIdx - 1);
        _QuickTime(arr, pivotIdx + 1, last);
    }
}

void quickSortVer2Time(int a[], int n) {
    _QuickTime(a, 0, n - 1);
}

/*-----------------***-----------------*/

inline int _sortFirstMiddleLastC(int arr[], int first, int last, unsigned long long &count) {
    int mid = (first + last) / 2;
    if (++count && arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    if (++count && arr[mid] > arr[last])
        swap(arr[mid], arr[last]);
    if (++count && arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    return mid;
}

inline int _partitionC(int arr[], int first, int last, unsigned long long &count) {
    int pivotIdx = _sortFirstMiddleLastC(arr, first, last, count);
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

inline void _QuickCmp(int * arr, int first, int last, unsigned long long &count) {
    if (++count && (last - first + 1) < 10)
        insertionSortCmp(arr, (last - first + 1), count);
    else {
        int pivotIdx = _partitionC(arr, first, last, count);
        _QuickCmp(arr, first, pivotIdx - 1, count);
        _QuickCmp(arr, pivotIdx + 1, last, count);
    }
}

void quickSortVer2Cmp(int a[], int n, unsigned long long &numberOfCmp) {
    _QuickCmp(a, 0, n - 1, numberOfCmp);
}

//--------------------------------------------------
//9. Merge Sort

inline void _mergeT(int arr[], int *leftArr, int *rightArr, int n) {
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

inline void _mergeSortT(int arr[], int n) {
    if (n <= 1)
        return;
    int nLeft = n / 2, nRight = n - nLeft;
    int *arrLeft = new int[nLeft], *arrRight = new int[nRight];
    for (int i = 0; i < nLeft; i++)
        arrLeft[i] = arr[i];
    for (int i = nLeft; i < n; i++)
        arrRight[i - nLeft] = arr[i];
    
    // Call recursion to split array
    _mergeSortT(arrLeft, nLeft);
    _mergeSortT(arrRight, nRight);
    _mergeT(arr, arrLeft, arrRight, n);

    //Free up to memory
    delete[] arrLeft;
    delete[] arrRight;
}

void mergeSortTime(int a[], int n) {
    _mergeSortT(a, n);
}

inline void _mergeC(int arr[], int *leftArr, int *rightArr, int n, unsigned long long &count) {
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

inline void _mergeSortC(int arr[], int n, unsigned long long &count) {
    if (++count && n <= 1)
        return;
    int nLeft = n / 2, nRight = n - nLeft;
    int *arrLeft = new int[nLeft], *arrRight = new int[nRight];
    for (int i = 0; ++count && i < nLeft; i++)
        arrLeft[i] = arr[i];
    for (int i = nLeft; ++count && i < n; i++)
        arrRight[i - nLeft] = arr[i];

    // Call recursion to split array
    _mergeSortC(arrLeft, nLeft, count);
    _mergeSortC(arrRight, nRight, count);
    _mergeC(arr, arrLeft, arrRight, n, count);

    //Free up to memory
    delete[] arrLeft;
    delete[] arrRight;
}

void mergeSortCmp(int a[], int n, unsigned long long &numberOfCmp) {
    _mergeSortC(a, n, numberOfCmp);
}

//----------------------------------------------
//10. Radix Sort

void radixSortTime(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    //find the maximun muber of digits
    int digits = 0, div;
    do {
        digits++;
        div = maxVal / pow(10, digits);
    } while (div > 0);
    int *tempArr[10];
    for (int i = 0; i < 10; i++)
        tempArr[i] = new int[n];
    int tempCount[10] = {0};

    //form groups of number and combine groups
    for (int i = 0; i < digits; i++) {
        int exponent = pow(10, i);
        for (int j = 0; j < n; j++) {
            int idx = (arr[j] / exponent) % 10;
            tempArr[idx][tempCount[idx]++] = arr[j];
        }
        int idx = 0;
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < tempCount[j]; k++)
                arr[idx++] = tempArr[j][k];
    }
}


void radixSortCmp(int arr[], int n, unsigned long long &numberOfCmp) {
    int maxVal = arr[0];
    for (int i = 1; ++numberOfCmp && i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    //find the maximun muber of digits
    int digits = 0, div;
    do {
        digits++;
        div = maxVal / pow(10, digits);
    } while (++numberOfCmp && div > 0);
    int *tempArr[10];
    for (int i = 0; ++numberOfCmp &&  i < 10; i++)
        tempArr[i] = new int[n];
    int tempCount[10] = {0};

    //form groups of number and combine groups
    for (int i = 0; ++numberOfCmp && i < digits; i++) {
        int exponent = pow(10, i);
        for (int j = 0; ++numberOfCmp && j < n; j++) {
            int idx = (arr[j] / exponent) % 10;
            tempArr[idx][tempCount[idx]++] = arr[j];
        }
        int idx = 0;
        for (int j = 0; ++numberOfCmp && j < 10; j++)
            for (int k = 0; ++numberOfCmp && k < tempCount[j]; k++)
                arr[idx++] = tempArr[j][k];
    }
}

//-----------------------------------------------
//11. Counting Sort

void countingSortTime(int a[], int n) {
    int maxVal = a[0];
    for (int i = 1; i < n; i++) 
        if (a[i] > maxVal)
            maxVal = a[i];
    int* count = new int[maxVal + 1] {0};
    for (int i = 0; i < n; i++)
        count[a[i]]++;
    for (int i = 1; i <= maxVal; i++)
        count[i] = count[i - 1] + count[i];
    int* output = new int[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = output[i];
    delete[] output;
    delete[] count;
}

void countingSortCmp(int a[], int n, unsigned long long &numberOfCmp) {
    int maxVal = a[0];
    for (int i = 1; ++numberOfCmp && i < n; i++) 
        if (++numberOfCmp && a[i] > maxVal)
            maxVal = a[i];
    int* count = new int[maxVal + 1] {0};
    for (int i = 0; ++numberOfCmp && i < n; i++)
        count[a[i]]++;
    for (int i = 1; ++numberOfCmp && i <= maxVal; i++)
        count[i] = count[i - 1] + count[i];
    int* output = new int[n];
    for (int i = n - 1; ++numberOfCmp && i >= 0; i--) {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for (int i = 0; ++numberOfCmp && i < n; i++)
        a[i] = output[i];
    delete[] output;
    delete[] count;
}

//----------------------------------------------
//12. Flash Sort

inline int _getBuc(int value, int minVal, int maxVal, int numClass) {
    return (numClass - 1) * (value - minVal) / (maxVal - minVal);
}

void flashSortTime(int a[], int n) {
    if (n <= 1) 
        return;
    
    int minVal = a[0], maxVal = a[0];
    int numClass = (int)(0.45 * n);
    for (int i = 1; i < n; i++) {
        if (maxVal < a[i])
            maxVal = a[i];
        if (minVal > a[i])
            minVal = a[i];
    }
    if (maxVal == minVal) 
        return;
    
    // step1 create bucket
    int* bucket = new int[numClass]{0};
    for (int i = 0; i < n; i++)
        ++bucket[_getBuc(a[i], minVal, maxVal, numClass)];
    for (int i = 1; i < numClass; i++)
        bucket[i] += bucket[i - 1];

    //Step2
    int count = 0, i = 0;
    while (count < n) {
        int k = _getBuc(a[i], minVal, maxVal, numClass);
        while (i >= bucket[k])
            k = _getBuc(a[++i], minVal, maxVal, numClass);
        int z = a[i];
        while (i != bucket[k]) {
            k = _getBuc(z, minVal, maxVal, numClass);
            int y = a[bucket[k] - 1];
            a[--bucket[k]] = z;
            z = y;
            ++count;
        }
    }

    // Step 3
    for (int k = 1; k < numClass; ++k) {
        for (int i = bucket[k] - 2; i >= bucket[k - 1]; --i) {
            if (a[i] > a[i + 1]) {
                int t = a[i], j = i;
                while (t > a[j + 1]) {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
        }
    }

    delete[] bucket;
}

void flashSortCmp(int a[], int n, unsigned long long &numberOfCmp) {
    if (++numberOfCmp && n <= 1)
        return;

    int minVal = a[0], maxVal = a[0];
    int numClass = (int)(0.45 * n);
    for (int i = 1; ++numberOfCmp && i < n; i++) {
        if (++numberOfCmp && maxVal < a[i])
            maxVal = a[i];
        if (++numberOfCmp && minVal > a[i])
            minVal = a[i];
    }
    if (++numberOfCmp && maxVal == minVal) 
        return;

    // step1 create bucket
    int* bucket = new int[numClass]{0};
    for (int i = 0; ++numberOfCmp && i < n; i++)
        ++bucket[_getBuc(a[i], minVal, maxVal, numClass)];
    for (int i = 1; ++numberOfCmp && i < numClass; i++)
        bucket[i] += bucket[i - 1];

    //Step2
    int count = 0, i = 0;
    while (++numberOfCmp && count < n) {
        int k = _getBuc(a[i], minVal, maxVal, numClass);
        while (++numberOfCmp && i >= bucket[k])
            k = _getBuc(a[++i], minVal, maxVal, numClass);
        int z = a[i];
        while (++numberOfCmp && i != bucket[k]) {
            k = _getBuc(z, minVal, maxVal, numClass);
            int y = a[bucket[k] - 1];
            a[--bucket[k]] = z;
            z = y;
            ++count;
        }
    }

    // Step 3
    for (int k = 1; ++numberOfCmp && k < numClass; ++k) {
        for (int i = bucket[k] - 2; ++numberOfCmp && i >= bucket[k - 1]; --i) {
            if (++numberOfCmp && a[i] > a[i + 1]) {
                int t = a[i], j = i;
                while (++numberOfCmp && t > a[j + 1]) {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
        }
    }

    delete[] bucket;
}