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
