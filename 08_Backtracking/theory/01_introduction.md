# Backtracking — Introduction

## What is Backtracking?
Backtracking is a systematic way of trying out
different possibilities to find a solution.

It builds the solution INCREMENTALLY.
If at any point the partial solution CANNOT
lead to a valid complete solution → BACKTRACK!
(Undo last step and try another option)

## Real Life Analogy
Solving a maze:
→ Try going RIGHT
→ Hit dead end → BACKTRACK
→ Try going DOWN
→ Hit dead end → BACKTRACK
→ Try going LEFT → reaches exit ✅

## Template / Pattern
void backtrack(state):
if isGoal(state):
record solution
return
for each choice in choices(state):
    if isValid(choice, state):
        make choice         ← CHOOSE
        backtrack(state)    ← EXPLORE
        undo choice         ← UNCHOOSE (backtrack)

## Three Key Steps
1. CHOOSE   → Make a decision
2. EXPLORE  → Recurse deeper
3. UNCHOOSE → Undo decision (backtrack)

## Pruning
Key optimization in backtracking.
If current partial solution CANNOT lead to
a valid solution → prune that branch entirely.
Avoids exploring unnecessary paths.

## Backtracking vs Brute Force
| Feature | Brute Force | Backtracking |
|---------|------------|--------------|
| Tries all | YES | NO (prunes invalid) |
| Speed | Slow | Faster |
| Space | Same | Same |
| Smartness | None | Prunes early |

## When to Use Backtracking?
→ Constraint satisfaction problems
→ Finding ALL solutions
→ Finding ONE valid arrangement
→ When problem has multiple choices at each step

## Common Backtracking Problems
| Problem | Goal |
|---------|------|
| N-Queens | Place N queens safely |
| Rat in Maze | Find path from start to end |
| Subset Sum | Find subset adding to target |
| Graph Coloring | Color graph with K colors |
| Sudoku | Fill 9×9 grid |
| Hamiltonian Path | Visit all vertices once |

## Time Complexity
Backtracking is exponential in WORST case.
Pruning reduces average case significantly.
O(b^d) where b = branching factor, d = depth
