#include<iostream>
#include<string>
using  namespace std;

class list{
private:
	int *p=NULL;
	int size,len,*current,*temp;
public:

    //Constructor for initializing List
	list(){
		std::cout << "enter size of the list" << '\n';
		std::cin >> size;

		len=0;
		int *current=NULL;
		int *temp=NULL;
		p=new int[size];
		current=p;

		for(int i=0; i<size; i++){
			*current=0;
			current++;
		}
	}

    //Deep Copy Constructor
	list(list& othrList){


	}


    //Clear Or Empty the List
	void clear(){
	//	delete[] p;
	current=p;
		for (int i=0;i <= size ;i++){
			delete current;
			current=current+1;
		}
		current=NULL;
	}



    //Insert a Value at Specific Position
	void insert(int value){
		current=p;
		if(len==0){
			len+=1;

			*current=value;
			return;	}
		if(len == size){
			cout<<"list is full"<<endl;
		}
	for(int i=0 ; i<size; i++){
		if(*current ==0){
			*current=value;
			break;
		}
		else{
			current++;
		}
		}
	}

    //Insert the given value in the list at the next available position
    void insert(int value, int pos){
			while(*p!=0){
				p++;
			}
			*p=value;
	}


    //Remove a value at specific position
	void remove(int pos){
		int counter=0;
		while(counter != pos){
			p++;
			counter++;
		}
		//*p=0;
		delete p;
	}



    //Get value stored at a specific position
	int get(int pos){
	int counter=0;
	while(counter!= pos){
		p++;
		counter++;
	}
	cout<<*p<<"\n";

	}

    //Update Existing value at a position
	void update(int value,int pos){
		int counter=0;
		while(counter != pos){
			p++;
			counter++;
		}
		*p=value;
	}


    //Find a value in the list
	bool find(int value){
		current=p;
		for(int i=0; i<=size; i++){
				if(*current != value){
					current++;
				}
			}
				return true;
	}


    //Return Current Length of the list
	int length(){
		current=p;
	int	counter=0;
	while(*current !=0){
		counter++;
		current++;
	}
	cout<<counter<<endl;
	return counter;
	}


    //Move to starting position of the list
	void start(){
current=p;
return;

	}

    //Move to the end of the list
	void end(){
		current=p;
		for(int i=0; i<size ; i++){
			current++;
		}
		cout<<*current<<endl;
	}

	void show(){
		current=p;
		cout<<"[ ";
		for(int i=0;i<size; i++){
			cout<<*current<<" ,";
			current++;
		}
		cout<<" ]"<<endl;
	}

};

int main(){
	list l;
	l.show();
	l.insert(200);
	l.insert(300);
	l.insert(400);
	l.insert(500);
	l.insert(600);
	l.show();
	l.length();





//	system("pause");
	return 0;

}
