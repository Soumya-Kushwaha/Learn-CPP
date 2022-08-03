/*Q3. Evaluate the following expression using stack:
•	(2+3)*5
•	2+3-4+6       */

#include<iostream>
#include<string>
using namespace std;

class sta_char; //stack class for char data
class sta_int; //stack class for int data
bool check_if_digit(char c); //checks if entered character is digit
bool check_if_alphabet(char c); //checks if entered character is alphabet(lower/Upper case both)
string infix_to_postfix(string infix_expression); //returns postfix expression
int evaluate_postfix_expression(string expression); //retutns value of the provided postfix expression
int evaluate_infix_expression(string expression); //it calls infix_to_postfix() and evaluate_postfix_expression()

//char of a digit i.e. '0','1',...,'9' can be converted to int of the digit i.e. 0,1,...,9 in two ways
//first... int i = '5' - '0';
//second.. int i = (int)'5' - 48, here you may also skip type casting of character because int and char are similar dtypes

class sta_char{
	
	int top;
	char arr[100];
	
	public:
		
		sta_char(){
			top = -1;
		}
		
		bool isEmpty(){
			return (top == -1);
		}
		
		bool isFull(){
			return (top == sizeof(arr)/sizeof(char));
		}
		
		void push(char c){
			if(!isFull()){
				top = top + 1;
				arr[top] = c;
			}
			else
				cout<<"Stack is full"<<endl;
		}
		
		char pop(){
			if(!isEmpty()){
				top = top - 1;
				return arr[top+1];
			}
			else
				cout<<"Stack is empty - pop"<<endl;
		}
		
		char peek(){
			if(!isEmpty()){
				return arr[top];
			}
			else
				cout<<"Stack is empty - peek"<<endl;
		}
		
		void print(){
			if(!isEmpty()){
				for(int a=0; a<top+1; a++){
					cout<<arr[a]<<" ";
				}
				cout<<endl;
			}
			else{
				cout<<"Stack is empty - print"<<endl;
			}
		}
};

class sta_int{
	
	int top;
	int arr[100];
	
	public:
		
		sta_int(){
			top = -1;
		}
		
		bool isEmpty(){
			return (top == -1);
		}
		
		bool isFull(){
			return (top == sizeof(arr)/sizeof(int));
		}
		
		void push(int i){
			if(!isFull()){
				top = top + 1;
				arr[top] = i;
			}
			else
				cout<<"Stack is full"<<endl;
		}
		
		int pop(){
			if(!isEmpty()){
				top = top - 1;
				return arr[top+1];
			}
			else
				cout<<"Stack is empty - pop"<<endl;
		}
		
		int peek(){
			if(!isEmpty()){
				return arr[top];
			}
			else
				cout<<"Stack is empty - peek"<<endl;
		}
		
		void print(){
			if(!isEmpty()){
				for(int a=0; a<top+1; a++){
					cout<<arr[a]<<" ";
				}
				cout<<endl;
			}
			else{
				cout<<"Stack is empty - print";
			}
		}
};

bool check_if_digit(char c){
	bool yes = false;
	for(int i=48; i<58; i++){
		if(c == (char)i){
			yes = true;
			break;
		}
	}
	return yes;
}

bool check_if_alphabet(char c){
	bool yes = false;
	for(int i=65; i<91; i++){
		if(c == (char)i){
			yes = true;
			break;
		}
	}
	if(!yes){
		for(int i=97; i<123; i++){
			if(c == (char)i){
				yes = true;
				break;
			}
		}
	}
	return yes;
}

string infix_to_postfix(string infix_expression){
	string postfix_expression; //this will be the final output container
	string temp_num; //string used to temporarily store a string of number
	
	char c = infix_expression[0];
	int i = 0, length = 0;
	sta_char operator_stack;
	
	while(c != '\0'){
		
		length = postfix_expression.length();
		
		if(c == '('){
			operator_stack.push(c);
		}
		else if(check_if_digit(c)){
			temp_num += c;
			if(check_if_digit(infix_expression[i+1])){
				//pass, let the next digit come
			}
			else{
				postfix_expression += temp_num;
				temp_num = "";
			}
		}
		else if(check_if_alphabet(c)){
			postfix_expression += c; 
		}
		else if( c == '/' || c == '*' || c == '%'){
			if(!operator_stack.isEmpty() && (operator_stack.peek() == '/' || operator_stack.peek() == '*' || operator_stack.peek() == '%'))
				postfix_expression += operator_stack.pop();
			operator_stack.push(c);
		}
		else if(c == '+' || c == '-'){
			if(!operator_stack.isEmpty() && operator_stack.peek() != '(')
				postfix_expression += operator_stack.pop();
			operator_stack.push(c);
		}
		else if(c == ')'){
			char temp;
			do{
				temp = operator_stack.pop();
				if(temp != '(') postfix_expression += temp;
			}while(temp != '(');
		}
		else if(c == ' '){
			//ignore
		}
		else{
			cout<<"Some error occured!\nUse only +,-,*,/,% as operators and";
			cout<<"integrs/alphabets(variables) as operands,\nspaces are allowed\n";
		}
		
		//for spaces in between operands and operators
		if(postfix_expression.length() > length)
			postfix_expression += ' ';
		
		i++;
		c = infix_expression[i];
	}
	
	//empting out the operator_stack
	while(! operator_stack.isEmpty()){
		postfix_expression += operator_stack.pop();
		if(!operator_stack.isEmpty())	postfix_expression += ' ';
	}
	
	return postfix_expression;
}

int evaluate_postfix_expression(string expression){
	int i = 0;
	sta_int operand_stack;
	char c = expression[i];
	
	while(c != '\0'){
		
		//operand
		if(check_if_digit(c)){
			int temp = c - 48;
			while(check_if_digit(expression[i+1])){
				i++;
				c = expression[i];
				temp = temp*10 + (c - 48);
			}
			operand_stack.push(temp);
		}
		
		//spaces
		else if(c == ' '){
			//pass
		}
		
		//operator
		else if(c == '+'||c == '-'||c == '*'||c == '/'||c == '%'){
			int value = 0;
			int n2 = operand_stack.pop();
			int n1 = operand_stack.pop();
			if(c == '+'){
				value = n1 + n2;
			}
			else if(c == '-'){
				value = n1 - n2;
			}
			else if(c == '*'){
				value = n1 * n2;
			}
			else if(c == '/'){
				value = n1 / n2;
			}
			else if(c == '%'){
				value = n1 % n2;
			}
			operand_stack.push(value);
		}
		
		//error
		else{
				cout<<"\nUse only +,-,/,*,% as operators\n";
		}
		
		i++;
		c = expression[i];
	}
	
	return operand_stack.pop();
}

int evaluate_infix_expression(string expression){
	return evaluate_postfix_expression(infix_to_postfix(expression));
}

int main(){
	
	cout<<"Input is (2+3)*5\nIt's postfix is "<<infix_to_postfix("(2+3)*5")<<"\nValue = "<<evaluate_infix_expression("(2+3)*5");
	cout<<"\n"<<endl;
	cout<<"Input is 2+3-4+6\nIt's postfix is "<<infix_to_postfix("2+3-4+6")<<"\nValue = "<<evaluate_infix_expression("2+3-4+6");
	
	return 0;
}