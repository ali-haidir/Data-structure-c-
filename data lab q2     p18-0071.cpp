#include<iostream>

using namespace std;

class node{
	public:
	char data;
	node *left;
	node *right;
	
	node(char character){
		data =character;
		left =NULL;
		right=NULL;
	}
};

class tree{
	public:
	node *root=NULL;
	
	void inorder_trivalsal(node *root){
		if (root == NULL){
			return;
		}
	
		inorder_trivalsal(root->left);
		cout<<root->data<<" , ";
		inorder_trivalsal(root->right);
	}
	
	void insertt(node **root, int character){
		node *temp=new node(character);
		
		if(*root == NULL){
			*root=temp;
			
		}
		
		if(character < (*root)->data){
			insertt(&(*root)->left, character);
		}
		
		if(character > (*root)->data){
			insertt(&(*root)->right, character);
		}
	}
	

	
	void insert(int val){
		
		insertt(&root, val);
	}
	
};


int main(){
	tree t;
	cout<<"this is the output of qs 1 : ";
	char array[26]={'a' , 'b' , 'f' , 'd' , 'c' , 'y' , 'e' , 'h' , 'g' , 'j' , 'i' , 'l' , 'k' , 'n' , 'm' , 'p' , 'o' , 'r' , 'q' , 't' , 's' , 'v' , 'u' , 'x' , 'w' , 'z' };
	cout<< array<<endl;
	for(int i=0 ; i< 26; i++){
		t.insert(array[i]);
	}
	cout<<"this is the alphabatical order :\n";
	t.inorder_trivalsal(t.root);
	
}
