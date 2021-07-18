#include<iostream>

using namespace std;

class node{
	public:
	int data;
	node *next;
	
	node(int val){
		data=val;
		next=NULL;
	}
};

class queue{
	public:
	node *head=NULL;
	node *tail=NULL;
	int count;
	
	void enque(int val){
		node *temp=new node(val);
		
		if(head ==NULL or tail == NULL ){
			head=temp;
			tail =head;
			count +=1;
			return;
		}
		
		else{
			temp->next=head;
			head= temp;
			count+=1;
		}
	}
	
	void deque(){
		if(head == NULL or tail == NULL){
			cout<<"no value to delete , queue underflow \n";
			return;
		}
		
	
		else{
			node *temp= head ;
			while(temp->next != tail or temp->next == NULL ){
				temp =temp->next;
			}
			
			temp->next =NULL;
			delete tail;
			tail =temp;
		}
	}
	
	void print(){
		cout<<"[ ";
		node *temp=head;
		while(temp != NULL ){
			cout<<temp->data<<" , ";
			temp=temp->next;
		}
		cout<<" ]"<<endl;
	}
};

int main(){
	queue q;
	q.enque(4);
	q.enque(8);
	q.enque(10);
	q.enque(12);
	q.print();
	

	
	q.deque();
	

	q.print();
	
	cout<<q.head->data<<endl;
	cout<<q.tail->data<<endl;
}
