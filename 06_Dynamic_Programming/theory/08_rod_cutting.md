# Rod Cutting Problem

## Problem Statement
Given a rod of length n.
Prices for each length: price[1..n]
Cut the rod to MAXIMIZE total revenue.

## Example
Length:  1  2  3  4  5  6  7  8
Price:   1  5  8  9 10 17 17 20

Rod of length 4:
Options:
4 → price 9
1+3 → 1+8 = 9
2+2 → 5+5 = 10 ✅
1+1+2 → 1+1+5 = 7
1+1+1+1 → 4

Best = 10 (cut into two pieces of length 2)

## DP Approach

### Step 1: Define Subproblem
dp[i] = maximum revenue for rod of length i

### Step 2: Recurrence
For each cut at position j (1 ≤ j ≤ i):
dp[i] = max(dp[i], price[j] + dp[i-j])

### Step 3: Base Cases
dp[0] = 0 (no rod, no revenue)

## Example Step by Step
Price: [0,1,5,8,9,10,17,17,20]
       (0 index unused)

dp[0]=0
dp[1]=max(price[1]+dp[0])=1
dp[2]=max(price[1]+dp[1], price[2]+dp[0])
     =max(1+1, 5+0)=5
dp[3]=max(price[1]+dp[2], price[2]+dp[1],
          price[3]+dp[0])
     =max(1+5, 5+1, 8+0)=8
dp[4]=max(price[1]+dp[3], price[2]+dp[2],
          price[3]+dp[1], price[4]+dp[0])
     =max(1+8, 5+5, 8+1, 9+0)=10 ✅

## Complexity
| | Time | Space |
|-|------|-------|
| DP | O(n²) | O(n) |
