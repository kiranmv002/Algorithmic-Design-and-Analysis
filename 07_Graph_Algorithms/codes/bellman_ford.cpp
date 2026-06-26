// ============================================================
// FILE: bellman_ford.cpp
// TOPIC: Bellman-Ford (Graph Algorithms version)
// TIME:  O(V×E)   SPACE: O(V)
// Compile: g++ -std=c++17 -o bellman bellman_ford.cpp
// ============================================================
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge { int u, v, weight; };

bool bellmanFord(int V, vector<Edge>& edges, int src,
                  vector<int>& dist) {
    dist.assign(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto& e : edges) {
            if (dist[e.u] != INT_MAX &&
                dist[e.u] + e.weight < dist[e.v])
                dist[e.v] = dist[e.u] + e.weight;
        }
    }

    // Check for negative cycle (V-th relaxation)
    for (auto& e : edges) {
        if (dist[e.u] != INT_MAX &&
            dist[e.u] + e.weight < dist[e.v])
            return false; // Negative cycle exists
    }
    return true;
}

int main() {
    cout << "=== BELLMAN-FORD (GRAPH VERSION) ===\n\n";

    int V = 5;
    vector<Edge> edges = {
        {0,1,6}, {0,2,7}, {1,2,8}, {1,3,-4},
        {1,4,5}, {2,3,9}, {2,4,-3}, {3,0,2}, {4,3,7}
    };

    vector<int> dist;
    bool noNegCycle = bellmanFord(V, edges, 0, dist);

    if (noNegCycle) {
        cout << "Shortest distances from vertex 0:\n";
        for (int i = 0; i < V; i++)
            cout << "0 → " << i << " = " << dist[i] << "\n";
        // Expected: 0,6,7,2,4
    } else {
        cout << "Negative cycle detected!\n";
    }

    cout << "\n=== NEGATIVE CYCLE TEST ===\n";
    vector<Edge> edges2 = {{0,1,1}, {1,2,-3}, {2,0,1}};
    vector<int> dist2;
    bool result = bellmanFord(3, edges2, 0, dist2);
    cout << (result ? "No negative cycle" : "Negative cycle detected!") << "\n";

    return 0;
}
