#include<stdio.h>
int main(){

    double num;
    scanf("%lf",&num);
    while(1)
    {
        num *= 4;
        num += 4;
        num /= 2;
        num -= 2;
        num /= 2;
        num --;
        if(num == 0)
        {
            break;
        }
    }

    return 0;
}