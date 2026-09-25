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

// Find next empty cell
bool findEmpty(vector<vector<int>>& grid,
               int& row, int& col) {
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0) return true;
    return false; // No empty cell → solved!
}

// Solve sudoku using backtracking
bool solveSudoku(vector<vector<int>>& grid) {
    int row, col;

    // No empty cell → puzzle solved
    if (!findEmpty(grid, row, col)) return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;              // CHOOSE

            if (solveSudoku(grid)) return true;// EXPLORE

            grid[row][col] = 0;                // UNCHOOSE
        }
    }
    return false; // Trigger backtrack
}

void printGrid(vector<vector<int>>& grid) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0)
            cout << "------+-------+------\n";
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) cout << "| ";
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "=== SUDOKU SOLVER ===\n\n";

    vector<vector<int>> grid = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    cout << "Input Sudoku:\n";
    printGrid(grid);
