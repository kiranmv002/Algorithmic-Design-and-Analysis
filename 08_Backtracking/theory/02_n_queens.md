# N-Queens Problem

## Problem Statement
Place N queens on an N×N chessboard such that
NO two queens attack each other.

Queens attack:
→ Same row
→ Same column
→ Same diagonal (both diagonals)

## Example: 4-Queens

One valid solution:
. Q . .
. . . Q
Q . . .
. . Q .

Queens at: (0,1), (1,3), (2,0), (3,2)

## Backtracking Approach
Place queens ROW by ROW.
For each row try each column.
Check if placement is SAFE.
If safe → place queen → go to next row.
If no safe column → BACKTRACK to previous row.

## Safety Check
For queen at (row, col):
1. No queen in same column
   → board[i] != col for all i < row

2. No queen in left diagonal
   → abs(board[i] - col) != abs(i - row)
   for all i < row

3. No queen in right diagonal
   → same as above (same formula covers both)

