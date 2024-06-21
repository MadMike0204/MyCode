#include<iostream>
#include<cmath>
using namespace std;
static float PRECISION = 0.001;
class Player
{
    protected:
        string name;
        int height;
        int weight;
    public:
        Player(string namei,int heighti,int weighti):
            name(namei),height(heighti),weight(weighti){}
        int MVPorDPOY(float scorei,float blanki,
                     float helpi,float hati,float robi)
        {
            int x = 0;
            if(scorei > 25 || fabs(scorei - 25) < PRECISION
            && blanki > 6 || fabs(blanki-6) < PRECISION
            && helpi  > 6 || fabs(helpi-6)<PRECISION)
                x++;
            if(scorei > 25 || fabs(scorei - 25) < PRECISION
            && blanki > 6 || fabs(blanki-6) < PRECISION
            && helpi  > 6 || fabs(helpi-6)<PRECISION)
        }
};
class MVP:public Player
{
    protected:
        int year;
        float score;
        float blank;
        float help;
    MVP(string namei,int heighti,int weighti,int yeari,
        float scorei,float blanki,float helpi):
        Player(namei,heighti,weighti),
        year(yeari),score(scorei),blank(blanki),help(helpi){}
};
class DPOY:public Player
{
    protected:
        int year;
        float blank,hat,rob;
    DPOY(string namei,int heighti,int weighti,int yeari,
        float blanki,float hati,float robi):
        Player(namei,heighti,weight),
        year(yeari),blank(blanki),hat(hati),rob(robi){}

};

int main(){



    return 0;
}