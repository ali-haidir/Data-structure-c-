#include<iostream>

using namespace std;

/*heap 
   In a complete binary tree all nodes are to the left.
   formula for nodes is 2*h.(h is the height of tree)
   max nodes = 2*h+1  -1.
	its ordered so can be stored in an array.(starting from 1)
	to find left child 2i;   (I IS THE INDEX)
	to find right child 2i + 1;
	to find parent i/2.
	
	why not use this for evevry tree?
	memory wastage + fixed formula
	
	
	heap
	heap use is in piorty queses,
	tyoes:
		2, min and max.
		min= parent smallest.
		max = parent largest.
		
		*/
		
class heep{
	public:
		int *h;
		int max_size;
		int values_present;
		
		heep(int l){
			max_size=l;
			values_present=0;
			h=new int[max_size];
			
		}
		
	
	/*	void insert(int val){
			if(values_present == max_size){
				cout<<"heap is full \n";
				return;
			}
			else{
			
			values_present++;
			h[values_present]= val;
			return;
		}
		}
	*/	
void insert_min(int val){
			if(values_present == max_size){
			cout<<"heep is fulll \n";
			return;
		}
			else{
			
			int x;
			values_present++;
			h[values_present]= val;
			
			while(values_present > 1   ){
				if(h[values_present] < h[values_present/2]{
					x= h[values_present];
				h[values_present]= h[ values_present/2];
				h[ values_present/2]= x;		
			}
		}
}
};
	
			



