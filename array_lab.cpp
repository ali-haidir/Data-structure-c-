#include<iostream>
#include<string>
using  namespace std;

class list{
private:
	int *p;
	int size,len,*current,*tail;
public:

    //Constructor for initializing List
	list(){
			cout<<"enter the size of the list: "<<endl;
			cin>>size;
			current=NULL;
			tail=NULL;
			len=0;

			p=new int[size];
			current=p;
			for(int i=0; i<size; i++){
				*current=0;
				current++;
			}
			tail=current;
			current=p;
	}

    //Deep Copy Constructor
	list(list& othrList){

		current=NULL;
		tail=NULL;

		size=othrList.size;

		p=new int[othrList.size];
	//	copy(p,p.othrList);
	}


    //Clear Or Empty the List
	void clear(){
		current=p;
				for(int i=0 ; i<size; i++){
					*current=0;
					current++;
 			}
			len=0;
			current=NULL;
			}




    //Insert a Value at Specific Position


	void insert(int value,int pos){
		current=p;
		int *temp=p;
		int counter=0;
		if(len >= size){
			cout<<"list is full "<<endl;
			return;
		}

		while(counter != pos-1){
			current++;
			counter++;
		}
		if(*current==0){
			*current=value;
			len +=1;
			return;
		}
		if(*current != 0){
			while(*temp!=0){
				temp++;
			}
			while(temp != current){
				*temp=*(temp-1);
				temp--;
			}
			*current=value;
			len +=1;
			while(*current !=0 ){
				current++;
			}
			current=current-1;
		}
	}

    //Insert the given value in the list at the next available position
    void insert(int value){
			if(len==0){
				len +=1;
				*current=value;
				return;
			}
			if(len==size){
				cout<<"list is full "<<endl;
			}
			else{
				current++;
				*current=value;
				len +=1;
			}
	}


    //Remove a value at specific position
	void remove(int value){
		current=p;
		int *temp=current+1;

		while(current !=tail){
			if(*temp == value){
				current++;
				temp++;
				while(temp-1 !=tail){
				*current=*temp;
				temp++;
				current++;
			}
			  *(temp-2)=0;
			return;
			}
			current++;
			temp++;

		}

	}



    //Get value stored at a specific position
	int get(int pos){
		current=p;
		int counter=0;
		while(counter != pos){
			counter++;
			current++;
		}
		cout<<*(current-1)<<endl;
		return *(current-1);

	}

    //Update Existing value at a position
	void update(int value,int pos){
		current=p;
		int counter=0;
	while(counter != pos ){
		current++;
		counter++;
	}
	*(current-1)=value;

	}


    //Find a value in the list
	bool find(int value){
		current=p;
		while(current != tail){

			if(*current==value){
				cout<<"true";
				return true;
			}
				current++;
		}
		return false;

	}


    //Return Current Length of the list
	int length(){
		current=p;
		int counter=0;
		while(current != tail){
		if(*current !=0){
			counter++;
		}
			current++;
		}
		cout<<counter;

	}


    //Move to starting position of the list
	void start(){
		current=p;

	}

    //Move to the end of the list
	void end(){
		current=tail;
	}

	void show();

};
void list::show(){
	int *temp=p;
	cout<<"[ ";
	while(temp != tail){
		cout<<*temp<<" ,";
		temp++;

	}
	cout<<" ]"<<endl;

}

int main(){
	list l;

	list l2;
	l2=list(l);
	l2.show();
	return 0;
}
