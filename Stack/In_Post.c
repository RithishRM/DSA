#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//For Converting A Infix to Postfix -First Put Operators Until a operator with lower or equal precedence is not encountered and write operatant as seperate expression,If encountered Pop the Operatores from stack and write in Expression.

struct stack {
    int top;
    int size ;
    char * arr; 
};

int isFull(struct stack * s){
    if (s->top==s->size-1){
        return 1 ;
    }else{
        return 0;
    }
}

int isEmpty(struct stack * s){
    if (s->top==-1){
        return 1;
    }else{
        return 0;
    }
}

void Push (struct stack * s,char val){
    if (isFull(s)){
        printf("Stack Overflow!!!");
    }else{
        s->top++;
        s->arr[s->top]=val;
    }
}

char Pop(struct stack * s){
    if (isEmpty(s)){
        printf("Stack Underflow!!");
    }else{
        char val = s->arr[s->top];
        s->top=s->top-1;
        return val;
    }
}

int Prec(char ch){      //This Precedence Function is Only usable if operators in Expression are Basic.
    if (ch=='*' || ch=='/'){
        return 3;
    }else if(ch=='+' || ch=='-'){
        return 2;
    }else{
        return 0;
    }
}

int isoperator(char ch){
    if (ch=='*' || ch=='/' || ch=='+' || ch=='-'){
        return 1;
    }
}

char * In_Post(char * Infix){
    struct stack * s=(struct stack *)malloc(sizeof(struct stack));      //We have to make a stack instance 
    s->size=10;
    s->top=-1;
    s->arr=(char *)malloc(s->size * sizeof(char));
    char * pos= (char *)malloc((strlen(Infix)+1) * sizeof(char));
    int i=0;    //Infix Scanner 
    int j=0;    //Postfix Filler
    while(Infix[i]!='\0'){
        if (!isoperator(Infix[i])){    //This if loop is only for operant 
            pos[j]=Infix[i];
            i++;
            j++;
        }else{
            if(Prec(Infix[i])>Prec(s->arr[s->top])){
                Push(s,Infix[i]);
            }else{
                pos[j]=Pop(s);
                j++ ;
            }
        }
    }
    if(!isEmpty(s)){
        pos[j]=Pop(s);
        j++;
    }
    pos[j]='\0';
    return pos;
}

int main(){
    char * in="a+b*c*d-e";
    printf("The Postfix is %s",In_Post(in));
    return 0;
}



//ERROR IN CODE WILL FIX IT LATER   