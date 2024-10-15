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

void Insert(struct Node * root,int key){
    struct Node * prev=NULL;
    while(root!=NULL){
        prev=root;
        if(root->data==key){
            printf("Already Exists in Tree => Cant't be added!!");
            return ;
        }else if(root->data>key){
            root=root->left;
        }else{
            root=root->right;
        }
    }
    struct Node * new=createNode(key);
    if(prev->data>key){
        prev->left=new;
    }else{
        prev->right=new;
    }
    
}