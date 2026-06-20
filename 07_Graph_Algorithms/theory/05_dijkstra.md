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
Core operation in Dijkstra:
For edge u→v with weight w:
If dist[u] + w < dist[v]:
    dist[v] = dist[u] + w  ← RELAX

