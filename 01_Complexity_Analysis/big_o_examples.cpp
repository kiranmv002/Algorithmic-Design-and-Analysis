// ============================================================
// FILE: big_o_examples.cpp
// TOPIC: Time Complexity Examples
// ============================================================

#include <iostream>
using namespace std;

// O(1) — Constant Time
void constant(int arr[], int n) {
    cout << arr[0] << endl; // Always 1 operation
}

// O(n) — Linear Time
void linear(int arr[], int n) {
    for (int i = 0; i < n; i++)   // runs n times
        cout << arr[i] << " ";
}

// O(n²) — Quadratic Time
void quadratic(int arr[], int n) {
    for (int i = 0; i < n; i++)       // n times
        for (int j = 0; j < n; j++)   // n times each
            cout << arr[i] + arr[j];
}
