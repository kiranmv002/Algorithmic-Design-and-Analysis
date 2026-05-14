// ============================================================
// FILE: coin_change.cpp
// TOPIC: Coin Change — Minimum Coins
// TIME:  O(amount × coins)   SPACE: O(amount)
// Compile: g++ -std=c++17 -o coin coin_change.cpp
// ============================================================
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, amount+1); // Init to impossible
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int c : coins) {
            if (c <= i)
                dp[i] = min(dp[i], dp[i-c] + 1);
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

// Print which coins are used
void printCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, amount+1);
    vector<int> used(amount+1, -1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int c : coins) {
            if (c <= i && dp[i-c]+1 < dp[i]) {
                dp[i] = dp[i-c] + 1;
                used[i] = c;
            }
        }
    }

    cout << "Coins used: ";
    int rem = amount;
    while (rem > 0) {
        cout << used[rem] << " ";
        rem -= used[rem];
    }
    cout << "\n";
}
