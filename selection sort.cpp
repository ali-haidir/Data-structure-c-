#include<iostream>
using namespace std;


void selection_sort(int arr[], int size ){
	
	for(int i=0 ; i<  (size- 1); i++){
		int min=i;
		
		for(int j=i ; j< (size-1); j++){
			if(arr[min] < arr[j+1]){
				min = j+1;
			}
			
		}
		swap(arr[min], arr[i]);
	}
	
	
	for(int i=0; i<size ; i++){
	
	cout<<arr[i]<<endl	;
}
}






int main(){
	int arr[5]={1,9,5,99,4};
	selection_sort(arr, 5);
//	selection_sor_decending(arr , 5);
}
