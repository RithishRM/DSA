#include<stdio.h>
#include<stdlib.h>

struct Node {
    struct Node * left;
    int data;
    struct Node * right ;
};

struct Node * createNode(int data){
    struct Node * n=(struct Node *)malloc(sizeof(struct Node));
    n->left=NULL;
    n->right=NULL;
    n->data=data;
    return n;
}

int main(){
    //Construct Tree Manually without Function-But this causes Repetition of lines
    // struct Node * p=(struct Node * )malloc(sizeof(struct Node));
    // p->left=NULL;
    // p->right=NULL;
    // p->data=7;

    // struct Node * p1=(struct Node * )malloc(sizeof(struct Node));
    // p1->left=NULL;
    // p1->right=NULL;
    // p1->data=11;

    // struct Node * p2=(struct Node * )malloc(sizeof(struct Node));
    // p2->left=NULL;
    // p2->right=NULL;
    // p2->data=70;

    // p->left=p1;
    // p->right=p2;

    //Construct Root Node with Function 
    struct Node * p=createNode(7);
    struct Node * p1=createNode(11);
    struct Node * p2=createNode(77);

    //Linking
    p->left=p1;
    p->right=p2;

    return 0;
}