#include<stdio.h>
#include<stdlib.h>

struct Node {
    int f;
    int r;
    int * arr;
    int size;
};

int isFull(struct Node * q){
    if (q->r==q->size-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct Node * q){
    if(q->r==q->f){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct Node * q,int val){
    if (isFull(q)){
        printf("Node is Full!!");
    }else{
        q->r++;
        q->arr[q->r]=val;
    }
}

int dequeue(struct Node * q){
    int a=-1;
    if(isEmpty(q)){
        printf("Node is Empty!!");
    }else{
        a=q->arr[q->f];
        q->f++;
        if ( q->f > q->r){
            q->f=q->r=-1;
        }
    }
    return a;
}

int main(){
    //Initializing Queue
    struct Node * q = (struct Node *)malloc(sizeof(struct Node));
    q->size = 10;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    //BFS Implementation  
    int i=0;    //This is the First Random Noed Taken in Graph
    int visited[7] = {0,0,0,0,0,0,0} ;   //Keeps Track of the which elements have been visited in Graph  
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    printf("%d",i);
    visited[i]=1;   //Since it has been printed => It has been visited 
    enqueue(q,i);    //Enqueued i in Exploration
    while(!isEmpty(q)){
        int node = dequeue(q);  //  //Temporoary Element to store the dequeued element from Exploration Queue
        for(int j=0;j<7;j++){
            if(a[node][j]==1 && visited[j]==0){ //Checking Adjacent and Unvisited Matrix
                printf("%d",j);
                visited[j]=1;
                enqueue(q,j);
            }
        }
    }
    return 0;
}