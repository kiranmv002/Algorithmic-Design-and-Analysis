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
```
Valid 3-coloring:
0 = Red
1 = Blue
2 = Red
3 = Blue
(0 and 2 not adjacent → can be same color)

## Backtracking Approach
For each vertex (in order 0 to V-1):
Try each color (1 to K):
  If color is SAFE (no adjacent vertex has same color):
    Assign color → go to next vertex
  If no color works → BACKTRACK
