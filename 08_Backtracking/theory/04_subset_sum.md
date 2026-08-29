# Subset Sum Problem

## Problem Statement
Given array of N integers and target sum S.
Find if any subset of the array sums to S.
OR find all subsets that sum to S.

## Example
```
Array = {3, 34, 4, 12, 5, 2}
Target = 9
```
Subsets that sum to 9:
```
{3, 4, 2} → 3+4+2 = 9 ✅
{4, 5}    → 4+5 = 9 ✅
```
## Backtracking Approach
For each element → two choices:
1. INCLUDE the element
2. EXCLUDE the element

Build decision tree exploring both choices.
Prune when current sum > target.

## Decision Tree (simplified)
Array = {3, 4, 2}, Target = 5

                  {}(sum=0)
                /            \
          {3}(sum=3)      {}(sum=0)
          /      \          /     \
    {3,4}(7)  {3}(3)    {4}(4)   {}(0)
    PRUNE!   /    \      /  \     / \
          {3,2}  {3} {4,2} {4} {2} {}
           (5)✅  (3)  (6)  (4) (2) (0)

## Pruning Strategies
1. If sum > target → prune (no point going deeper)
2. If remaining elements cannot reach target → prune

