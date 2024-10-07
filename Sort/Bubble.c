// In Bubble Sort the different Pass's are done by pushing the greatest elements to last possible each pass.
// 1st Pass -Biggest Element goes last
// 2nd Pass -Second Largest goes 2nd last
//..    Goes till n-1 Pass (where n is number of elements)
// Time Complexity-O(n^2)
// It is Stable Algorithm
// It is Not Adaptive by default but it can be made adaptive

#include <stdio.h>

void print(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubble(int *A, int n)
{
    int temp;
    int isSorted=0;
    for (int i = 0; i < n - 1; i++)
    { // n-1 As the Last Pass Wont Run cause the array is sorted by then-For Passes
        isSorted=1; //This makes the code Adaptive by Not doing unnessaray passes in Sorted Array
        for (int j = 0; j < n - i - 1; j++)
        { // For Comparison in each Pass
            if (A[j] > A[j + 1])
            {
                temp = A[j + 1];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted=0;
            }
        }
        if(isSorted){
            return ;
        }
    }
}

int main()
{
    int A[5] = {7, 1, 9, 3, 4};
    print(A, 5);
    bubble(A,5);
    print(A,5);
}