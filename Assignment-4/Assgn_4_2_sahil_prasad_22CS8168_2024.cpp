/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad             		     %
%  Roll: 22CS8168                 		     %
%  Question: inversionCountDistance(q no: 2) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/



#include <bits/stdc++.h>
using namespace std;


//O(n^2) solution brute force
int dist_n2(vector<int>& r) {
    int n = r.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (r[i] > 2 * r[j]) {
                count++;
            }
        }
    }
    return count;
}


// O(nlogn) solution optimal
int merge_count(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;    // Left subarray starting index
    int j = mid + 1; // Right subarray starting index
    int k = left;    // Index for sorted subarray
    int inv_count = 0;

    // Counting the valid pairs
    while (i <= mid && j <= right) {
        if (arr[i] <= 2 * arr[j]) {
            i++;
        } 
		else {
            inv_count += (mid - i + 1);
            j++;
        }
    }

    // Merging the arrays
    i = left;
    j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

int merge_sort_and_count(vector<int>& arr, vector<int>& temp, int left, int right) {
    int inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += merge_sort_and_count(arr, temp, left, mid);
        inv_count += merge_sort_and_count(arr, temp, mid + 1, right);
        inv_count += merge_count(arr, temp, left, mid, right);
    }
    return inv_count;
}

int dist_nlogn(vector<int>& r) {
    int n = r.size();
    vector<int> temp(n);
    return merge_sort_and_count(r, temp, 0, n - 1);
}


int main() {
    int n;
    cout << "Enter the number of movies: ";
    cin >> n;

    vector<int> r(n);
    cout << "Enter the rankings: ";
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }

    // O(n^2) solution
    int d_n2 = dist_n2(r);
    cout << "O(n^2) Distance: " << d_n2 << endl;

    // O(nlogn) solution
    int d_nlogn = dist_nlogn(r);
    cout << "O(nlogn) Distance: " << d_nlogn << endl;
    return 0;
}
