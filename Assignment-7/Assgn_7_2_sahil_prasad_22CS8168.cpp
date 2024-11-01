/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad             		 %
%  Roll: 22CS8168                 		 %
%  Question: backtracking sweets (q no: 2)%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/




#include <bits/stdc++.h>
using namespace std;

void func_a(int i, int j, int n, int m, string &temp, set<string> &ans){
    if (i > n || j > m)
        return;
    if (i == n && j == m)
    {
        ans.insert(temp);
        return;
    }
    temp += "|S";
    func_a(i + 1, j + 1, n, m, temp, ans);
    temp.pop_back();
    temp.pop_back();
    temp += "S";
    func_a(i + 1, j, n, m, temp, ans);
    temp.pop_back();
}

void func_b(int i, int j, int &ctr, string s, int n, int m, set<string> &ans, int not_t){
    if (i == n && j == m){
        string temp = "";
        temp += s[s.size() - 2];
        temp += s[s.size() - 1];
        if (temp != "||"){
            ans.insert(s);
            ctr++;
        }
        return;
    }
    if (i < n){
        func_b(i + 1, j, ctr, s + "S", n, m, ans, 0);
    }
    if (j > 1){
        string temp = "";
        temp += s[s.size() - 2];
        temp += s[s.size() - 1];
        if (temp == "||"){
            not_t = 1;
        }
        else
            not_t = 0;
    }
    if (j < m && not_t < 1){
        if (!i){
            not_t = 1;
        }
        func_b(i, j + 1, ctr, s + "|", n, m, ans, not_t);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    string temp = "";
    temp += "S";
    set<string> ans;
    int i = 0, j = 0;
    func_a(i + 1, j, n, m - 1, temp, ans);
    i = 0, j = 0;
    cout << "A" << endl;
    for (auto a : ans)
    {
        cout << a << endl;
    }
    cout << "B :" << endl;
    set<string> ans2;
    string temp2 = "";
    int ctr = 0;
    int not_take = 0;
    func_b(i, j, ctr, temp2, n, m - 1, ans2, not_take);
    for (auto a : ans2)
    {
        cout << a << '\n';
    }
}