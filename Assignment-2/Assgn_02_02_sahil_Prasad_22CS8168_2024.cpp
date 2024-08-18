/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad                          %
%  Roll: 22CS8168                              %
%  Question: tabulation MCM (question no. - 02) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/

#include <bits/stdc++.h>
using namespace std;

// Dynamic Programming function to compute the minimum cost
int matrixChainDP(int dims[], int n) {
    int dp[n][n];

    for (int i = 0; i < n; i++){
        dp[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (int r = 0; r < n - l + 1; r++) {
            int s = r + l - 1;
            dp[r][s] = INT_MAX;
            for (int t = r; t < s; t++) {
                int cost = dp[r][t] + dp[t + 1][s] + dims[r] * dims[t + 1] * dims[s + 1];
                dp[r][s] = min(dp[r][s], cost);
            }
        }
    }
    return dp[0][n - 1];
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
    //Tabulation DP: T.C->O(n^3) and S.C->O(n^2)
    clock_t start = clock();
    int minCost = matrixChainDP(dims, n);
    clock_t end = clock();
    
    cout << "Minimum cost (DP): " << minCost << endl;
    cout << "Time spent (DP): " << (end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    
    return 0;
}
