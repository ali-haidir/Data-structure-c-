#include<iostream>
#include<string>

using namespace std;

class stack{
public:
  int *array;
  int *top=NULL;
  int count=0;

  stack(){

    array= new int(5);
    top=NULL;
  }

  void push(int val){
    if(top==NULL){
      top=array;
    }

      if(is_full()){
      cout<<"stack is full \n";
      return;
    }


    *top= val;
    top++;
    count++;


  }

  bool is_full(){
    if(count == 5){
      cout<<"stack is full \n";
      return true;
    }
    else return false;
  }

  bool is_empty(){
    if(count == 1){

      return false;
    }
    else{
      return true;
    }
  }

  bool print(){
    int *temp=array;
    cout<<"[ \n";
    for(int i=0; i<5; i++){
      cout<<*temp<<" , ";
      temp++;
    }
    cout<<" ] \n";
  }

  void pop(){
    if(!is_empty()){
    cout<<"stack is empty \n";
    return;
  }
    *top=0;
    top--;
    count--;
    return;
  }


};

int main(){
  stack s;
  s.push(2);
  s.push(4);
  s.push(6);
  s.push(8);
  s.push(10);
  s.push(12);
  s.print();
  s.pop();
  s.pop();
  s.pop();
  s.pop();
  s.print();
}
