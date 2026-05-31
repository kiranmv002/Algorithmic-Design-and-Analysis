// ============================================================
// FILE: bfs.cpp
// TOPIC: Breadth First Search
// TIME:  O(V+E)   SPACE: O(V)
// Compile: g++ -std=c++17 -o bfs bfs.cpp
// ============================================================
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS traversal
void bfs(vector<vector<int>>& adj, int start, int V) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS from " << start << ": ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

