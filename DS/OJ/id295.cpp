#include<iostream>
#include<cmath>
#define SIZE 100
using namespace std;

struct IndexType{
    int maxKey;
    int startPostion;
};
struct SearchInfo{
    int searchTime;
    int position;
};

class SSTable{
private:
    int length;
    int blockNum;
    int blockLength;
    int* element;
    IndexType* indexTable;
public:
    SSTable();
    ~SSTable();
    void initSStable();
    void initIndexTable();
    SearchInfo blockSearchElementByKey(int key);
};
SSTable::SSTable(){

    element = new int[SIZE];
    length = 0;
    blockNum = 0;
    blockLength = 0;
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
void SSTable::initIndexTable(){

    cin >> blockNum;
    blockLength = ceil(length*1.0 / blockNum); // 求最小分块
    indexTable = new IndexType[blockNum];
    
    for(int i=0;i<blockNum;i++){
        cin >> indexTable[i].maxKey;
        indexTable[i].startPostion = i*blockLength + 1;
    }
}
SearchInfo SSTable::blockSearchElementByKey(int key){

    SearchInfo info = {0,0};

    int searchTime = 0; // 记录查找次数
    int index = -1;

    for(int i=0;i<blockNum;i++){
        searchTime++;
        if(key <= indexTable[i].maxKey){
            index = i;
            break;
        }
    }

    if(index == -1)
        return info; // 超过上界 结束 
    
    int startPosition = indexTable[index].startPostion;

    for(int i=0;i<blockLength;i++){
        searchTime++;
        if(key == element[startPosition+i]){
            info.position = startPosition + i;
            info.searchTime = searchTime;
            break;
        }
    }
    return info; // 块内 找到/没找到 结束
}

int main(){

    SSTable jojo;
    jojo.initSStable();
    jojo.initIndexTable();
    int t,key,rt;
    cin >> t;
    while(t--){

        cin >> key;
        SearchInfo info = jojo.blockSearchElementByKey(key);
        if(info.position)
            cout << info.position << "-" << info.searchTime << endl;
        else
            cout << "error" << endl;
    }
}
