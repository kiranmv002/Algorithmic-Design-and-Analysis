// ============================================================
// FILE: fractional_knapsack.cpp
// TOPIC: Fractional Knapsack Problem
// TIME:  O(n log n) for sorting
// SPACE: O(1)
// GREEDY CHOICE: Pick item with highest value/weight ratio first
// NOTE:  This greedy does NOT work for 0/1 Knapsack!
// ============================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
    double ratio;
};

double fractionalKnapsack(vector<Item>& items, int W) {
    // Sort by value/weight ratio descending
    sort(items.begin(), items.end(), [](Item a, Item b){
        return a.ratio > b.ratio;
    });

    double totalValue = 0.0;
    int remaining = W;

    for (auto& item : items) {
        if (remaining <= 0) break;
        if (item.weight <= remaining) {
            // Take full item
            totalValue += item.value;
            remaining -= item.weight;
            cout << "Take full item  → weight: " << item.weight
                 << " value: " << item.value << "\n";
        } else {
            // Take fraction of item
            double fraction = (double)remaining / item.weight;
            totalValue += item.value * fraction;
            cout << "Take " << fraction * 100 << "% of item"
                 << " → weight: " << item.weight
                 << " value: " << item.value << "\n";
            remaining = 0;
        }
    }
    return totalValue;
}
