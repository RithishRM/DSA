//Given the head of a singly linked list, reverse the list, and return the reversed list.

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data ;
    struct Node * next;
};

struct Node * Reverse(struct Node * head){
    struct Node * p=NULL;
    struct Node * m=head;
    struct Node * f=NULL;
    while(m!=NULL){
    f=m->next;  //Forward Pointer That the next value as it is lost when reversing the linked list link
    m->next=p;
    p=m;
    m=f;
    }
    head=p;
    return head;
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
    struct Node * head1=(struct Node *)malloc(sizeof(struct Node));
    struct Node * sec1=(struct Node *)malloc(sizeof(struct Node));
    struct Node * third1=(struct Node *)malloc(sizeof(struct Node));
    struct Node * four1=(struct Node *)malloc(sizeof(struct Node));
    struct Node * five1=(struct Node *)malloc(sizeof(struct Node));

    head1->next=sec1;
    head1->data=1;
    sec1->next=third1;
    sec1->data=2;
    third1->next=four1;
    third1->data=2;
    four1->next=five1;
    four1->data=2;
    five1->next=NULL;
    five1->data=3;

    Traversal(head1);
    head1=Reverse(head1);
    Traversal(head1);
}