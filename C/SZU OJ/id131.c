

#include<stdio.h>
int main(void){
    int n; 

        for(n=1;;n++){
            if(n%5==1 && n%6==5 && n%7==4 && n%11==10 ){
                printf("%d",n);
                break;
            }
        }
        
    return 0;
}