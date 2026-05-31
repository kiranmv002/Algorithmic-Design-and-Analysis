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

## Graph Representations

### Adjacency Matrix
2D array of size V×V
matrix[i][j] = 1 if edge i→j exists
             = weight if weighted

Pros:  O(1) edge lookup
Cons:  O(V²) space — bad for sparse graphs
