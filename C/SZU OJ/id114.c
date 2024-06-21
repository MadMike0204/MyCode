#include<stdio.h>
int main(){

    int M[3];
    scanf("%d %d %d",&M[0],&M[1],&M[2]);
    int max=M[0];
    int i;
    for(i=0;i<3;i++)
    {
        if(max<M[i])
            max = M[i];
    }
    printf("%d",max);

    return 0;
}