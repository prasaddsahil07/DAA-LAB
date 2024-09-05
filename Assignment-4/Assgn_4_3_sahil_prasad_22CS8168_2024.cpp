/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad             	 %
%  Roll: 22CS8168                 	 %
%  Question: kSizeSubstring(q no: 3) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/



#include<bits/stdc++.h>
using namespace std;

int kSizeSubString(string& s, int k) {
    int n = s.size();
    int maxLen = 0;
    for (int h = 1; h <= 26; h++) {
        vector<int> freq(26, 0);
        int i = 0, j = 0, unique = 0, countAtLeastK = 0;
        while (j < n) {
            if (unique <= h) {
                int index = s[j] - 'a';
                if (freq[index] == 0) unique++;
                freq[index]++;
                if (freq[index] == k) countAtLeastK++;
                j++;
            }
            while (unique > h) {
                int index = s[i] - 'a';
                if (freq[index] == k) countAtLeastK--;
                freq[index]--;
                if (freq[index] == 0) unique--;
                i++;
            }
            if (unique == h && unique == countAtLeastK) {
                maxLen = max(maxLen, j - i);
            }
        }
    }
    return maxLen;
}

int main(){
    string str;
    int k;
    cout << "Enter the string:" << endl;
    cin >> str;
    cout << "Enter the value of k:" << endl;
    cin >> k;
    cout << "The output is:" << endl;
    cout << kSizeSubString(str, k) << endl;
    return 0;
}

