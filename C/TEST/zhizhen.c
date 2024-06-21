#include<stdio.h>
int main(void){

    short* Por;
    short m = 999;
    short** Lor;
    Por = &m;
    Lor = &Por;
    m = *Por +1;
    char a[] = "language",*p;

p = a;

while(*p != 'u') { printf("%c",*p-32); p++;}


    return 0;
}
/*个人认为学习指针最好的方法应该是打开visual studio
写几行简单的指针变量代码，设断点
打开调试窗口下的监视和内存窗口
将移位操作、强制类型转换、结构体、sizeof、数组类型
都亲自动手试一遍
对内存窗口下每个将要操作的内存地址单元的变化进行合理预测
这样来理解效果应该是比较清晰直观的*/