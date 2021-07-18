#include<iostream>

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

class singlelinked{
public:
  node *head=NULL;
  int count= 0;

  void enque( int val );
  void print();
  void dequeue();
};

void singlelinked::enque(int val){
    node *new_node= new node(val);

    node *temp=head;

    if(count == 10 ){
      cout<<"queue is full overflow \n";
      return;
    }


    if(count == 0){
      head=new_node;
      count++;
      return;
    }

    while(temp->next != NULL){
      temp= temp->next;

    }
    if(temp->next == NULL){
      temp->next=new_node;
      count++;
      return;
    }


}

void singlelinked::print(){
  node *temp=head;
  cout<<"[ ";
  while(temp != NULL){
    cout<<temp->data<<",";

    temp=temp->next;
  }
  cout<<" ]  \n";
}

void singlelinked::dequeue(){
  node *temp=head;
  if(count <= 0 ){
    cout<<"queue empty \n";
    return;
  }


  if(temp == head ){
    head=head->next;
    temp->next=NULL;
    delete temp;
    count--;
  }
}

int main(){
  singlelinked s;
  s.enque(2);
  s.enque(4);
  s.enque(6);
  s.enque(6);   


  s.print();
  s.dequeue();
  s.dequeue();
  s.dequeue();
  s.dequeue();

  s.print();

}
