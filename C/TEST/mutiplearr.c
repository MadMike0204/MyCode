#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stuffing(int* arr,int L1,int L2)
{
    int i;
    for(i=0;i<L1*L2;i++)
    {
        *(arr+i) = rand();
    }
    for(i=0;i<L1*L2;i++)
    {
        printf("(%d,%d)\n",*(arr+i/5),*(arr+i));
    }
    return 0;
}

int main(){

    int arr[5][5] = {1,[0][3] = 5,3};
    int a2rr[10];
    memset(a2rr,'a',sizeof(a2rr));

    return 0;
}