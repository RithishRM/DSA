#include <stdio.h>
#define SIZE 10

struct Node {
    int data;
    int flag;
};

void ini_HashT(struct Node * HashTAble){
    for(int i=0;i<SIZE;i++){
        HashTAble[i].data=0;
        HashTAble[i].flag=0;
    }
}

void insert(int key,struct Node * HashTable){
    int hash ,i=0;
    hash=((key%SIZE)+i) % SIZE;
    while(HashTable[hash].flag!=0 && i<SIZE){
        i++;    //Increment i value
        hash=((key%SIZE)+i)%SIZE;
    }
    if(HashTable[hash].flag==0 ){
        HashTable[hash].data=key;
        HashTable[hash].flag=1;
    }else{
        printf("\nData cannot be inserted\n");
    }
}

void search(int key ,struct Node * HashTable){
    int hash , i=0;
    hash=((key %SIZE)+i)%SIZE;
    while(i<SIZE){
        if(HashTable[hash].data == key && HashTable[hash].flag == 1)
        {
            printf("\nThe data %d is found at location %d\n", key, hash);
            return;
        }
        i++;
        hash=((key %SIZE)+i)%SIZE;
    }
    printf("\nData not found\n");
}

void disp(struct Node * HashTable){
    printf("\nHash Table:\n");
    for(int i=0;i<SIZE;i++){
        if(HashTable[i].flag==1){
            printf("Index %d: %d\n", i, HashTable[i].data);
        }else{
            printf("Index %d: EMPTY\n", i);
        }
    }
}

int main()
{
    struct Node  hashTable[SIZE];
    ini_HashT(hashTable);

    insert(5, hashTable);
    insert(15, hashTable);
    insert(25, hashTable);
    insert(49, hashTable);
    insert(59, hashTable);
    disp(hashTable);

    search(15, hashTable); // Should find the data
    search(35, hashTable); // Should not find the data

    return 0;
}