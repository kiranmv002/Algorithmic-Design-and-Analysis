# Topological Sort

## What is Topological Sort?
Linear ordering of vertices in a DAG such that
for every directed edge u→v,
vertex u comes BEFORE vertex v.

## Key Requirement
Only works on DAG (Directed Acyclic Graph).
If cycle exists → topological sort NOT possible.

## Real Life Examples
→ Course prerequisites
  (Take Math before Physics)
→ Build systems
  (Compile A before B which needs A)
→ Task scheduling
  (Do task A before task B)

## Example
DAG:
5 → 0
5 → 2
4 → 0
4 → 1
2 → 3
3 → 1

Valid Topological Orders:
5 4 2 3 1 0
4 5 2 3 0 1
5 4 2 3 0 1
(Multiple valid orders possible)

## Method 1: DFS Based
1. Do DFS on all vertices
2. After all neighbors of vertex u are done
   → push u to a stack
3. Pop stack for topological order

## Method 2: Kahn's Algorithm (BFS Based)
1. Calculate in-degree of all vertices
2. Add all 0 in-degree vertices to queue
3. While queue not empty:
   a. Dequeue vertex u
   b. Add u to result
   c. For each neighbor v of u:
      Decrease in-degree of v
      If in-degree of v becomes 0 → enqueue v
4. If result has all vertices → valid DAG
   Else → cycle exists!

## Kahn's vs DFS

| Feature | Kahn's (BFS) | DFS |
|---------|-------------|-----|
| Approach | In-degree | Finish time |
| Cycle Detection | Yes (easy) | Yes (harder) |
| Order | BFS order | Reverse DFS |
| Implementation | Iterative | Recursive |

## Complexity
| | Time | Space |
|-|------|-------|
| Both methods | O(V+E) | O(V) |
