#include<stdio.h>
#include<string.h>
int main(){

    char see[10] = "Hello~~OwO";
    char saw[6] = "32323";
    strncpy(saw,see,5);
    saw[5] = 0;
    printf("%s",saw);

    return 0;
}