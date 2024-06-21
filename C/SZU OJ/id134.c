#include<stdio.h>
#include<string.h>
int main(){

    char x[80],y[40],z[40];
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    memset(z,0,sizeof(z));
    
    int i,j=0;
    int m=0,n=0,bo=0;
    for(i=0;i<80;i++)
    {
        scanf("%c",&x[i]);
        if(x[i] == 10)
            break;
    }
    for(i=i-1;i>=0;i--)
    {
        switch(x[i])
        {
            case 97 ... 122:
                if(bo == 1)
                    break;
                y[m] = x[i];
                m++;
                break;
            case 65 ... 90:
                z[n] = x[i];
                n++;
                bo = 1;
                break;
        }
    }
    char temp1 = 'z';
    char temp2 = 'Z';
    if(bo != 1)
    {
        for(m=m-1;m>=0;m--)
        {
            if(y[m] < temp1)
                temp1 = y[m];
        }
        printf("%c",temp1);
    }
    else
    {
        for(n=n-1;n>=0;n--)
        {
            if(z[n] < temp2)
                temp2 = z[n];
        }
        printf("%c",temp2);
    }
    
    return 0;
}