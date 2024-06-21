#include<stdio.h>
int sWap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(void){

    int x,y;
    scanf("%d %d",&x,&y);
    sWap(&x,&y);
    printf("%d %d",x,y);

    return 0;
}