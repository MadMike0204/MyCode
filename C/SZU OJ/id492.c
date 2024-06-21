#include<string.h>
#include<stdio.h>

void Motion(const int A[],const int MotionD,const int N)
{
    int i,k;
    k = N-MotionD;
    for(i=0;i<N;i++)
    {
        if(k == N)
            k = 0;
        printf(i==0? "%d":" %d",A[k]);
        k++;
    }
    printf("\n");
    return;
}

int main()
{
    int num[88];
    int i,n,D,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    scanf("%d",&D);
    Motion(num,D,n);
    return 0;
}