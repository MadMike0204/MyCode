#include <iostream>
#include <vector>
using namespace std;

class Newnew
{
    private:
        static int alive_count;
        static int final_year;
        static int now_year;
        int age;
    public:
        Newnew()
        {
            alive_count++;
            age = 1;
        }
        ~Newnew()
        {
            alive_count--;
        }
        bool isGiveBirth()
        {
            if(age <= 11 && age >= 4)
                return 1;
            else 
                return 0;
        }
        bool isToDie()
        {
            if(age >= 12)
                return 1;
            else 
                return 0;
        }
        static void Set_final_year(int a)
        {
            final_year = a;
        }
        void GetOld()
        {
            age++;
        }
        static void Add_one_year()
        {
            now_year++;
        }
        static int Get_Now()
        {
            return now_year;
        }
        static int Get_Final()
        {
            return final_year;
        }
        static void Set_Now()
        {
            now_year = 1;
        }
        static int GetTotal()
        {
            return alive_count;
        }
};

int Newnew::alive_count = 0;
int Newnew::final_year = 0;
int Newnew::now_year = 1;

void multiply(vector<Newnew*> &cows);

int main(){

    int t,final_year;
    cin >> t;
    vector<Newnew*> Cows;
    while(t > 0)
    {
        Newnew::Set_Now();
        cin >> final_year;
        Newnew::Set_final_year(final_year);
        Newnew* firstCows = new Newnew;
        Cows.push_back(firstCows);
        multiply(Cows);
        t--;
        delete firstCows;
        Cows.clear();
    }

    return 0;
}

void multiply(vector<Newnew*> &cows)
{
    while(1)
    {
        if(Newnew::Get_Now() > Newnew::Get_Final())
        {
            return;
        }
        int num = cows.size();
        cout << num << endl;
        for(int i=0;i<num;i++)
        {
            if(cows[i]->isToDie())
            {
                cows.erase(cows.begin()+i);
                continue;
            }
            if(cows[i]->isGiveBirth())
            {
                Newnew* Cow = new Newnew;
                cows.push_back(Cow);
            }
            cows[i]->GetOld();
        }
        Newnew::Add_one_year();
    }
}