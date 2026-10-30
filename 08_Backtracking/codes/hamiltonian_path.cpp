// ============================================================
// FILE: hamiltonian_path.cpp
// TOPIC: Hamiltonian Path and Cycle
// TIME:  O(V!)   SPACE: O(V)
// Compile: g++ -std=c++17 -o hamiltonian hamiltonian_path.cpp
// ============================================================
#include <iostream>
#include <vector>
using namespace std;

// Check if vertex v can be added at position pos
bool isSafe(vector<vector<int>>& adj, vector<int>& path,
            int v, int pos) {
    // Check if v is adjacent to previous vertex
    if (adj[path[pos-1]][v] == 0) return false;

    // Check if v already in path
    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;

    return true;
}

// Hamiltonian PATH
bool hamiltonianPath(vector<vector<int>>& adj,
                      vector<int>& path,
                      int pos, int V) {
    if (pos == V) return true; // All vertices visited

    for (int v = 1; v < V; v++) {
        if (isSafe(adj, path, v, pos)) {
            path[pos] = v;                          // CHOOSE
            if (hamiltonianPath(adj, path,
                                 pos+1, V))// EXPLORE
                return true;
            path[pos] = -1;                         // UNCHOOSE
        }
    }
    return false;
}

// Hamiltonian CYCLE
bool hamiltonianCycle(vector<vector<int>>& adj,
                       vector<int>& path,
                       int pos, int V) {
    if (pos == V) {
        // Check if last vertex connects back to first
        return adj[path[pos-1]][path[0]] == 1;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(adj, path, v, pos)) {
            path[pos] = v;                           // CHOOSE
            if (hamiltonianCycle(adj, path,
                                  pos+1, V)) // EXPLORE
                return true;
            path[pos] = -1;                          // UNCHOOSE
        }
    }
    return false;
}

void printPath(vector<int>& path, bool isCycle) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i < path.size()-1) cout << " → ";
    }
    if (isCycle) cout << " → " << path[0];
    cout << "\n";
}

int main() {
    cout << "=== HAMILTONIAN PATH AND CYCLE ===\n\n";

    int V = 5;
    // Adjacency matrix
    vector<vector<int>> adj = {
        {0,1,0,1,0},
        {1,0,1,1,1},
        {0,1,0,0,1},
        {1,1,0,0,1},
        {0,1,1,1,0}
    };

    // Hamiltonian Path
    vector<int> path(V, -1);
    path[0] = 0; // Start from vertex 0

    cout << "Hamiltonian PATH:\n";
    if (hamiltonianPath(adj, path, 1, V)) {
        printPath(path, false);
    } else {
        cout << "No Hamiltonian Path exists!\n";
    }

    // Hamiltonian Cycle
    fill(path.begin(), path.end(), -1);
    path[0] = 0;

    cout << "\nHamiltonian CYCLE:\n";
    if (hamiltonianCycle(adj, path, 1, V)) {
        printPath(path, true);
    } else {
        cout << "No Hamiltonian Cycle exists!\n";
    }

