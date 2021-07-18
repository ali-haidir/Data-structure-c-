#include<iostream>

using namespace std;

// very fast for large list + small

int binary_search(int arr[], int l , int r , int val ){
	if(l<=r){
		int mid = (l+r)/2;
	
		if(arr[mid]== val ){
			return mid;
		}
		
		if(arr[mid] < val){
			return binary_search(arr, mid+1 , r, val);
		}
		else if (arr[mid] > val){
			return binary_search(arr, l,mid-1, val);
		}
	}
	return -1;
}

int main(){
	int arr[5]={1,4,6,7,8};
	int b=binary_search(arr, 0 , 5, 8);
	cout<<b<<endl;
	for(int i=0 ; i< 5 ; i++){
		cout<<arr[i]<<" , ";
	}
	
}
