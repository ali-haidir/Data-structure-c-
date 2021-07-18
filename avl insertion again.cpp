#include<iostream>

using namespace std;


struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

class node{
	public:
		int data;
		node *left;
		node *right;
		
		node(int val){
			data=val;
			left=NULL;
			right=NULL;
		} 
		
};


class AVL{
	public:
		node *root=NULL;
		
		
		int height(node *temp);
		int balance_factor(node *temp);
		
		node* rotate_left(node *current);
		node* rotate_right(node *current);
		
		void inorder(node *temp);
		
		void insertt(node **temp, int val);
		
		
		void printTree(node *root, Trunk *prev, bool isRight){
    if (root == NULL)
        return;
    
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->data << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

		
};

int AVL::height(node *temp){
	if(temp == NULL){
		return 0;
	}
	
	int left=height(temp->left);
	int right=height(temp->right);
	
	if(left > right ){
		return left +1;
	}
	else{
		return right +1;
	}
}

int AVL::balance_factor(node *temp){
		int left=height(temp->left);
			int right=height(temp->right);
			
			int val = left - right;
			return val; 
} 

void AVL::inorder(node *temp){
	if(temp == NULL){
		return ;
	}
	inorder(temp->left);
	cout<<temp->data<<" , ";
	inorder(temp->right);
}

void AVL::insertt(node **temp, int val){
	node *gar= new node(val);
	
	if(*temp == NULL){
		*temp=gar;
		return;
		
	}
	if((*temp)->data== val){
		cout<<"duplicate decteded \n";
		return;
	}
	
	else if( val < (*temp)->data){
		insertt(&(*temp)->left, val);
	}
	
	else if(val > (*temp)->data){
		insertt(&(*temp)->right, val);
	}
	else{
		return;
	}
	
	int diff= balance_factor(*temp);
	
		if(diff > 1 && val < (*temp)->left->data){		// LEFT LEFT CASE			Single *tempotation
		cout<<"*tempight ROTATE"<<endl;
		rotate_right(*temp);
		return ;
	}
	
	if(diff < -1 && val > (*temp)->right->data){	// RIGHT RIGHT CASE			Single Rotation
		cout<<"Left ROTATE"<<endl;
		rotate_left(*temp);
		return ;
	}
	
	if(diff > 1 && val > (*temp)->left->data){		// LEFT RIGHT CASE			Double Rotation
		(*temp)->left = rotate_left((*temp)->left);
		rotate_right(*temp);
		return ;
	}
	
	if(diff < -1 && val < (*temp)->right->data){	// RIGHT LEFT CASE			Double Rotation
		(*temp)->right = rotate_right((*temp)->right);
		rotate_left((*temp));
		return ;
	}
}

node* AVL:: rotate_right(node *current){
	node *child=current->left;
	node *sub_tree=child->right;
	child->right=current;
	current->left=sub_tree;
	
	return child;
}

node* AVL::rotate_left(node *current){
	node *child=current->right;
	node *sub_tree=child->left;
	child->left=current;
	current->right=sub_tree;
	
	return child;
}





int main(){
	AVL a;
	a.insertt(&a.root, 30);
	a.insertt(&a.root,20);
	a.insertt(&a.root,10);
	
	a.printTree(a.root,NULL,false);
	
	cout<<"------------------------------- \n";
	
	a.rotate_right(a.root);
	a.printTree(a.root,NULL,false);
	
	
	cout<<a.root->data<<endl;

}









