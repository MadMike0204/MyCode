#include<iostream>
using namespace std;
#define MAXLENGTH 1000
#define INVALID -999
class SL{
private:
    int length;
    int* data;
public:
    SL()
    {
        data = new int[MAXLENGTH];
        for(int i=0;i<MAXLENGTH;i++)
        {
            data[i] = INVALID;
        }
    }
    void initialList(int length)
    {
        this->length = length;
        for(int i=0;i<length;i++)
        {
            cin >> data[i];
        }
    }
    int searchLocation(int loc)
    {
        if(data[loc] != INVALID)
            return data[loc];
        return INVALID;
    }
    int insertData(int loc,int num)
    {
        if(length == MAXLENGTH)
            return INVALID;
        int index = loc-1;
        for(int i=length-1;i>=index;i--)
        {
            data[i+1] = data[i];
        }
        data[index] = num;
    }
    int (int loc)
    {

    }
};


int main(){



    return 0;
}