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

// Find minimum colors needed (chromatic number)
int chromaticNumber(vector<vector<int>>& adj, int V) {
    for (int K = 1; K <= V; K++) {
        vector<int> color(V, 0);
        if (graphColoring(adj, color, 0, V, K))
            return K;
    }
    return V;
}

void printColoring(vector<int>& color, int V) {
    string colorNames[] = {"", "Red", "Blue",
                            "Green", "Yellow"};
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " → "
             << colorNames[color[i]] << "\n";
}

int main() {
    cout << "=== GRAPH COLORING ===\n\n";

    int V = 4;
    vector<vector<int>> adj(V);

    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    // Graph: cycle of 4 vertices
    addEdge(0, 1); addEdge(1, 2);
    addEdge(2, 3); addEdge(3, 0);

    cout << "Graph: 0-1-2-3-0 (cycle)\n\n";

    int K = 3;
    vector<int> color(V, 0);

    if (graphColoring(adj, color, 0, V, K)) {
        cout << "Coloring with " << K
             << " colors: POSSIBLE\n";
        printColoring(color, V);
    } else {
        cout << "Coloring with " << K
             << " colors: NOT POSSIBLE\n";
    }

    cout << "\nChromatic number: "
         << chromaticNumber(adj, V) << "\n"; // 2

    // Complete graph K4 (needs 4 colors)
    cout << "\n=== COMPLETE GRAPH K4 ===\n";
    int V2 = 4;
    vector<vector<int>> adj2(V2);
    for (int i = 0; i < V2; i++)
        for (int j = i+1; j < V2; j++) {
            adj2[i].push_back(j);
            adj2[j].push_back(i);
        }
    cout << "Chromatic number of K4: "
         << chromaticNumber(adj2, V2) << "\n"; // 4

    return 0;
}
