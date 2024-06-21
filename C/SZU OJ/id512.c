/*
题目描述
手机号是一个11位长的数字串。
同时，大家可以申请加入校园网，
如果加入成功，你将另外拥有一个短号。
假设所有的短号都是是 6+手机号的后5位，比如号码为13512345678的手机，对应的短号就是645678。
自定义函数，参数为手机号（字符串），该手机号为合法手机号，则计算该手机号的短号，并用数组传回。
返回1；否则返回0。主函数定义两个串，手机号串和短号串，调用该函数，输出error或得到的短号。
合法手机号判断：11位数字，前三位为：
中国电信：133，153， 180，181，189
中国联通：130，131，132，155，156
中国移动：134，135，136，137，138，182，183，184
（为简化，上述三位数字省去了一些。）
输入
第一行：测试次数
每组测试数据一行，手机号
输出
对每组测试数据，调用函数，根据返回结果，若为1，输出对应短号；若为0，输出error。
*/
#include<string.h>
#include<stdio.h>

static int Short_Num[6];

int ShortNum(const char str[]);

int main(){

    char str[13];
    memset(str,0,sizeof(str));
    int t,i,len;
    scanf("%d",&t);
    while(t>0)
    {
        scanf("%s",str);
        len = strlen(str);
        if(ShortNum(str) && len == 11)
        {
            for(i=0;i<6;i++)
            {
                printf("%d",Short_Num[i]);
            }
            printf("\n");
        }
        else
        {
            printf("error\n");
        }
        t--;
    }

    return 0;
}

int ShortNum(const char str[])
{
    int Head[3],head,flag = 0;
    int i;
    for(i=0;i<3;i++)
    {
        Head[i] = str[i] - '0';
    }
    head = Head[0] * 100 + Head[1] * 10 + Head[2];
    switch(head)
    {
        case 133:
        case 153:
        case 180:
        case 181:
        case 189:
        case 130:
        case 131:
        case 132:
        case 155:
        case 156:
        case 134:
        case 135:
        case 136:
        case 137:
        case 138:
        case 182:
        case 184:
        case 183:
            flag = 1;
            break;
    }
    if(flag)
    {
        Short_Num[0] = 6;
        for(i=1;i<6;i++)
        {
            Short_Num[i] = str[i+5] - '0';
        }
        return 1;
    }
    else   
        return 0;
}