#include <iostream>
#include <cstring>
using namespace std;

class compute;
class person
{
    friend compute;
    private:
        char name[10];
        char num[10];
    private:
        person()
        {
            memset(name,0,sizeof(num));
            memset(num,0,sizeof(num));
        }
        void SetName(char* name_in)
        {
            strcpy(name,name_in);
        }
        void SetNum(char* num_in)
        {
            strcpy(num,num_in);
        }
};
class compute
{
    private:
        person pn[3];
    public:
        void setdata()
        {
            char name_in[10],num_in[10];
            for(int i=0;i<3;i++)
            {
                cin >> name_in >> num_in;
                pn[i].SetName(name_in);
                pn[i].SetNum(num_in);
            }
        }
        void sort()
        {
            person temp;
            int flag;
            for(int i=0;i<2;i++)
            {
                for(int j=i+1;j<3;j++)
                {
                    flag = 0;
                    for(int m=0;m<9;m++)
                    {
                        if(pn[i].name[m] > pn[j].name[m])
                        {
                            flag = 1;
                            break;
                        }
                        if(pn[i].name[m] || pn[j].name[m] == 0)
                        {
                            break;
                        }
                    }
                    if(flag == 1)
                    {
                        temp = pn[i];
                        pn[i] = pn[j];
                        pn[j] = temp;
                    }
                }
            }
        }
        void print()
        {
            for(int i=0;i<3;i++)
            {
                cout << pn[i].name << " " << pn[i].num << endl;
            }
        }
};

int main(){

    compute JOJO;
    JOJO.setdata();
    JOJO.sort();
    JOJO.print();

    return 0;
}