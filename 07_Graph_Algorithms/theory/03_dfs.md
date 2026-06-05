# Depth First Search (DFS)

## What is DFS?
DFS explores graph by going DEEP first.
Follow one path as far as possible.
Backtrack when stuck.
Uses STACK (or recursion).

## Real Life Analogy
Exploring a maze.
Go as deep as possible in one direction.
If stuck → backtrack and try another direction.

## Algorithm Steps
1. Start at source vertex
2. Mark it visited
3. For each unvisited neighbor v:
   - Recursively DFS(v)
4. Backtrack when no unvisited neighbors

## Example
Graph:
0 — 1 — 3
|       |
2 — — — 4

DFS from 0:
Visit 0 → go to 1
Visit 1 → go to 3
Visit 3 → go to 4
Visit 4 → go to 2
Visit 2 → no unvisited neighbors
Backtrack all the way

DFS Order: 0 1 3 4 2
