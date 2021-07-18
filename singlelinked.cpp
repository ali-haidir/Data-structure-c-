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


class singlelinked{
public:
  node *head=NULL;

  void insert(int val, int pos );
  void print();
  void deletion(int val);

};

void singlelinked:: insert(int val, int pos){
  node *n= new node(val);

  int count=1;
  node *temp=head;
  if(temp == NULL || pos ==1){
    head=n;
    return;
  }
  while(count != pos -1){
    temp=temp->next;
    count++;

  }
  n->next=temp->next;
  temp->next=n;
}

void singlelinked:: print(){
  node *temp=head;

  cout<<"[ ";
  while(temp!= NULL){
    cout<<temp->data<<", ";
    temp=temp->next;
  }
  cout<<" ]"<<endl;

}

void singlelinked:: deletion(int val){
  node *temp=head->next;
  node *del=head;

  if(head->data==val){
    head=head->next;
    delete del;
    return;
  }


  while(temp->data != val ){
    temp=temp->next;
    del=del->next;
  }
  if(temp->data==val ){
    del->next=temp->next;
    delete temp;
    return;
  }
}

int main(){
  singlelinked s;
  s.insert(2,1);
  s.insert(3,2);
  s.insert(4,3);
  s.insert(5,4);
  s.insert(6,2);
  s.insert(8,3);
  s.print();

  s.deletion(2);
  s.deletion(4);
  s.deletion(8);

  s.print();

}
