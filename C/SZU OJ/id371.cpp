#include <iostream>
using namespace std;

class CMetal
{
    private:
        int hardness,weight,volumn;
    public: 
        CMetal(int h=0,int w=0,int v=0):
            hardness(h),weight(w),volumn(v){}
        void Print()
        {
            cout << "硬度" << hardness 
                 << "--" << "重量" << weight 
                 << "--" << "体积" << volumn << endl;
        }
        CMetal operator + (CMetal &m)
        {
            CMetal temp;
            temp.hardness = this->hardness + m.hardness;
            temp.weight = this->weight + m.weight;
            temp.volumn = this->volumn + m.volumn;
            return temp;
        }
        CMetal operator * (int n)
        {
            CMetal temp;
            temp.hardness = this->hardness;
            temp.weight = this->weight;
            temp.volumn = this->volumn * n;
            return temp;
        }
        CMetal operator ++ ()
        {
            CMetal temp;
            temp.hardness = this->hardness + 1;
            temp.weight = this->weight * 1.1;
            temp.volumn = this->volumn * 1.1;
            return temp;
        }
        CMetal operator -- (int)
        {
            CMetal temp;
            temp.hardness = this->hardness - 1;
            temp.weight = this->weight * 0.9;
            temp.volumn = this->volumn * 0.9;
            return temp;
        }
};

int main(){

    int w,h,v,n;
    cin >> h >> w >> v;
    CMetal jo(h,w,v);
    cin >> h >> w >> v;
    CMetal dio(h,w,v);
    CMetal temp;
    cin >> n;

    temp = jo + dio;
    temp.Print();

    temp = jo * n;
    temp.Print();

    temp = ++jo;
    temp.Print();

    temp = dio--;
    temp.Print();

    return 0;

}