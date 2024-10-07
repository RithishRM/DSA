//Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
//LeetCode Question
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data ;
    struct Node * next;
};

struct Node * del(struct Node * head ){
    struct Node * p=head;
    while(p!=NULL && p->next!=NULL){
        if(p->data==(p->next)->data){
            struct Node * temp =p->next ;   //We are writing these to lines so that the update the link to skip over the freed node, causing a memory leak and potentially undefined behavior.
            p->next=p->next->next;
            free(temp);
        }else{
            p=p->next;
        }
    }
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
    head=del(head);
    Traversal(head);
}