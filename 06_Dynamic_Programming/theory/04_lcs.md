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

## Example Step by Step
s1 = "ABCB"  (length 4)
s2 = "BCB"   (length 3)

DP Table:
```
     ""  B   C   B
""    0   0   0   0
A     0   0   0   0
B     0   1   1   1
C     0   1   2   2
B     0   1   2   3
```
LCS length = dp[4][3] = 3 → "BCB" ✅

## LCS vs LIS vs Edit Distance

| Problem | Input | Output |
|---------|-------|--------|
| LCS | Two strings | Common subsequence |
| LIS | One array | Increasing subsequence |
| Edit Distance | Two strings | Min edits to convert |

## Applications
→ DNA sequence alignment (bioinformatics)
→ File diff tools (git diff)
→ Plagiarism detection
→ Version control systems

## Complexity
| | Time | Space |
|-|------|-------|
| Standard | O(m×n) | O(m×n) |
| Space optimized | O(m×n) | O(min(m,n)) |
