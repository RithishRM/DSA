#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size ;
    char * arr;
};

int isEmpty(struct stack * s ){
    if (s->top==-1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(struct stack * s){
    if (s->top==(s->size)-1){
        return 1 ;
    }else{
        return 0;
    }
}

void Push (struct stack * s,char value ){
    if (isFull(s)){
        printf("Stack Overflow!!");
    }else{
        s->top++;
        s->arr[s->top]=value;
    }
}

char Pop(struct stack * s ){
    if ( isEmpty(s)){
        printf("Stack Underflow!!");
    }else{
        char val=s->arr[s->top];
        s->top=(s->top)-1;
        return val;
    }
}

int Parenthesis_match(char * exp){
    //We are inizializing a Stack for the expression
    struct stack * s;
    s->top=-1;
    s->size=100;
    s->arr=(char *)malloc(s->size *sizeof(char));

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            Push(s,'(');
        }else {
            if(isEmpty(s)){
                return 0;
            }
            Pop(s);
        };
    }
    if(isEmpty(s)){
        return 1;
    }
}

int main(){
    char * e= "a*b(k*1))(";
    if (Parenthesis_match(e)) {
        printf("The parentheses are Balanced\n");
    } else {
        printf("The parentheses are not Balanced\n");
    }
}