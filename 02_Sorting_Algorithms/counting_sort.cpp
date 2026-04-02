// ============================================================
// FILE: counting_sort.cpp
// TIME:  O(n + k) where k = range of input
// SPACE: O(k)
// STABLE: YES
// NOTE:  Only works for non-negative integers
// ============================================================
#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n) {
    int maxVal = *max_element(arr, arr + n);
    vector<int> count(maxVal + 1, 0);

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int idx = 0;
    for (int i = 0; i <= maxVal; i++)
        while (count[i]-- > 0)
            arr[idx++] = i;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = 7;
    cout << "Before: "; printArray(arr, n);
    countingSort(arr, n);
    cout << "After:  "; printArray(arr, n);
    return 0;
}
