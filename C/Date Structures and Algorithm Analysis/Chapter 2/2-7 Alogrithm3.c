#include<stdio.h>
#include<stdlib.h>

int swap(int* x,int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    return 0;
}

static int Max3(int x,int y,int z)
{
    int arr[3] = {x,y,z};
    int i,j,temp;
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<3;j++)
        {
            if(arr[j] < arr[i])
                swap(arr+j,arr+i);
        }
    }
    return arr[2];
}

static int MaxSubSum(const int A[],int left,int right){
    int MaxLeftSum,MaxRightSum;
    int MaxLeftBorderSum,MaxRightBorderSum;
    int LeftBorderSum,RightBorderSum;
    int Center,i;

    if(left == right)
        if(A[left] > 0)
            return A[left];
        else
            return 0;

    Center = (left + right) / 2;
    MaxLeftSum = MaxSubSum(A,left,Center);
    MaxRightSum = MaxSubSum(A,Center+1,right);

    MaxLeftBorderSum = 0,LeftBorderSum = 0;
    for(i=Center;i>=left;i--)
    {
        LeftBorderSum += A[i];
        if(LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }

    MaxRightBorderSum = 0,RightBorderSum = 0;
    for(i=Center+1;i<=right;i++)
    {
        RightBorderSum += A[i];
        if(RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }

    return Max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubsequenceSum(const int a[],int N){
    return MaxSubSum(a,0,N-1);
}

int main(){

    int n = 14;
    int arr[14] = {2,5,6,7,8,1,2,3,5,6,5,2,9,6};
    int i;
/*    for(i=0;i<n;i++)
    {
        arr[i] = rand()  + 0;
    }*/
    printf("%d",MaxSubsequenceSum(arr,n));

    return 0;
}