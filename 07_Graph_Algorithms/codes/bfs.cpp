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

// BFS shortest path (unweighted)
vector<int> bfsShortestPath(vector<vector<int>>& adj,
                             int src, int V) {
    vector<int> dist(V, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

// BFS for all components (disconnected graph)
void bfsAllComponents(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    int components = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;
            cout << "Component " << components << ": ";
            queue<int> q;
            visited[i] = true;
            q.push(i);
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
    }
    cout << "Total components: " << components << "\n";
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    // Add undirected edges
    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1); addEdge(0, 2);
    addEdge(1, 3); addEdge(2, 4);
    addEdge(3, 5); addEdge(4, 5);

    cout << "=== BFS TRAVERSAL ===\n";
    bfs(adj, 0, V);

    cout << "\n=== SHORTEST DISTANCES FROM 0 ===\n";
    auto dist = bfsShortestPath(adj, 0, V);
    for (int i = 0; i < V; i++)
        cout << "0 → " << i << " = " << dist[i] << "\n";

    cout << "\n=== CONNECTED COMPONENTS ===\n";
    int V2 = 7;
    vector<vector<int>> adj2(V2);
    adj2[0].push_back(1); adj2[1].push_back(0);
    adj2[2].push_back(3); adj2[3].push_back(2);
    adj2[4].push_back(5); adj2[5].push_back(4);
    adj2[5].push_back(6); adj2[6].push_back(5);
    bfsAllComponents(adj2, V2);

    return 0;
}
