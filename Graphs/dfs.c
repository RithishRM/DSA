#include<stdio.h>
#include<stdlib.h>

//Instead of Inizializing a Stack we use the systems in-built heap logic through function Recursion 

int visited ={0,0,0,0,0,0,0};
int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
};

void DFS(int i){
    printf("%d",i);
    visited[i]=1;
    for ( int j=0;j<7;j++){
        if(a[i][j]==1 && visited[j]==0){    //[i] is the current node wrt we checking for other nodes in the array 
            DFS(j);
        }
    }
}

int main(){
    //DFS Implementation
    DFS(0); //We starting with 0
    return 0;
}