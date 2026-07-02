// ============================================================
// FILE: kruskal.cpp
// TOPIC: Kruskal's MST (Graph Algorithms version)
// TIME:  O(E log E)   SPACE: O(V)
// Compile: g++ -std=c++17 -o kruskal kruskal.cpp
// ============================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Edge { int u, v, weight; };

int find(vector<int>& parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]); // Path compression
    return parent[x];
}

bool unite(vector<int>& parent, vector<int>& rank, int x, int y) {
    int px = find(parent, x), py = find(parent, y);
    if (px == py) return false; // Cycle detected
    if (rank[px] < rank[py]) swap(px, py);
    parent[py] = px;
    if (rank[px] == rank[py]) rank[px]++;
    return true;
}

int kruskalMST(int V, vector<Edge>& edges,
               vector<Edge>& mstEdges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.weight < b.weight;
    });

    vector<int> parent(V), rank(V, 0);
    iota(parent.begin(), parent.end(), 0);

    int totalWeight = 0, count = 0;
    for (auto& e : edges) {
        if (unite(parent, rank, e.u, e.v)) {
            mstEdges.push_back(e);
            totalWeight += e.weight;
            count++;
            if (count == V - 1) break;
        }
    }
    return totalWeight;
