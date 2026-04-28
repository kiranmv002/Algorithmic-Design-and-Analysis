// ============================================================
// FILE: knapsack_01.cpp
// TOPIC: 0/1 Knapsack Problem
// TIME:  O(n × W)   SPACE: O(n × W)
// Compile: g++ -std=c++17 -o knapsack knapsack_01.cpp
// ============================================================
#include <iostream>
#include <vector>
using namespace std;

// Standard 2D DP
int knapsack(vector<int>& weights, vector<int>& values,
             int W, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Don't take item i
            dp[i][w] = dp[i-1][w];
            // Take item i (if it fits)
            if (weights[i-1] <= w)
                dp[i][w] = max(dp[i][w],
                    dp[i-1][w-weights[i-1]] + values[i-1]);
        }
    }
    return dp[n][W];
}

// Space optimized 1D DP
int knapsackOpt(vector<int>& weights, vector<int>& values,
                int W, int n) {
    vector<int> dp(W+1, 0);
    for (int i = 0; i < n; i++) {
        // Traverse right to left to avoid using item twice
        for (int w = W; w >= weights[i]; w--)
            dp[w] = max(dp[w], dp[w-weights[i]] + values[i]);
    }
    return dp[W];
}

// Print which items are selected
void printItems(vector<int>& weights, vector<int>& values,
                int W, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i-1][w];
            if (weights[i-1] <= w)
                dp[i][w] = max(dp[i][w],
                    dp[i-1][w-weights[i-1]] + values[i-1]);
        }

    cout << "Selected items: ";
    int w = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            cout << "Item" << i
                 << "(w=" << weights[i-1]
                 << ",v=" << values[i-1] << ") ";
            w -= weights[i-1];
        }
    }
    cout << "\n";
}

