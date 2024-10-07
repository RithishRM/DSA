//Given the head of a singly linked list, return the middle node of the linked list.
//If there are two middle nodes, return the second middle node.

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data ;
    struct Node * next;
};

struct Node * mid(struct Node * head){
    int count=0;
    struct Node * p=head;
    while(p!=NULL){
        p=p->next;
        count++;
    }
    int mid=count/2;
    struct Node * p1=head;
    for(int i=0;i<mid;i++){
        p1=p1->next;
    }
    return p1;
}

void Traversal(struct Node * ptr){
    int i=1;
    while(ptr!=NULL){
        printf("Element %d is %d\n",i,ptr->data);
        ptr=ptr->next;
        i++;
    }
}


int main(){
    struct Node * head=(struct Node *)malloc(sizeof(struct Node));
    struct Node * sec=(struct Node *)malloc(sizeof(struct Node));
    struct Node * third=(struct Node *)malloc(sizeof(struct Node));
    struct Node * four=(struct Node *)malloc(sizeof(struct Node));
    struct Node * five=(struct Node *)malloc(sizeof(struct Node));

    head->next=sec;
    head->data=1;
    sec->next=third;
    sec->data=2;
    third->next=four;
    third->data=2;
    four->next=five;
    four->data=2;
    five->next=NULL;
    five->data=3;
    head=mid(head);
    Traversal(head);
}