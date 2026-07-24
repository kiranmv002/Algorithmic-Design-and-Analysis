# Floyd-Warshall (Graph Topic)

## Review
Covered in Week 5 (Dynamic Programming).
Here we focus on GRAPH perspective.

## All Pairs Shortest Path (APSP)
Find shortest path between EVERY pair of vertices.

Running Dijkstra V times = O(V × (V+E) log V)
Floyd-Warshall = O(V³) simpler code

For dense graphs: Floyd-Warshall often preferred.
```
## Path Reconstruction
Store a next[][] matrix.
next[i][j] = next vertex on shortest path from i to j.

To reconstruct path from i to j:
path = [i]
while i != j:
    i = next[i][j]
    path.append(i)
```
## When to Use Which?

| Algorithm | When | Time |
|-----------|------|------|
| BFS | Unweighted SSSP | O(V+E) |
| Dijkstra | Weighted SSSP, no negative | O((V+E)logV) |
| Bellman-Ford | Weighted SSSP, negative ok | O(VE) |
| Floyd-Warshall | APSP, dense graph | O(V³) |
