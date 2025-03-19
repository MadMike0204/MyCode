// 根据主函数，补齐input,output,find_ele函数和头文件
/********** Write your code here! **********/
#include<iostream>
using namespace std;
void input(int* arr,int m){
    for(int i=0;i<m;i++){
        cin >> arr[i];
    }
}
void output(int* arr,int m){
    for(int i=0;i<m;i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}
int& find_ele(int* arr,int m){
    int target = m-1;
    for(int i=0;i<m;i++){
        if(arr[i] % 2 == 0){
            target = i;
            break;
        }
    }
    return arr[target];
}
/*******************************************/
int main()
{
    int *num, m, t;
    cin >> t;
    while (t--)
    {
        cin >> m;
        // 为数组num动态分配m个整数空间
/********** Write your code here! **********/
        num = new int[m];
/*******************************************/
		input(num, m); // 输入m个数组元素
        find_ele(num, m) *= 2;
        output(num, m); // 输出m个数组元素
        delete[] num;
    }
    return 0;
}