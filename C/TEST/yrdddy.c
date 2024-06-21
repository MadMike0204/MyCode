#include<stdio.h>
int main(){

    char x[8] = "1234567";
    char* p = x;
    *p = 0;
    *(p+1) = 0;
    printf("%c",x[1]);

    return 0;
}