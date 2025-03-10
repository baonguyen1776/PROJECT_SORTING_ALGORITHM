#include <ShakerSort.h>
using namespace std;
using namespace std::chrono;

// shaker sort also cocktail shaker sort 
// https://www.geeksforgeeks.org/cocktail-sort/

double shakerSortTime(int *a, int n) {
    auto start = high_resolution_clock::now();

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

    auto end = high_resolution_clock::now();
    return duration<double>(end - start).count() * 1e6;
}

unsigned long long shakerSortCmp(int *a, int n) {
    unsigned long long numberOfCmp = 0;

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

    return numberOfCmp;
}