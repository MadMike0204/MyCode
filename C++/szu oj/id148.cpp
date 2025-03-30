#include<iostream>
#include<cstring>
using namespace std;

class IDCard{
    static int weights[17];
    static int checkCode[11];
    private:
        int originEdition[15];
        int newEdition[18];
    public:
        IDCard(int o[15]){
            int l = sizeof(int);
            memcpy(originEdition,o,l * 15);
            cout << "construct ID=";
            printOriginEdition();
        }
        ~IDCard(){
            cout << "destruct ID=" << newEdition[14] << newEdition[15] << newEdition[16];
            if(newEdition[17] < 0){
                cout << 'X';
            }
            else{
                cout << newEdition[17];
            }
            cout << endl;

        }
        void Upgrade(){
            for(int i=0;i<6;i++){
                newEdition[i] = originEdition[i];
            }
            newEdition[6] = 1;
            newEdition[7] = 9;
            for(int i=6;i<15;i++){
                newEdition[i+2] = originEdition[i];
            }

            int s = 0;
            for(int i=0;i<17;i++){
                s += newEdition[i] * weights[i];
            }
            int y = (s %= 11);
            newEdition[17] = checkCode[y];

            cout << "upgrade ID=";
            printNewEdition();
        }
        void printOriginEdition(){
            for(int i=0;i<15;i++){
                cout << originEdition[i];
            }
            cout << endl;
        }
        void printNewEdition(){
            for(int i=0;i<17;i++){
                cout << newEdition[i];
            }
            if(newEdition[17] < 0) 
                cout << "X";
            else 
                cout << newEdition[17];
            cout << endl;
        }
};
int IDCard::weights[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int IDCard::checkCode[11] = {1,0,-1,9,8,7,6,5,4,3,2};

int main(){

    int t;
    cin >> t;
    char c[15];
    int arr[15];
    while(t--){
        for(int i=0;i<15;i++){
            cin >> c[i];
            arr[i] = c[i] - '0';
        }
        IDCard card(arr);
        card.Upgrade();
    }

    return 0;
}