# Subset Sum Problem

## Problem Statement
Given array of N integers and target sum S.
Find if any subset of the array sums to S.
OR find all subsets that sum to S.

## Example
Array = {3, 34, 4, 12, 5, 2}
Target = 9

Subsets that sum to 9:
{3, 4, 2} → 3+4+2 = 9 ✅
{4, 5}    → 4+5 = 9 ✅

## Backtracking Approach
For each element → two choices:
1. INCLUDE the element
2. EXCLUDE the element
