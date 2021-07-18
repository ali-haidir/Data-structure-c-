#include<iostream>

using namespace std;

void evaluating_prefix(string x){


  for(int i=0; i<x.size(); i++){
    if(isdigit(x[i])){
      push(x[i]);
    }
    else{
      int a=pop();
      int b=pop();
      int r=0;
      switch (x[i]) {
        case '+':
        r=a+b;
        push(r);
        break;

        case '-':
        r=a-b;
        push(r);
        break;

        case '*':
        r=a*b;
        push(r);
        break;

        case '/':
        r=a/b;
        push(r);
        break;

        case '^':
        r=a^b;
        push(r);
        break;
      }
    }
  }
}

void working()
