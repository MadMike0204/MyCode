#include<stdio.h>
int main()
{  
    int n;
    scanf("%d",&n);
    for(int i=1; i <=n; i++)
    {  
        int max=0,min=100000000;
        int a;
        scanf("%d",&a);
        for(int j=1; j<=a/2; j++)
        {
            int b=0;
            b=(a-2*j)/4;
            if (b+j>=max)
            {
                max=b+j;
            }
            if (b+j<=min)
            {
                min=b+j;
            }
        }
        if (a%2!=0)
        {
            min=0;max=0;
        }
        printf("%d %d\n",min,max);
    }


}
