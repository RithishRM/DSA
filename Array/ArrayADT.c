#include<stdio.h>
#include<stdlib.h>

struct myArr{
    int total_size;     //memory to reserved
    int used_size;      //memory to used
    int *ptr;           //pointer points to first element
    //This ptr gives Heap memory 
};

void createarray(struct myArr* a,int ts,int us){
    // (*a).total_size=ts;
    // (*a).used_size=us;
    // (*a).ptr= (int*)malloc(ts*sizeof(int));     //In heap we use malloc to dyanmically point towards the first element
    a->total_size=ts;
    a->used_size=us;
    a->ptr=(int*)malloc(ts*sizeof(int));
}

void show(struct myArr *a){     //prints the value
    for (int  i = 0; i < a->used_size; i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
    
}

void putval(struct myArr *a){       //To take values in
    int n;
    for (int  i = 0; i < a->used_size; i++)
    {
        printf("Enter %d Element:",i);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
    
}

int main(){
    struct myArr marks;
    createarray(&marks,10,2);     //We're making an marks with total size 100 and used size 20
    putval(&marks);
    show(&marks);
    return 0;
}