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
fib(5) call tree:
              fib(5)
           /         \
        fib(4)       fib(3)
       /     \       /    \
    fib(3) fib(2) fib(2) fib(1)
    /   \
 fib(2) fib(1)

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
