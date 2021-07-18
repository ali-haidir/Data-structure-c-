#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node *previous;


	node(int value){
		data = value;
		previous = NULL;
	}
};

class stack{
	node *top, *temp;
	int count;

	public:
		stack(){
			top = NULL;
			count = 0;
		}

		void push(int value){
			node *temp;
			if(top == NULL){
				node *temp = new node(value);
				top = temp;
				temp = NULL;
				count++;
				return;
			}

			temp = new node(value);
			temp->previous = top;
			top = temp;
			temp = NULL;
			count++;
			return;
		}

		int pop(){
			if(top == NULL){
				cout<<"no value to pop \n";
				return 0;
			}

			node *temp;

			temp = top;
			cout<<"valueue to be poped: /n"<<temp->data;
			top = top->previous;
			delete temp;
			temp = NULL;
		}

		void print_stack(){
			node *temp = top;
			cout<<"[ ";
			while (temp != NULL){
				cout<<temp->data<<" ";
				temp = temp->previous;
			}
			cout<<"]"<<endl;
		}
};

int main(){
	stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.print_stack();
	s.pop();
	s.pop();
	s.pop();
	s.pop();

}
