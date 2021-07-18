#include<iostream>

using namespace std;

class node{
	public:
	int data;
	node *left;
	node *right;
	
	node(int val){
		data =val;
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
		cout<<root->data<<" , ";
		print(root->left);
		print(root->right);
	}
	void insert(node **root, int val){
		node *temp=new node(val);
		
		if(*root == NULL){
			*root=temp;
			
		}
		
		if(val < (*root)->data){
			insert(&(*root)->left, val);
		}
		
		if(val > (*root)->data){
			insert(&(*root)->right, val);
		}
	}
	
	void deletion(node **root , int val){
		if(*root == NULL){
		
			return;
		}
		
		if(  val < (*root)->data  ){
			deletion(&(*root)->left, val);
		}
		
		if(  val > (*root)->data  ){
			deletion(&(*root)->right, val);
		}
		
		if((*root)->data == val){
			if((*root)->left == NULL){
				node *temp= *root;
				*root=(*root)->right;
				delete temp;
			}
			if((*root)->right == NULL){
				node *temp= *root;
				*root=(*root)->left;
				delete temp;
			}
			
			else{
				node *temp= min((*root)->right);
				(*root)->data=temp->data;
				deletion(&(*root)->right, temp->data);
				
			}
			
		}
		
		
	}
	
	node* min(node *root){
		
		while(root->left != NULL){
			root= root->left;
		}
		
		return root;
	}
};


int main(){
	tree t;
	t.insert(&t.root, 8);
	t.insert(&t.root, 10);
	t.insert(&t.root, 12);
	t.insert(&t.root, 14);
	t.insert(&t.root, 16);
	t.insert(&t.root, 18);
	t.insert(&t.root, 20);
	t.insert(&t.root, 22);
	t.insert(&t.root, 24);
	t.print(t.root);
	cout<<"--------------------------------\n";
	
	t.deletion(&t.root, 24);
	t.print(t.root);
	
}
