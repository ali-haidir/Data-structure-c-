#include<iostream>

using namespace std;


class node{
	public:
		int data;
		node *left;
		node *right;
		bool lchild;
		bool rchild;
		
		
		node(int val){
			data=val;
			left=NULL;
			right=NULL;
			lchild=false;
			rchild=false;
		}
};

class tree{
	public:
		node* root;
		node* dummy;
		
		tree(){
			root=NULL;
			dummy=NULL;
			dummy->left=root;
			dummy->right=dummy;
			
		}
		
		
		node* succerior(node *current){
			
			if(current->rchild == true){
				current=current->right;
				
				while(current->lchild == true){
					current=current->left;
				}
				return current;
			}
			
			if(current->rchild == false){
				return current->right;
			}
		}
		
		node* fast_inorder(node *p){
			while((p=succerior(p)) != dummy){
				cout<<p->data<<" , ";
			}
		}
			
		
			
		}
};


int main(){
	tree t;
	t->root= new node
}
