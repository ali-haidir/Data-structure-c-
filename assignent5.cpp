#include<iostream>

using namespace std;


class node{
	public:
		int info;
		node *left;
		node *right;
		
		
	node(int value){
		info = value;
		left=NULL;
		right=NULL;
	}
};


class bst{
	public:
	
	node *root = NULL;
	
	node* insert(int value);
	
	void preorder(node *root);
	
	
	
	node* get_root(){
		return root;
	}
};

node* bst::insert(int value){
	if(root ==NULL){
		root=new node(value);
		cout<<"value added "<<root->info<<endl;
		return root;
	}
	
	if(root->info== value){
		cout<<"this is already present thus a duplicate \n";
		return 0;
	}
	
	if(root->info > value){
		root->left=insert(value);
		return root->left;
	}
	
	if(value > root->info ){
		root->right=insert(value);
		cout<<"going right ";
		return root->right;
	}
	
	 
} 

void bst:: preorder(node *root){
	if(root == NULL){
		return;
	}
	
	cout<<root->info;
	preorder(root->left);
	preorder(root->right);
}


int main(){
	bst b;
	node *temp=b.get_root();
	b.insert(5);
	b.insert(6);
	b.preorder(temp);
}
