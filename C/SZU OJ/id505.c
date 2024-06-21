#include <stdio.h>
#include <string.h>
#define SIZE 10
//请补充itostr函数的实现
void itostr(int num, char str[])
{
/********** Write your code here! **********/
    if(num > 0)
    {
        int i,bit = 0,x = num,k = 1;
        for(i=0;;i++)
        {
            if(x < 10)
            {
                bit++;
                break;
            }
            else if(x > 10)
            {
                x /= 10;
                bit++;
            }
        }
        printf("%d\n",bit);
        x = num;
        while(1)
        {
            if(x > 0 && x < 10)
                break;
            x /= 10;
        }
        str[bit-1] = x + '0';
        if(bit >= 2)
        {
            for(i=1;i<bit;i++)
            {
                k *= 10;
            }
            num -= k * x;
            itostr(num,str);
        }
    }


/*******************************************/
}
int main()
{
    int t,num;
    char str[SIZE];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &num);
        itostr(num,str);
        printf("%s\n",str);
    }
}