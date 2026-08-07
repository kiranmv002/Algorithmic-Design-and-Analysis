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

int main() {
    cout << "=== SUBSET SUM ===\n\n";

    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target1 = 9, target2 = 30;

    cout << "Array: 3 34 4 12 5 2\n\n";
    cout << "Target " << target1 << ": "
         << (subsetExists(arr, 0, 0, target1)
             ? "EXISTS" : "NOT FOUND") << "\n"; // EXISTS

    cout << "Target " << target2 << ": "
         << (subsetExists(arr, 0, 0, target2)
             ? "EXISTS" : "NOT FOUND") << "\n\n"; // NOT FOUND

    // Find all subsets summing to 9
    cout << "All subsets summing to " << target1 << ":\n";
    vector<int> chosen;
    vector<vector<int>> result;
    findAllSubsets(arr, 0, 0, target1, chosen, result);
    for (auto& s : result) {
        cout << "{ ";
        for (int x : s) cout << x << " ";
        cout << "}\n";
    }

    // Generate all subsets of {1,2,3}
    cout << "\nAll subsets of {1, 2, 3}:\n";
    vector<int> small = {1, 2, 3}, cur;
    generateAllSubsets(small, 0, cur);

    return 0;
}
