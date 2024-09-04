#include <iostream>
#include <memory>
using namespace std;

template<class T>
class SqList
{
    private:
        static int default_max_length = 100;
        int length;
        int max_length;
        T* list;
    public:
        SqList(int l,int m):length(l),max_length(m),list(nullptr){}
        ~SqList()
        {
            if(list) delete[] list;
        }
        int InitSqList()
        {
            list = new T[max_length = default_max_length];
            if(list) return -1;
            length = 0;
            return 0;
        }
        int InsertSqList(int idx)
        {
            
        }
};

