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
class doublelinked{
public:
  node *head=NULL;

  void insert(int data, int pos);
  void print();
  void deletion(int val);
  void get(int pos );
  bool search(int val);
};

void doublelinked:: insert(int data, int pos){
    node *new_node=new node(data);
    int count=1;
    node *temp=head;

    if(temp == NULL || pos==1){
      head=new_node;
      new_node->pre=head;
      return;
    }

    while(count != pos-1){
      temp=temp->next;
      count++;
    }
    new_node->next=temp->next;



    temp->next=new_node;
    new_node->pre=temp;

    return;
}

void doublelinked:: print(){
  node *temp=head;
  cout<<"[ ";
  while(temp != NULL){
    cout<<temp->val<< ", ";
    temp=temp->next;
  }
  cout<<"] "<<endl;
}

void doublelinked:: deletion(int data){
  node *temp=head;

    if(head->next == NULL && head->val== data){
      delete head;
      head=NULL;
      return;
    }
    if(head->val==data){
      head=head->next;
      head->pre=NULL;
      delete temp;
    }
    node *current= NULL;
    while(temp->next!= NULL){
      if(temp->val == data){
        current=temp->pre;
        current->next=temp->next;
        temp->next->pre=current;
        delete temp;
        return;
      }
      temp=temp->next;

    }
}


void doublelinked:: get(int pos ){
  if(  pos < 1){
    cout<<"position not found enter a valid position "<<endl;
    return;
  }
  int count=1;
  node *current= head;
  while (current != NULL) {
    if(count == pos ){
      cout<<current->val;
      return;
    }
    current= current->next;
    count++;
  }
}

bool doublelinked:: search(int val){
  node *current= head;
  int count =0 ;
  while(current != NULL){
    if(current-> val == val){     // when to use this
      cout<< count+1<<endl;
      return true;
    }
    count++;
    current = current-> next;

  }
  current= head;                // a little hack
  if(current->val != val){
    cout<<" value not found, enter a valid position "<<"\n";
    return false;
  }
}


int main(){
  doublelinked d;
  d.insert(2,1);
  d.insert(3,2);
  d.insert(4,3);
  d.insert(5,4);
  d.insert(6,5);
  d.insert(7,3);

  d.print();

  d.deletion(5);
  d.deletion(2);
  d.deletion(6);
  d.print();


  //d.get(3);
  d.search(7);
}
