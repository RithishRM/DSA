#include<stdio.h>
#include<stdlib.h>
 
struct Node{
    int data;
    struct Node * next;     //Pointer to the Next node element
};

void Traversal(struct Node * ptr){      //The Node given here is the head 
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
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
    head->data=7;               //  (*head).data=7
    head->next=second;          //(*head).next=second

    second->data=11;
    second->next=third;

    third->data=98;
    third->next=NULL;

    Traversal(head);
}