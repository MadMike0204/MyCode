#include<string.h>
#include<stdio.h>
int main(){

    char c1[50],c2[50];
    memset(c1,0,sizeof(c1));
    memset(c2,0,sizeof(c2));
    scanf("%s",c1);
    strcpy(c2,c1);
    int i;
    for(i=0;i<50;i++)
    {
        switch(c2[i])
        {
            case 'a' :
            case 'e' :
            case 'i' :
            case 'o' :
            case 'u' :
                printf("%c",c2[i]);
                break;
            default :
                continue;
        }
    }

    return 0;
}