// ============================================================
// FILE: job_sequencing.cpp
// TOPIC: Job Sequencing with Deadlines
// TIME:  O(n log n) sorting + O(n²) scheduling = O(n²)
// SPACE: O(n)
// GREEDY CHOICE: Pick highest profit job that fits before deadline
// ============================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

void jobSequencing(vector<Job>& jobs) {
    // Sort by profit descending
    sort(jobs.begin(), jobs.end(), [](Job a, Job b){
        return a.profit > b.profit;
    });

    int maxDeadline = 0;
    for (auto& j : jobs)
        maxDeadline = max(maxDeadline, j.deadline);

    vector<char> slots(maxDeadline + 1, '-');
    vector<bool> filled(maxDeadline + 1, false);
    int totalProfit = 0;

    for (auto& job : jobs) {
        // Find latest available slot before deadline
        for (int t = job.deadline; t >= 1; t--) {
            if (!filled[t]) {
                slots[t] = job.id;
                filled[t] = true;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "Job Sequence: ";
    for (int i = 1; i <= maxDeadline; i++)
        if (filled[i]) cout << slots[i] << " ";
    cout << "\nTotal Profit: " << totalProfit << "\n";
}

int main() {
    vector<Job> jobs = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };
    jobSequencing(jobs);
    // Expected: a c e → Profit: 142
    return 0;
}
