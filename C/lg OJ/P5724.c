#include<stdio.h>
#include<math.h>
int main(void){

    int n;
    int num[101];
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    int max=num[0],min=num[0];
    for(i=0;i<n;i++)
    {
        if(num[i] < min)
            min = num[i];
    }
    for(i=0;i<n;i++)
    {
        if(num[i] > max)
            max = num[i];
    }
    printf("%d",max-min);

    return 0;
}