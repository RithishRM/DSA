#include<stdio.h>
#include<stdlib.h>

struct Node * f=NULL;
struct Node * r=NULL;

struct Node{
    int data ;
    struct Node * next;
};

void enqueue(int val){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    if(ptr==NULL){
        printf("Queue Overflow!!!");
    }else{
        ptr->data=val;
        ptr->next =NULL;    //Since it is added in the last and last element in LL has a NULL
        if(f==r==NULL){
            f=r=ptr;          //This is special case where Queue is empty and we make front and rear the same element and then start adding 
        }else{
            r->next=ptr;
            r=ptr;
        }
    }
}

int dequeue(){
    int val=-1;
    struct Node * ptr=f;
    if(f==r){
        printf("Queue Underflow");
        return val;
    }else{
        f=f->next;
        val=ptr->data;
        free(ptr);
        return val;
    }
}

void Traversal(struct Node * ptr){      //The Node given here is the head 
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    //struct Node * f=NULL;
    //struct Node * r=NULL;
    //We are not passing the element from here as in the LL we return head there but here we are not returning that so we are making it a global variable. 
    
    enqueue(11);
    enqueue(17);
    enqueue(10);
    Traversal(f);
    dequeue();
    Traversal(f);
    return 0;
}