#include <iostream>
#include <string>
using namespace std;
int main(){

    int arr[6]={0},a,b,c,temp;
    char str[6][25] = {"Not triangle",
    "Right triangle",
    "Acute triangle",
    "Obtuse triangle",
    "Isosceles triangle",
    "Equilateral triangle"};
    scanf("%d %d %d",&a,&b,&c);
    int i,j;
    int ar[3] = {a,b,c};
    for(j=0;j<2;j++)
    {
        for(i=0;i<2;i++)
        {
            if(ar[i] < ar[i+1])
            {
                temp = ar[i];
                ar[i] = ar[i+1];
                ar[i+1] = temp;
            }
        }
    }

    if(ar[1] + ar[2] <= ar[0])
    {
        arr[0] = 1;
    }
    else
    {
        if(ar[1] * ar[1] + ar[2] *ar[2] == ar[0] * ar[0])
        {
            arr[1] = 1;
        }
        if(ar[1] * ar[1] + ar[2] *ar[2] > ar[0] * ar[0])
        {
            arr[2] = 1;
        }
        if(ar[1] * ar[1] + ar[2] *ar[2] < ar[0] * ar[0])
        {
            arr[3] = 1;
        }
        if(ar[0] == ar[1] || ar[1] == ar[2])
        {
            arr[4] = 1;
        }
        if(ar[0] == ar[1] && ar[1] == ar[2])
        {
            arr[5] = 1;
        }
    }
    for(i=0;i<6;i++)
    {
        if(arr[i] == 1)
        {
            printf("%s\n",str[i]);
        }
    }

    return 0;
}