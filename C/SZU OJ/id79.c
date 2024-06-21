#include<stdio.h>
#include<math.h>
int main(){

    const int base = 8;
    const int overwt = 4;
    const int hurry = 5;
    int ifhurry=0,weight,fee,k1,k2,owt;
    char yOn;
    scanf("%d %c",&weight,&yOn);
    if((weight-1000)>0)
        owt = ceil((weight*1.0-1000)/500);
    else 
        owt = 0; 
    fee = owt*overwt + base;  
    if(yOn == 'y')
        printf("%d",fee+hurry);
    else    
        printf("%d",fee);

    return 0;
}