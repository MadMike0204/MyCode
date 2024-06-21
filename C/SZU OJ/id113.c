#include<stdio.h>
int main(){

    int m,n;
    scanf("%d",&m);
    n = m/10;
    switch (n)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("E");
            break;
        case 6:
            printf("D");
            break;
        case 7:
            printf("C");
            break;
        case 8:
            printf("B");
            break;
        case 9:
        case 10:
            printf("A");
            break;
    }

    return 0;
}