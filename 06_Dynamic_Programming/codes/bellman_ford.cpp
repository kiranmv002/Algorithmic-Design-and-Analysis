// ============================================================
// FILE: bellman_ford.cpp
// TOPIC: Bellman-Ford Shortest Path
// TIME:  O(V×E)   SPACE: O(V)
// Works with NEGATIVE edges
// Detects NEGATIVE CYCLES
// Compile: g++ -std=c++17 -o bellman bellman_ford.cpp
// ============================================================
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge { int u, v, weight; };

void bellmanFord(int V, vector<Edge>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V-1; i++) {
        for (auto& e : edges) {
            if (dist[e.u] != INT_MAX &&
                dist[e.u] + e.weight < dist[e.v])
                dist[e.v] = dist[e.u] + e.weight;
        }
    }

    // Check for negative cycle
    bool negCycle = false;
    for (auto& e : edges) {
        if (dist[e.u] != INT_MAX &&
            dist[e.u] + e.weight < dist[e.v]) {
            negCycle = true;
            break;
        }
    }

    if (negCycle) {
        cout << "Negative cycle detected!\n";
        return;
    }

    cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << src << " → " << i << " = ";
        if (dist[i] == INT_MAX) cout << "INF";
        else cout << dist[i];
        cout << "\n";
    }
}

int main() {
    cout << "=== BELLMAN-FORD ===\n\n";
    int V = 5;
    vector<Edge> edges = {
        {0,1,6}, {0,2,7}, {1,2,8}, {1,3,-4},
        {1,4,5}, {2,3,9}, {2,4,-3}, {3,0,2}, {4,3,7}
    };
    bellmanFord(V, edges, 0);
    // Expected: 0→0=0, 0→1=6, 0→2=7, 0→3=2, 0→4=4

    cout << "\n=== NEGATIVE CYCLE DETECTION ===\n";
    vector<Edge> edges2 = {
        {0,1,1}, {1,2,-3}, {2,0,1}
    };
    bellmanFord(3, edges2, 0);
    // Expected: Negative cycle detected!
    return 0;
}
