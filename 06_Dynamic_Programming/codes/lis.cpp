// ============================================================
// FILE: lis.cpp
// TOPIC: Longest Increasing Subsequence
// TIME:  O(n²) DP | O(n log n) Binary Search
// Compile: g++ -std=c++17 -o lis lis.cpp
// ============================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(n²) DP approach
int lisDP(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxLen = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

// O(n log n) Binary Search approach
int lisBinarySearch(vector<int>& arr) {
    vector<int> tails;
    for (int x : arr) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}

// Print actual LIS
void printLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1), parent(n, -1);
    int maxLen = 1, lastIdx = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j]+1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > maxLen) { maxLen = dp[i]; lastIdx = i; }
    }

    vector<int> lis;
    for (int i = lastIdx; i >= 0; i = parent[i]) {
        lis.push_back(arr[i]);
        if (parent[i] == -1) break;
    }
    reverse(lis.begin(), lis.end());
    cout << "LIS: ";
    for (int x : lis) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "=== LONGEST INCREASING SUBSEQUENCE ===\n";
    cout << "Array: 10 9 2 5 3 7 101 18\n\n";
    cout << "LIS Length (DP O(n²)):      " << lisDP(arr) << "\n";         // 4
    cout << "LIS Length (Binary Search): " << lisBinarySearch(arr) << "\n"; // 4
    printLIS(arr); // 2 3 7 101 or 2 5 7 101
    return 0;
}
