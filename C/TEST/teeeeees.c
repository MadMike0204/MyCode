#include<stdio.h>
int main(){

    char str[5] = "AVCX";
    char* To_str = &str[2];
    printf("%s",To_str);

    return 0;
}