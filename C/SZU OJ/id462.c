#include<stdio.h>
#include<string.h>

void Josegh(int m,int n)
{
    int arr[m];
    memset(arr,0,sizeof(arr));
    int i;
    int count = 0,alive = m;
    for(i=0;;i++)
    {
        if(alive == 0)
        {
            printf("\n");
            return;
        }
        if(i == m)
            i = 0;
        if(arr[i] == 1)
            continue;

        count++;
        count %= n;
        if(count == 0)
        {
            arr[i] = 1;
            alive--;
            printf(alive == (m-1)?"%d":" %d",i+1);
        }
    }
}

int main(){

    int m,t,n;
    scanf("%d",&t);
    while(t > 0)
    {
        scanf("%d %d",&m,&n);
        Josegh(m,n);
        t--;
    }

    return 0;
}