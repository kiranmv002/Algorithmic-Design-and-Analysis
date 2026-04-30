// ============================================================
// FILE: lcs.cpp
// TOPIC: Longest Common Subsequence
// TIME:  O(m×n)   SPACE: O(m×n)
// Compile: g++ -std=c++17 -o lcs lcs.cpp
// ============================================================
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LCS Length
int lcsLength(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

// Print actual LCS string
string printLCS(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    // Backtrack to find LCS string
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs = s1[i-1] + lcs;
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    return lcs;
}

int main() {
    string s1 = "ABCBDAB";
    string s2 = "BDCAB";

    cout << "=== LONGEST COMMON SUBSEQUENCE ===\n";
    cout << "s1: " << s1 << "\n";
    cout << "s2: " << s2 << "\n\n";
    cout << "LCS Length: " << lcsLength(s1, s2) << "\n"; // 4
    cout << "LCS String: " << printLCS(s1, s2) << "\n";  // BCAB or BDAB
    return 0;
}
