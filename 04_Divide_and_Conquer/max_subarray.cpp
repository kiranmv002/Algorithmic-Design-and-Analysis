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

// Kadane's Algorithm O(n) for comparison
int kadane(int arr[], int n) {
    int maxSum = arr[0], currSum = arr[0];
    for (int i = 1; i < n; i++) {
        currSum = max(arr[i], currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = 9;
    cout << "Array: -2 1 -3 4 -1 2 1 -5 4\n";
    cout << "Max Subarray (D&C):    " << maxSubarrayDC(arr, 0, n-1) << "\n"; // 6
    cout << "Max Subarray (Kadane): " << kadane(arr, n) << "\n";              // 6
    return 0;
}
