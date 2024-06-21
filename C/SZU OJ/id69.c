#include<stdio.h>
int main(){

    int h1,m1,s1,h2,m2,s2,h,m,s;
    char pp;
    scanf("%d%c%d%c%d",&h1,&pp,&m1,&pp,&s1);
    scanf("%d%c%d%c%d",&h2,&pp,&m2,&pp,&s2);
    int count1,count2,count;
    count1 = h1*3600+m1*60+s1;
    count2 = h2*3600+m2*60+s2;
    count = count1 - count2;
    h = count/3600;
    m = (count - h*3600)/60;
    s = count -h*3600-m*60;
    printf("%d:%d:%d",h,m,s);

    return 0;
}