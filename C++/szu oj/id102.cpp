#include <iostream>
using namespace std;

class Cat{

    private:
        string name;
        int weight;
    public:
        void init_cat()
        {
            cin >> name >> weight;
        }
        string get_name()
        {
            return name;
        }
        int get_weight()
        {
            return weight;
        }
        void edit_both(int weigh,string nam)
        {
            name = nam;
            weight = weigh;
        }
};

void SortCat(Cat (&cat)[],int n)
{
    Cat temp;
    for(int i=0;i<n-1;i++)
    {
        int k = i+1;
        for(int j=k;j<n;j++)
        {
            if(cat[i].get_weight() > cat[j].get_weight())
            {
                temp.edit_both(cat[i].get_weight(),cat[i].get_name());
                cat[i].edit_both(cat[j].get_weight(),cat[j].get_name());
                cat[j].edit_both(temp.get_weight(),temp.get_name());
            }
        }
    }
}

int main(){

    int t;
    cin >> t;
    Cat newnew[t];
    for(int i=0;i<t;i++)
    {
        newnew[i].init_cat();
    }
    SortCat(newnew,t);
    for(int i=0;i<t;i++)
    {
        if(i != 0)
        {
            cout << " " << newnew[i].get_name();
        }
        else
        {
            cout << newnew[i].get_name();
        }
    }
    cout << endl;

    return 0;
}