// ============================================================
// FILE: n_queens.cpp
// TOPIC: N-Queens Problem
// TIME:  O(N!)   SPACE: O(N)
// Compile: g++ -std=c++17 -o nqueens n_queens.cpp
// ============================================================
#include <iostream>
#include <vector>
using namespace std;

// Check if placing queen at (row, col) is safe
bool isSafe(vector<int>& board, int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        // Same column or diagonal
        if (board[i] == col ||
            abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

// Print the board
void printBoard(vector<int>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i] == j ? "Q " : ". ");
        cout << "\n";
    }
    cout << "\n";
}

// Solve N-Queens using backtracking
void solveNQueens(vector<int>& board, int row,
                  int N, int& count, bool printAll) {
    if (row == N) {
        count++;
        if (printAll) {
            cout << "Solution " << count << ":\n";
            printBoard(board, N);
        }
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row] = col;              // CHOOSE
            solveNQueens(board, row + 1,
                         N, count, printAll); // EXPLORE
            board[row] = -1;               // UNCHOOSE
        }
    }
}

int main() {
    cout << "=== N-QUEENS PROBLEM ===\n\n";

    // Count solutions for N = 1 to 8
    cout << "Number of solutions:\n";
    for (int N = 1; N <= 8; N++) {
        vector<int> board(N, -1);
        int count = 0;
        solveNQueens(board, 0, N, count, false);
        cout << N << "-Queens: " << count
             << " solutions\n";
    }

    // Print all solutions for 4-Queens
    cout << "\n=== ALL SOLUTIONS FOR 4-QUEENS ===\n";
    int N = 4;
    vector<int> board(N, -1);
    int count = 0;
    solveNQueens(board, 0, N, count, true);
    cout << "Total solutions: " << count << "\n";

    return 0;
}
