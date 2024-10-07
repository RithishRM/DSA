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

struct Node * consec_sum(struct Node * head){
    struct Node * p=head;
    struct Node * b=NULL;
    while(p!=NULL || p->next!=NULL){
        int sum=p->next->data + p->next->next->data;
        if(sum==0){
            p->next=p->next->next->next;
            free(p->next);
            free(p->next->next);
        }else{
            p=p->next;
        }
    }
    return head;
}

int main(){
    struct Node * head ;
    struct Node * second;
    struct Node * third;

    //Assigning memory for nodes in Linked List in Heap
    head=(struct Node *)malloc(sizeof (struct Node));
    second=(struct Node *)malloc(sizeof (struct Node));
    third=(struct Node *)malloc(sizeof (struct Node));

    //Linking the Nodes
    head->data=7;              
    head->next=second;          

    second->data=-7;
    second->next=third;

    third->data=98;
    third->next=NULL;
    Traversal(head);
    head=consec_sum(head);
    Traversal(head);
}