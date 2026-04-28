# 0/1 Knapsack Problem

## Problem Statement
Given N items each with weight w[i] and value v[i].
Knapsack has capacity W.
Each item can be taken FULLY or NOT AT ALL (0 or 1).
Maximize total value without exceeding capacity.

## Why NOT Greedy?
Greedy (highest ratio first) fails for 0/1 Knapsack.
Counter example:
Items: (w=10,v=60), (w=20,v=100), (w=30,v=120)
Capacity = 50

Greedy picks: item1(10) + item2(20) + part of item3 ❌
But 0/1 means no fractions allowed!
Best: item2(20) + item3(30) = value 220 ✅
Greedy would give wrong answer.

## DP Approach

### Step 1: Define Subproblem
dp[i][w] = maximum value using first i items
           with knapsack capacity w
