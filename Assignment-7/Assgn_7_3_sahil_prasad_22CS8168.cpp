/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad             		 %
%  Roll: 22CS8168                 		 %
%  Question: convex hull problm  (q no: 1)%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/



#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

// Time Complexity: O(log(n)) on average for each comparison due to sort algorithm
bool compare(const Point &p1, const Point &p2) {
    return (p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y);
}

// Time Complexity: O(1)
int crossProduct(const Point &p1, const Point &p2, const Point &p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

// Time Complexity: O(n)
vector<Point> generateRandomPoints(int n) {
    vector<Point> points;
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        int x = rand() % 100 + 1;
        int y = rand() % 100 + 1;
        points.push_back({x, y});
    }
    return points;
}

// Convex Hull Construction Time Complexity: O(n)
vector<Point> computeConvexHull(vector<Point> &points) {
    if (points.size() <= 1) return points;
    sort(points.begin(), points.end(), compare);
    vector<Point> hull;

    // Time Complexity: O(n)
    for (const auto &p : points) {
        while (hull.size() >= 2 && crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], p) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    // Time Complexity: O(n)
    int lowerHullSize = hull.size();
    for (int i = points.size() - 2; i >= 0; --i) {
        while (hull.size() > lowerHullSize && crossProduct(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    hull.pop_back();
    return hull;
}

int main() {
    int n;
    cout << "Enter the number of random points to generate: ";
    cin >> n;
    vector<Point> points = generateRandomPoints(n);
    cout << "Generated points:" << endl;
    for (const auto &p : points) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }
    vector<Point> convexHull = computeConvexHull(points);
    cout << "\nConvex Hull points:" << endl;
    for (const auto &p : convexHull) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }
    return 0;
}
