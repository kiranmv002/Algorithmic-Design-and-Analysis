// ============================================================
// FILE: graph_coloring.cpp
// TOPIC: Graph Coloring
// TIME:  O(K^V)   SPACE: O(V)
// Compile: g++ -std=c++17 -o coloring graph_coloring.cpp
// ============================================================
#include <iostream>
#include <vector>
using namespace std;

// Check if assigning color c to vertex u is safe
bool isSafe(vector<vector<int>>& adj, vector<int>& color,
            int u, int c) {
    for (int v : adj[u])
        if (color[v] == c) return false;
    return true;
}

// Solve graph coloring using backtracking
bool graphColoring(vector<vector<int>>& adj,
                   vector<int>& color,
                   int u, int V, int K) {
    if (u == V) return true; // All vertices colored

    for (int c = 1; c <= K; c++) {
        if (isSafe(adj, color, u, c)) {
            color[u] = c;                           // CHOOSE
            if (graphColoring(adj, color,
                               u+1, V, K)) // EXPLORE
                return true;
            color[u] = 0;                           // UNCHOOSE
        }
    }
    return false; // No valid coloring
}

