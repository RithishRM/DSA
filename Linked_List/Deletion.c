#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data ;
    struct Node * next;
};

void Traversal(struct Node * ptr){
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

//Case 1:Deleting the First Node 

struct Node * Delete_at_first(struct Node * head){
    struct Node * ptr=head;     
    head=head->next;
    free(ptr);
    return head;
}

//Case 2 :This is to Delete a Node in between the LIst

struct Node * Delete_In_between(struct Node * head,int ind){
    struct Node * p=head;
    int i=0;
    while(i!=ind-1){
        p=p->next;
        i++;
    }
    struct Node * q=p->next;
    p->next=q->next;
    free(q);
    return head;
}

//Case 3 :Delete the Last Node 

struct Node * Delete_last(struct Node * head){
    struct Node * p=head;
    while (p->next->next != NULL){        //next->next....Here indicates the next nodes next should be NULL
        p=p->next;  //Finds The Second Last Node 
    }
    struct Node * q=p->next;
    p->next =NULL;
    free(q);
    return head;
}

//Case 4:Delete a Node with the Given Value (It only deletes the first Ocurence Of the Value)

struct Node * Delete_with_value(struct Node * head,int value){
    struct Node * p=head;
    struct Node * q=head->next;
    while(q->data != value && q->next != NULL ){
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
        p->next=q->next;
        free(q);
    }
    return head;
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));;
    head->data=1;
    head->next =second;
    second->data=5;
    second->next=third;
    third->data=8;
    third->next=NULL;
    head=Delete_with_value(head,9);
    Traversal(head);
}