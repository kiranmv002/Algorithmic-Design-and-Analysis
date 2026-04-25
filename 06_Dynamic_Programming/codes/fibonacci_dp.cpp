// ============================================================
// FILE: fibonacci_dp.cpp
// TOPIC: Fibonacci — Memoization, Tabulation, Space Optimized
// Compile: g++ -std=c++17 -o fib fibonacci_dp.cpp
// ============================================================
#include <iostream>
#include <vector>
using namespace std;

// Naive Recursion — O(2ⁿ) BAD!
long long fibNaive(int n) {
    if (n <= 1) return n;
    return fibNaive(n-1) + fibNaive(n-2);
}

// Memoization (Top-Down) — O(n) time, O(n) space
long long fibMemo(int n, vector<long long>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fibMemo(n-1, memo) + fibMemo(n-2, memo);
}

// Tabulation (Bottom-Up) — O(n) time, O(n) space
long long fibTab(int n) {
    if (n <= 1) return n;
    vector<long long> dp(n+1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

// Space Optimized — O(n) time, O(1) space
long long fibOpt(int n) {
    if (n <= 1) return n;
    long long prev2 = 0, prev1 = 1;
    for (int i = 2; i <= n; i++) {
        long long curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

