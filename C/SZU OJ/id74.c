#include<stdio.h>
int main(){

    int a,b;
    scanf("%d %d",&a,&b);
    int count = 0;
    if(a%b == 0)
        count += 1;
    else
        count += 100;
    if(b%a == 0)
        count += 3;
    else
        count += 300;
    
    switch(count)
    {
        case 301:
            printf("1");
            break;
        case 103:
            printf("2");
            break;
        case 4:
            printf("3");
            break;
        case 400:
            printf("4");
            break;

    }
    
    return 0;
}