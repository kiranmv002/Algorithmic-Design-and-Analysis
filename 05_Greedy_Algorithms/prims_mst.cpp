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
