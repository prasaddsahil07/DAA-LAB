/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad                          %
%  Roll: 22CS8168                              %
%  Question: Recursive MCM (question no. - 01) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive function to compute the minimum cost
int matrixChainRec(int dims[], int r, int s) {
    if (r == s){
        return 0;
    }
    int minCost = INT_MAX;
    for (int t = r; t < s; t++) {
        int cost = matrixChainRec(dims, r, t) + matrixChainRec(dims, t + 1, s) + dims[r - 1] * dims[t] * dims[s];
        minCost = min(minCost, cost);
    }
    return minCost;
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int dims[n + 1];
    cout << "Enter the dimensions of the matrices: ";
    for (int i = 0; i <= n; i++) {
        cin >> dims[i];
    }
    // Recursive Approach: T.C->Exponential and S.C->O(n^2)
    clock_t start = clock();
    int minCost = matrixChainRec(dims, 1, n);
    clock_t end = clock();
    
    cout << "Minimum cost (Recursive): " << minCost << endl;
    cout << "Time spent (Recursive): " << (end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    
    return 0;
}

