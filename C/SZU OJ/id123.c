#include<stdio.h>
int main(){

    int start,end;
    int a[4]= {153,370,371,407};
    scanf("%d %d",&start,&end);
    int i;
    for(i=0;i<4;i++)
    {
        if(a[i]<=end && a[i]>=start)
        {
            printf("%d\n",a[i]);
        }
    }

    return 0;
}