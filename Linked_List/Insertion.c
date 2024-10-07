#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
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

//Insertion-Case 1 -To insert in the Begining Of the Linked list 

struct Node * Insert_at_first(struct Node * head,int data){         //This is function that returns a structure Pointer which here is head
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}

//Insertion -Case 2-To insert at a an index 

struct Node * Insert_at_index(struct Node *head,int data ,int index){
    struct Node * ptr =(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head ;
    int i=0;
    while(i!=index-1){          //Its index-1 as we want p to be one index before where we want to add 
        p=p->next;  
        i++; 
    }
    ptr->next=p->next;
    ptr->data=data;
    p->next=ptr;
    return head ;
}

//Insertion Case 3-To Insert in the End 

struct Node * Insert_end(struct Node * head ,int data){
    struct Node * ptr =(struct Node *)malloc(sizeof(struct Node ));
    struct Node * p=head;
    while(p->next!=NULL){
        p=p->next ;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head ;
}

//Inserion Case 4-To insert after a give Node 

struct Node * Insert_node(struct Node * head,struct Node * p,int data ){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node ));
    ptr->next = p->next ;
    p->next =ptr;
    ptr->data=data;
    return head;
}

int main(){
    struct Node *head,*second,*third;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    head->data=12;
    head->next=second;
    second->data=13;
    second->next=third;     //  (*second).next=third
    third->data=89;
    third->next=NULL;
    //head = Insert_at_first(head,56);
    //head=Insert_at_index(head,34,2);
    //head=Insert_end(head,23);
    head=Insert_node(head,second,78);
    Traversal(head);
    return 0;
}