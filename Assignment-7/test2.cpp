#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool is_possible(int n, const vector<ll>& a, ll k) {
    int i = 0;
    while (i < n) {
        if (i + 1 < n && abs(a[i + 1] - a[i]) <= k) {
            i += 2; // Move to the next index directly
        } else if (i + 1 < n && abs(a[i + 1] - a[i]) > k) {
            // If the gap is greater than k, check if we can consider an imaginary element
            if (k >= 1) {
                i += 1; // Jump to the next index
            } else {
                return false; // Cannot proceed further
            }
        } else {
            return false; // If we reach here, we cannot proceed
        }
    }
    return true; // Successfully reached the end
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        ll left = 0, right = 1e18;
        ll answer = right;

        while (left <= right) {
            ll mid = left + (right - left) / 2;
            if (is_possible(n, a, mid)) {
                answer = mid; // Found a valid k
                right = mid - 1; // Try for a smaller k
            } else {
                left = mid + 1; // Increase k
            }
        }

        cout << answer << "\n"; // Output the result
    }

    return 0;
}
