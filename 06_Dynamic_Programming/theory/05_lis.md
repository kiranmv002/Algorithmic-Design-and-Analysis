# Longest Increasing Subsequence (LIS)

## Problem Statement
Given an array of integers.
Find length of longest subsequence where
each element is STRICTLY GREATER than previous.

## Example
Array: [10, 9, 2, 5, 3, 7, 101, 18]

Some increasing subsequences:
[2, 3, 7, 101] → length 4
[2, 5, 7, 101] → length 4
[2, 3, 7, 18]  → length 4

LIS = 4 ✅

## DP Approach O(n²)

### Step 1: Define Subproblem
dp[i] = length of LIS ending at index i
(index i is ALWAYS included)

### Step 2: Recurrence
For each i, look at all j < i:
If arr[j] < arr[i]:
    dp[i] = max(dp[i], dp[j] + 1)

### Step 3: Base Cases
dp[i] = 1 for all i (each element alone)

### Step 4: Answer
max(dp[0], dp[1], ..., dp[n-1])
