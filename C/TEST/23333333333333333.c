#include<stdio.h>
int main(){

    int x=1;
    int y=2;
    if(!x)
        y = y+1;
    else if(x=0)
        if(x)
            y = y + 2;
        else    
            y = y + 3;
    printf("%d\n%d",x,y);
    return 0;
}