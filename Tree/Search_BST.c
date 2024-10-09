#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * left ;
    struct Node * right ;
};

struct Node * createNode (int data){
    struct Node * n=(struct Node *)malloc(sizeof(struct Node ));
    n->left=NULL;
    n->right=NULL;
    n->data=data;
}

int  Search(struct Node * root,int val){           //This Function is Used to Check wheather a given val is in the BST 
    if(root==NULL){
        return 0;
    }
    if(root->data==val){
        return 1;
    }else if(root->data > val){
        return Search(root->left,val);
    }else{
        return Search(root->right,val);
    }
}

//Using Interative Search instead of Recursive Search

struct Node * IterSearch(struct Node * root,int val){
    while(root!=NULL){
        if(root->data==val){
            return root ;
        }else if (root->data>val){
            root=root->left;
        }else{
            root=root->right;
        }
    }
    return  NULL;
}