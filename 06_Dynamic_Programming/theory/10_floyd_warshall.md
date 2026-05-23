# Floyd-Warshall Algorithm

## Problem Statement
Find SHORTEST PATH between ALL pairs of vertices.
Works with negative weights.
Does NOT work with negative cycles.

Called: All-Pairs Shortest Path (APSP)

## Key Idea
For each intermediate vertex k:
Check if path i→k→j is shorter than direct i→j.

## DP Approach

### Step 1: Define Subproblem
dp[i][j][k] = shortest path from i to j
              using only vertices {1,2,...,k}
              as intermediate vertices

Simplified to 2D: dp[i][j]

### Step 2: Recurrence
dp[i][j] = min(dp[i][j],
               dp[i][k] + dp[k][j])

For each k from 1 to V.

### Step 3: Base Cases
dp[i][i] = 0    (distance to itself)
dp[i][j] = edge weight if edge exists
dp[i][j] = ∞ if no edge

## Example
Graph (4 vertices):
0→1 = 3
0→3 = 7
1→0 = 8
1→2 = 2
2→0 = 5
2→3 = 1
3→0 = 2
