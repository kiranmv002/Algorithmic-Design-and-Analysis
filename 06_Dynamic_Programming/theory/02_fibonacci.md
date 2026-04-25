# Fibonacci — Dynamic Programming

## Problem Statement
Find the nth Fibonacci number.
F(0)=0, F(1)=1
F(n) = F(n-1) + F(n-2) for n > 1

Sequence: 0 1 1 2 3 5 8 13 21 34 55...

## Naive Recursion (BAD)
T(n) = T(n-1) + T(n-2)
Solution: O(2ⁿ) — EXPONENTIAL!

For n=50: 2^50 = 1,125,899,906,842,624 operations!
Completely impractical.

## Why is it Slow?
```
fib(5) call tree:
              fib(5)
           /         \
        fib(4)       fib(3)
       /     \       /    \
    fib(3) fib(2) fib(2) fib(1)
    /   \
 fib(2) fib(1)
```
fib(3) computed 2 times
fib(2) computed 3 times → OVERLAPPING SUBPROBLEMS!

## Approach 1: Memoization (Top-Down)
Store computed results in memo array.
Before computing check if already stored.

Time:  O(n)  — each value computed once
Space: O(n)  — memo array + recursion stack

## Approach 2: Tabulation (Bottom-Up)
Fill table from F(0) to F(n) iteratively.
No recursion at all.

Time:  O(n)
Space: O(n)

## Approach 3: Space Optimized
Only need last 2 values at any time.
Use 2 variables instead of array.

Time:  O(n)
Space: O(1) ← BEST!

## Comparison Table

| Approach | Time | Space | Method |
|----------|------|-------|--------|
| Naive Recursion | O(2ⁿ) | O(n) | Recursion |
| Memoization | O(n) | O(n) | Recursion + Cache |
| Tabulation | O(n) | O(n) | Iteration + Table |
| Space Optimized | O(n) | O(1) | 2 Variables |

## Example: fib(6)

Tabulation:
Index: 0  1  2  3  4  5  6
Value: 0  1  1  2  3  5  8

dp[2] = dp[1] + dp[0] = 1 + 0 = 1
dp[3] = dp[2] + dp[1] = 1 + 1 = 2
dp[4] = dp[3] + dp[2] = 2 + 1 = 3
dp[5] = dp[4] + dp[3] = 3 + 2 = 5
dp[6] = dp[5] + dp[4] = 5 + 3 = 8 ✅
