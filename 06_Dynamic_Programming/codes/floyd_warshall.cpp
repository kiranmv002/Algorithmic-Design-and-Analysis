// ============================================================
// FILE: floyd_warshall.cpp
// TOPIC: Floyd-Warshall All Pairs Shortest Path
// TIME:  O(V³)   SPACE: O(V²)
// Compile: g++ -std=c++17 -o floyd floyd_warshall.cpp
// ============================================================
#include <iostream>
#include <vector>
#define INF 99999
using namespace std;

void floydWarshall(vector<vector<int>>& dist, int V) {
    // Try each vertex as intermediate
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
            }
        }
    }
}

void printMatrix(vector<vector<int>>& dist, int V) {
    cout << "Shortest distances:\n";
    cout << "     ";
    for (int i = 0; i < V; i++) cout << i << "    ";
    cout << "\n";
    for (int i = 0; i < V; i++) {
        cout << i << " →  ";
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) cout << "INF  ";
            else cout << dist[i][j] << "    ";
        }
        cout << "\n";
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

    cout << "=== FLOYD-WARSHALL ===\n\n";
    floydWarshall(dist, V);
    printMatrix(dist, V);

    // Detect negative cycle
    bool negCycle = false;
    for (int i = 0; i < V; i++)
        if (dist[i][i] < 0) { negCycle = true; break; }
    cout << "\nNegative Cycle: "
         << (negCycle ? "YES" : "NO") << "\n";
    return 0;
}
