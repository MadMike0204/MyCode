#include<stdio.h>
int main()
{
    int n;
    long GiveMillionair = 0,Stranger = 0,temp = 1;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
    {
        GiveMillionair += 100000;
        Stranger += temp;
        temp *= 2;
    }
    printf("%ld\n%ld",GiveMillionair,Stranger);

    return 0;
}