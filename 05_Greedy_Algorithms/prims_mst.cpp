// ============================================================
// FILE: prims_mst.cpp
// TOPIC: Prim's Minimum Spanning Tree
// TIME:  O((V + E) log V) with min heap
// SPACE: O(V)
// GREEDY CHOICE: Always add minimum weight edge from MST to non-MST
// DIFFERENCE from Kruskal: Grows one tree vs sorting all edges
// ============================================================
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> pii;

void primsMST(vector<vector<pii>>& adj, int V) {
    vector<int> key(V, INT_MAX);   // Min weight to reach vertex
    vector<int> parent(V, -1);     // MST parent
    vector<bool> inMST(V, false);  // In MST or not

    priority_queue<pii, vector<pii>, greater<pii>> pq; // min heap

    key[0] = 0;
    pq.push({0, 0}); // {weight, vertex}

    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto [weight, v] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "MST Edges:\n";
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << "  weight: " << key[i] << "\n";
        totalWeight += key[i];
    }
    cout << "Total MST Weight: " << totalWeight << "\n";
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    // Add edges {weight, vertex}
    adj[0].push_back({2, 1}); adj[1].push_back({2, 0});
    adj[0].push_back({3, 3}); adj[3].push_back({3, 0});
    adj[1].push_back({1, 2}); adj[2].push_back({1, 1});
    adj[1].push_back({4, 3}); adj[3].push_back({4, 1});
    adj[2].push_back({5, 4}); adj[4].push_back({5, 2});
    adj[3].push_back({7, 4}); adj[4].push_back({7, 3});

    primsMST(adj, V);
    // Expected Total: 13
    return 0;
}
