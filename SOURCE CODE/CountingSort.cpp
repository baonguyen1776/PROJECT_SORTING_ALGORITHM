#include <CountingSort.h>
using namespace std;
using namespace std::chrono;

double countingSortTime(int *a, int n) {
    auto start = high_resolution_clock::now();

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

    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count() * 1e6;
}

unsigned long long countingSortCmp(int *a, int n) {
    unsigned long long numberOfCmp = 0;

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

    return numberOfCmp;
}