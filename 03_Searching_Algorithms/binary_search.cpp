// ============================================================
// FILE: binary_search.cpp
// TIME:  O(log n)
// SPACE: O(1) iterative | O(log n) recursive
// NOTE:  Array MUST be sorted
// RECURRENCE: T(n) = T(n/2) + 1 → O(log n) Master Thm Case 1
// ============================================================
#include <iostream>
using namespace std;

// Iterative Binary Search
int binarySearchIter(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoids overflow
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Recursive Binary Search
int binarySearchRec(int arr[], int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target)
        return binarySearchRec(arr, mid + 1, high, target);
    else
        return binarySearchRec(arr, low, mid - 1, target);
}

// First and Last occurrence of target
int firstOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) { result = mid; high = mid - 1; }
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return result;
}

int lastOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) { result = mid; low = mid + 1; }
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return result;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = 7;

    cout << "Array: 2 4 6 8 10 12 14\n";
    cout << "Search 10 (Iterative): index = " << binarySearchIter(arr, n, 10) << "\n"; // 4
    cout << "Search 10 (Recursive): index = " << binarySearchRec(arr, 0, n-1, 10) << "\n"; // 4
    cout << "Search 99: index = " << binarySearchIter(arr, n, 99) << "\n"; // -1

    int arr2[] = {1, 2, 2, 2, 3, 4, 5};
    cout << "\nArray: 1 2 2 2 3 4 5\n";
    cout << "First occurrence of 2: " << firstOccurrence(arr2, 7, 2) << "\n"; // 1
    cout << "Last occurrence of 2:  " << lastOccurrence(arr2, 7, 2) << "\n";  // 3
    return 0;
}
