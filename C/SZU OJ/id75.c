#include<stdio.h>
int main(){

    int a,b,c;
    char motion,equal;
    scanf("%d%c%d%c%d",&a,&motion,&b,&equal,&c);
    printf("%d%c%d%c%d ",a,motion,b,equal,c);
    int ifresult=0,ifmotion=0;
    switch(motion)
    {
        case '+':
        {
            ifmotion = 1;
            if(c == (a+b))
                ifresult = 1;
            break;
        }
        case '-':
        {
            ifmotion = 1;
            if(c == (a-b))
                ifresult = 1;
            break;
        }
        case '*':
        {
            ifmotion = 1;
            if(c == (a*b))
                ifresult = 1;
            break;
        }
        case '/':
        {
            ifmotion = 1;
            if(c == (a/b))
                ifresult = 1;
            break;
        }
        case '%':
        {
            ifmotion = 1;
            if(c == (a%b))
                ifresult = 1;
            break;
        }
        default:
            printf("error op");
    }
    if(ifresult == 1)
        printf("correct");
    else if(ifresult == 0 && ifmotion == 1)
        printf("wrong");
    return 0;
}