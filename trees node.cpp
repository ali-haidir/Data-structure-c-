#include<iostream>

using namespace std;

class node{
	public:
	node *left;
	node *right;
	char value;
	
	
	node(char val){
		value =val;
		left =NULL;
		right=NULL;
	}
};

class tree{
	public:
	node *root=NULL;
	
	void print(node *root){
		if (root == NULL){
			return;
		}
		
		print(root->left);
		cout<<root->value<<" , ";
		print(root->right);
	}
	 
	node* insert(node *root, char val){
		node *temp=new node(val);
		if(root == NULL){
			root = temp;
			return root;
		}
		
		if(val < root->value){
			root->left=insert(root->left, val);
			
		}
		if( val > root->value){
			root->right=insert(root->right, val);
			
			
		}
		
		return root;
	} 	
	
	node* get_root(){
		return root;
	}
};

int main(){
	tree t; 
	node *n=t.get_root();

	
	char list[26]={'b' , 'a' , 'c' , 'e' , 'd' , 'f' , 'h' , 'g' , 'i' , 'k' , 'j' , 'l' , 'n' , 'm' , 'o' , 'q' , 'p' , 'r' , 't' , 's' , 'u' , 'w' , 'v' , 'x' , 'z' , 'y' };
	for(int i=0 ; i<26 ;i++){
		n=t.insert(n, list[i]);
	}
	t.print(n);
}
