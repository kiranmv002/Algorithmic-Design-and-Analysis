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

## Example
Vertices: 0,1,2,3,4
Edges: 0→1(6), 0→2(7), 1→2(8), 1→3(-4),
       1→4(5), 2→3(9), 2→4(-3), 3→0(2), 4→3(7)
Source = 0

Initial: dist=[0, ∞, ∞, ∞, ∞]

Iteration 1:
0→1: dist[1]=min(∞,0+6)=6
0→2: dist[2]=min(∞,0+7)=7
1→2: dist[2]=min(7,6+8)=7
1→3: dist[3]=min(∞,6-4)=2
1→4: dist[4]=min(∞,6+5)=11
2→3: dist[3]=min(2,7+9)=2
2→4: dist[4]=min(11,7-3)=4
3→0: dist[0]=min(0,2+2)=0
4→3: dist[3]=min(2,4+7)=2

After V-1=4 iterations:
dist = [0, 6, 7, 2, 4] ✅

## Negative Cycle Detection
After V-1 iterations, try relaxing again.
If dist[v] can still decrease → NEGATIVE CYCLE exists!

## Why V-1 Iterations?
Shortest path in graph with V vertices
has at most V-1 edges (no cycles in shortest path).
Each iteration guarantees shortest path using
at most i edges is found.

## Complexity
| | Time | Space |
|-|------|-------|
| Bellman-Ford | O(V×E) | O(V) |
| Dijkstra | O((V+E)logV) | O(V) |

Bellman-Ford is slower but handles negative weights!
