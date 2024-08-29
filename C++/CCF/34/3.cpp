#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

static bool alpha[26] = {0};

struct Data
{
    string word;
    int frequency;
};

class Text
{
    private:
        Data* word_data;
        string** dict;
        string** black_list;
        int black;
        int word_num;
        int expectation_length;
        int real_length;
        int max_length;
    public:
        int GetReal_length()
        {
            return real_length;
        }
        Text(int m,int l):word_num(m),expectation_length(l)
        {
            max_length = 0;
            black = 0;
            real_length = 0;
            word_data = new Data[word_num];
            for(int i=0;i<word_num;i++)
            {
                cin >> word_data[i].word >> word_data[i].frequency;
                if(word_data[i].word.length() > max_length)
                    max_length = word_data[i].word.length();
            }
            dict = new string*[expectation_length];
            for(int i=0;i<expectation_length;i++)
            {
                dict[i] = new string[max_length];
            }
            black_list = new string*[expectation_length];
            for(int i=0;i<expectation_length;i++)
            {
                black_list[i] = new string[max_length];
            }
        }
        
        void GetOriginDict()
        {
            int length;
            for(int i=0;i<word_num;i++)
            {
                length = word_data[i].word.length();
                for(int j=0;j<length;j++)
                {
                    alpha[word_data[i].word[j]-97] = 1;
                }
            }
            for(int i=0;i<26;i++)
            {
                if(alpha[i])
                {
                    *dict[real_length] = i+97;
                    real_length++;
                }
            }
        }
        bool CheckIfRepeat(const string&aim)
        {
            bool flag = 1;
            for(int i=0;i<real_length;i++)
            {
                if(aim == *dict[i])
                {
                    flag = 0;
                    break;
                }
            }
            return flag;
        }
        void GetMostFrequentPair()
        {
            int CurX=0,CurY=0,MaxX=0,MaxY=0,CurL;
            int Max_count = -1,temp;
            bool isinBlack;
            string Possible_Result = *dict[MaxX] + *dict[MaxY];
            for(int i=0;i<real_length-1;i++)
            {
                for(int j=i+1;j<real_length;j++)
                {   
                    temp = GetPairAppearNum(i,j);
                    if(temp > 0)
                    {
                        Possible_Result = *dict[i] + *dict[j];
                    }
                    else if(temp < 0)
                    {
                        Possible_Result = *dict[j] + *dict[i];
                    }
                    if(CheckIfRepeat(Possible_Result))
                    {
                        if(fabs(temp) > Max_count && temp > 0)
                        {
                            Max_count = fabs(temp);
                            MaxX = i;
                            MaxY = j;
                        }
                        else if(fabs(temp) > Max_count && temp < 0)
                        {
                            Max_count = fabs(temp);
                            MaxX = j;
                            MaxY = i;
                        }
                    }
                    
                }
            }
            (*dict[real_length]) = *dict[MaxX] + *dict[MaxY];
            real_length++;
        }
        int GetPairAppearNum(int x,int y)//x y为两个词汇在dict中的位置
        {
            int length_1 = (*dict[x]).length();
            int length_2 = (*dict[y]).length();
            int l = length_1 + length_2; // 词汇对长度
            int a,b,location;//a,b为最终结果，location为测试string起始位置
            
            a=location=0;
            string test_1 = *dict[x] + *dict[y];
            for(int i=0;i<word_num;i++)
            {
                int length = word_data[i].word.length();
                while(location + l <= length)
                {
                    string sub = word_data[i].word.substr(location,l);
                    if(sub == test_1)
                    {
                        a += word_data[i].frequency;
                    }
                    location++;
                }
                location = 0;
            }
            b=location=0;
            string test_2 = *dict[y] + *dict[x];
            for(int i=0;i<word_num;i++)
            {
                while(location + l <= word_data[i].word.length())
                {
                    string sub = word_data[i].word.substr(location,l);
                    if(sub == test_2)
                    {
                        b += word_data[i].frequency;
                    }
                    location++;
                }
                location = 0;
            }
            // cout << "词汇对" << (a>b?(test_1):(test_2)) << "本轮检测最大值为: " << (a>b?a:b) << endl;
            return (a>b?a:(-b));
        }
        void test()
        {
            for(int i=0;i<real_length;i++)
            {
                cout << *dict[i] << endl;
            }
        }
};



int main(){

    int m,n;
    cin >> n >> m;
    Text JOJO(n,m);
    JOJO.GetOriginDict();
    int cur_length = JOJO.GetReal_length();
    for(int i=1;i+cur_length<=m;i++)
    {
        JOJO.GetMostFrequentPair();
    }
    JOJO.test();

    return 0;
}