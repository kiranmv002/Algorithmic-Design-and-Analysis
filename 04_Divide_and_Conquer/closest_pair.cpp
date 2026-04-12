// ============================================================
// FILE: closest_pair.cpp
// TOPIC: Closest Pair of Points - Divide & Conquer
// TIME:  O(n log n) vs naive O(n²)
// RECURRENCE: T(n) = 2T(n/2) + O(n) → O(n log n)
// ============================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

struct Point { double x, y; };

double dist(Point a, Point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double stripClosest(vector<Point>& strip, double d) {
    double minD = d;
    sort(strip.begin(), strip.end(), [](Point a, Point b){ return a.y < b.y; });
    for (int i = 0; i < strip.size(); i++)
        for (int j = i+1; j < strip.size() && (strip[j].y - strip[i].y) < minD; j++)
            minD = min(minD, dist(strip[i], strip[j]));
    return minD;
}

double closestPair(vector<Point>& pts, int l, int r) {
    if (r - l <= 2) {
        double minD = 1e18;
        for (int i = l; i <= r; i++)
            for (int j = i+1; j <= r; j++)
                minD = min(minD, dist(pts[i], pts[j]));
        return minD;
    }
    int m = (l + r) / 2;
    double midX = pts[m].x;
    double d = min(closestPair(pts, l, m), closestPair(pts, m+1, r));

    vector<Point> strip;
    for (int i = l; i <= r; i++)
        if (abs(pts[i].x - midX) < d)
            strip.push_back(pts[i]);

    return min(d, stripClosest(strip, d));
}
