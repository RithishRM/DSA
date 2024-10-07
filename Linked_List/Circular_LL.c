#include<stdio.h>
#include<stdlib.h>
 
struct Node{
    int data;
    struct Node * next;     
};

void Traversal(struct Node * head){      
    struct Node * ptr=head;
    // printf("%d\n",ptr->data);   
    // ptr=ptr->next;
    // while(ptr != head){             //Since the while loop won't start itself as ptr = head....This why we print first elements through the above 2 lines 
    //     printf("%d\n",ptr->data);   
    //     ptr=ptr->next;
    //      }   
    do{             //Since the while loop won't start itself as ptr = head....This why we print first elements through the above 2 lines 
         printf("%d\n",ptr->data);   
         ptr=ptr->next;
    }while(ptr != head);
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
    third->next=head;

    Traversal(head);
}