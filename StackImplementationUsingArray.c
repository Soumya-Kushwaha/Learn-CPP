#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack_arr[MAX];
int top=-1;
int isfull() {

    if(top==MAX-1)
        return 1;

    else
        return 0;
}

int isEmpty() {

    if(top==-1)
        return 1;
    else
        return 0;
}

void push(int item) {
    if(isfull()) {
        printf("Stack overflow..\n");
        return;
    }
    top++;
    stack_arr[top]=item;
}

int pop() {
    int item;

    if(isEmpty()) {
        printf("Stack underflow..\n");
        exit(1);
    }

    item=stack_arr[top];
    top--;
    return item;
}

int peek() {
    if(isEmpty()) {
        printf("Stack underflow..\n");
        exit(1);
    }
    return stack_arr[top];
}

void display() {
    int i;
    if(isEmpty()) {
        printf("Stack is empty..\n");
        return;
    }
    
    printf("Stack elements: \n");
    for(i=top;i>=0;i--) {
        printf("%d\n",stack_arr[i]);
    }

    printf("\n");
}

int main() {
    int ch,item;
    while(1) {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display the top element\n");
        printf("4.Display all stack elements\n");
        printf("5.Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        
        switch(ch) {
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d",&item);
                push(item);
                break;

            case 2:
                item=pop();
                printf("Popped item is: %d\n",item);
                break;

            case 3:
                printf("Item at the top is: %d\n",peek());
                break;  
            
            case 4:
                display();
                break;
            
            case 5:
                exit(1);
                
            default:
                printf("Wrong choice..\n");
                break;

            }
    }
    return 0;
}