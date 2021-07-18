#include<iostream>
#include<string>

using namespace std;

class node{
public:
      int val;
      node *next;

      node(int data){
        val=data;
        next=NULL;
      }

};

class linkedlist{
public:
  node *head=NULL;
  int len=0;

  void insert(int value, int pos);
  void print();
  void search(int value);
  void get(int pos);
  bool empty();
  void deletenode(int value);
};

void linkedlist::deletenode(int value){
  node *current=head->next;
  node *last=head;

  if(last->val == value){
    head=head->next;
    delete last;
    len--;
    return;
  }


  while(current != NULL){
    if(current->val == value){
        last->next=last->next->next;
        delete current;
        len--;
        return;
    }
    current= current->next;
    last=last->next;

  }
  if(last->val != value){
    cout<<"value not found "<<endl;
    return;
  }

}

void linkedlist:: print(){
  node *temp=head;
  cout<<"[ ";
  while(temp != NULL){
    cout<<temp->val<<" ,";
    temp=temp->next;

  }
  cout<<" ]"<<endl;
}

void linkedlist:: insert(int val, int pos){
                // 3 Cases , 1 Sanity check
node *n = new node(val);

if (pos == 1 ){
cout<<"Inserting at HEAD"<<endl;
n->next = head;
head = n;
len++;
return;
}


int count = 1;
node *temp;
temp = head;

if (pos-1 == len){
cout<<"Inserting at END"<<endl;
while(temp->next != NULL){
temp = temp->next;
}
temp->next = n;
len++;
return;
}

if (pos > len){
cout<<"Cannot Insert. Position exceeding length of list"<<endl;
return;
}

cout<<"Inserting in MID"<<endl;
while ( temp->next != NULL && count < pos - 1){
temp = temp->next;
count++;
}
n->next = temp->next;
temp->next = n;
len++;
return;

}

void linkedlist:: search(int value){
  node *current=head;
  int counter=1;
  while(current->val != value){
    current=current->next;
    counter++;
  }
  cout<<counter<<endl;

}

void linkedlist:: get(int pos){
  node *current=head;
  int count=1;
  if(pos >len){
    cout<<"out of list enter a valid position...  "<<"\n";
    return;
  }

  while(count != pos){
    current=current->next;
    count++;
  }
  cout<<current->val;

}

bool linkedlist:: empty(){
  if(head == NULL){
    cout<<"list is empty "<<endl;
    return true;
  }
  else{
    cout<<"list is not empty "<<endl;
    return false;
  }
}
int main(){
  linkedlist l;
  l.insert(2,1);
  l.insert(4,2);
  l.insert(6,3);
  l.insert(8,2);
  l.print();
  l.deletenode(6);
  l.print();
cout<<  l.len;

  return 0;

}
