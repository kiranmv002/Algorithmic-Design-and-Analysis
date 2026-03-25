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

// O(log n) — Logarithmic Time
void logarithmic(int n) {
    for (int i = 1; i < n; i = i * 2) // halves each step
        cout << i << " ";
}

// O(n log n)
void nlogn(int n) {
    for (int i = 0; i < n; i++)            // n times
        for (int j = 1; j < n; j = j * 2) // log n times
            cout << i + j << " ";
}

// O(2ⁿ) — Exponential (Recursive Fibonacci)
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "O(1): "; constant(arr, n);
    cout << "\nO(n): "; linear(arr, n);
    cout << "\nO(log n): "; logarithmic(n);
    cout << "\nO(2n) Fib(6): " << fibonacci(6);
    return 0;
}
