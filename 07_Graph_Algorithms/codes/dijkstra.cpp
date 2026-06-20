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
