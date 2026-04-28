# Longest Common Subsequence (LCS)

## Problem Statement
Given two strings s1 and s2.
Find length of longest subsequence common to both.

Subsequence: characters in order but NOT necessarily
contiguous. Can skip characters.

## Example
s1 = "ABCBDAB"
s2 = "BDCAB"

LCS = "BCAB" or "BDAB" → length 4 ✅

## DP Approach

### Step 1: Define Subproblem
dp[i][j] = length of LCS of s1[0..i-1] and s2[0..j-1]

### Step 2: Recurrence Relation

If s1[i-1] == s2[j-1]:    ← characters MATCH
    dp[i][j] = dp[i-1][j-1] + 1

If s1[i-1] != s2[j-1]:    ← characters DON'T match
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    (skip one character from either string)

### Step 3: Base Cases
dp[i][0] = 0 for all i (empty s2)
dp[0][j] = 0 for all j (empty s1)
