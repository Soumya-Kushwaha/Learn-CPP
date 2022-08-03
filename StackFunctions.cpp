//lab5 Question2

/*Q2 Implement the functions like Push, Pop, Initialize, Empty and Full onto stacks size 10 for doing following tasks:
a. Insert your roll number in the stack (Push your last two digits of roll no.).
b. Return the top element of stack without changing it.
c Push atleast three subject codes of current semester on to the existing stack (User choice)
d Return the fourth element from top of stack, provided that the stack contains 4 integers.*/

#include<iostream>
using namespace std;

class sta{
	
	int top;
	int arr[10];
	
	public:
		
		sta(){
			top = -1;
		}
		
		bool isEmpty(){
			return (top == -1);
		}
		
		bool isFull(){
			return (top == sizeof(arr)/sizeof(int));
		}
		
		int peek(){
			if(!isEmpty()){
				return arr[top];
			}
			else
				cout<<"Stack is empty"<<endl;
                return 0;
		}
		
		void push(int n){
			if(!isFull()){
				top = top + 1;
				arr[top] = n;
			}
			else
				cout<<"Stack is full"<<endl;
		}
		
		int pop(){
			if(!isEmpty()){
				top = top - 1;
				return arr[top + 1];
			}
			else
				cout<<"Stack is empty"<<endl;
		}
		
		int print_element(int j){
			if(j <= top+1)
				return arr[j-1];
			else
				cout<<"There are only "<<top+1<<" elements int the stack\n";
                return 0;
		}
};

int main(){
	
	sta s; //s is a stack that can store int data elements
	
	//a>
	s.push(62);
	cout<<"62 is pushed"<<endl;
	
	//b>
	cout<<"\nPeek element is "<<s.peek();
	
	//c>
	int i,j;
	do{
		cout<<"\n\nHow many subject codes you want to push ?: ";
		cin>>i;
		if(i < 3)
			cout<<"Enter atleast three codes!";
	}while(i < 3);
	for(i; i>0; i--){
		cout<<"Enter subject code: ";
		cin>>j;
		s.push(j);
	}
	
	//d>
	cout<<"\nFourth element from top is "<<s.print_element(4);
	
	return 0;
}