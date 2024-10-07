#include<stdio.h>

int linear(int arr[],int size,int element){
    for(int i=0;i<=size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;      //This is return case if element wasn't found
}

int binary(int arr[],int size,int ele){
    int low,mid,high;
    low=0;
    high=size-1;
    while(low<=high){
        mid=low+high/2;
        if(arr[mid]==ele){
            return mid;
        }else if(arr[mid]<ele){
            low=mid+1;  //The +1 is so that the mid should'nt be included as we know its not there  
        }else{
            high=mid-1; //The -1 is so that the mid should'nt be included as we know its not there  
    }
}}

int main(){
    // int arr[]={1,3,2,5,90,98,76,33};
    // int size = sizeof(arr)/sizeof(int);
    // int ele=900;
    // int search_index=linear(arr,size,ele);
    // printf("The Element %d was found in %d",ele,search_index);

}