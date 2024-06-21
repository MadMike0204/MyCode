#include<stdio.h>
int main(){

    long int m;
    scanf("%c",&m);
    switch(m){
        case 'A':
            printf("一个学期的努力给你带来了应有的收获");
            break;
        case 'B':
            printf("你与成功还缺少了一点契机");
            break;
        case 'C':
            printf("保底已到，力争上游");
            break;
        case 'D':
            printf("失败与你只是一步之遥，莫一失足成千古恨");
            break;
        case 'F':
            printf("一次失败代表不了什么，请从头再来");
            break;
    }


    return 0;
}