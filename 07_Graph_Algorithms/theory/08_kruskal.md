# Kruskal's MST (Graph Topic)

## Review
Covered in Week 4 (Greedy Algorithms).
Here we focus on GRAPH perspective.

## Spanning Tree Properties
```
For graph with V vertices:
→ Spanning tree has exactly V-1 edges
→ No cycles
→ All vertices connected
```
## Number of Spanning Trees
```
Complete graph with V vertices has V^(V-2) spanning trees.
Example: K4 (4 vertices) has 4^2 = 16 spanning trees!
MST selects the ONE with minimum total weight.
```
## Cut Property (Why Greedy Works)
For any cut of the graph into two sets S and V-S:
The minimum weight edge crossing the cut
is always in some MST.

This PROVES Kruskal's greedy choice is correct!

## Union-Find Operations
find(x): Which component does x belong to?
union(x,y): Merge components of x and y.

Path Compression: Speeds up find() to nearly O(1)
Union by Rank: Keeps tree balanced

## Kruskal vs Prim Detailed

| Feature | Kruskal | Prim |
|---------|---------|------|
| Strategy | Add min edge globally | Add min edge from tree |
| Data Structure | Union-Find | Priority Queue |
| Graph Type | Works on disconnected | Connected only |
| Dense graphs | Slower | Faster |
| Sparse graphs | Faster | Slower |
| Time | O(E log E) | O((V+E) log V) |
