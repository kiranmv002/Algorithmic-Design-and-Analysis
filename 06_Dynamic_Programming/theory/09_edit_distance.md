# Edit Distance (Levenshtein Distance)

## Problem Statement
Given two strings s1 and s2.
Find MINIMUM number of operations to convert s1 to s2.

Allowed operations (each costs 1):
1. INSERT a character
2. DELETE a character
3. REPLACE a character

## Example
s1 = "SUNDAY"
s2 = "SATURDAY"

SUNDAY → SATURDAY
S_NDAY  (insert A)
SA_NDAY (insert T)
SATURDAY (replace N with R, U with U, D→D, A→A, Y→Y)

Minimum edit distance = 3 ✅

## DP Approach

### Step 1: Define Subproblem
dp[i][j] = minimum edits to convert
           s1[0..i-1] to s2[0..j-1]

### Step 2: Recurrence

If s1[i-1] == s2[j-1]:   ← characters match, no edit
    dp[i][j] = dp[i-1][j-1]

If s1[i-1] != s2[j-1]:   ← characters don't match
    dp[i][j] = 1 + min(
        dp[i-1][j],    ← DELETE from s1
        dp[i][j-1],    ← INSERT into s1
        dp[i-1][j-1]   ← REPLACE in s1
    )
