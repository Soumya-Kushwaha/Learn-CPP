
/*Q1 Print your name in reverse using the stack.
Example: Input: Saumil
Output: limuaS*/

#include <iostream>
#include <string.h>
#define max 100
int top;
char stack[max];

void push(char x)
{
    if(top==max-1)
    std::cout<<"stack overflow";
    
    else
    printf("%c", stack[++top] = x);
    
}

void pop()
{
    printf("%c", stack[top--]);
}


int main() {
    char str[] = "Soumya";
    int len = strlen(str);
    
    std::cout<<"Original String: ";
    for(int i=0; i<len; i++)
    push(str[i]);
    std::cout<<"\n";
   
   std::cout<<"Reversed String: ";
    for(int i=0; i<len; i++)
    pop();
    return 0;
}
