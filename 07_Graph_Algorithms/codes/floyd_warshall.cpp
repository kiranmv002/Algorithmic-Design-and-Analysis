// ============================================================
// FILE: floyd_warshall.cpp
// TOPIC: Floyd-Warshall (Graph Algorithms version)
// TIME:  O(V³)   SPACE: O(V²)
// Compile: g++ -std=c++17 -o floyd floyd_warshall.cpp
// ============================================================
#include <iostream>
#include <vector>
#define INF 99999
using namespace std;

void floydWarshall(vector<vector<int>>& dist,
                    vector<vector<int>>& next, int V) {
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k]; // Path reconstruction
                }
}

void printPath(vector<vector<int>>& next, int u, int v) {
    if (next[u][v] == -1) { cout << "No path"; return; }
    cout << u;
    while (u != v) {
        u = next[u][v];
        cout << " → " << u;
    }
}

int main() {
    int V = 4;
    vector<vector<int>> dist = {
        {0,   3,   INF, 7  },
        {8,   0,   2,   INF},
        {5,   INF, 0,   1  },
        {2,   INF, INF, 0  }
    };
