#include<stdio.h>
#include<string.h>
int main(){

    char x[200];
    memset(x,0,sizeof(x));
    int i;
    for(i=0;;i++)
    {
        scanf("%c",&x[i]);
        if(x[i] == 10)
            break;
    }
    int alpha=0,num=0,space=0,other=0;
    for(i=i-1;i>=0;i--)
    {
        switch(x[i])
        {
            case 65 ... 90:
                alpha++;
                break;
            case 48 ... 57:
                num++;
                break;
            case 97 ... 122:
                alpha++;
                break;
            case 32:
                space++;
                break;
            default:
                other++;
        }
    }
    printf("%d %d %d %d",alpha,num,space,other);

    return 0;
}