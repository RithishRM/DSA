#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data ;
    struct Node * next;
};

struct Node * del(struct Node * head,int val){
    struct Node * p=head;
    struct Node * b=NULL;
    while(p!=NULL){
        if(p->data==val){
            if(b==NULL){    //This if-else is for pointing b properly
                head=p->next;      
            }else{
                b->next=p->next;
            }
            struct Node * temp=p;
            p=p->next;
            free(temp);
        }else{
            b=p;
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

    second->data=11;
    second->next=third;

    third->data=98;
    third->next=NULL;
    Traversal(head);
    head=del(head,98);
    Traversal(head);
}