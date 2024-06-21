#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int MaxSubsequenceSum(const int A[],int n){
    int ThisSum,MaxSum,j;

    ThisSum = MaxSum = 0;
    for(j=0;j<n;j++)
    {
        ThisSum += A[j];

        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}

int main(){

    srand(time(NULL));
    int n = 14;
    int arr[14] = {2,5,6,7,8,1,2,3,5,6,5,2,9,6};
    int i;
/*    for(i=0;i<n;i++)
    {
        arr[i] = rand() % 10 +0;
    }
    */
    printf("%d",MaxSubsequenceSum(arr,n));


    return 0;
}