#include <iostream>
#include <stdlib.h>
using namespace std;

void qsort(void* base,int nelem,//base:数组起始地址,nelem:元素个数
           unsigned int width,//width:每个元素占的字节大小
           int(*point_toFuncton_Compare)(const void *,const void *));
           /*函数指针,指向一个比较函数,比较函数规则：
           elem1应该排在elem2后面 返回正整数
           反之 返回负整数
           都行,返回0*/
int Compare_Big(const void * elem1,const void * elem2);

int main(){

    return 0;
}

void qsort(void* base,int nelem,
           unsigned int width,
           int(*point_toFuncton_Compare)(const void *,const void *))
{

}

int Compare_Big(const void * elem1,const void * elem2)
{
    int *pointer_to_num1,*pointer_to_num2;
    pointer_to_num1 = (int*) elem1;
    pointer_to_num2 = (int*) elem2;
    return (*pointer_to_num2 - *pointer_to_num1);
}
