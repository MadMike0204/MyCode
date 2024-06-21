#include<stdio.h>
int main(){

    int m;
    short a,b,c;
    scanf("%d",&m);
    switch(m)
    {
        case 100 ... 1000:
        {
            a = m/100;
            c = m%10;
            b = (m-a*100-c)/10;
            if(m == (c*c*c+b*b*b+a*a*a))
                printf("1");
            else
                 printf("0");
            break;
        }
        default:
            printf("ERROR");
    }

    return 0;
}