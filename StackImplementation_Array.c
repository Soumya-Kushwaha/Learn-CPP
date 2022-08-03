// Stack implementation in C

#include <stdio.h>
#include <stdlib.h>

int count = 0;

// Creating a stack
struct stack {
  int size;;
  int top;
  int *arr;
};

// Check if the stack is full
int isfull(struct stack *s) {
  if (s->top == s->size - 1)
    return 1;
  else
    return 0;
}

// Check if the stack is empty
int isempty(struct stack *s) {
  if (s->top == -1)
    return 1;
  else
    return 0;
}

// Add elements into stack
void push(struct stack *s, int newitem) {
  if (isfull(s)) {
    printf("STACK FULL");
  } else {
    s->top++;
    s->arr[s->top] = newitem;
  }
  count++;
}

// Remove element from stack
void pop(struct stack *s) {
  if (isempty(s)) {
    printf("\n STACK EMPTY \n");
  } else {
    printf("Item popped= %d", s->arr[s->top]);
    s->top--;
  }
  count--;
  printf("\n");
}

// Print elements of stack
void printStack(struct stack *s) {
  printf("Stack: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", s->arr[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  struct stack *s = (struct stack *)malloc(sizeof(struct stack));
  s->size = 5;
  s->top = -1;
  s->arr = (int *)malloc(s->size * sizeof(int));

  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);

  printStack(s);

  pop(s);

  printf("\nAfter popping out\n");
  printStack(s);
}