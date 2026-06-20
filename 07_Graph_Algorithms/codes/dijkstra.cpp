// ============================================================
// FILE: dijkstra.cpp
// TOPIC: Dijkstra's Shortest Path (Graph Algorithms version)
// TIME:  O((V+E) log V) with min heap
// SPACE: O(V)
// Compile: g++ -std=c++17 -o dijkstra dijkstra.cpp
// ============================================================
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> pii; // {weight, vertex}

vector<int> dijkstra(vector<vector<pii>>& adj, int src, int V) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // Outdated entry, skip

        for (auto [weight, v] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Print actual shortest path using parent array
vector<int> dijkstraWithPath(vector<vector<pii>>& adj, int src,
                              int V, vector<int>& parent) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    parent.assign(V, -1);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [weight, v] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

void printPath(vector<int>& parent, int dest) {
    if (parent[dest] == -1) {
        cout << dest;
        return;
    }
    printPath(parent, parent[dest]);
    cout << " → " << dest;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); // Undirected
    };

    addEdge(0, 1, 4);
    addEdge(0, 2, 1);
    addEdge(1, 2, 2);
    addEdge(1, 3, 5);
    addEdge(2, 3, 8);
    addEdge(2, 4, 2);
    addEdge(3, 4, 3);

    cout << "=== DIJKSTRA SHORTEST PATH ===\n";
    auto dist = dijkstra(adj, 0, V);
    for (int i = 0; i < V; i++)
        cout << "0 → " << i << " = " << dist[i] << "\n";
    // Expected: 0,3,1,6,3

    cout << "\n=== SHORTEST PATH RECONSTRUCTION ===\n";
    vector<int> parent;
    auto dist2 = dijkstraWithPath(adj, 0, V, parent);
    cout << "Path from 0 to 3: ";
    printPath(parent, 3);
    cout << " (distance: " << dist2[3] << ")\n";

    return 0;
}
