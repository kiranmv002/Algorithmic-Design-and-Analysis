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

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    // Add edges {weight, vertex}
    adj[0].push_back({4, 1}); adj[1].push_back({4, 0});
    adj[0].push_back({1, 2}); adj[2].push_back({1, 0});
    adj[1].push_back({2, 2}); adj[2].push_back({2, 1});
    adj[1].push_back({5, 3}); adj[3].push_back({5, 1});
    adj[2].push_back({8, 3}); adj[3].push_back({8, 2});
    adj[2].push_back({2, 4}); adj[4].push_back({2, 2});
    adj[3].push_back({3, 4}); adj[4].push_back({3, 3});

    dijkstra(adj, 0, V);
    // Expected: 0→0=0, 0→1=3, 0→2=1, 0→3=6, 0→4=3
    return 0;
}
