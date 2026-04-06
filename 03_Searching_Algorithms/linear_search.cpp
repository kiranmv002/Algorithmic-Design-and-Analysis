// ============================================================
// FILE: linear_search.cpp
// TIME:  O(n) worst | O(1) best
// SPACE: O(1)
// NOTE:  Works on unsorted arrays
// ============================================================
#include <iostream>
using namespace std;

// Iterative Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i; // Return index if found
    return -1; // Not found
}

// Recursive Linear Search
int linearSearchRec(int arr[], int n, int target) {
    if (n == 0) return -1;
    if (arr[n - 1] == target) return n - 1;
    return linearSearchRec(arr, n - 1, target);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = 6;

    cout << "Array: 10 20 30 40 50 60\n";
    cout << "Search 40 (Iterative): index = " << linearSearch(arr, n, 40) << "\n";    // 3
    cout << "Search 40 (Recursive): index = " << linearSearchRec(arr, n, 40) << "\n"; // 3
    cout << "Search 99: index = " << linearSearch(arr, n, 99) << "\n"; // -1
    return 0;
}
