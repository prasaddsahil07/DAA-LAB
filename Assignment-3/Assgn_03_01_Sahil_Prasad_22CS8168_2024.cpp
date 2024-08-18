/*
%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad  %
%  Roll: 22CS8168      %
%  Question: Greedy_01 %
%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <bits/stdc++.h>
using namespace std;

bool compareByDeadline(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];  // Compare by deadline
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    vector<vector<int>> jobs(n, vector<int>(2));
    cout << "Enter the lengths and deadlines of the jobs:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Job " << i + 1 << " length and deadline:\n";
        cin >> jobs[i][0] >> jobs[i][1]; 
    }
    // Sorting jobs by deadline
    sort(jobs.begin(), jobs.end(), compareByDeadline);
    int currentTime = 0;
    int maxLateness = 0;
    // Schedule jobs in the order of sorted deadlines
    for (int i = 0; i < n; ++i) {
        currentTime += jobs[i][0];
        int lateness = max(0, currentTime - jobs[i][1]);
        maxLateness = max(maxLateness, lateness);
    }
    // Output the maximum lateness
    cout << "Maximum Lateness: " << maxLateness << endl;
    return 0;
}
