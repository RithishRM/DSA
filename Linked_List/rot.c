#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data ;
    struct Node * next;
};
void Traversal(struct Node * ptr){
    int i=1;
    while(ptr!=NULL){
        printf("Element %d is %d\n",i,ptr->data);
        ptr=ptr->next;
        i++;
    }
}

struct Node * rot(struct Node * head,int k){
    struct Node * p=head;
    int c=0;
    while(c!=k){
        if(p->next->next==NULL){
            struct Node * temp=p->next;
            temp->next=head;
            temp=head;
            p->next=NULL;
        }else{
            p=p->next;
        }
    }
    return head;
}
