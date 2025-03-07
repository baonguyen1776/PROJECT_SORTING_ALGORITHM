#include <RadixSort.h> 

inline void _RadixTime(int *arr, int n) {
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

double radixSortTime(int *a, int n) {
    auto start = high_resolution_clock::now();

    //start sort:
    _RadixTime(a, n);

    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count() * 1e6;
}

/*---------------------------------------------*/

inline void _RadixCmp(int *arr, int n, unsigned long long &count) {
    int maxVal = arr[0];
    for (int i = 1; ++count && i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    //find the maximun muber of digits
    int digits = 0, div;
    do {
        digits++;
        div = maxVal / pow(10, digits);
    } while (++count && div > 0);
    int *tempArr[10];
    for (int i = 0; ++count &&  i < 10; i++)
        tempArr[i] = new int[n];
    int tempCount[10] = {0};

    //form groups of number and combine groups
    for (int i = 0; ++count && i < digits; i++) {
        int exponent = pow(10, i);
        for (int j = 0; ++count && j < n; j++) {
            int idx = (arr[j] / exponent) % 10;
            tempArr[idx][tempCount[idx]++] = arr[j];
        }
        int idx = 0;
        for (int j = 0; ++count && j < 10; j++)
            for (int k = 0; ++count && k < tempCount[j]; k++)
                arr[idx++] = tempArr[j][k];
    }
}

unsigned long long radixSortCmp(int *a, int n) {
    unsigned long long numberOfCmp = 0;

    //start
    _RadixCmp(a, n, numberOfCmp);

    return numberOfCmp;
}