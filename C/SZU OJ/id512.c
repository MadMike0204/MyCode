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
#include<math.h>

static int first3[18] = { // 存放合法的前三位
    130,131,132,133,134,135,136,137,138,
    153,155,156,
    180,181,182,183,184,189
};

int ShortNum(const char str[],int result[6]);

int main(){

    char str[13]; // 存放手机号
    int t,i,len;
    scanf("%d",&t);
    int result[6];
    while(t--)
    {
        scanf("%s",str);
        len = strlen(str); // 获取字符串长度

        // 判断手机号是否合法
        if(ShortNum(str,result) && len == 11){ 
            
            for(i=0;i<6;i++){
                printf("%d",result[i]);
            }
            printf("\n");
        }
        else{
            printf("error\n");
        }
    }
    return 0;
}

int ShortNum(const char str[],int result[6])
{   
    int head = 0;
    int i;

    // 将前三位变成int类型三位数 与我们设置的静态变量一致
    for(i=0;i<3;i++){
        head += (str[i] - '0') * (int)pow(10,2-i);
    }
    // 判断是否合法 由于数据比较少 遍历搜索就行
    int flag = 0; // 是否找到
    for(int i=0;i<18;i++){
        if(head == first3[i]){
            flag = 1;
            break; // 提前结束
        }
    }
    // 如果合法 就计算短号
    if(flag)
    {
        result[0] = 6;
        for(i=1;i<6;i++)
        {
            result[i] = str[i+5] - '0';
        }
        return 1;
    }
    // 不合法退出
    return 0;
}