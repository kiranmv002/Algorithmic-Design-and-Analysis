// ============================================================
// FILE: selection_sort.cpp
// TIME:  O(n²) always
// SPACE: O(1)
// STABLE: NO
// ============================================================
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[minIdx], arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    cout << "Before: "; printArray(arr, n);
    selectionSort(arr, n);
    cout << "After:  "; printArray(arr, n);
    return 0;
}
