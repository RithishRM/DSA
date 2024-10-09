#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node * left;
    int data;
    struct Node * right ;
} Node;
struct Node * createNode(int data){
    struct Node * n=(struct Node *)malloc(sizeof(struct Node));
    n->left=NULL;
    n->right=NULL;
    n->data=data;
    return n;
}
void InOrder(struct Node * root){
    if(root!=NULL){
        InOrder(root->left);
        printf("%d\n",root->data);
        InOrder(root->right);
    }
}

int isBST(Node * root){
    if(root==NULL){
        return 1;
    }
    if(root->left!=NULL && root->left->data>root->data){    
        return 0;
    }
    if(root->right!=NULL && root->right->data>root->data){
        return 0;
    }
    return isBST(root->left) && isBST(root->right);     //This && denotes the return statement but Compares left and right and then returns 1 or 0 by AND logic
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
    printf("%d",isBST(p));
    return 0;
}