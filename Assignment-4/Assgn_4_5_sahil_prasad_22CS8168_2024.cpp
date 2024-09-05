/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad             %
%  Roll: 22CS8168                 %
%  Question: peakElement(q no: 5) %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/



#include<bits/stdc++.h>
using namespace std;

int peak(vector<int>& arr, int n){
	int peakEle = -1;
	if(arr[0] > arr[1])	return arr[0];
	if(arr[n-1]> arr[n-2])	return arr[n-1];
	for(int i=1; i<n-1; i++){
		if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
			peakEle = arr[i];
			break;
		}
	}
	return peakEle;
}

int main(){
	int n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	vector<int> arr(n);
	cout<<"Enter the elements in the array:"<<endl;
	for(int i=0; i<n; i++)	cin>>arr[i];
	cout<<"The output is:"<<endl;
	cout<<peak(arr, n)<<endl;
	return 0;
}
