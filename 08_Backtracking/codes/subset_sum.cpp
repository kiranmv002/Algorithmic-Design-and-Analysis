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
