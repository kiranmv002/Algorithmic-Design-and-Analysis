# N-Queens Problem

## Problem Statement
Place N queens on an N×N chessboard such that
NO two queens attack each other.

Queens attack:
```
→ Same row
→ Same column
→ Same diagonal (both diagonals)
```
## Example: 4-Queens
```
One valid solution:
. Q . .
. . . Q
Q . . .
. . Q .
```
Queens at: (0,1), (1,3), (2,0), (3,2)

## Backtracking Approach
Place queens ROW by ROW.
For each row try each column.
Check if placement is SAFE.
If safe → place queen → go to next row.
If no safe column → BACKTRACK to previous row.

## Safety Check
```
For queen at (row, col):
1. No queen in same column
   → board[i] != col for all i < row

2. No queen in left diagonal
   → abs(board[i] - col) != abs(i - row)
   for all i < row

3. No queen in right diagonal
   → same as above (same formula covers both)
```
## Step by Step: 4-Queens
```
Row 0: Try col 0
       Safe! → board = [0, _, _, _]

Row 1: Try col 0 → UNSAFE (same col)
       Try col 1 → UNSAFE (diagonal)
       Try col 2 → Safe! → board = [0, 2, _, _]

Row 2: Try col 0 → UNSAFE (diagonal)
       Try col 1 → UNSAFE (diagonal)
       Try col 2 → UNSAFE (same col)
       Try col 3 → UNSAFE (diagonal)
       No valid column → BACKTRACK!

Row 1: Try col 3 → Safe! → board = [0, 3, _, _]

Row 2: Try col 0 → UNSAFE (diagonal)
       Try col 1 → Safe! → board = [0, 3, 1, _]

Row 3: Try col 0 → UNSAFE (diagonal)
       Try col 1 → UNSAFE (same col)
       Try col 2 → UNSAFE (diagonal)
       Try col 3 → UNSAFE (same col)
       No valid column → BACKTRACK!

Row 2: Try col 2 → UNSAFE
       No valid column → BACKTRACK!

Row 1: No more columns → BACKTRACK!

Row 0: Try col 1 → Safe! → board = [1, _, _, _]
       ... (continues until solution found)
```
## Solutions Count
| N | Solutions |
|---|-----------|
| 1 | 1 |
| 2 | 0 |
| 3 | 0 |
| 4 | 2 |
| 5 | 10 |
| 6 | 4 |
| 7 | 40 |
| 8 | 92 |

## Complexity
```
Time:  O(N!) — N choices for row 0,
               N-1 for row 1, etc.
Space: O(N)  — board array + recursion stack
```
