#include <iostream> 
#include <map>
#include <vector>
using namespace std;

struct MyDict
{
    public:
        std::map<int,int> frequency;
        int length;
        int* article;
        std::map<string,int> words_frequency;
    
        static int articles,words;
        static std::map<int,int> sum;
        static std::map<string,int> word_sum;

        static void Initial(int as,int ws)
        {
            articles = as;
            words = ws;
            for(int i=1;i<=words;i++)
            {
                sum[i] = 0;
            }
        }

        MyDict(int l):length(l)
        {  
            for(int i=1;i<=words;i++)
            {
                frequency[i]=0;
            }
            article = new int[length];
            for(int i=0;i<length;i++)
            {
                cin >> article[i];
                frequency[article[i]]++;
                sum[article[i]] += 1;
            }
        }
        MyDict(){}      
};

std::map<int,int> MyDict::sum;
std::map<string,int> MyDict::word_sum;
int MyDict::articles = 0;
int MyDict::words = 0;

void PrintResult(vector<MyDict>& v)
{
    int count;
    for(int i=1;i<=MyDict::words;i++)
    {
        count = 0;
        for(auto element:v)
        {
            if(element.frequency[i])
            {
                count++;
            }
        }
        cout << count << " " << MyDict::sum[i] << endl;
    }
}

int main(){

    int articles,words,length;
    cin >> articles >> words;
    vector<MyDict> Jo;
    MyDict::Initial(articles,words);
    while(articles--)
    {
        cin >> length;
        MyDict temp(length);
        Jo.push_back(temp);
    }
    PrintResult(Jo);

    return 0;
}