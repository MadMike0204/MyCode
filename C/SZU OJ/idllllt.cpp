#include<stdio.h>
int main(){

    int h,n,i;
    double H,sum;
    sum = 0;
    scanf("%d %d",&h,&n);
    H=h;
    for(int i=2;i<=n;i++)
    {
        H = H/2.0;
        H = (int)((H*1000+5)/10)/100.0;
        sum += 2*H;
        sum = (int)((sum*1000+5)/10)/100.0;
    }
    double a,b;

    a = sum+h;
    sum = (int)((a*1000+5)/10)/100.0;
    H /= 2.0;
    b = (int)((H*1000+5)/10)/100.0;

    printf("%.2f\n%.2lf",a,b);
    return 0;
}