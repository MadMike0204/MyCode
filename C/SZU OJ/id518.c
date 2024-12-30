#include<stdio.h>
#include<string.h>
void MaxLenWord(char s[]){
    int maxLength = 0;
    int length = strlen(s);
    int maxCount = 0; // 记录最大长度的字符串有多少个

    int counter;
    for(int i=0;i<length;i++){
        if(s[i] == ' ' || s[i] == '\n') // 检测空格
        {
            if(counter > maxLength)
            {
                maxLength = counter;
                maxCount = 1;
            }
            else if(counter == maxLength)
            {
                maxCount++;
            }
            counter = 0;
            continue;
        }
        counter++;
    }

    for(int i=0;i<length;i++){
        if(s[i] == ' ' || s[i] == '\n')
        {
            if(counter == maxLength)
            {
                maxCount--;
                printf((maxCount==0)?"%.*s":"%.*s ",maxLength,s+i-maxLength);
            }
            counter = 0;
            continue;
        }
        counter++;
    }
    printf("\n");
}

int main(){

    int t;
    scanf("%d",&t);
    getchar();
    char str[100];
    while(t--){
        // fgets保留换行符
        fgets(str,sizeof(str),stdin);
        MaxLenWord(str);
    }

    return 0;
}