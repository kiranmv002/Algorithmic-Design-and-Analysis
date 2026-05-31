// ============================================================
// FILE: dfs.cpp
// TOPIC: Depth First Search
// TIME:  O(V+E)   SPACE: O(V)
// Compile: g++ -std=c++17 -o dfs dfs.cpp
// ============================================================
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Recursive DFS
void dfsRec(vector<vector<int>>& adj, int u,
            vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u])
        if (!visited[v])
            dfsRec(adj, v, visited);
}

// Iterative DFS using stack
void dfsIter(vector<vector<int>>& adj, int start, int V) {
    vector<bool> visited(V, false);
    stack<int> st;
    st.push(start);

    cout << "DFS Iterative from " << start << ": ";
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (!visited[u]) {
            visited[u] = true;
            cout << u << " ";
            for (int v : adj[u])
                if (!visited[v])
                    st.push(v);
        }
    }
    cout << "\n";
}

// DFS with discovery and finish times
int timer = 0;
void dfsTime(vector<vector<int>>& adj, int u,
             vector<bool>& visited,
             vector<int>& disc, vector<int>& fin) {
    visited[u] = true;
    disc[u] = ++timer;
    for (int v : adj[u])
        if (!visited[v])
            dfsTime(adj, v, visited, disc, fin);
    fin[u] = ++timer;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1); addEdge(0, 2);
    addEdge(1, 3); addEdge(2, 4);
    addEdge(3, 5); addEdge(4, 5);

    cout << "=== DFS TRAVERSAL ===\n";
    vector<bool> visited(V, false);
    cout << "DFS Recursive from 0: ";
    dfsRec(adj, 0, visited);
    cout << "\n";

    dfsIter(adj, 0, V);

    cout << "\n=== DISCOVERY AND FINISH TIMES ===\n";
    vector<bool> vis2(V, false);
    vector<int> disc(V), fin(V);
    dfsTime(adj, 0, vis2, disc, fin);
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i
             << ": disc=" << disc[i]
             << " fin=" << fin[i] << "\n";

    return 0;
}
