#include<iostream>
#include<string>

using namespace std;

class node{
public:
  int data;
  node *next;

  node(int val){
    data=val;
    next=NULL;
  }

};

class ring{
public:
  node *head=NULL;

  void insert(int val, int pos);
  void deletion(int val);
  void print();

};

void ring:: insert(int val , int pos ){
  node *new_node=new node(val);

      int count=1;

      if(head == NULL){
        cout<<"working    \n";
        new_node->next=head;
        head=new_node;

        return;
      }

      node *current= head;

      while(count != pos-1){
        current=current->next;
        count++;
      }
      new_node->next=current->next;
      current->next=new_node;




}

void ring:: print(){
  node *current=head;
  cout<<"[ ";
//  cout<<head->data<<",";
  while (current->next != head) {
    cout<<current->data<<",";
    current=current->next;

  }
  cout<<"]"<<endl;


}

void ring:: deletion(int val){
  node *current=head;
  node *last=NULL;

  if(head->data == val){
    while(last->next==head){
      last=last->next;
    }
    head=head->next;
    delete current;
    last->next=head;
  }

  while(current->next != head){
    if(current->data== val){

    }
    current=current->next;
    last=last->next;

  }

}

int main(){
  ring r;
  r.insert(2,1);
  //r.insert(3,2);
//  r.insert(4,3);
// r.insert(5,6);
//  r.insert(6,100);
  //r.insert(8,4);
//  r.insert(9,1);
 r.print();
}
