// ============================================================
// FILE: count_inversions.cpp
// TOPIC: Count Inversions using Modified Merge Sort
// TIME:  O(n log n)
// Inversion: i < j but arr[i] > arr[j]
// ============================================================
#include <iostream>
using namespace std;

long long mergeCount(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    long long inv = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else {
            arr[k++] = R[j++];
            inv += n1 - i; // All remaining left elements form inversions
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    return inv;
}
