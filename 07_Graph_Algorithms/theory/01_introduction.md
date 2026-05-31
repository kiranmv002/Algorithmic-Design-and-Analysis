# Graph Algorithms — Introduction

## What is a Graph?
A graph G = (V, E) consists of:
V = set of vertices (nodes)
E = set of edges (connections)

## Real Life Examples
→ Google Maps    → Cities = vertices, Roads = edges
→ Social Network → People = vertices, Friendship = edges
→ Internet       → Computers = vertices, Links = edges
→ Circuit Board  → Components = vertices, Wires = edges

## Types of Graphs
```
### 1. Directed vs Undirected
Directed (Digraph): Edges have direction A→B
Undirected: Edges go both ways A—B

### 2. Weighted vs Unweighted
Weighted: Edges have values (distances, costs)
Unweighted: All edges equal

### 3. Cyclic vs Acyclic
Cyclic: Contains cycles (loops)
Acyclic: No cycles
DAG = Directed Acyclic Graph

### 4. Connected vs Disconnected
Connected: Path exists between every pair
Disconnected: Some vertices unreachable
```
## Graph Representations
```
### Adjacency Matrix
2D array of size V×V
matrix[i][j] = 1 if edge i→j exists
             = weight if weighted

Pros:  O(1) edge lookup
Cons:  O(V²) space — bad for sparse graphs

### Adjacency List
Array of lists
adj[i] = list of neighbors of vertex i

Pros:  O(V+E) space — good for sparse graphs
Cons:  O(degree) edge lookup
```
## When to Use Which?

| Representation | Space | Edge Check | Neighbors | Best For |
|---------------|-------|------------|-----------|----------|
| Adj Matrix | O(V²) | O(1) | O(V) | Dense graphs |
| Adj List | O(V+E) | O(degree) | O(degree) | Sparse graphs |

## Graph Algorithms Overview

| Algorithm | Purpose | Time |
|-----------|---------|------|
| BFS | Shortest path (unweighted) | O(V+E) |
| DFS | Cycle detection, topo sort | O(V+E) |
| Dijkstra | Shortest path (weighted) | O((V+E)logV) |
| Bellman-Ford | Shortest path (negative) | O(VE) |
| Floyd-Warshall | All pairs shortest path | O(V³) |
| Kruskal | Minimum spanning tree | O(E logE) |
| Prim | Minimum spanning tree | O((V+E)logV) |
| Topological Sort | Ordering of DAG | O(V+E) |
| Kosaraju | Strongly connected components | O(V+E) |
