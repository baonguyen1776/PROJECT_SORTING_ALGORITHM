#include <FlashSort.h>

// https://codelearn.io/sharing/flash-sort-thuat-toan-sap-xep-than-thanh

inline int getBuc(int value, int minVal, int maxVal, int numClass) {
    return (numClass - 1) * (value - minVal) / (maxVal - minVal);
}

double flashSortTime(int *a, int n) {
    auto start = high_resolution_clock::now();
    
    if (n <= 1) {
        auto end = high_resolution_clock::now();
        return duration<double>(end - start).count() * 1e6;
    }

    int minVal = a[0], maxVal = a[0];
    int numClass = (int)(0.45 * n);
    for (int i = 1; i < n; i++) {
        if (maxVal < a[i])
            maxVal = a[i];
        if (minVal > a[i])
            minVal = a[i];
    }
    if (maxVal == minVal) {
        auto end = high_resolution_clock::now();
        return duration<double>(end - start).count() * 1e6;
    }
    
    // step1 create bucket
    int* bucket = new int[numClass]{0};
    for (int i = 0; i < n; i++)
        ++bucket[getBuc(a[i], minVal, maxVal, numClass)];
    for (int i = 1; i < numClass; i++)
        bucket[i] += bucket[i - 1];

    //Step2
    int count = 0, i = 0;
    while (count < n) {
        int k = getBuc(a[i], minVal, maxVal, numClass);
        while (i >= bucket[k])
            k = getBuc(a[++i], minVal, maxVal, numClass);
        int z = a[i];
        while (i != bucket[k]) {
            k = getBuc(z, minVal, maxVal, numClass);
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
    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count() * 1e6;
}

unsigned long long flashSortCmp(int *a, int n) {
    unsigned long long numberOfCmp = 0;

    if (++numberOfCmp && n <= 1)
        return numberOfCmp;
    int minVal = a[0], maxVal = a[0];
    int numClass = (int)(0.45 * n);
    for (int i = 1; ++numberOfCmp && i < n; i++) {
        if (++numberOfCmp && maxVal < a[i])
            maxVal = a[i];
        if (++numberOfCmp && minVal > a[i])
            minVal = a[i];
    }
    if (++numberOfCmp && maxVal == minVal) 
        return numberOfCmp;

    // step1 create bucket
    int* bucket = new int[numClass]{0};
    for (int i = 0; ++numberOfCmp && i < n; i++)
        ++bucket[getBuc(a[i], minVal, maxVal, numClass)];
    for (int i = 1; ++numberOfCmp && i < numClass; i++)
        bucket[i] += bucket[i - 1];

    //Step2
    int count = 0, i = 0;
    while (++numberOfCmp && count < n) {
        int k = getBuc(a[i], minVal, maxVal, numClass);
        while (++numberOfCmp && i >= bucket[k])
            k = getBuc(a[++i], minVal, maxVal, numClass);
        int z = a[i];
        while (++numberOfCmp && i != bucket[k]) {
            k = getBuc(z, minVal, maxVal, numClass);
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
    return numberOfCmp;
}