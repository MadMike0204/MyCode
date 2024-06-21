/*大减小（默认第一个数据大于第二个数据）*/
#include <stdio.h>
#include <string.h>
int main()
{
    char s1[3000],s2[3000];//准备字符串，收集数字
    scanf("%s%s",s1,s2);
    int a[3000],b[3000],c[3000];//准备数组 储存数字
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int l1 = strlen(s1);//测量数字长度
    int l2 = strlen(s2);//测量数字长度
    int i,j;
    for(i=0,j=l1-1;i<l1;i++,j--)//i和j的变化方向相反 即可达到反向输出
    {
        a[i] = s1[j] - '0';
    }
    /*char数组储存的是ascii码 
    需要转化为十进制数储存起来*/
    for(i=0,j=l2-1;i<l2;i++,j--)
    {
        b[i] = s2[j] - '0';
    }/*第二个数字*/
    int len = 0;
    if(l1>l2)//判断总共需要多长的字符串
    {
        len = l1;
    }
    else
    {
        len = l2;
    }
    for(i=0;i<len;i++)//减法
    {
        c[i] = a[i] - b[i];
    }
    for(i=0;i<len;i++)//退位操作（对嘛对嘛对嘛对嘛))))))
    {
        if(c[i]<0)
        {
            c[i+1] -= 1;
            c[i] += 10;
        }
    }
    i = 2999;//判断运算后的数组长度 
    while(c[i]==0 && i>0)
    {
        i--;
    }
    for(j=i;j>=0;j--)//从不是0的一位开始输出（因为整个数是反向的 第一位数必定不等于0）
    {
        printf("%d",c[j]);
    }
    return 0;
}