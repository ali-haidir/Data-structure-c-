#include<iostream>

using namespace std;

  int arr[5]={0,0,0,0,0};
  int *temp =NULL;

int get(int value){
  int counter = 0;
  int *temp2=NULL;
  temp2=arr;
  while (counter != value) {
    /* code */
    counter = counter + 1;
    temp2=temp2 + 1;

  }
  cout<<*temp2;
  return 0;
}

int next(int *current){
    current=current+1;
    return *current;
}

int back(int *current){
  current=current-1;
  return *current;
}

int start(){
  int *current;
  current=arr;
  cout<<*current <<"\n";
  return *current;
}

int end(){
  int *current=NULL;
  current=arr;
  for(int i=0; i<4;i++){
    current=current+ 1;

  }
  cout<<*current<<"\n";
  return *current;

}

int update(int value, int index){
  temp=arr;
  int counter=0;
  while(counter!= index){
    counter=counter+1;
    temp++;
  }
  *temp=value;
  cout<<*temp<<"\n";
}

int remove(int value){
  temp=arr;
  int *temp2=arr+1;
  int counter=0;
  while(*temp !=value){
    temp++;
    temp2++;
  }
  *temp=0;
  *temp=*temp2;
  temp=temp2+2;
  temp2=temp2+1;
  *temp2=*temp;
  cout<<*temp2;

  //problem
}

int length(){
  int counter=0;
  temp=arr;
  for(int i=0; i<5; i++){
    if(*temp != 0){
      counter +=1;
      temp=temp+1;
    }
    else{
      temp=temp+1;
    }
  }
  cout<<counter;
}

int show(){
  int *temp2=NULL;
  temp2=arr;
  cout<<"[ ";
  for(int i=0; i<5; i++){
    cout<<*temp2<<", ";
    temp2=temp2+1;
  }
  cout<<" ]"<<endl;
  //cout<<" ]";
}
int main(){

update(2,0);
update(4,3);
update(6,4);
show();
length();
end();
start();
get(3);
  return 0;
}
