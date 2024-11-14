#include<stdio.h>
int main()
{   int x,y,i,T,n,m,num1,num2,num3,num4,max,min;
    num1=0;
    num2=0;
    num3=0;
    num4=0;

    scanf("%d",&T);

    for(i=1;i<=T;i++)
    {
        scanf("%d",&n);
        if(n>6&&n%2==0)
	    {
	        for(y=0;y<=n/4;y++)
	        {
                if((n-4*y)/2>=0) //&&(n-4*y)%2==0
	                num3=y;
	            num4=(n-4*y)/2;
	        }
		    min=num3+num4;
		    printf("%d ",min);
            
	        for(x=0;x<=n;x++)
	        {
                if((n-2*x)/4>=0 && (n-2*x)%2 == 0)
	                num1=x;
			    num2=(n-2*x)/4; // 兔子
			}

		    max=num1+num2;
		    printf("%d\n",max);
		}
	    else
	        printf("0 0\n"); 
	}

    printf("%d",-2%2 == 0);
	return 0;

}