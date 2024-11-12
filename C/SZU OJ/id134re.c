#include <stdio.h>
int main(){

    char alpha;
    char max = 'z'; // 最弱的字母作为初始值

    while(scanf("%c",&alpha)){
        if(alpha == '\n') // 判断输入是否结束
            break;

        if(alpha < max)  // 更新最强字母
            max = alpha;
    }
    printf("%c",max);
    
    return 0;
}