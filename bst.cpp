#include<iostream>
#include<cmath>
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
		int val;
		node *left;
		node *right;
		node *parent;
		
		node(int data){
			val = data;
			left = NULL;
			right = NULL;
			parent = NULL;
		}
	
};

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
    cout << root->val << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

class BST{
	int node_count;
	node *root;
	
	public:
		BST(){
			node_count = 0;
			root = NULL;
		}
		
		bool empty(){
			if(node_count==0){
				return true;
			}
			
			else
			{
				return false;
			}
		}
		
		node* parent(node* current, int num, node* par){
		    if(current == NULL)
		        return NULL;
		
		    if (current->val == num)
		    {
		        return par;
		    }
		    else
		    {
		        node *t = NULL;
		        t = parent(current->left, num, current);
		        if(t!= NULL)
		            return t;
		        else
		        {
		            t = parent(current->right, num, current);
		            return t;
		        }
		
		    }
		}

		int maxDepth(node* node){  
		    if (node == NULL)  
		        return -1;  
		    else
		    {  
		        
		        int lDepth = maxDepth(node->left);  
		        int rDepth = maxDepth(node->right);  
		      
		        
		        if (lDepth > rDepth)  
		            return(lDepth + 1);  
		        else return(rDepth + 1);  
		    }  
		}
						
		node *insert(node *r, int num){
			if(r==NULL){
			
				r = new node(num);
				node_count++;

				return r; 
			}
			
			if(node_count% 2 != 0){
				if(maxDepth(r)/2==1){
					r = r->right;
				}

				r->left= insert(r->left, num);
				r->left->parent = r;

				return r;
			}
			
			else{
				if(maxDepth(r)/2==1){
					r = r->left;

				}
				
				

				r->right= insert(r->right, num);
				r->right->parent = r;

				return r;
			}
			
		}
		
		
		
		node *get_root(){
			return root;
		}
		

		node *del(node *r){
			if(maxDepth(r->right) == maxDepth(r) - 1){
				if(r->right->right != NULL){
					
					node *temp = r->right->right;
					r->right->right = NULL;
					delete temp;
					return r;
				}
				
				else if(r->right->left != NULL){
					
					node *temp = r->right->left;
					r->right->left = NULL;
					delete temp;
					return r;
				}
				
			}
			
			else if(maxDepth(r->left) == maxDepth(r) - 1){
				if(r->left->right != NULL){
				
					node *temp = r->left->right;
					r->left->right = NULL;
					delete temp;
					return r;
				}
				
				else if(r->left->left != NULL){
				
					node *temp = r->left->left;
					delete temp;
					r->left->left = NULL;
					return r;
				}				
			}
		}
		
		void current_level(node* root, int l)  				 
		{  
		    if (root == NULL){
		    	return;
			}  
		          
		    if (l == 1){
		    	cout<<root->val<<" ";
			}  
		          
		    else
		    {  
		        current_level(root->left, l-1);  
		        current_level(root->right, l-1); 
		    }  
		}
		
		void levelorder(node *rootoot){
			int d = maxDepth(root);				
			
			for(int i=1;i<=d+1;i++){
				current_level(root, i);			 
			}
		}	

};


	
	
	


int main(){
	BST b;
	node *n = b.get_root();
	n = b.insert(n,1);
	b.insert(n,2);
	b.insert(n,3);
	b.insert(n,4);
	b.insert(n,5);
	b.insert(n,6);
	printTree(n, NULL, false);
	
	cout<<"[ ";
	b.levelorder(n);
	cout<<"]"<<endl;
	
		
	cout<<endl;
	cout<<endl;
	
	b.del(n);
	
	cout<<"[ ";
	b.levelorder(n);
	cout<<"]"<<endl;
	
		
	printTree(n, NULL, false);
	
	cout<<endl;
	cout<<endl;
	
	
	b.del(n);
	
	cout<<"[ ";
	b.levelorder(n);
	cout<<"]"<<endl;
		
	printTree(n, NULL, false);

	
}
