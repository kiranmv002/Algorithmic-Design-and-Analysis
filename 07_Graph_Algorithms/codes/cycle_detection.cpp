// ============================================================
// FILE: cycle_detection.cpp
// TOPIC: Cycle Detection — Undirected and Directed
// TIME:  O(V+E)   SPACE: O(V)
// Compile: g++ -std=c++17 -o cycle cycle_detection.cpp
// ============================================================
#include <iostream>
#include <vector>
using namespace std;

// Undirected Graph — DFS with parent tracking
bool dfsCycleUndirected(vector<vector<int>>& adj,
                         int u, int parent,
                         vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfsCycleUndirected(adj, v, u, visited))
                return true;
        } else if (v != parent) {
            return true; // Back edge found → CYCLE!
        }
    }
    return false;
}

bool hasCycleUndirected(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
        if (!visited[i])
            if (dfsCycleUndirected(adj, i, -1, visited))
                return true;
    return false;
}

// Directed Graph — DFS with color marking
// 0=WHITE(unvisited), 1=GRAY(in stack), 2=BLACK(done)
bool dfsCycleDirected(vector<vector<int>>& adj,
                       int u, vector<int>& color) {
    color[u] = 1; // GRAY — currently processing
    for (int v : adj[u]) {
        if (color[v] == 1) return true; // Back edge → CYCLE!
        if (color[v] == 0)
            if (dfsCycleDirected(adj, v, color))
                return true;
    }
    color[u] = 2; // BLACK — done
    return false;
}

bool hasCycleDirected(vector<vector<int>>& adj, int V) {
    vector<int> color(V, 0);
    for (int i = 0; i < V; i++)
        if (color[i] == 0)
            if (dfsCycleDirected(adj, i, color))
                return true;
    return false;
}

// Union-Find method for undirected
int find(vector<int>& parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

bool hasCycleUnionFind(int V, vector<pair<int,int>>& edges) {
    vector<int> parent(V);
    iota(parent.begin(), parent.end(), 0);

    for (auto& [u, v] : edges) {
        int pu = find(parent, u);
        int pv = find(parent, v);
        if (pu == pv) return true; // Same component → CYCLE!
        parent[pu] = pv;
    }
    return false;
}

int main() {
    cout << "=== CYCLE DETECTION ===\n\n";

    // Undirected with cycle
    cout << "Undirected Graph (with cycle):\n";
    int V1 = 4;
    vector<vector<int>> adj1(V1);
    adj1[0].push_back(1); adj1[1].push_back(0);
    adj1[1].push_back(2); adj1[2].push_back(1);
    adj1[2].push_back(3); adj1[3].push_back(2);
    adj1[3].push_back(0); adj1[0].push_back(3); // cycle!
    cout << "Has cycle: "
         << (hasCycleUndirected(adj1, V1) ? "YES" : "NO")
         << "\n\n"; // YES

    // Undirected without cycle
    cout << "Undirected Graph (no cycle):\n";
    int V2 = 4;
    vector<vector<int>> adj2(V2);
    adj2[0].push_back(1); adj2[1].push_back(0);
    adj2[1].push_back(2); adj2[2].push_back(1);
    adj2[2].push_back(3); adj2[3].push_back(2);
    cout << "Has cycle: "
         << (hasCycleUndirected(adj2, V2) ? "YES" : "NO")
         << "\n\n"; // NO

    // Directed with cycle
    cout << "Directed Graph (with cycle):\n";
    int V3 = 4;
    vector<vector<int>> adj3(V3);
    adj3[0].push_back(1);
    adj3[1].push_back(2);
    adj3[2].push_back(3);
    adj3[3].push_back(1); // cycle: 1→2→3→1
    cout << "Has cycle: "
         << (hasCycleDirected(adj3, V3) ? "YES" : "NO")
         << "\n\n"; // YES

    // Union-Find
    cout << "Union-Find cycle detection:\n";
    vector<pair<int,int>> edges = {{0,1},{1,2},{2,3},{3,0}};
    cout << "Has cycle: "
         << (hasCycleUnionFind(4, edges) ? "YES" : "NO")
         << "\n"; // YES

    return 0;
}
