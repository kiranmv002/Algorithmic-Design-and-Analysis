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
