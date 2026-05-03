# Matrix Chain Multiplication

## Problem Statement
Given a sequence of matrices A1, A2, ..., An.
Find the OPTIMAL way to parenthesize them
to MINIMIZE total number of multiplications.

Note: We are NOT actually multiplying matrices.
We are finding the OPTIMAL ORDER to multiply.

## Why Order Matters?
Multiplying matrices A(p×q) and B(q×r):
Cost = p × q × r multiplications

Example: Three matrices
A = 10×30, B = 30×5, C = 5×60

Option 1: (AB)C
AB cost = 10×30×5 = 1500
(AB)C cost = 10×5×60 = 3000
Total = 4500

Option 2: A(BC)
BC cost = 30×5×60 = 9000
A(BC) cost = 10×30×60 = 18000
Total = 27000

Option 1 is 6× FASTER! ✅

## DP Approach

### Step 1: Define Subproblem
dp[i][j] = minimum cost to multiply
           matrices from i to j

### Step 2: Recurrence
For each split point k (i ≤ k < j):
dp[i][j] = min(dp[i][k] + dp[k+1][j]
               + dims[i-1] × dims[k] × dims[j])

Where dims[] stores dimensions.
Matrix i has dimensions dims[i-1] × dims[i]

### Step 3: Base Cases
dp[i][i] = 0 (single matrix, no multiplication)

### Step 4: Fill diagonally
Fill for chains of length 2, 3, ..., n
```
## Example
Matrices: dims = [40, 20, 30, 10, 30]
A1=40×20, A2=20×30, A3=30×10, A4=10×30

dp[1][2] = 40×20×30 = 24000
dp[2][3] = 20×30×10 = 6000
dp[3][4] = 30×10×30 = 9000

dp[1][3] = min(
  dp[1][1]+dp[2][3]+40×20×10 = 0+6000+8000 = 14000
  dp[1][2]+dp[3][3]+40×30×10 = 24000+0+12000 = 36000
) = 14000

dp[2][4] = min(
  dp[2][2]+dp[3][4]+20×30×30 = 0+9000+18000 = 27000
  dp[2][3]+dp[4][4]+20×10×30 = 6000+0+6000 = 12000
) = 12000

dp[1][4] = min(
  dp[1][1]+dp[2][4]+40×20×30 = 0+12000+24000 = 36000
  dp[1][2]+dp[3][4]+40×30×30 = 24000+9000+36000 = 69000
  dp[1][3]+dp[4][4]+40×10×30 = 14000+0+12000 = 26000
) = 26000 ✅
```
## Complexity
| | Time | Space |
|-|------|-------|
| DP | O(n³) | O(n²) |
