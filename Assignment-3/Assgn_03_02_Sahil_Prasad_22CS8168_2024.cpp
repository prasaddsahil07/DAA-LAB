/*
%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad  %
%  Roll: 22CS8168      %
%  Question: Greedy_02 %
%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <bits/stdc++.h>
using namespace std;

bool compareByEndAngle(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];  // Compare by endAngle
}

int main() {
    int n;
    cout << "Enter the number of pies: ";
    cin >> n;
    vector<vector<int>> pies(n, vector<int>(2)); 
    cout << "Enter the startAngle and endAngle of the pies:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Pie " << i + 1 << " startAngle and endAngle:\n";
        cin >> pies[i][0] >> pies[i][1];
    }
    // Sorting pies by endAngle
    sort(pies.begin(), pies.end(), compareByEndAngle);
    int maximumPies = 1;
    int prevEnd = pies[0][1];
    // Arrange pies in the order of sorted endAngle
    for (int i = 1; i < n; ++i) {
        int currStart = pies[i][0];
        if (currStart < prevEnd) {
            continue;
        }
        prevEnd = pies[i][1];
        maximumPies++;
    }
    // Output the maximum pies
    cout << "Maximum Pies: " << maximumPies << endl;
    return 0;
}
