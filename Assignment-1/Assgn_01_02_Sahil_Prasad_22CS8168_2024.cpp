/*

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad                        %
%  Roll: 22CS8168                            %
%  Question: Quick Sort (question no - 2)    %
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

int partition(int arr[], int start, int end){
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start+count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end){
	if(start>=end){
		return;
	}
	int part = partition(arr, start, end);
    quickSort(arr, start, part-1);
	quickSort(arr, part+1, end);
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
	cout<<endl;
	quickSort(arr, 0, n-1);
	cout<<endl;
	printArr(arr,n);
	return 0;
}
