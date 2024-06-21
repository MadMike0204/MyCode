#include<stdio.h>
int main(){

    int m;
    scanf("%d",&m);
    switch(m)
    {
        case 1:
        case 3:
        case 5:
        {
            printf("NO");
            break;
        }
        default:
        {
            printf("YES");
        }

    }

    return 0;
}