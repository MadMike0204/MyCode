#include<stdio.h>
int main(){

    int n;
    scanf("%d",&n);
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int sum = 0;
    int L,R;
    scanf("%d %d",&L,&R);
    L -= 2;
    R -= 1;
    while(L != R)
    {
        L++;
        sum += arr[L];
    }
    printf("%d",sum);

    return 0;
}