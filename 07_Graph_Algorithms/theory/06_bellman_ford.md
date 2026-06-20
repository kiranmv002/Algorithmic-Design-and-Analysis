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
