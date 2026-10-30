# Graph Coloring Problem

## Problem Statement
Given a graph with V vertices.
Color each vertex with one of K colors such that
NO two ADJACENT vertices have the same color.

Find minimum K needed (chromatic number).
OR check if graph can be colored with given K.

## Real Life Applications
```
→ Map coloring (adjacent countries different colors)
→ Exam scheduling (conflicting exams different slots)
→ Register allocation in compilers
→ Frequency assignment in mobile networks
```
## Famous Result: Four Color Theorem
Any planar map can be colored with just 4 colors!
(Proved in 1976 using computers)

## Example (K=3 colors)
Graph:
```
0 — 1
|   |
3 — 2

Valid 3-coloring:
0 = Red
1 = Blue
2 = Red
3 = Blue
(0 and 2 not adjacent → can be same color)
```
## Backtracking Approach
For each vertex (in order 0 to V-1):
Try each color (1 to K):
  If color is SAFE (no adjacent vertex has same color):
    Assign color → go to next vertex
  If no color works → BACKTRACK

## Safety Check
For vertex u with color c:
Check all neighbors of u.
If any neighbor has color c → UNSAFE!

## Step by Step
Graph: 0-1, 1-2, 2-3, 3-0 (cycle)
K = 3 colors

Vertex 0: Try color 1 → Safe ✅ → color[0]=1
Vertex 1: Try color 1 → UNSAFE (adj to 0)
           Try color 2 → Safe ✅ → color[1]=2
Vertex 2: Try color 1 → UNSAFE (adj to 1? No!)
           Wait, 1 and 2 are adjacent
           Try color 1 → UNSAFE (adj to 1=color2? No)
           color[2]=1 ← Wait, check adj:
           neighbor of 2 is 1(color=2) and 3(uncolored)
           color 1 ≠ color[1]=2 → SAFE ✅ → color[2]=1
Vertex 3: neighbors are 2(color=1) and 0(color=1)
           Try color 1 → UNSAFE
           Try color 2 → UNSAFE (adj to 0? No, 0 has color 1)
           color[3] = 2 ← neighbor 0 has color 1 ≠ 2 ✅
                          neighbor 2 has color 1 ≠ 2 ✅
           SAFE! → color[3]=2

Result: colors = [1, 2, 1, 2] ✅

## Complexity
Time:  O(K^V) — K choices for V vertices
Space: O(V)   — color array + recursion stack
