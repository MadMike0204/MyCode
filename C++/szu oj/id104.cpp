#include <iostream> 
#include <iomanip>
#include <cmath>
using namespace std;

class CHealth
{
    private:
        string name;
        double height,weight,waistline;
    public:
        CHealth()
        {
            cin >> name >> height >> weight >> waistline;
        }
        int GetBMI()
        {
            return round(weight*1.0/(height * height));
        }
        double GetBFR()
        {
            return ((waistline * 0.74) - (weight * 0.082 + 34.89))/weight;
        }
        void Print()
        {
            cout << name << "'s BMI: " << GetBMI() << "--BFR: " 
                 << fixed << setprecision(2) << GetBFR() << endl; 
        }
};

int main(){

    int t;
    cin >> t;
    while(t--)
    {
        CHealth jojo;
        jojo.Print();
    }

    return 0;
}