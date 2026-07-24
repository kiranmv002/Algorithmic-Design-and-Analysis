# Dijkstra's Algorithm (Graph Topic)

## Review
Covered in Week 4 (Greedy Algorithms).
Here we focus on GRAPH perspective.

## Dijkstra as Graph Algorithm
Finds Single Source Shortest Path (SSSP)
in weighted graph with NON-NEGATIVE weights.

## Key Data Structures
Priority Queue (Min Heap):
→ Always process vertex with minimum distance
→ O(log V) for insert and extract

Distance Array:
→ dist[v] = current shortest distance from source

Visited Array:
→ Avoid reprocessing vertices

## Relaxation
```
Core operation in Dijkstra:
For edge u→v with weight w:
If dist[u] + w < dist[v]:
    dist[v] = dist[u] + w  ← RELAX
```
## Dijkstra with Adjacency List
```
Step 1: dist[src]=0, all others=∞
Step 2: Add (0, src) to min heap
Step 3: While heap not empty:
  Extract (d, u) with minimum d
  If d > dist[u]: skip (outdated)
  For each neighbor v of u:
    Relax(u, v, weight)
    If dist[v] updated: add to heap
```
## Negative Weights Problem
```
Edge 0→1 = 5
Edge 0→2 = 3
Edge 2→1 = -4 (negative!)

Dijkstra: dist[1] = 5 (marks 1 as done)
Actual:   dist[1] = 3 + (-4) = -1 (WRONG!)
```
Dijkstra gives WRONG answer with negative weights.
Use Bellman-Ford instead.

## Complexity
| Implementation | Time |
|---------------|------|
| Adjacency Matrix | O(V²) |
| Binary Heap + Adj List | O((V+E) log V) |
| Fibonacci Heap | O(E + V log V) |
