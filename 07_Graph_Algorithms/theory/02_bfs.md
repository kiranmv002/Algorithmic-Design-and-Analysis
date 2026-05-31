# Breadth First Search (BFS)

## What is BFS?
BFS explores graph LEVEL BY LEVEL.
Visit all neighbors before going deeper.
Uses a QUEUE (FIFO).

## Real Life Analogy
Ripples in a pond when you throw a stone.
First ring = level 1 neighbors
Second ring = level 2 neighbors
Spreads outward level by level.

## Algorithm Steps
1. Start at source vertex
2. Mark it visited, add to queue
3. While queue not empty:
   a. Dequeue front vertex u
   b. Process u
   c. For each unvisited neighbor v of u:
      - Mark v visited
      - Enqueue v

## Example
Graph:
0 — 1 — 3
|       |
2 — — — 4

BFS from 0:
Queue: [0]         → Visit 0
Queue: [1, 2]      → Visit 1
Queue: [2, 3]      → Visit 2
Queue: [3, 4]      → Visit 3
Queue: [4]         → Visit 4
Queue: []          → Done

BFS Order: 0 1 2 3 4

## BFS Tree and Levels
Level 0: {0}
Level 1: {1, 2}
Level 2: {3, 4}

## Shortest Path Property
BFS gives SHORTEST PATH in UNWEIGHTED graphs.
Level of vertex = shortest distance from source.

## Applications
→ Shortest path in unweighted graph
→ Level order traversal of tree
→ Finding connected components
→ Bipartite graph checking
→ Web crawlers
→ Social network friend suggestions

## Complexity
| | Time | Space |
|-|------|-------|
| BFS | O(V+E) | O(V) |

V = vertices visited
E = edges explored
O(V) space for visited array and queue
