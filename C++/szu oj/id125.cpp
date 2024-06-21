#include <iostream>
#include <string>
#include <string.h>
using namespace std;

bool isAllNum(char* num,int leng)
{
    int flag = 1;
    for(int i=0;i<leng;i++)
    {
        if(*(num+i) >= '0' && *(num+i) <= '9')
        {}
        else
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

class CCTel
{
    private:
        char* telnum;
        int isupgraded = 0;
    public:
        CCTel()
        {
            isupgraded = 0;
            telnum = new char[10];
            memset(telnum,0,10*sizeof(char));
            string temp;
            cin >> temp;
            for(int i=0;i<7;i++)
            {
                char x = temp[i];           
                telnum[i] = x;
            }
        }
        CCTel(CCTel &p)
        {
            int strlen = 0;
            for(int i=0;i<10;i++)
            {
                if(*(p.telnum+i) == 0)
                {
                    break;
                }
                strlen++;
            }
            if(strlen == 7)
            {
                bool flag = 1;
                for(int i=0;i<7;i++)
                {
                    if(*(p.telnum+i) < '0' || *(p.telnum+i) > '9')
                    {
                        flag = 0;
                    }
                }
                if(!flag)
                {
                    cout << "Illegal phone number" <<endl;
                }
                else
                {
                    telnum = new char[10];
                    memset(telnum,0,10*sizeof(char));
                    switch(p.telnum[0])
                    {
                        case '2':
                        case '3':
                        case '4':
                            telnum[0] = '8';
                            for(int i=1;i<8;i++)
                            {
                                telnum[i] = p.telnum[i-1];
                            }
                            PrintTel();
                            break;
                        case '5':
                        case '6':
                        case '7':
                        case '8':
                            telnum[0] = '2';
                            for(int i=1;i<8;i++)
                            {
                                telnum[i] = p.telnum[i-1];
                            }
                            PrintTel();
                            break;
                        default:
                            cout << "Illegal phone number" << endl;
                    }
                    isupgraded = 1;
                }    
            }
            else
            {
                cout << "Illegal phone number" << endl;
            }
        }
        void PrintTel()
        {
            for(int i=0;i<8;i++)
            {
                cout << telnum[i];
            }
            cout << endl;
        }
};

int main(){

    int t;
    cin >> t;
    while(t > 0)
    {
        CCTel newnew;
        CCTel upgraded_newnew(newnew);
        t--;
    }

    return 0;
}