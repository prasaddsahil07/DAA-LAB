/*

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad                        %
%  Roll: 22CS8168                            %
%  Question: Merge Sort (question no - 1)    %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

*/

#include<iostream>
using namespace std;

void printArr(int arr[], int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void merge(int arr[], int a, int b, int c) {
    int n1 = b-a+1;
    int n2 = c-b;

    int leftArr[n1], rightArr[n2];

    for(int i = 0; i < n1; i++)
        leftArr[i] = arr[a+i];
    for(int j = 0; j < n2; j++)
        rightArr[j] = arr[b+1+j];

    int i=0, j=0, k=a;
    while (i < n1 && j < n2) {
        if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        } 
        else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end){
    if (start >= end)
        return;
    int mid = start+(end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main(){
	int n;
	cout<<"Enter the number of elements: "<<endl;
	cin>>n;
	cout<<"Enter the elements into the array to sort: "<<endl;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	mergeSort(arr, 0, n-1);
	cout<<endl;
	printArr(arr,n);
	return 0;
}
