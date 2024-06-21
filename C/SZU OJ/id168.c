#include<stdio.h>
#include<math.h>
int main(){

    const double precision = 0.00000001;
    int n;
    scanf("%d",&n);
    int k,num;
    double temp1,temp2,delta;
    int i,j,l;
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        for(j=k;j<200;j++)
        {
            temp1 = 1.0/j;
            for(l=j;l<200;l++)
            {
                temp2 = 1.0/l;
                delta = fabs(temp1+temp2-(1.0/k));
                if(delta < precision)
                {
                    printf("1/%d=1/%d+1/%d\n",k,l,j);
                }
            }
        }
    }
    return 0;
}