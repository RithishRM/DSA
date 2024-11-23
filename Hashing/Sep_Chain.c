#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node * next;
};

struct Hash{
    int count ;
    struct Node *head;
};

struct Node * newnode(int key){
    struct Node * nn=(struct Node *)malloc(sizeof(struct Node));
    nn->data=key;
    nn->next=NULL;
    return nn;
}

// Insert key into the hash table
void insert(int key,struct Hash * HashTable){
    int hash=key%SIZE;  //k mod n ; n here is the size  
    struct Node * nn=newnode(hash);
    nn->next=HashTable[hash].head;
    HashTable[hash].head=nn;
    HashTable[hash].count++;
}

// Search for a key in the hash table
void search(int key ,struct Hash * HashTable){
    int hash = key%SIZE,pos=1;
    struct Node * nn=HashTable[hash].head;
    while(nn){
        if(nn->data==key){
            printf("Found at Index %d in Position %d\n",hash,pos);
        }
        pos++;
        nn=nn->next;
    }
    printf("Data not found\n");
}

// Delete a key from the hash table
void del(int key , struct Hash * HashTable){
    int hash=key%SIZE;
    struct Node * n=HashTable[hash].head,*prev=NULL;
    while(n){
        if(n->data==key){
            if(prev){
                prev->next=n->next;
            }else{
                HashTable[hash].head=n->next;
            }
            free(n);
            HashTable[hash].count--;
            printf("\nData deleted successfully\n");
            return ;
        }
        prev=n;
        n=n->next;
    }
    printf("\nData not found\n");
}

void disp(struct Hash *HashTable ){
    for(int i=0;i<SIZE;i++){
        if(HashTable[i].count!=0){
            printf("Index %d:\n",i);
            struct Node * n=HashTable[i].head;
            while(n){
                printf("%d\n",n->data);
                n=n->next;
            }
        }
    }
}

// Main function to initialize the hash table and test the operations
int main() {
    struct Hash HashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        HashTable[i].count = 0;
        HashTable[i].head = NULL;
    } 
    insert(10, HashTable);
    insert(20, HashTable);
    insert(15, HashTable);
    insert(30, HashTable);
    insert(47, HashTable);
    insert(65, HashTable);
    //insert(60, HashTable);
    disp(HashTable);
    search(20, HashTable);
    del(10, HashTable);
    disp(HashTable);
    return 0;
}