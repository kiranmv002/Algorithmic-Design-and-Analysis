// ============================================================
// FILE: subset_sum.cpp
// TOPIC: Subset Sum Problem
// TIME:  O(2^N)   SPACE: O(N)
// Compile: g++ -std=c++17 -o subset subset_sum.cpp
// ============================================================
#include <iostream>
#include <vector>
using namespace std;

// Check if any subset sums to target
bool subsetExists(vector<int>& arr, int idx,
                  int current, int target) {
    if (current == target) return true;
    if (idx == arr.size() || current > target) return false;

    // INCLUDE current element
    if (subsetExists(arr, idx+1,
                     current + arr[idx], target))
        return true;

    // EXCLUDE current element
    return subsetExists(arr, idx+1, current, target);
}

// Find ALL subsets that sum to target
void findAllSubsets(vector<int>& arr, int idx,
                    int current, int target,
                    vector<int>& chosen,
                    vector<vector<int>>& result) {
    if (current == target) {
        result.push_back(chosen);
        return;
    }
    if (idx == (int)arr.size() || current > target)
        return;

    // INCLUDE arr[idx]
    chosen.push_back(arr[idx]);              // CHOOSE
    findAllSubsets(arr, idx+1,
                   current + arr[idx],
                   target, chosen, result);  // EXPLORE
    chosen.pop_back();                       // UNCHOOSE

    // EXCLUDE arr[idx]
    findAllSubsets(arr, idx+1, current,
                   target, chosen, result);
}

// Generate ALL possible subsets (2^N)
void generateAllSubsets(vector<int>& arr, int idx,
                         vector<int>& current) {
    // Print current subset
    cout << "{ ";
    for (int x : current) cout << x << " ";
    cout << "}\n";

    for (int i = idx; i < (int)arr.size(); i++) {
        current.push_back(arr[i]);          // CHOOSE
        generateAllSubsets(arr, i+1, current); // EXPLORE
        current.pop_back();                 // UNCHOOSE
    }
}

