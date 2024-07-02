#include <iostream>
#include <iomanip>
using namespace std;

class Cstudent
{
    private:
        bool state;
        string id,name,birthday;
        double score;
    public:
        Cstudent()
        {
            score = 0;
            id = "null";
            name = "null;";
            birthday = "null";
            state = 0;
        }
        void Set(string id)
        {
            state = 1;
            cin >> name >> birthday >> score;
            this->id = id;
            string temp;

            for(int i=0;i<4;i++)
            {   
                temp += birthday[i];
            }
            temp += '_';
            
            if(birthday[6] != '0')
            {
                temp += birthday[6];
            }
            temp += '_';

            if(birthday[8] != '0')
            {
                temp += birthday[8];
            }
            temp += birthday[9];
            birthday = temp;
        }
        void Print()
        {
            cout << "id:" << id  << " name:" << name << " "
                 << "birthday:" << birthday << " "
                 << "score:" << fixed << setprecision(1) << score << endl;
        }
        bool GetState()
        {
            return state;
        }
        string GetId()
        {
            return id;
        }
};

int main(){

    int t;
    bool flag;
    string id;
    cin >> t;
    Cstudent jojo[t];
    for(int i=0;i<t;i++)
    {
        flag = 0;
        cin >> id;
        for(int j=0;j<t;j++)
        {
            
            if(jojo->GetState())
            {
                if(id == jojo[j].GetId())
                {
                    jojo[j].Set(id);
                    flag = 1;
                    break;
                }
            }
        }
        if(!flag)
        {
            jojo[i].Set(id);
        }
    }
    for(int i=0;i<t;i++)
    {
        if(jojo[i].GetState())
        {
            jojo[i].Print();
        }
    }

    return 0;
}