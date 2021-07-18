#include<iostream>
using namespace std;

void bubble_sort(int arr[] , int size ){
	for(int i =0 ; i< size-1; i++){
		for(int j = 1; j< size -i ; j++){
			if(arr[j-1] > arr[j ]){
				swap(arr[j-1], arr[j]);
			}
		}
	}
}


void print(int arr[]){
	for(int i=0 ; i< 4 ; i++){
		cout<<arr[i]<<" , ";
	}
}

int main(){
	int arr[4]={ 2, 88 , 6, 99};
	bubble_sort(arr, 4);  // increasing
	print(arr);
}
