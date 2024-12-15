/*
Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and
measure the difference in run-time. 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int binSearch(int x, int v[], int n);
int my_binSearch(int x, int v[], int n);

int main() {
    int v[1000000];
    time_t start, end;
    double runningTime_1, runningTime_2;

    for (int i = 1; i < 1000000; i++) {
        v[i] = i; 
    }
    int x = 567;

    start = clock();
    int result_1 = binSearch(x, v, 1000000);
    end = clock();
    runningTime_1 = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    int result_2 = my_binSearch(x, v, 1000000);
    end = clock();
    runningTime_2 = (double)(end - start) / CLOCKS_PER_SEC;

    (result_1 == -1) ? printf("Element not found\n") : printf("Element found at index %d\n", result_1);
    printf("Running time for binSearch: %f\n", runningTime_1);
    (result_2 == -1) ? printf("Element not found\n") : printf("Element found at index %d\n", result_2);
    printf("Running time for my_binSearch: %f\n", runningTime_2);
    return 0;
}

int binSearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int my_binSearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    return (x == v[mid]) ? mid : -1;
}