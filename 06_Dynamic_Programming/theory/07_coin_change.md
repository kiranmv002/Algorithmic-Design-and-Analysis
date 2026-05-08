# Coin Change Problem

## Problem Statement
Given coins of certain denominations and a target amount.
Find MINIMUM number of coins to make the amount.
Unlimited supply of each coin.

## Example
Coins = [1, 5, 6, 9]
Amount = 11

Possible ways:
11 = 1+1+1+1+1+1+1+1+1+1+1 → 11 coins
11 = 5+5+1 → 3 coins
11 = 5+6   → 2 coins ✅ MINIMUM!

## Why Greedy Fails?
Greedy picks largest coin ≤ amount first.
Coins=[1,3,4], Amount=6
Greedy: 4+1+1 = 3 coins
DP: 3+3 = 2 coins ✅ (Greedy is WRONG!)
