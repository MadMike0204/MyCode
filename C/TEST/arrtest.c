#include<stdio.h>

int Sum(int* arr,int length)
{
    int i,sum=0;
    for(i=0;i<length;i++)
    {
        sum += *(arr+i);
    }
    return sum;
}

int main(){

    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    printf("%d",Sum(arr,10));

    return 0;
}