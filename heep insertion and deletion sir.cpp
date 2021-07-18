#include<iostream>

using namespace std;


class heep{
	public:
	int max_size;
	int nodes;
	int *h;
	
	heep(int val){
		max_size= val;
		nodes=0;
		h= new int[max_size];
	}
	
	
	void print();
	void insert(int val);
	int deletion();
	
	
};

void heep::print(){
	for(int i=1; i<=nodes ; i++){
		cout<<h[i]<<" ; ";
	}
}


void heep::insert(int val){
	if(nodes == max_size){
		cout<<"heep is full \n";
		return;
	}
	
	nodes++;
	int i;
	for( i=nodes ; i> 1; i=i/2){
		if(val >= h[i/2])
			break;
		h[i]=h[i/2];
	}
		
	h[i]=val;
	cout<<"this is the value added : "<< h[i]<<endl;
	
}

int heep:: deletion(){
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

int main(){
	heep h(5);
	h.insert(5);
	h.insert(8);
	h.insert(2);
	h.insert(10);
	h.insert(7);
	h.insert(2);
	
	h.print();
	cout<<"------------------------ \n";
	
	h.deletion();
	h.deletion();
//	h.deletion();
	h.print();
}
