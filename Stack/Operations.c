#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr ;
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

void Push(struct stack *s,int value){
    if (isFull(s)){
        printf("Stack Overflow");
    }else{
        s->top++;
        s->arr[s->top]=value;
    }
}

int Pop(struct stack * s){
    if(isEmpty(s)){
        return -1;
    }else{
        int val=s->arr[s->top];     //Through this we are storing as it will be lost when we change it
        s->top=s->top-1;            //By reducing the top we will overwrite the next time we do any operation 
        return val;
    }
}

int Peek(struct stack * s,int i){           //'i' here is the Position we want
    if ((s->top)-i+1<0){
        printf("Enter Valid Element!!!");       //Array Index = Top - Position(i) + 1
        return -1;                              //Postion=      1   2   3
    }else{                                      //Array Index=  2   1   0
        return s->arr[s->top-i+1];
    }
}

int main(){
    struct stack * s=(struct stack *)malloc(sizeof(struct stack));      //NOTE- Always Allocate it this Dynamically in Heap
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int));
    Push(s,7);
    Push(s,9);
    // int i=Pop(s);
    // printf("The Poped Element is %d\n",i);
    // int i=Peek(s,1);
    // printf("The Peeked Element is %d\n",i);
    //For Printing The Entire Stack 
    for(int i=1;i<=s->top+1;i++){
        printf("The Element in Position %d is %d\n",i,Peek(s,i));
    }

}