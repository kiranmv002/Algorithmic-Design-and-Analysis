// ============================================================
// FILE: ternary_search.cpp
// TIME:  O(log₃n)
// SPACE: O(1) iterative | O(log₃n) recursive
// NOTE:  Array MUST be sorted
// ============================================================
#include <iostream>
using namespace std;

// Iterative Ternary Search
int ternarySearchIter(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        if (arr[mid1] == target) return mid1;
        if (arr[mid2] == target) return mid2;

        if (target < arr[mid1]) high = mid1 - 1;
        else if (target > arr[mid2]) low = mid2 + 1;
        else { low = mid1 + 1; high = mid2 - 1; }
    }
    return -1;
}

// Recursive Ternary Search
int ternarySearchRec(int arr[], int low, int high, int target) {
    if (low > high) return -1;
    int mid1 = low + (high - low) / 3;
    int mid2 = high - (high - low) / 3;

    if (arr[mid1] == target) return mid1;
    if (arr[mid2] == target) return mid2;

    if (target < arr[mid1])
        return ternarySearchRec(arr, low, mid1 - 1, target);
    else if (target > arr[mid2])
        return ternarySearchRec(arr, mid2 + 1, high, target);
    else
        return ternarySearchRec(arr, mid1 + 1, mid2 - 1, target);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = 10;

    cout << "Array: 1 3 5 7 9 11 13 15 17 19\n";
    cout << "Search 11 (Iterative): index = " << ternarySearchIter(arr, n, 11) << "\n"; // 5
    cout << "Search 11 (Recursive): index = " << ternarySearchRec(arr, 0, n-1, 11) << "\n"; // 5
    cout << "Search 99: index = " << ternarySearchIter(arr, n, 99) << "\n"; // -1
    return 0;
}
