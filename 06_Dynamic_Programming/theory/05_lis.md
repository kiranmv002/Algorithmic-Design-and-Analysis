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

## Example Step by Step
Array: [10, 9, 2, 5, 3, 7, 101, 18]
Index:   0  1  2  3  4  5   6   7
```
dp[0]=1 (10 alone)
dp[1]=1 (9 alone, 10>9 so can't extend)
dp[2]=1 (2 alone, 10>2, 9>2)
dp[3]=2 (2<5 → dp[3]=dp[2]+1=2)
dp[4]=2 (2<3 → dp[4]=dp[2]+1=2)
dp[5]=3 (2<7,5<7,3<7 → dp[5]=dp[3]+1=3)
dp[6]=4 (all < 101 → dp[6]=dp[5]+1=4)
dp[7]=4 (2,5,7 < 18 → dp[7]=dp[5]+1=4)

dp = [1, 1, 1, 2, 2, 3, 4, 4]
LIS = max(dp) = 4 ✅
```
## Binary Search Approach O(n log n)
Maintain a tails array.
tails[i] = smallest tail element for
           increasing subsequence of length i+1.
Use binary search to update tails.

Much faster for large inputs!

## Complexity
| Approach | Time | Space |
|----------|------|-------|
| DP O(n²) | O(n²) | O(n) |
| Binary Search | O(n log n) | O(n) |

## Applications
→ Patience sorting card game
→ Box stacking problem
→ Building bridges problem
→ Stock market analysis
