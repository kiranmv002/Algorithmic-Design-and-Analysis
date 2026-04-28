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

### Step 2: Recurrence Relation
For each item i and capacity w:

Option 1: Don't take item i
dp[i][w] = dp[i-1][w]

Option 2: Take item i (only if w[i] ≤ w)
dp[i][w] = dp[i-1][w - w[i]] + v[i]

Take the MAXIMUM of both options:
dp[i][w] = max(dp[i-1][w],
               dp[i-1][w-w[i]] + v[i])

### Step 3: Base Cases
dp[0][w] = 0 for all w (no items → value 0)
dp[i][0] = 0 for all i (no capacity → value 0)

## Example
Items: weights=[2,3,4,5], values=[3,4,5,6]
Capacity W = 5

DP Table (rows=items, cols=capacity 0 to 5):
```
    0  1  2  3  4  5
i=0 0  0  0  0  0  0
i=1 0  0  3  3  3  3   ← item1(w=2,v=3)
i=2 0  0  3  4  4  7   ← item2(w=3,v=4)
i=3 0  0  3  4  5  7   ← item3(w=4,v=5)
i=4 0  0  3  4  5  7   ← item4(w=5,v=6)
```
Answer = dp[4][5] = 7 ✅
(Take item1 w=2,v=3 + item2 w=3,v=4 = 7)

## Complexity Analysis
| Step | Time | Space |
|------|------|-------|
| Fill DP table | O(n × W) | O(n × W) |
| Space optimized | O(n × W) | O(W) |

Note: O(nW) is PSEUDO-POLYNOMIAL
(depends on value of W, not just count of items)
