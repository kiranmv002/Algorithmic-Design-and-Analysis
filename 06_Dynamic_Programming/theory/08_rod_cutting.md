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
