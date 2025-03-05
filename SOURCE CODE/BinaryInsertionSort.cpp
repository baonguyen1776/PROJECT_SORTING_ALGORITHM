#include <BinaryInsertionSort.h>

double binaryInsertionSortTime(int *a, int n) {
    clock_t start = clock();

    //Start sort
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
    
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}   


unsigned long long binaryInsertionSortCmp(int *a, int n) {
    unsigned long long numberOfCmp = 0;

    // Start sort to counting comparision
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

    return numberOfCmp;
}