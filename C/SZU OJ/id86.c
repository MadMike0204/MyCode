#include<stdio.h>
int main(){

    int a,b,c;
    char operation;
    scanf("%d %d %c",&a,&b,&operation);
    switch(operation)
    {
        case '+':
            c = a+b;
            printf("%d",c);
            break;
        case '-':
            c = a-b;
            printf("%d",c);
            break;
        case '*':
            c = a*b;
            printf("%d",c);
            break;
        case '/':
            if(b == 0)
            {
                printf("Divided by zero!");
            }
            else
            {   
                c = a/b;
                printf("%d",c);
            }
            break;
        default:
            printf("Invalid operator!");

    }

    return 0;
}