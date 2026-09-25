// ============================================================
// FILE: sudoku_solver.cpp
// TOPIC: Sudoku Solver using Backtracking
// TIME:  O(9^empty_cells)   SPACE: O(1)
// Compile: g++ -std=c++17 -o sudoku sudoku_solver.cpp
// ============================================================
#include <iostream>
#include <vector>
using namespace std;

// Check if placing num at (row, col) is safe
bool isSafe(vector<vector<int>>& grid, int row,
            int col, int num) {
    // Check row
    for (int j = 0; j < 9; j++)
        if (grid[row][j] == num) return false;

    // Check column
    for (int i = 0; i < 9; i++)
        if (grid[i][col] == num) return false;

    // Check 3×3 subgrid
    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[boxRow+i][boxCol+j] == num)
                return false;

    return true;
}
