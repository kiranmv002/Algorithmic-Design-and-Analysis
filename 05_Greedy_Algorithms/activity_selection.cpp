// ============================================================
// FILE: activity_selection.cpp
// TOPIC: Activity Selection Problem
// TIME:  O(n log n) for sorting + O(n) selection = O(n log n)
// SPACE: O(1)
// GREEDY CHOICE: Always pick activity with earliest finish time
// ============================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish, index;
};

void activitySelection(vector<Activity>& acts) {
    // Sort by finish time
    sort(acts.begin(), acts.end(), [](Activity a, Activity b){
        return a.finish < b.finish;
    });

    cout << "Selected Activities:\n";
    int lastFinish = -1;
    int count = 0;

    for (auto& a : acts) {
        if (a.start >= lastFinish) {
            cout << "Activity " << a.index
                 << " [" << a.start << " - " << a.finish << "]\n";
            lastFinish = a.finish;
            count++;
        }
    }
    cout << "Total activities selected: " << count << "\n";
}

int main() {
    vector<Activity> acts = {
        {1, 3, 1}, {2, 5, 2}, {4, 6, 3},
        {6, 7, 4}, {5, 8, 5}, {8, 9, 6}
    };
    activitySelection(acts);
    // Expected: Activities 1, 3, 4, 6 → 4 activities
    return 0;
}
