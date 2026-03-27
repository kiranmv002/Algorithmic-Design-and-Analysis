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

