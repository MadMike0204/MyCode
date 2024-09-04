#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

template<class T>
class SqList
{
    private:
        static int default_max_length;
        int length;
        int max_length;
        T* list;
    public:
        SqList(int l):length(l),list(nullptr){}
        ~SqList()
        {

        }
        void InitSqList()
        {
            list = new T[max_length = default_max_length];
            memset(list,0,sizeof(list));

            for(int i=0;i<length;i++)
            {
                cin >> list[i];
            }
            return;
        }
        int InsertSqList(int idx,T value)
        {
            if(idx > length+1 || idx <= 0)
            {
                cout << "error" << endl;
                return -1;
            }
            //如果插入位置有效，开始倒着移动1位
            for(int i=length-1;i>=idx-1;i--)
            {
                list[i+1] = list[i];
            }
            list[idx-1] = value;
            length++;
            return 1;
        }
        int RemoveSqList(int idx)
        {
            if(idx > length+1 || idx <= 0)
            {
                cout << "error" << endl;
                return -1;
            }
            list[idx-1] = -1;
            for(int i=idx-1;i<length-1;i++)
            {
                list[i] = list[i+1];
            }
            length--;
            return 1;
        }
        void PrintSqList()
        {
            cout << length << " ";
            for(int i=0;i<length;i++)
            {
                cout << list[i] << " ";
            }
            cout << endl;
        }
        T SearchSqList(int idx)
        {
            if(idx > length || idx <= 0)
            {
                cout << "error" << endl;
                return -1;
            }
            return list[idx-1];
        }
        int MultiInsert(int idx,int n,int item[])
        {
            int p = 0;
            
            for(int i=length+n-1;i>=idx-1;i--)
            {
                list[i] = list[i-n];
            }
            for(int i=idx-1;i<idx-1+n;i++)
            {
                list[i] = item[p];
                p++;
            }
            length += n;
            return 1;
        }
        int MultiDelete(int idx,int n)
        {
            for(int i=idx-1;i<idx-1+n;i++)
            {
                list[i] = list[i+n];
            }
            length -= n;
            return 1;
        }
};
template<class T> int SqList<T>::default_max_length = 1000;

// void test()
// {
//     SqList<int> JO(6);
//     JO.InitSqList();
//     JO.PrintSqList();

//      int item[5] = {8,7,9,5,0};
//      JO.MultiInsert(1,5,item);
//      JO.MultiDelete(2,3);
//     JO.PrintSqList();
// }

int main(){
    
    int n;
    cin >> n;
    SqList<int> JO(n);
    JO.InitSqList();
    JO.PrintSqList();

    int idx,k;
    cin >> idx >> k;
    int item[k];
    for(int i=0;i<k;i++)
    {
        cin >> item[i];
    }
    JO.MultiInsert(idx,k,item);
    JO.PrintSqList();


    cin >> idx >> k;
    JO.MultiDelete(idx,k);
    JO.PrintSqList();

    return 0;
}