#include <iostream>
#include <cstring>
using namespace std;

template <class T>
void maxN(int n,T arr[])
{
    const int N = n;
    struct count
    {
        int type_num;
        int counts[50];
        T list[50];
    };
    count jojo;
    jojo.type_num = 0;
    memset(jojo.counts,0,sizeof(jojo.counts));
    int flag;
    for(int i=0;i<n;i++)
    {
        flag = 1;
        for(int j=0;j<jojo.type_num;j++)
        {
            if(jojo.list[j] == arr[i]) 
            {
                flag = 0;
                jojo.counts[j]++;
            }
        }
        if(flag)
        {
            jojo.type_num++;
            jojo.list[jojo.type_num-1] = arr[i];
            jojo.counts[jojo.type_num-1]++;
        }
    }
    int max = -1,max_idx;
    for(int i=0;i<jojo.type_num;i++)
    {
        if(jojo.counts[i] > max)
        {
            max = jojo.counts[i];
            max_idx = i;
        }
    }
    cout << jojo.list[max_idx] << " " << max << endl;
}

int main(){

    int t,num;
    char opcode;
    cin >> t;
    while(t--)
    {
        cin >> opcode >> num;
        if(opcode == 'I')
        {
            int arr[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr[i];
            }
            maxN(num,arr);
        }
        else if(opcode == 'C')
        {
            char arr[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr[i];
            }
            maxN(num,arr);
        }
        else if(opcode == 'S')
        {
            string arr[num];
            for(int i=0;i<num;i++)
            {
                cin >> arr[i];
            }
            maxN(num,arr);
        }
    }

    return 0;
}