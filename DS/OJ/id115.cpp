#include <iostream>
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
        SqList(int l,int m = SqList::default_max_length):length(l),max_length(m),list(nullptr){}
        ~SqList()
        {
        }
        void InitSqList()
        {
            list = new T[max_length = default_max_length];
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
        int Combine2(int n,int m,int* a,int* b)
        {
            int i,j,k;
            bool flag;
            length = n + m;
            i = j = k = 0;
            while(i < length)
            {   
                flag = 0; // 0 = a, 1 = b
                if(j<n && k<m)
                {
                    if(a[j] > b[k]) 
                        flag = 1;
                    if(flag)
                    {
                        list[i] = b[k];
                        k++;
                    }
                    else
                    {
                        list[i] = a[j];
                        j++;
                    }
                }
                else if(j<n)
                {
                    list[i] = a[j];
                    j++;
                }
                else if(k<m)
                {
                    list[i] = b[k];
                    k++;
                }
                i++;
            }
            return 1;
        }
};
template<class T> int SqList<T>::default_max_length = 1000;

int main(){

    int n,m;
    cin >> n;
    int arr1[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr1[i];
    }
    cin >> m;
    int arr2[m];
    for(int i=0;i<m;i++)
    {
        cin >> arr2[i];
    }
    
    SqList<int> JO(0);
    JO.InitSqList();
    JO.Combine2(n,m,arr1,arr2);
    JO.PrintSqList();

    return 0;
}