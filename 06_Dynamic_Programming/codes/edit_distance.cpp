// ============================================================
// FILE: edit_distance.cpp
// TOPIC: Edit Distance (Levenshtein Distance)
// TIME:  O(m×n)   SPACE: O(m×n)
// Compile: g++ -std=c++17 -o edit edit_distance.cpp
// ============================================================
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int editDistance(const string& s1, const string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    // Base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1]; // No edit needed
            else
                dp[i][j] = 1 + min({
                    dp[i-1][j],   // Delete
                    dp[i][j-1],   // Insert
                    dp[i-1][j-1]  // Replace
                });
        }
    }
    return dp[m][n];
}

int main() {
    cout << "=== EDIT DISTANCE ===\n\n";

    cout << "SUNDAY → SATURDAY: "
         << editDistance("SUNDAY", "SATURDAY") << "\n"; // 3

    cout << "CAT → CUT: "
         << editDistance("CAT", "CUT") << "\n"; // 1

    cout << "kitten → sitting: "
         << editDistance("kitten", "sitting") << "\n"; // 3

    cout << "abc → abc: "
         << editDistance("abc", "abc") << "\n"; // 0

    cout << "abc → \"\": "
         << editDistance("abc", "") << "\n"; // 3
    return 0;
}
