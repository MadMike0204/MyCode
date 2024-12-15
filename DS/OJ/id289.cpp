#include<iostream>
#include<string.h>
using namespace std;

#define EMPTY -123 

struct hashFindResult
{
    bool found; // 是否找到 0 | 1
    int time;   // 比较次数 >= 0
    int location; // 查找到的位置 >= 1
    hashFindResult(bool fd,int t,int loc):found(fd),time(t),location(loc){}
};

int getHash(int key)
{
    return key % 11;
}
bool settleElementHash(int key,int length,int hashhSet[])
{
    bool ifSettled = 0;
    int hash = getHash(key);
    int i = hash;
    while(!ifSettled)
    {   // 判断
        if(hashhSet[i] == EMPTY)
        {
            hashhSet[i] = key;
            ifSettled = 1;
            break;
        }
        // 探测增量
        i++;
        i %= length;
        // 是否已经遍历一遍
        if(i == hash)
            break;
    }
    return 0;
}

bool settleElementHash(int key,int length,int hashSet[])
{
    int hash = getHash(key);
    int i = hash;
    for(int attempts = 0;attempts < length;attempts++)
    {
        if(hashSet[i] == EMPTY)
        {
            hashSet[i] = key;
            return 1;
        }
        i = (i + 1) % length; // 增量公式
    }
    return false; // 哈希表已满
}

hashFindResult hashFind(int key,int length,int hashSet[])
{
    bool found = 0;
    int time = 0;
    int location = 0;
    bool ifTraverse = 0;
    int hash = getHash(key);
    int i = hash;
    while(!found)
    {
        time++;
        if(ifTraverse) // 遍历完成
            break;
        if(hashSet[i] == EMPTY) // 判断为空
        {
            break;
        }
        else if(hashSet[i] == key) // 遍历找到
        {
            found = 1;
            location = i+1;
            break;
        }
        // 没找到 增量
        i++;
        i %= length;
        // 判断是否已经遍历一遍
        if(i == hash)
            ifTraverse = 1;
        
    }
    return hashFindResult(found,time,location);
}

int main(){

    int t,m,n,k,key;
    cin >> t;
    while(t--)
    {   
        cin >> m >> n;
        // 初始化
        int hashSet[m];
        for(int i=0;i<m;i++)
        {
            hashSet[i] = EMPTY;
        }
        // 填充
        for(int i=0;i<n;i++)
        {
            cin >> key;
            settleElementHash(key,m,hashSet);
        }
        // 输出哈希表
        for(int i=0;i<m-1;i++)
        {
            if(hashSet[i] != EMPTY)
                cout << hashSet[i] << " ";
            else
                cout << "NULL ";
        }
        if(hashSet[m-1] != EMPTY)
            cout << hashSet[m-1];
        else
            cout << "NULL";
        cout << endl;
        // 哈希表查找
        cin >> k;
        for(int i=0;i<k;i++)
        {
            cin >> key;
            hashFindResult result = hashFind(key,m,hashSet);
            if(result.found)
                cout << result.found << " " << result.time << " " << result.location << endl;
            else    
                cout << result.found << " " << result.time << endl;
        }
    }
    
    return 0;
}