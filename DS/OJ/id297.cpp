/*
    *静态查找: 顺序查找 + 哨兵优化
    *哨兵优化: 查找时从末尾开始，将idx=0设为key,返回结果不为0则查找成功
              在循环中不需要循环终止条件,减少计算量
*/
#include<iostream>
#define SIZE 100
using namespace std;

class SSTable{
private:
    int length;
    int* element;
public:
    SSTable();
    ~SSTable();
    void initSStable();
    int sequentialSearchElementByKey(int key);
};
SSTable::SSTable(){

    element = new int[SIZE];
    length = 0;
}
SSTable::~SSTable(){

    if(element != nullptr)
        delete[] element;
}
void SSTable::initSStable(){

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> element[i];
    }
    length = n;
}
int SSTable::sequentialSearchElementByKey(int key){

    element[0] = key;
    for(int i=length;;i--){
        if(element[i] == key)
            return i;    
    }
}

int main(){

    SSTable jojo;
    jojo.initSStable();
    int k,key,result;
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> key;
        result = jojo.sequentialSearchElementByKey(key);
        if(result == 0)
            cout << "error" << endl;
        else
            cout << result << endl;
    }

    return 0;
}