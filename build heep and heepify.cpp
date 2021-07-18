#include<iostream>
using namespace std;


class heep{
	public:
		int max_size;
		int nodes;
		int *h;
		
		heep(int *arr, int ms, int sz){
			max_size=ms;
			nodes=sz;
			h=arr;
		}
		
		
		
		void heepify(int x){
			int smallest=x;
			int left= 2*x;
			int right=2*x +1;
			
			if(left <= nodes && h[left] < h[smallest]){
				smallest=left;
			}
			
			if(right <=nodes && h[right]< h[smallest]){
			  smallest=	right;
			}
			
			if(smallest != x){
				swap(h[x] ,h[smallest]);
				heepify(smallest);
			}
			
		}
		
		void build_heep(){
			for(int i=nodes/2 ; i>=1 ; i--){
				heepify(i);
			}
		}
		
		void print(){
			for(int i=1 ; i<= nodes ; i++){
				cout<<h[i]<<" , ";
			}
			cout<<" "<<endl;
		}
		
		void decrease_key(int val , int info ){
			for(int i=1 ; i<= nodes; i++){
				if(h[i]== val){
					h[i]= info;
					break;	
				}	
			}
			build_heep();
		}
		
		void increase_key(int val , int info){
			for(int i=i ; i <= nodes ; i++  ){
				if(h[i]== val){
					h[i]=info;
					break;
				}
			}
			build_heep();
		}
		
	int  deletion(){
	if(nodes == 0){
		cout<<"heep is empty \n";
		return 0;
	}
	int x=h[1];
	int last= h[nodes];
	nodes--;
	int i,j ;
	for(i=1 , j=2 ; j<=nodes; i=j, j=j*2){
		if(j<nodes){
			if(h[j] > h[j+1]){
				j++;
			}
		}
			if(last <= h[j]){
				break;
			}
			h[i]=h[j];
	}
	h[i]= last;
	return x;
}
		void del(int val){
			decrease_key(val , 1);
			deletion();
			print();
		}
};

int main(){
	
	int arr[]={0,2,4,1,5,3,1 };
	int size= sizeof(arr)/sizeof(int);
	cout<<"yhis is the length :";
	cout<<size<<endl;
	heep h(arr , size, size-1);
	cout<<"before building \n";
	h.print();
	h.build_heep();
	cout<<"after building \n";
	h.print();
	h.decrease_key(26 , 2);
	
	h.print();
	
	cout<<"--------------------------------- \n";
	
	h.increase_key(5, 500);
	h.print();
	
	cout<<"===================================== \n";
	h.deletion();
	h.print();
	cout<<"--------------------------------- \n";
	h.del(500);
	
	
}


