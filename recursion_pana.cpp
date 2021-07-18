#include<iostream>
#include<string>

using namespace std;

bool palendron(string exp, char *first, char *last){
    if(*first != *last){
      cout<<"falseeeeeeee \n";
      return false;
    }
    else{
      if(first == last || first+1 == last ){
        cout<<"trueeeeeeeeeeeeeee \n";
        return true;
      }

      first++;
      last--;
      palendron(exp, first, last);
    }
}

void new_array(string exp, char *current , char first , char second){

}


int main(){
string abc ="madam";
int la=abc.length()-1;
  palendron(abc, &abc[0] , &abc[la]);
}
