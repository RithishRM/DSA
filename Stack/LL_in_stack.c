#include<stdio.h>
#include<stdlib.h>

struct Node {       //In this stack the Head element will be the Top
    int data;
    struct Node * next;
};

int isEmpty(struct Node * s){
    if(s==NULL){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct Node *s ){
    struct Node * n=(struct Node *)malloc(sizeof(struct Node));
    if (n==NULL){
        return 1;
    }else{
        return 0;
    }
}

void Push(struct Node *top,int val ){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL){
        printf("Stack Overflow!!");
    }else{
        ptr->data=val;
        ptr->next=top;
        top=ptr;
    }
}

int Pop(struct Node * top){
    if(isEmpty(top)){
        printf("Stack Underflow!!");
        return -1;
    }else{
        struct Node * ptr=top;
        top=top->next;
        int x=ptr->data;
        free(ptr);
        return x;
    }
}

void Traversal(struct Node * ptr){      //The Node given here is the head 
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    struct Node * top=(struct Node * )malloc(sizeof(struct Node));
    struct Node * second=(struct Node * )malloc(sizeof(struct Node));
    struct Node * third=(struct Node * )malloc(sizeof(struct Node));

    top->data=11;
    top->next=second;
    second->data=90;
    second->next=third;
    third->data=78;
    third->next=NULL;
    Traversal(top);
    Push(top,3);
    Traversal(top);
}