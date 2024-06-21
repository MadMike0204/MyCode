#include <iostream>
using namespace std;

class Buyer{

    private:
        string name;
        int num;
        int** arr = NULL;
        int* counter = NULL;
        int result[3] = {0};
    public:

        string Na[3] = {"一等奖","二等奖","三等奖"};

        void init()
        {
            counter = new int[num];
            for(int i=0;i<7;i++)
            {
                counter[i] = 0;
            }
        }

        void createBuyer()
        {
            cin >> num;
            cin >> name;
            arr = new int*[num];
            for(int i=0;i<num;i++)
            {
                arr[i] = new int[7];
                for(int j=0;j<7;j++)
                {
                    cin >> arr[i][j];
                }
            }
        }

        void compare(int (&origin)[7])
        {
            for(int i=0;i<num;i++)
            {
                for(int j=0;j<7;j++)
                {
                    if(arr[i][j] == origin[j])
                    {
                        counter[i]++;
                    }
                }
                if(counter[i] == 7)
                {
                    result[0]++;
                }
                else if(counter[i] == 5 || counter[i] == 6)
                {
                    result[1]++;
                }
                else if(counter[i] >= 2)
                {
                    result[2]++;
                }
            }
        }
        void outputResult()
        {
            int flag = 0;
            for(int i=0;i<3;i++)
            {
                if(result[i] != 0)
                {
                    flag = 1;
                    cout << "恭喜" << name << "中了" << result[i] << "注" << Na[i] << "！";
                }
            }
            if(!flag)
            {
                cout << "加油！继续！" << endl;
            }
        }


};

int main(){

    Buyer b1;
    b1.init();
    b1.createBuyer();
    int real[7];
    for(int i=0;i<7;i++)
    {
        cin >> real[i];
    }
    b1.compare(real);
    b1.outputResult();

    return 0;
}