# 05 - Greedy Algorithms

## What is Greedy?
At each step pick the locally optimal choice hoping it leads to global optimal.

## Files
| File | Algorithm | Time | Greedy Choice |
|------|-----------|------|---------------|
| activity_selection.cpp | Activity Selection | O(n log n) | Earliest finish time |
| fractional_knapsack.cpp | Fractional Knapsack | O(n log n) | Highest value/weight ratio |
| huffman_coding.cpp | Huffman Coding | O(n log n) | Merge lowest frequency nodes |
| job_sequencing.cpp | Job Sequencing | O(n²) | Highest profit job first |
| kruskal_mst.cpp | Kruskal's MST | O(E log E) | Minimum weight edge no cycle |
| prims_mst.cpp | Prim's MST | O((V+E) log V) | Minimum edge from MST |
| dijkstra.cpp | Dijkstra SSSP | O((V+E) log V) | Minimum distance vertex |

## Key Comparisons
- Kruskal vs Prim → Both give MST, Kruskal sorts edges, Prim grows one tree
- Dijkstra vs Bellman-Ford → Dijkstra faster but no negative weights
- Fractional vs 0/1 Knapsack → Greedy works for fractional, DP needed for 0/1
