# Bellman-Ford Algorithm

## Problem Statement
Find SHORTEST PATH from source to all vertices.
Works with NEGATIVE edge weights.
Detects NEGATIVE CYCLES.

## Why Not Dijkstra for Negative Edges?
Dijkstra marks vertex as done permanently.
With negative edges, a longer path might
become shorter later → Dijkstra misses this!

## Key Idea
Relax ALL edges V-1 times.
After V-1 iterations, shortest paths are finalized.
(Shortest path can have at most V-1 edges)

## DP / Relaxation Approach

### Relaxation
For edge u→v with weight w:
If dist[u] + w < dist[v]:
    dist[v] = dist[u] + w  ← RELAX!

### Algorithm
1. Initialize dist[src]=0, dist[all others]=∞
2. Repeat V-1 times:
   For each edge (u,v,w):
     Relax(u, v, w)
3. Check for negative cycle:
   If any edge can still be relaxed → NEGATIVE CYCLE!
