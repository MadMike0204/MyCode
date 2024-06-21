#include<stdio.h>
#include<stdbool.h>
int main(void){

    int N=0;
    scanf("%d\n",&N);
    for(int i=0;i<N;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        bool m = (a+c>c && b==c);
        printf("%d\n",m);
    }

    return 0;
}