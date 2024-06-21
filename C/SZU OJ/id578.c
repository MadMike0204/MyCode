#include<stdio.h>

int main()
{
     int i;
     char w[][10]={"susan","peter","jack","mary"};
     for(i=1;i<3;i++)
          printf("%s\t",w[i]);
     printf("\n");
}