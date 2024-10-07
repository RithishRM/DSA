//addAfter(int b, int data);  Write a method that adds a new node containing data after a node containing the value b.
//Assignment Question
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data ;
    struct Node * next;
};
struct Node * AddAfter(int b,int data,struct Node * head){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    while(p!=NULL){
        if(p->data==b){
            ptr->data=data;
            ptr->next=p->next;
            p->next=ptr;
            break;
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
    head=AddAfter(2,3,head);
    Traversal(head);

}