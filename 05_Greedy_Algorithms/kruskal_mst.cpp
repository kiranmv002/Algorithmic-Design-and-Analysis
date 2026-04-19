// ============================================================
// FILE: kruskal_mst.cpp
// TOPIC: Kruskal's Minimum Spanning Tree
// TIME:  O(E log E) for sorting edges
// SPACE: O(V)
// GREEDY CHOICE: Add minimum weight edge that doesn't form cycle
// USES:  Union-Find (Disjoint Set Union) data structure
// ============================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

// Union-Find with path compression + union by rank
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

void kruskalMST(int V, vector<Edge>& edges) {
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.weight < b.weight;
    });

    vector<int> parent(V), rank(V, 0);
    iota(parent.begin(), parent.end(), 0); // parent[i] = i

    cout << "MST Edges:\n";
    int totalWeight = 0, edgeCount = 0;

    for (auto& e : edges) {
        if (unite(parent, rank, e.u, e.v)) {
            cout << e.u << " - " << e.v
                 << "  weight: " << e.weight << "\n";
            totalWeight += e.weight;
            edgeCount++;
            if (edgeCount == V - 1) break;
        }
    }
    cout << "Total MST Weight: " << totalWeight << "\n";
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };
    kruskalMST(V, edges);
    // Expected: 2-3(4), 0-3(5), 0-1(10) → Total: 19
    return 0;
}
