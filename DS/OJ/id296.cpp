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
    int binarySearchElementByKey(int key);
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

int SSTable::binarySearchElementByKey(int key){
    // 初始化折半查找的上下界和中点
    int high = length;
    int low = 1;
    int mid = (low+high)/2;
    // 输入的数据假定顺序表已经有序化 升序
    while(1){
        if(low > high)
            return 0; // 查找失败
        if(key == element[mid])
            return mid;
        else if(key < element[mid])
            high = mid - 1;
        else if(key > element[mid])
            low = mid + 1;
    }
}

int main(){



    return 0;
}