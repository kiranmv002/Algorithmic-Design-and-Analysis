// ============================================================
// FILE: strassen_matrix.cpp
// TOPIC: Strassen's Matrix Multiplication
// TIME:  O(n^2.81) vs naive O(n³)
// RECURRENCE: T(n) = 7T(n/2) + O(n²) → O(n^log₂7) ≈ O(n^2.81)
// NOTE:  Works for 2x2 matrices (base case for demonstration)
// ============================================================
#include <iostream>
using namespace std;

void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    // 7 multiplications instead of 8
    int m1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int m2 = (A[1][0] + A[1][1]) * B[0][0];
    int m3 = A[0][0] * (B[0][1] - B[1][1]);
    int m4 = A[1][1] * (B[1][0] - B[0][0]);
    int m5 = (A[0][0] + A[0][1]) * B[1][1];
    int m6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    int m7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = m1 + m4 - m5 + m7;
    C[0][1] = m3 + m5;
    C[1][0] = m2 + m4;
    C[1][1] = m1 - m2 + m3 + m6;
}

