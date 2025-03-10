#include <BubbleSort.h>
using namespace std;
using namespace std::chrono;

double bubbleSortTime(int *a, int n) {
    auto start = high_resolution_clock::now();

    //Start bubble sort
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }

    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count() * 1e6;
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