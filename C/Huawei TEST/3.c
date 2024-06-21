#include<stdio.h>
int main(void){

    long n,x;
    scanf("%d %d",&n,&x);
    int Bit;
    int N=0;
    int Bit10 = n%10;//个位数
    int B1 = Bit10;
    int Bit100 = n%100;//十位数
    int B2 = (Bit100-Bit10)/10;
    int Bit1000 = n%1000;//百位数
    int B3 = (Bit1000 - Bit100 - Bit10)/100;
    int Bit10000 = n%10000;//千位数
    int B4 = (Bit10000 - Bit1000 - Bit100 - Bit10)/1000;
    int Bit100000 = n%100000;//万位数
    int B5 = (Bit100000 - Bit10000 - Bit1000 - Bit100 - Bit10)/10000;
    int Bit1000000 = n%1000000;//十万位数
    int B6 = (Bit1000000 - Bit100000 - Bit10000 - Bit1000 - Bit100 - Bit10)/100000;



    if(B1 >= x) N++;
    int A = N;
    if(B2 > x) N = N+9+B2;
    int B = N;
    if(B2 = x) N = N+(B1+1)+B2;
    int C = N;
    if(B2 < x) N = N+B2;
    int D = N;
    printf("%d",N);






            










    return 0;
}