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

Initial matrix:
     0    1    2    3
0  [ 0    3    ∞    7  ]
1  [ 8    0    2    ∞  ]
2  [ 5    ∞    0    1  ]
3  [ 2    ∞    ∞    0  ]

After k=0 (via vertex 0):
dp[1][3] = min(∞, dp[1][0]+dp[0][3]) = min(∞,8+7) = 15
dp[2][1] = min(∞, dp[2][0]+dp[0][1]) = min(∞,5+3) = 8
dp[2][3] = min(1,  dp[2][0]+dp[0][3]) = min(1,5+7) = 1
dp[3][1] = min(∞, dp[3][0]+dp[0][1]) = min(∞,2+3) = 5
dp[3][2] = min(∞, dp[3][0]+dp[0][2]) = min(∞,∞) = ∞

(Continue for k=1,2,3...)

Final shortest paths:
0→2 = 5 (via 1: 0→1→2 = 3+2 = 5)
1→3 = 3 (via 2: 1→2→3 = 2+1 = 3)

## Negative Cycle Detection
If dp[i][i] < 0 after algorithm → negative cycle exists!

## Dijkstra vs Bellman-Ford vs Floyd-Warshall

| Algorithm | Type | Negative | Time | APSP |
|-----------|------|----------|------|------|
| Dijkstra | SSSP | No | O((V+E)logV) | No |
| Bellman-Ford | SSSP | Yes | O(VE) | No |
| Floyd-Warshall | APSP | Yes | O(V³) | Yes |

SSSP = Single Source Shortest Path
APSP = All Pairs Shortest Path

## Complexity
| | Time | Space |
|-|------|-------|
| Floyd-Warshall | O(V³) | O(V²) |
