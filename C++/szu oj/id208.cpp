#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
static float PRECISION = 0.001;
class Player
{
    protected:
        string name;
        float height;
        float weight;
    public:
        Player(string &name_,float height_,float weight_):
            name(name_),height(height_),weight(weight_){}
        bool isMVP(float score,float rebound,float assist)
        {
            if(score > 25 || fabs(score-25) < PRECISION)
            {
                if(rebound > 6 || fabs(rebound-6) < PRECISION)
                {
                    if(assist > 6 || fabs(assist-6) < PRECISION)
                    {
                        return 1;
                    }
                }
            }
            return 0;
        }
        bool isDPOY(float steal,float rebound,float block)
        {
            if(steal > 1.5 || fabs(steal-1.5) < PRECISION)
            {
                if(rebound > 12 || fabs(rebound-12) < PRECISION)
                {
                    if(block > 2.5 || fabs(block-2.5) < PRECISION)
                    {
                        return 1;
                    }
                }
            }
            return 0;
        }
        void printPlayer()
        {
            cout << "球员姓名:" << name << " 身高:" << height << " 体重:" << weight << endl;
        }
};
class MVP:public Player
{
    protected:
        int year;
        float score;
        float rebound;
        float assist;
    public:
        MVP(const Player &p):
            Player(p){}
        void fill(int year_,float score_,float rebound_,float assist_)
        {
            score = score_;
            rebound = rebound_;
            assist = assist_;
            year = year_;
        }
        void print()
        {
            cout << "MVP年份:" << year 
                 << fixed << setprecision(1)
                 << " 得分:" << score 
                 << " 篮板:" << rebound 
                 << " 助攻:" << assist << endl;
        }
};
class DPOY:public Player
{
    protected:
        int year;
        float rebound;
        float block;
        float steal;
    public:
        DPOY(const Player &p):
            Player(p){}
        void fill(int year_,float steal_,float rebound_,float block_)
        {
            steal = steal_;
            rebound = rebound_;
            block = block_;
            year = year_;
        }
        void print()
        {
            cout << "DPOY年份:" << year 
                 << fixed << setprecision(1)
                 << " 盖帽:" << block 
                 << " 篮板:" << rebound 
                 << " 抢断:" << steal << endl;
        }
};

int main(){

    string name;
    float weight,height;
    cin >> name >> height >> weight;
    Player jojo(name,height,weight);

    vector<MVP*>MVPs;
    vector<DPOY*>DPOYs;
    MVP* p_MVP = NULL;
    DPOY* p_DPOY = NULL;

    float score,block,rebound,steal,assist;
    int year;
    for(int i=0;i<12;i++)
    {
        year = 2010+i;
        cin >> score >> rebound >> assist >> block >> steal;
        if(jojo.isMVP(score,rebound,assist))
        {
            p_MVP = new MVP(jojo);
            p_MVP->fill(year,score,rebound,assist);
            MVPs.push_back(p_MVP);
        }
        if(jojo.isDPOY(steal,rebound,block))
        {
            p_DPOY = new DPOY(jojo);
            p_DPOY->fill(year,steal,rebound,block);
            DPOYs.push_back(p_DPOY);
        }
    }

    jojo.printPlayer();
    for(MVP* element : MVPs)
    {
        element->print();
    }
    for(DPOY* element : DPOYs)
    {
        element->print();
    }

    return 0;
}