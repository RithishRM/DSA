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

void PreOrder(struct Node * root){
    if(root!=NULL){
        printf("%d\n",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(struct Node * root){
    if(root!=NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d\n",root->data);
    }
}

void InOrder(struct Node * root){
    if(root!=NULL){
        InOrder(root->left);
        printf("%d\n",root->data);
        InOrder(root->right);
    }
}

int main(){
    struct Node * p=createNode(7);
    struct Node * p1=createNode(11);
    struct Node * p2=createNode(77);
    struct Node * p3=createNode(80);
    struct Node * p4=createNode(9);
    struct Node * p5=createNode(58);

    //Linking
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->right=p5;

    InOrder(p);

    return 0;
}