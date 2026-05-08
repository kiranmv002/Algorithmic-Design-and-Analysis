# Coin Change Problem

## Problem Statement
Given coins of certain denominations and a target amount.
Find MINIMUM number of coins to make the amount.
Unlimited supply of each coin.

## Example
Coins = [1, 5, 6, 9]
Amount = 11

Possible ways:
```
11 = 1+1+1+1+1+1+1+1+1+1+1 → 11 coins
11 = 5+5+1 → 3 coins
11 = 5+6   → 2 coins ✅ MINIMUM!
```

## Why Greedy Fails?
Greedy picks largest coin ≤ amount first.
Coins=[1,3,4], Amount=6
Greedy: 4+1+1 = 3 coins
DP: 3+3 = 2 coins ✅ (Greedy is WRONG!)

## DP Approach

### Step 1: Define Subproblem
dp[i] = minimum coins needed to make amount i

### Step 2: Recurrence
For each coin c in coins:
  If c ≤ i:
    dp[i] = min(dp[i], dp[i-c] + 1)

### Step 3: Base Cases
dp[0] = 0 (0 coins for amount 0)
dp[i] = infinity initially (impossible)

## Example Step by Step
```
Coins=[1,5,6,9], Amount=11

dp[0]=0
dp[1]=min(dp[0]+1)=1      ← use coin 1
dp[2]=min(dp[1]+1)=2      ← use coin 1
dp[3]=min(dp[2]+1)=3      ← use coin 1
dp[4]=min(dp[3]+1)=4      ← use coin 1
dp[5]=min(dp[4]+1,dp[0]+1)=1  ← use coin 5
dp[6]=min(dp[5]+1,dp[1]+1,dp[0]+1)=1 ← use coin 6
dp[7]=min(dp[6]+1,dp[2]+1,dp[1]+1)=2 ← 1+6
dp[8]=min(dp[7]+1,dp[3]+1,dp[2]+1)=3 ← 1+1+6
dp[9]=min(dp[8]+1,dp[4]+1,dp[3]+1,dp[0]+1)=1 ← coin 9
dp[10]=min(dp[9]+1,dp[5]+1,dp[4]+1,dp[1]+1)=2 ← 1+9
dp[11]=min(dp[10]+1,dp[6]+1,dp[5]+1,dp[2]+1)=2 ← 5+6 ✅

Answer = dp[11] = 2 ✅
```
## Complexity
| | Time | Space |
|-|------|-------|
| DP | O(amount × coins) | O(amount) |
