#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int f;
    int r;
    int size;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
        return 1;
    else
        return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size-1)
        return 1;
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
        printf("Queue Overflow\n");
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("%d is Enqueued\n", val);
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q))
        printf("Queue underflow.\n");
    else{
        q->f++;
        a = q->arr[q->f]; 
        printf("%d is dequeued\n", a);
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    printf("Enter last two digits of roll number: ");
    int x;
    scanf("%d", &x);
    enqueue(&q, x);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    
    printf("\n");

    dequeue(&q);
    dequeue(&q);
    dequeue(&q); 
    
    printf("\n");
    
    enqueue(&q, 51);
    enqueue(&q, 52);
    enqueue(&q, 53);

    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }

    return 0;
}