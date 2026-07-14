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
