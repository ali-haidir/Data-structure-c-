#include<iostream>
#include<string>

using namespace std;

class node{
public:

    int val;
    node *next;
    node *pre;
    node(int data){
    val=data;
    next=NULL;
    pre=NULL;
  }
};

class doublering{
public:

  node *head=NULL;

  void insert(int data, int pos){
    node *new_node= new node(data);

    node *current=head->next;
    node *last=head;
    int count=1;

    if(pos == 1){
    if(head == NULL){
      head=new_node;
      new_node->pre=NULL;
      new_node->next=head;
      return;
    }
    if(head != NULL){
      while(last->next != head){
        last=last->next;
      }
      new_node->next=head;
      last->next=new_node;
      new_node->pre=last;
      head->pre= new_node;
      head=new_node;
      return;
    }
  }
  while(count != pos  ){
    current=current->next;
    last=last->next;
    count++;
  }
  if(count== pos ){
    new_node->next=current;
    last->next=new_node;
    new_node->pre=last;
    current->pre=new_node;
    return;
  }
  }


};


int main(){
  doublering d;
  d.insert(2,1);
  d.insert(3,2);

}
