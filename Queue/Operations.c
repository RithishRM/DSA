#include<stdio.h>
#include<stdlib.h>  

struct Queue{
    int size ;
    int front ;     //This Front gets Incremented by 1 upon Dequeue 
    int rear ;      //This Rear gets Incremented by 1 upon Enqueue
    int * arr;
};

int isFull(struct Queue * q){
    if (q->rear == (q->size)-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct Queue * q){
    if (q->rear == q->front){
        return 1;
    }else{
        return 0;
    
}
}
void enqueue(struct Queue *q ,int val){
    if(isFull(q)){
        printf("The Stack Is Full And Elements Can't Be Added!!!");
    }else{
        q->rear++;
        q->arr[q->rear]=val;
        printf("Enqueued: %d\n", val);
    }
}

int dequeue(struct Queue * q){
    int a=-1;
    if(isEmpty(q)){
        printf("The Queue is Empty!!");
        return a;
    }else{
        a=q->arr[q->front];   
        q->front++;   //The front is now pointing in the element which will be left empty 
        printf("Dequeued: %d\n", a);
        return a;           
    }
}

int main(){
    struct Queue * q=(struct Queue *)malloc(sizeof(struct Queue));
    q->size=10;
    q->front=-1;
    q->rear=-1;
    q->arr=(int *)malloc(q->size * sizeof(int));
    enqueue(q,11);
    enqueue(q,89);
    dequeue(q);
}