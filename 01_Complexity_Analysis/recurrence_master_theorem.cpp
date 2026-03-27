// ============================================================
// FILE: recurrence_master_theorem.cpp
// TOPIC: Recurrence Relations + Master Theorem
// ============================================================
#include <iostream>
using namespace std;

// -----------------------------------------------
// T(n) = T(n/2) + 1  → Binary Search → O(log n)
// a=1, b=2, f(n)=1
// log_b(a) = log_2(1) = 0 → f(n) = O(n^0) = O(1)
// Case 2 → O(log n)
// -----------------------------------------------
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearch(arr, mid + 1, high, target);
    else return binarySearch(arr, low, mid - 1, target);
}

// -----------------------------------------------
// T(n) = 2T(n/2) + n  → Merge Sort → O(n log n)
// a=2, b=2, f(n)=n
// log_b(a) = log_2(2) = 1 → f(n) = O(n^1)
// Case 2 → O(n log n)
// -----------------------------------------------
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}
