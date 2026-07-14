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

