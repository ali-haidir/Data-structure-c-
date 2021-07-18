#include<iostream>

using namespace std;


class node{
	public:
	int info;
	node *left;
	node *right;
	
	node(int val){
		info=val;
		left=NULL;
		right=NULL;
		
	}
};

class tree{
	public:
	node *root=NULL;
	
		void insertt(node **head, int val ){
		node *temp=new node(val);
		
		if(*head == NULL){
			*head=temp;
			return;
		}
		if((*head)->info == val){
			cout<<"there is a duplicate, thus cannot insert \n";
			cout<<" the previous list is as follows \n";
			return; 
		}
		
		if(val < (*head)->info){
			insertt(&(*head)->left , val);
		}
		if(val > (*head)->info){
			insertt(&(*head)->right, val);
		}
	}	
		void insert(int val){
			insertt(&root, val);
		}
	
	
		void preorderr(node* poi){
		if(poi == NULL){
			return;
		}
		
		cout<<poi->info<<" , ";
		preorderr(poi->left);
		preorderr(poi->right);
	}
		void preorder(){
			preorderr(root);
		}
	
		int height(node *current){
		if(current== NULL){
			return 0;
		}
		else{
		
		int left= height(current->left);
		int right = height(current->right);
		
		if(left > right ){
			return left+1;
		}
		else{
			return right+1;
		}
	}
}
		node* min(node* root){
			while(root->left != NULL){
				root=root->left;
			}	
			cout<<root->info;
			return root;
	}
		
		void deletionn(node **cur, int val){
			
			if(*cur == NULL){
				return;
			}
			
			if(val < (*cur)->info){
				deletionn(&(*cur)->left, val);
			}
			
			if(val > (*cur)->info){
				deletionn(&(*cur)->right, val);
			}
			
			if(val == (*cur)->info){
				// case 1
//				if((*cur)->left == NULL && (*cur)->right == NULL ){
//					*cur = NULL;
//				}
				
				//case 2 
				if((*cur)->left == NULL){
					node *temp= *cur;
					*cur= (*cur)->right;
					delete temp;
				}
				else if((*cur)->right == NULL){
					node *temp=*cur;
					*cur= (*cur)->left;
					delete temp;
				}
				// case 3
				
				else{
					node *temp = min((*cur)->right);
					cout<<endl;
					(*cur)->info= temp->info;
					cout<<(*cur)->info<<endl;
					deletionn(&(*cur)->right, temp->info);
				}
				
			}
		}
		void deletion(int val){
			deletionn(&root, val);
		}
		
};

int main(){
	tree t;
	t.insert(51);
	t.insert(80);
	t.insert(20);
	t.insert(10);
	t.insert(30);
	t.insert(60);
	t.insert(100);
	t.insert(35);
	t.insert(34);
	
	t.preorder();
	cout<<endl;
	
	t.deletion(20);
	t.preorder();
	cout<<endl;
	
	t.deletion(34);
	t.preorder();
	cout<<endl;
	
	
}
