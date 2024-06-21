#include<math.h>
#include<stdio.h>
int main(void){

    const double prcs = 0.001;
    double a,b,c;
    int x=0,y=0;
    scanf("%lf%lf%lf",&a,&b,&c);
    if(fabs(a-b)<prcs) 
        x++;
    if(fabs(c-b)<prcs) 
        x++;
    if(fabs(a-c)<prcs) 
        x++;
    if(fabs(sqrt(a*a+b*b)-c)<prcs)
        x+=10;
    if(fabs(sqrt(c*c+b*b)-a)<prcs)
        x+=10;
    if(fabs(sqrt(a*a+c*c)-b)<prcs)
        x+=10;
    if(a+b<c||a+c<b||b+c<a)
        x = 12;
    if(fabs(a+c-b)<prcs||fabs(a+b-c)<prcs||fabs(c+b-a)<prcs)
        x = 12;
    switch(x)
        {
            case 0:
                printf("普通三角形");
                break;
            case 1:
                printf("等腰三角形");
                break;
            case 2:
                printf("等边三角形");
                break;
            case 3:
                printf("等边三角形");
                break;
            case 10:
                printf("直角三角形");
                break;
            case 11:
                printf("等腰直角三角形");
                break;
            case 12:
                printf("非三角形");
                break;
        }

    return 0;
}
//浮点数比较用fabs函数