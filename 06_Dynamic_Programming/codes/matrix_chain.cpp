// ============================================================
// FILE: matrix_chain.cpp
// TOPIC: Matrix Chain Multiplication
// TIME:  O(n³)   SPACE: O(n²)
// Compile: g++ -std=c++17 -o matrix matrix_chain.cpp
// ============================================================
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChain(vector<int>& dims) {
    int n = dims.size() - 1; // Number of matrices
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    // l = chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n-l+1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            // Try all split points k
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j]
                         + dims[i-1] * dims[k] * dims[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n];
}

// Print optimal parenthesization
void printParenthesis(vector<vector<int>>& bracket,
                      int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printParenthesis(bracket, i, bracket[i][j]);
    printParenthesis(bracket, bracket[i][j]+1, j);
    cout << ")";
}

int main() {
    // Matrix dimensions
    // A1=40×20, A2=20×30, A3=30×10, A4=10×30
    vector<int> dims = {40, 20, 30, 10, 30};

    cout << "=== MATRIX CHAIN MULTIPLICATION ===\n";
    cout << "Matrices: A1(40×20) A2(20×30) A3(30×10) A4(10×30)\n\n";
    cout << "Minimum multiplications: "
         << matrixChain(dims) << "\n"; // Expected: 26000
    return 0;
}
