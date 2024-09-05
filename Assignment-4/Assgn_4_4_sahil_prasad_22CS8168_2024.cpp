/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad             		 %
%  Roll: 22CS8168                 		 %
%  Question:longestCommonPrefix(q no: 4) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/



#include<bits/stdc++.h>
using namespace std;

string LCP(int n, vector<string>& strs){
    	sort(strs.begin(), strs.end());
    	string first = strs.front();
    	string last = strs.back();
    	int minLen = min(first.size(), last.size());
    	int i=0;
    	while(i < minLen && first[i] == last[i]){
        	i++;
    	}
    	if(i == 0) return "-1";
    	return first.substr(0, i);
}

int main(){
	int n;
	cout<<"Enter the size of the array:"<<endl;
	cin>>n;
	vector<string> arr(n);
	cout<<"Enter the array elements:"<<endl;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		arr[i] = s;
	}
	cout<<"The LCP is:"<<endl;
	cout<<LCP(n, arr)<<endl;
	return 0;
}
