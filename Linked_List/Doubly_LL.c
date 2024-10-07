#include <stdio.h>
#include<stdlib.h>

struct Node{
    struct Node * prev;
    int data ;
    struct Node * next;
};

void Trav_rev(struct Node * head){
    struct Node * p=head;
    while(p->next!=NULL){
        printf("%d<->",p->data);
        p=p->next;
    };
    printf("%d",p->data);
    printf("\n");
    while(p->prev!=NULL){
        printf("%d<->",p->data);
        p=p->prev;
    }
    printf("%d",p->data);
}

int main(){
    struct Node * N1=(struct Node *)malloc(sizeof(struct Node));
    struct Node * N2=(struct Node *)malloc(sizeof(struct Node));
    struct Node * N3=(struct Node *)malloc(sizeof(struct Node));
    struct Node *N4=(struct Node *)malloc(sizeof(struct Node));

   N1->prev = NULL;
    N1->data = 23;
    N1->next = N2;

    N2->prev = N1;
    N2->data = 42;
    N2->next = N3;

    N3->prev = N2;
    N3->data = 13;
    N3->next = N4;

    N4->prev = N3;
    N4->data = 36;
    N4->next = NULL;
    Trav_rev(N1);
}
