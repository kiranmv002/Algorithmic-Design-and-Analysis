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

