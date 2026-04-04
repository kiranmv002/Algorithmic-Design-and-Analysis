// ============================================================
// FILE: radix_sort.cpp
// TIME:  O(d * (n + k)) where d = digits, k = base (10)
// SPACE: O(n + k)
// STABLE: YES
// ============================================================
#include <iostream>
#include <vector>
using namespace std;

void countSort(int arr[], int n, int exp) {
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maxVal = *max_element(arr, arr + n);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;
    cout << "Before: "; printArray(arr, n);
    radixSort(arr, n);
    cout << "After:  "; printArray(arr, n);
    return 0;
}
