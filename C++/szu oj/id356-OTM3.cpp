#include <iostream>
using namespace std;
//守护神
class Angle
{
    private:
        int rank;
        int damage;
        int exp;
        int money;
        char type;//U:奥特曼 A:攻击型怪兽 D:防御型怪兽
    public:
        Angle()
        {
            rank = 0;
            damage = 0;
            exp = 0;
            money = 0;
        }
        void initialize(int rank_lord,char type_lord)
        {
            rank = rank_lord;
            type = type_lord;
            damage = rank/2;
            switch(type)
            {
                case 'U':
                    break;
                case 'A':
                case 'D':
                    money = rank * 5;
                    exp = rank * 5;
            }
        }
        void upgrade(int rank_lord)
        {
            rank = rank_lord;
            damage = rank/2;
            switch(type)
            {
                case 'U':
                    break;
                case 'A':
                case 'D':
                    money = rank * 5;
                    exp = rank * 5;
            }
        }
        
};
class Monster;
//奥特曼属性
class Ultraman
{   
    friend bool Fight(Ultraman &U,Monster &M);
    friend class Monster;
    protected:
        int rank;//奥特曼等级，初始为1
        int exp;//经验初始为0
        int hp;//血量上限
        int damage;//攻击力
        int money;//钱初始为0
        bool isalive;
    public:
        Ultraman();
        Ultraman(int rank_in);
        void UTM_escape();
        void attack(Monster &M);
        void attacked(int dmg_taken);
        void restore();
        void upgrade();
        void win(Monster &M);
        void display();
        int getRank(){return rank;}
        int getExp(){return exp;}
        int getHp(){return hp;}
        int getDamage(){return damage;}
        int getMoney(){return money;}
        bool getIsalive(){return isalive;}
        int MaxHp(){return rank * 10;}
};
//怪兽属性
class Monster
{
    friend bool Fight(Ultraman &U,Monster &M);
    friend class Ultraman;
    protected:
        int rank;//怪兽等级，初始为1
        int exp;//经验初始为0
        int hp;//血量上限
        int damage;//攻击力
        int money;//钱初始为0
        bool isalive;
    public:
        Monster();
        Monster(int rank_in);
        void fightback(Ultraman &U);
        void attacked(int dmg_taken);
        void display();
        int getRank(){return rank;}
        int getExp(){return exp;}
        int getHp(){return hp;}
        int getDamage(){return damage;}
        int getMoney(){return money;}
        bool getIsalive(){return isalive;}
};
//奥特曼成员函数
Ultraman::Ultraman()
{
    rank = 1;
    hp = rank * 10;
    damage = rank * 3;
    money = rank * 10;
    exp = 0;
}
Ultraman::Ultraman(int rank_in)
{
    rank = rank_in;
    hp = rank * 10;
    damage = rank * 3;
    money = rank * 10;
    exp = 0;
}
void Ultraman::UTM_escape()
{
    if(hp <= 10 && hp >= 1)
    {
        money = 0;
    }
}
void Ultraman::attack(Monster &M)
{
    int dmg_done = damage;
    M.attacked(dmg_done);
}
void Ultraman::attacked(int dmg_taken)
{
    dmg_taken /= 2;
    hp -= dmg_taken;
}
void Ultraman::display()
{
    cout << "rank=" << rank 
         << " hp=" << hp
         << " damage=" << damage
         << " exp=" << exp
         << " money=" << money 
         << endl; 
}
void Ultraman::restore()
{
    if(hp > 10 && hp < (float)MaxHp()/2)
    {
        int Max_Hp_added = money / 10;
        if(Max_Hp_added + hp >= MaxHp())
        {
            money -= (MaxHp() - hp) * 10;
            hp = MaxHp();
        }
        else
        {
            hp += Max_Hp_added;
            money -= Max_Hp_added * 10;
        }
    }
}
void Ultraman::upgrade()
{
    while(exp >= rank * 10)
    {
        exp -= rank * 10;
        rank++;
        damage = rank * 3;
        hp = rank * 10;
    }
}
void Ultraman::win(Monster &M)
{
    exp += M.exp;
    money += M.money;
}
//怪兽成员函数
Monster::Monster()
{
    rank = 1;
    hp = 20 * rank;
    money = 10 * rank;
    exp = 10 * rank;
    isalive = 1;
    damage = 2 * rank;
}
Monster::Monster(int rank_in)
{
    rank = rank_in;
    hp = 20 * rank;
    money = 10 * rank;
    exp = 10 * rank;
    isalive = 1;
    damage = 2* rank;
}
void Monster::fightback(Ultraman &U)
{
    int dmg_done = damage;
    U.attacked(dmg_done);
    return;
}
void Monster::attacked(int dmg_taken)
{
    hp -= dmg_taken;
}
void Monster::display()
{
    cout << "rank=" << rank 
         << " hp=" << hp
         << " damage=" << damage                                   
         << " exp=" << exp
         << " money=" << money 
         << endl; 
}
//怪兽派生类
class NMonster: Monster
{
    NMonster();
    NMonster(int rank_in)
    {
        rank = rank_in;
        hp = rank * 10;
        money = rank * 10;
        exp = rank * 10;
        damage = rank * 2;
    }
};
class AMonster: Monster
{
    AMonster();
    AMonster(int rank_in)
    {
        rank = rank_in;
        hp = rank * 5;
        money = rank * 10;
        exp = rank * 10;
        damage = rank * 4;
    }
};
class DMonster: Monster
{
    DMonster();
    DMonster(int rank_in)
    {
        rank = rank_in;
        hp = rank * 20;
        money = rank * 10;
        exp = rank * 10;
        damage = rank;
    }
};
class SMonster: Monster
{
    SMonster();
    SMonster(int rank_in)
    {
        rank = rank_in;
        hp = rank * 10;
        money = rank * 20;
        exp = rank * 20;
        damage = rank * 1;
    }
};



//战斗，如果凹凸曼胜利,返回1;反之返回0.
bool Fight(Ultraman &U,Monster &M)
{
    bool fight_flag = 1;
    bool win_or_lose;//1是赢，0是输
    while(fight_flag)
    {
        //打个架先
        U.attack(M);
        if(M.getHp() <= 0)//打死了没
        {
            fight_flag = 0;
            U.win(M);
            cout << "win" << endl;
            U.upgrade();
            U.display();
            win_or_lose = 1;
        }
        else//没有啊，要挨打了
        {
            M.fightback(U);
        }
        if(U.getHp() > 10)//要跑吗
        {
            U.restore();//不用，那加个血先
        }
        else//淦，要跑了
        {
            fight_flag = 0;
            U.UTM_escape();
            cout << "lose" << endl;
            U.display();
            win_or_lose = 0;
        }
    }
    return win_or_lose;
}
int main(){

    int t;
    cin >> t;
    while(t > 0)
    {
        int UTM;
        int MST;
        cin >> UTM >> MST;
        Ultraman newnew(UTM);
        Monster sword(MST);
        newnew.display();
        sword.display();
        Fight(newnew,sword);
        t--;
    }
    return 0;
}