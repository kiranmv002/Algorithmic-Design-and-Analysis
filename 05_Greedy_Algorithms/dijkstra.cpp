// ============================================================
// FILE: dijkstra.cpp
// TOPIC: Dijkstra's Shortest Path Algorithm
// TIME:  O((V + E) log V) with min heap
// SPACE: O(V)
// GREEDY CHOICE: Always visit unvisited vertex with min distance
// LIMITATION: Does NOT work with negative weight edges
// ============================================================
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> pii;

void dijkstra(vector<vector<pii>>& adj, int src, int V) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min heap

    dist[src] = 0;
    pq.push({0, src}); // {distance, vertex}

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // Outdated entry skip

        for (auto [weight, v] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << src << " → " << i << " = ";
        if (dist[i] == INT_MAX) cout << "INF";
        else cout << dist[i];
        cout << "\n";
    }
}
