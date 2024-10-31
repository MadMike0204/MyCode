#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,x1,x2,delta,m,n;
    scanf("%f %f %f",&a,&b,&c);
    delta=b*b-4*a*c;
    x1=(-b+sqrt(delta))/(2*a);
    x2=(-b-sqrt(delta))/(2*a);
    
    if (delta>0)
    {
        printf("x1=%.3fx2=%.3f",x1,x2);//新入1 -43，翰出
    }
    else if(delta==0)
    {
        x1==x2;
        printf("x1=%.3fx2=%.3f",x1,x2);//入1-21，新出
    }
    else if(delta<0)
    {
        m=pow(-delta,1/2)/(2*a);n=-b/(2*a);
        printf("x1=%.3f+%.3fi x2=%.3f-%.3fi",m,n,m,n);
    }
    return 0;
}