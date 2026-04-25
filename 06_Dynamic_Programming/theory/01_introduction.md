# Dynamic Programming — Introduction

## What is Dynamic Programming?
Dynamic Programming (DP) solves complex problems by:
1. Breaking into smaller OVERLAPPING subproblems
2. Solving each subproblem ONLY ONCE
3. STORING results to avoid recomputation

## Who invented it?
Richard Bellman in 1950s.
"Programming" here means tabular method, not coding.

## Real Life Example
Fibonacci without DP:
fib(5)
├── fib(4)
│   ├── fib(3)
│   │   ├── fib(2) ← computed again!
│   │   └── fib(1)
│   └── fib(2)     ← computed again!
└── fib(3)         ← computed again!

fib(3) is computed 2 times
fib(2) is computed 3 times → WASTEFUL!

With DP: compute each value ONCE → store → reuse!

## Two Properties Required

### 1. Overlapping Subproblems
Same subproblems are solved multiple times.
Example: fib(3) called many times in fib(5)

### 2. Optimal Substructure
Optimal solution is built from optimal sub-solutions.
Example: Shortest path A→C through B means
A→B and B→C are also shortest paths.

## Two Approaches

### Approach 1: Top-Down (Memoization)
Start from original problem.
Recurse down to smaller subproblems.
Store result when computed (cache it).
Return cached result if already computed.

Pros: Intuitive, only computes needed subproblems
Cons: Recursion overhead, stack overflow risk

### Approach 2: Bottom-Up (Tabulation)
Start from smallest subproblems.
Build up to original problem iteratively.
Store all results in a table (array/matrix).

Pros: No recursion, faster in practice
Cons: Computes all subproblems even if not needed
