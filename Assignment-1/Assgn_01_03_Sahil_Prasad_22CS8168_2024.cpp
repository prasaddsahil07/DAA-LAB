/*

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad                        %
%  Roll: 22CS8168                            %
%  Question: Insertion Sort (question no - 3)%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

*/


#include<iostream>
using namespace std;

void insertionSort(int arr[], int n){
    int i, element, j;
    for (i=1; i<n; i++) {
        element = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > element) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = element;
    }
    for(int i=0; i<n; i++){
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
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
	insertionSort(arr,n);
	return 0;
}
