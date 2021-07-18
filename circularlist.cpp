#include<iostream>
#include<string>

using namespace std;

class node{
public:
  int val;
  node *next;

  node(int data){
    val= data;
    next= NULL;
  }
};

class ring{
public:
  node *head= NULL;
  int len=0;

  void insert(int value, int pos);
  //void insert(int value, int pos);
  void search(int value);
  void get(int pos);
  void print();
  void deletion(int value);
  node* get_last();

};

void ring:: insert(int value, int pos ){
  node *new_node= new node(value);
  int count=1;
  if(head== NULL ){
    head=new_node;
    new_node->next=head;
    return;
  }


node *current=head;
node *next=NULL;
  while(cout != pos){
    current=current->next;
    count++;
  }
  next=current->next;
  new_node->next=next;
  current->next=new_node;

  return;


/*cout<<"hefgoiehfo"<<endl;
  node *last=head;
  while(current->next != head){
    if(count == pos){
      new_node->next=current;
      last->next=new_node;
      return;
    }
    current=current->next;
    last=last->next;
    count++;
  }
*/
}


 /*void ring:: insert(int value , int pos){
  node *new_node= new node(value);
  int count=0;
  node *current=head;
  node *next=NULL;
  while(count != pos-1){
    current=current->next;
    count++;
  }
  next=current->next;
  new_node->next= next;
  current->next=new_node;
  return;




}
*/
void ring:: print(){
  node *current=head->next;
  cout<<"[ ";
  cout<<head->val<<" ,";
  while(current != head){
    cout<<current->val<<", ";
    current=current->next;
  }
  cout<<" ]"<<endl;
}

node* ring:: get_last(){
  node *current=head;
  while(current->next != head){
    current=current->next;
  }
  node *last=NULL;
  last=current;
  //cout<<last<<endl;
  return last;
}

void ring:: search(int value){
  node *current=head->next;
  int count=2;
  if(head->val==value){
    cout<<count-1<<endl;
    return;
  }
  while (current !=head) {
    if(current->val == value){
      cout<<count<<endl;
      return;
    }
    count++;
    current=current->next;
      }
}

void ring:: get(int pos){
  int count=1;
  node *current=head;
  while(count != pos ){
    current->next;
    count++;
  }
  cout<<current->val<<endl;



}

void ring:: deletion(int value){
  node *current=head->next;
 node *last=head;
  if(head == NULL){
    cout<<"no value to remove "<<endl;
    return;
  }
  if(head->next == head){
    delete head;
    return;
  }


  while(current->next != head){
    if(current->val == value){
      last->next= current->next;
      delete current;
      return;
    }
    current=current->next;
    last=last->next;
  }
}


int main(){
  ring r;
  r.insert(2,1);
  r.insert(4,2);
  r.insert(6,3);
//  r.insert(8);
//  r.insert(10);
  r.print();

}
