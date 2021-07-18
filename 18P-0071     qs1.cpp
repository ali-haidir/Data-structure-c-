#include<iostream>

using namespace std;

void jumble_up(char arr[]){
	int length= 26;
//	length= sizeof(arr) / sizeof(arr[0])
	cout<<"this is the length of english language alphabets  : "<<length<<endl;
	
	int a=0;
	int b=1;
	int c=0;
		
		for(int j= 0; j<length ; j++){
			swap(arr[a], arr[j]);
			a=b+4;
			j++;
			
		}
}

void print(char arr[]){
	
	for(int i=0; i<26 ; i++){
		cout<<arr[i]<<" , ";
	}
	
}

int main(){
	
	char array[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	cout<<"this is the array before unsorting : "<<array<<endl;
	
	cout<<" ========================     =========================     =========================      "<<endl;
	jumble_up(array);
	cout<<"this is the jumbled array ";
	print(array);
	
	return 0;
}


