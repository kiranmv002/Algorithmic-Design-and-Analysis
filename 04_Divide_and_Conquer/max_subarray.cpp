// ============================================================
// FILE: max_subarray.cpp
// TOPIC: Maximum Subarray Sum - Divide & Conquer
// TIME:  O(n log n)
// NOTE:  Kadane's Algorithm is O(n) — compare both!
// RECURRENCE: T(n) = 2T(n/2) + O(n) → O(n log n)
// ============================================================
#include <iostream>
#include <climits>
using namespace std;

// Find max crossing subarray
int maxCrossing(int arr[], int l, int m, int r) {
    int leftSum = INT_MIN, sum = 0;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }
    int rightSum = INT_MIN; sum = 0;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }
    return leftSum + rightSum;
}

// Divide & Conquer approach
int maxSubarrayDC(int arr[], int l, int r) {
    if (l == r) return arr[l];
    int m = (l + r) / 2;
    return max({maxSubarrayDC(arr, l, m),
                maxSubarrayDC(arr, m + 1, r),
                maxCrossing(arr, l, m, r)});
}

