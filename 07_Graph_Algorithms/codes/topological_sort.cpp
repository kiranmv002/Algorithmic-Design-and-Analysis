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

// Method 2: Kahn's Algorithm (BFS)
void topoSortKahn(vector<vector<int>>& adj, int V) {
    vector<int> inDegree(V, 0);

    // Calculate in-degrees
    for (int u = 0; u < V; u++)
        for (int v : adj[u])
            inDegree[v]++;

    // Add all 0 in-degree vertices
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (inDegree[i] == 0)
            q.push(i);

    cout << "Topological Sort (Kahn's): ";
    int count = 0;
    vector<int> result;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        result.push_back(u);
        count++;

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0)
                q.push(v);
        }
    }

    if (count != V)
        cout << "CYCLE DETECTED! No topological order.\n";
    else {
        for (int x : result) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Directed edges
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    cout << "=== TOPOLOGICAL SORT ===\n";
    cout << "Graph: 5→0, 5→2, 4→0, 4→1, 2→3, 3→1\n\n";
    topoSortDFS(adj, V);
    topoSortKahn(adj, V);
    // Valid outputs: 5 4 2 3 1 0 or 4 5 2 3 0 1 etc.

    // Cycle detection test
    cout << "\n=== CYCLE DETECTION TEST ===\n";
    int V2 = 3;
    vector<vector<int>> adj2(V2);
    adj2[0].push_back(1);
    adj2[1].push_back(2);
    adj2[2].push_back(0); // Creates cycle!
    topoSortKahn(adj2, V2);

    return 0;
}
