# Cycle Detection in Graphs

## Why Detect Cycles?
→ Deadlock detection in OS
→ Dependency resolution
→ Topological sort (needs acyclic graph)
→ Circuit analysis

## Cycle in Undirected Graph

### Method: DFS with Parent Tracking
During DFS if we reach an ALREADY VISITED vertex
that is NOT the parent → CYCLE EXISTS!

Example:
0 — 1
|   |
2 — 3

DFS from 0:
Visit 0 (parent=-1)
Visit 1 (parent=0)
Visit 3 (parent=1)
Visit 2 (parent=3)
From 2, neighbor 0 is visited and not parent of 2
→ CYCLE DETECTED! ✅
