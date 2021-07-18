#include<iostream>
#include<string>

using namespace std;

class stack{
  int arr[5];

  stack(){
    for(int i=0, i<5, i++){
      arr[i]=0;
    }
  }

  void print(){
    cout<<"[";
    for(int i=0, i<5, i++){
      cout<<arr[i]<<endl;
    }
    cout<<"]";
    return;
  }

};

int main(){
  stack s;
  s.print();
}
