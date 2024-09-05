/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad             		 %
%  Roll: 22CS8168                 		 %
%  Question: maximumSubArraySum(q no: 1) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/



#include<bits/stdc++.h>
using namespace std;

int kadane(vector<int>& arr, int n){
	int maxSum = INT_MIN;
	int currSum = 0;
	for(int i=0; i<n; i++){      
		currSum += arr[i];
		maxSum = max(maxSum, currSum);       
		currSum = max(currSum, 0);
	}
	return maxSum;
}

int main(){
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	vector<int> arr(n);
	cout<<"Enter the elements in the array:"<<endl;
	for(int i=0; i<n; i++)	cin>>arr[i];
	cout<<"The output is:"<<endl;
	cout<<kadane(arr, n)<<endl;
	return 0;
}
