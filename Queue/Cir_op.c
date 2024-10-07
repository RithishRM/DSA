#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size ;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue * q){
    if ((q->r+1)%(q->size)==q->f){      //For Circular Increment--(i+1)%size
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct Queue * q){
    if (q->f==q->r){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct Queue * q,int val){
    if(isFull(q)){
        printf("Queue OVERFLOW !!!\n");
    }else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("Element %d Successfully Added!!!\n",val);
    }
}

int dequeue(struct Queue * q){
    int val=-1;
    if(isEmpty(q)){
        printf("Queue is Empty !!\n");
        return val;
    }else{
        val=q->arr[q->f];
        q->f=(q->f+1)%q->size;      //The front is now pointing in the element which will then enqueued later 
        printf("%d Successfully Dequeued!!!\n",val);
        return val;
    }
}

int main(){
    struct Queue * q;
    q=(struct Queue *)malloc(sizeof(struct Queue));
    q->size=10;
    q->f=-1;
    q->r=-1;
    q->arr=(int *)malloc(q->size * sizeof(int));
    enqueue(q,56);
    enqueue(q,92);
    enqueue(q,5);
    dequeue(q);
}