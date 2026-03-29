// ============================================================
// FILE: bubble_sort.cpp
// TIME:  O(n²) worst/avg | O(n) best
// SPACE: O(1)
// STABLE: YES
// ============================================================
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Already sorted
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    cout << "Before: "; printArray(arr, n);
    bubbleSort(arr, n);
    cout << "After:  "; printArray(arr, n);
    return 0;
}
