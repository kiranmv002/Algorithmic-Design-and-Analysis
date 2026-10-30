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
