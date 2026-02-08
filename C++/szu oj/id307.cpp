#include<iostream>
using namespace std;

class Box{
    private:
        string id;
        int length,width,height;
    public:
        Box(string i,int l,int w,int h):length(l),width(w),height(h),id(i){}
        // b放入a a的长宽必须大于等于b的长宽
        static bool isOperationValid(Box &a,Box &b){
            if(a.length >= b.length && a.length >= b.length){
                return 1;
            }
            return 0;
        }
        // 计算b 放入 a的溢出体积 如果不合法 返回-1
        static int calculateWaterVolume(Box &a,Box &b){
            if(!isOperationValid(a,b))
                return -1;
            int validHeight = min(a.height,b.height);
            return b.length * b.width * validHeight;
        }
        friend int operator-(Box &a,Box &b);
};

int operator-(Box &a,Box &b){
    return a.calculateWaterVolume(a,b);
}

int main(){

    int a,b,c;
    string id;
    int t;
    cin >> t;
    while(t--){
        cin >> id >> a >> b >> c;
        Box jo3(id,a,b,c);
    }
    cin >> id >> a >> b >> c;
    Box jo1(id,a,b,c);
    cin >> id >> a >> b >> c;
    Box jo2(id,a,b,c);
    

    string idA,idB;
    int maxVolume = -2;
    if(jo1 - jo2)

    return 0;
}