#include<iostream>

using namespace std;

class node_stack {
	public:
		int data;
		node_stack *pre;
		
		node_stack(int val){
			data= val;
			pre=NULL; 
		}
};

class stack{
	public:
		node_stack *head=NULL;
		int count ;
		
		
		
		node_stack* push(int val){
			node_stack *temp=new node_stack(val);
			
			if(head == NULL){
				head= temp;
				count +=1;
				return  head;
			}
			
			else{
				temp->pre=head;
				head=temp;
				count +=1;
				return head;
			}
			
		}
		
		node_stack* pop(){
			
			if(head == NULL){
				cout<<"no value to pop  \n";
				return NULL;
			}
			
			else{
				node_stack *temp=head;
				head=head->pre;
				count -=1;
				return temp;
			}
		}
		
		void print(){
			node_stack *temp=head;
			cout<<" [ ";
			while(temp != NULL){
				cout<<temp->data<<" , ";
				temp=temp->pre;
			}
			cout<<" ] \n";
		}
};

class node{
	public:
	int val;
	node *left;
	node *right;
	
	node(int val){
		this->val=val ;
		left=NULL;
		right=NULL;
	}
};

class tree{
	public:
		node *root=NULL;
		
		
		node* insert(int val){
			node *temp=new node(val);
			return temp;
		}
		
		void post_fix(string exp ){
			for(int i=0 ; i<exp.size(); i++){
				if(isdigit(exp[i])){
					root= insert(exp[i]);
					push(root)
				}
				else{
					node *temp1=pop();
					node *temp2=pop();
					root=insert()
					
				}
			}
		}
		
};

int main(){
	stack s;
	s.push(5);
	s.push(6);
	s.push(8);
	s.push(7);
	s.push(9);
	
	cout<<s.head->data<<endl;
	s.print();
	
	s.pop();
	s.pop();
	node_stack *temp= s.pop();
	cout<<temp->data;
	
	s.print();
	cout<<s.head->data<<endl;
	cout<<"------------------------------------ \n";
	
	
	
	
	
}
