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

bool settleElementHash(int key,int length,int hashSet[])
{
    int hash = getHash(key);
    int i;
    for(int attempts = 1;attempts < length;attempts++)
    {
        i = (hash + (attempts/2) * (attempts/2) * ((attempts%2) ? -1 : 1) + length) % length;
        if(hashSet[i] == EMPTY)
        {
            hashSet[i] = key;
            return 1;
        }
    }
    return false; // 哈希表已满
}

hashFindResult hashFind(int key,int length,int hashSet[])
{
    bool found = 0;
    int time = 0;
    int location = 0;
    int hash = getHash(key);
    int i;
    for(int attempts = 1;attempts < length;attempts++)
    {
        time++;
        i = (hash + (attempts/2) * (attempts/2) * ((attempts%2) ? -1 : 1) + length) % length;
        // cout << "time:" << time << " i:" << i << " attempts:" << attempts << " key:" << key << endl;
        if(hashSet[i] == EMPTY)
            break;
        if(hashSet[i] == key)
        {
            location = i+1;
            found = 1;
            break;
        }
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