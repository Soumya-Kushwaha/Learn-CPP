#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int f;
    int r;
    int size;
    int *arr;
};

int isEmpty(struct queue *q){
    if(q->r == q->f)
        return 1;
    else
        return 0;
}

int isFull(struct queue *q){
    if((q->r+1)%q->size==q->f)
        return 1;
    else
        return 0;
}

void enqueue(struct queue *q,int value){
    if(isFull(q))
        printf("Circular Queue overflow!");
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=value;
        printf("%d is enqueued.\n", value);
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q))
        printf("Circular Queue underflow!\n");
    else{
        q->f=(q->f+1)%q->size;
        a = q->arr[q->f];
        printf("%d is dequeued.\n", a);
    }
    return a;
}

int main(){
    struct queue q;
    q.f=-1;
    q.r=-1;
    q.size=10;
    q.arr=(int*)malloc(q.size*sizeof(int));

    printf("Enter last two digits of roll number: ");
    int x;
    scanf("%d", &x);
    enqueue(&q, x);
    enqueue(&q, 50);
    enqueue(&q, 40);

    printf("\n");
    
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
   
    return 0;
}