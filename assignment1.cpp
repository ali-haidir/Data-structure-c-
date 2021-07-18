#include<iostream>

using namespace std;

const int size=5;
class list{
public:
int arr[size];
int *current=NULL;
int *tail=NULL;

void add(int value);
void show(){
    int *temp=arr;
    cout<<"[ ";
    for(int i=0 ; i<5; i++){
      cout<<*temp<<", ";
      temp++;
    }
    cout<<" ]"<<"\n";
}

list(){
  int *temp=arr;
  for(int i=0; i<size; i++){
    *temp=0;
    temp++;
  }
  tail=temp;

}


void start(){
  current=arr;
  //cout<<*current<<"\n";
}

void end(){
  current=arr;
  for(int i=0; i<4; i++){
    current++;
  }
}

void next(){
  current++;
}

void back(){
  current=current-1;
}

int get(){
  cout<<*current<<"\n";
  return *current;
}

int update(int value){
  *current=value;
  return *current;
}

void length(){
  start();
  int counter=0;
  for(int i=0; i<size; i++){
    if(*current != 0){
      counter++;
      current++;
  }
  else{
    continue;
  }
}
cout<< counter <<"\n";

}

void remove(){
  int *nextt= NULL;
  nextt=current +1;
  while(nextt-1 != tail ){
    //cout<<"uigiuguigg";
    *current=*nextt;
    nextt++;
    current++;
  }
  *(nextt-2)=0;
}
};

void list::add(int value){

  while(current != tail){
    current++;
    if(*current ==0 ){
      *current= value;
      break;
    }
    else{
      continue;
    }
  }
}

int main(){
  list l;
  //l.show();
  l.start();
  l.update(2);
  l.next();
  l.update(4);
  l.next();
  l.update(6);
  l.next();
  l.update(8);
  l.next();
  l.update(10);
  l.back();
  l.back();
  l.back();
  l.show();
  l.remove();
  l.back();
  l.back();
  l.remove();
  l.back();
  l.back();
  l.back();

  l.add(200);



  l.show();
}
