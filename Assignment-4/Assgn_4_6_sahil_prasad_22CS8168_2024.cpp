/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad             	 %
%  Roll: 22CS8168                 	 %
%  Question: beautifulArray(q no: 6) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/



#include <bits/stdc++.h>
using namespace std;

vector<int> beautifulArray(int N) {
    vector<int> result;
    if (N == 1) {
        result.push_back(1);
        return result;
    }

    // Recursively solve for smaller arrays
    vector<int> oddPart = beautifulArray((N + 1) / 2);  // Array for odd indices
    vector<int> evenPart = beautifulArray(N / 2);        // Array for even indices

    for (int x : oddPart) {
        result.push_back(2 * x - 1);  // Odd numbers
    }
    for (int x : evenPart) {
        result.push_back(2 * x);      // Even numbers
    }

    return result;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    vector<int> result = beautifulArray(N);
    cout << "Beautiful array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
