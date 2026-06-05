// ============================================================
// FILE: topological_sort.cpp
// TOPIC: Topological Sort — DFS and Kahn's Algorithm
// TIME:  O(V+E)   SPACE: O(V)
// Only works on DAG (Directed Acyclic Graph)
// Compile: g++ -std=c++17 -o topo topological_sort.cpp
// ============================================================
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Method 1: DFS Based
void dfsTopoHelper(vector<vector<int>>& adj, int u,
                   vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfsTopoHelper(adj, v, visited, st);
    st.push(u); // Push after all neighbors done
}

void topoSortDFS(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfsTopoHelper(adj, i, visited, st);

    cout << "Topological Sort (DFS): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

