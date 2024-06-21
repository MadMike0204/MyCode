#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class CStock
{
    private:
        string name;
        string code;
        double prePrice;
        double curPrice;
    public:
        CStock()
        {
            code = "000001";
            name = "ChinaPingan";
        }
        CStock(string &name_in,string &code_in)
        {
            code = code_in;
            name = name_in;
        }
        void SetName(string &name_in)
        {
            name = name_in;
        }
        void SetCode(string &code_in)
        {
            code = code_in;
        }
        void SetCurP(double cur)
        {
            curPrice = cur;
        }
        void SetPreP(double pre)
        {
            prePrice = pre;
        }
        string getName()
        {
            return name;
        }
        string getCode()
        {
            return code;
        }
        double getChange()
        {
            double delta = curPrice - prePrice;
            double result = 100.0 * (delta / prePrice);
            return result;
        }
};

void test()
{
    CStock cc;
    cc.SetCurP(21.88);
    cc.SetPreP(21.68);
    cout << fixed << setprecision(2) << cc.getChange() << "%";
}


int main(){

    int t,op;
    cin >> t;
    CStock* cc;
    while(t > 0)
    {
        cin >> op;
        if(op == 1)
        {
            cc = new CStock;
        }
        else if(op == 2)
        {
            string name,code;
            cin >> name >> code;
            cc = new CStock(name,code);
        }
        for(int i=1;i<=5;i++)
        {
            double d1,d2;
            if(i == 1)
            {
                cin >> d1 >> d2;
            }
            else
            {
                double temp = d2;
                cin >> d2;
                d1 = temp;
            }
            cc->SetPreP(d1);
            cc->SetCurP(d2);
            cout << cc->getName() << " " << cc->getCode() << " "
                 << fixed << setprecision(2)
                 << d1 << " " << d2 << " "
                 << cc->getChange() << "%" << endl;
        }
        t--;
        delete cc;
    }

    return 0;
}