# Bellman-Ford (Graph Topic)

## Review
Covered in Week 5 (Dynamic Programming).
Here we focus on GRAPH perspective.

## When to Use Bellman-Ford?
→ Graph has NEGATIVE weight edges
→ Need to detect NEGATIVE CYCLES
→ Distributed systems (each node computes own distances)

## Negative Cycle
A cycle whose total weight is NEGATIVE.
Example: A→B(1), B→C(-3), C→A(1)
Total = 1 + (-3) + 1 = -1 (negative cycle!)

If negative cycle exists:
→ No shortest path (can go around cycle forever)
→ Distance keeps decreasing → -∞

## Why V-1 iterations?
Shortest path between any two vertices
in a graph with V vertices has at most V-1 edges.
(Assuming no negative cycles)

After i iterations:
Shortest paths using at most i edges are correct.
After V-1 iterations: all shortest paths found.

## Negative Cycle Detection
After V-1 iterations, try relaxing once more.
If any distance decreases → NEGATIVE CYCLE exists!

## Bellman-Ford vs Dijkstra

| Feature | Bellman-Ford | Dijkstra |
|---------|-------------|---------|
| Negative weights | YES | NO |
| Negative cycles | Detects | Cannot handle |
| Time | O(VE) | O((V+E)logV) |
| Approach | DP/Relaxation | Greedy |
| Distributed | Yes | No |
