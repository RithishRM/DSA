#include<stdio.h>

int insertion(int arr[],int size,int capacity,int index,int ele){
    if(size>=capacity){
        return -1;
    }else{
        for(int i=size-1;i>=index;i--){
            arr[i+1]=arr[i];        //This for loop is to move the existing elements by 1 index 
        }
        arr[index]=ele;
        return 1;
    }
}

void del(int arr[],int index,int size){
    for(int i=index;i<size-1;i++){
        arr[i+1]=arr[i];
    }
}

int main(){
    int arr[100]={1,4,3,8,7};
    int size=5,element=11,index=2,capacity=100;
    insertion(arr,size,capacity,index,element);
    del(arr,index,size);
    return 0;
}