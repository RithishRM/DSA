#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;       //Max size of the stack
    int top;
    int * arr;      //This is used to Dynamically allocate memory to stack
};

int isEmpty(struct stack * p){
    if(p->top==-1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct stack * p){
    if(p->top==(p->size)-1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    //struct stack S;
    // S.size=80;
    // S.size=-1;      //This denotes the stack is empty
    // S.arr=(int *)malloc(S.size * sizeof(int)); 
    
    struct stack *S;       //Making it structure pointer helps in making it easier for passing in function argument 
    S->size=80;
    S->top=-1;
    S->arr=(int *)malloc(S->size * sizeof(int) );

}