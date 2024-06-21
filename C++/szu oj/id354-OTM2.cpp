/*
现在有一个奥特曼打怪兽的角色扮演游戏。请你根据下面的描述，采用提示中给出的程序框架，定义两个类：奥特曼类(Ultraman)和怪兽类(Monster)。

在奥特曼的世界，打怪兽就是全部。现在人人都有机会成为奥特曼，加入到与怪兽无止境的战斗中。可惜，并非人人生来就是英雄，革命尚未成功，同志仍需努力啊。每一个奥特曼都要从零开始，辛勤劳动，打怪升级，最终才能成为举世瞩目的大英雄。

每个奥特曼的等级(rank)都从第一级开始，随着它打怪兽经验(exp)的增加，等级将不断攀升。随着等级的升高，奥特曼的生命值(hp)上限和攻击力(damage)也将大大增强。在与怪兽的战斗中，奥特曼收获的不仅仅是经验。有时，运气好的话，还能从怪兽身上弄到点小钱(money)。不要小看这些钱，关键时刻，它能给奥特曼买药补血呀。奥特曼没有金刚不坏之身，在与怪兽的战斗中，奥特曼会受到伤害。一旦奥特曼的生命值降到0，它英雄的一生就结束了。

好了，了解了奥特曼的基本情况，现在可以开始战斗了。首先，我们需要一位全新的奥特曼(Outman)，我们给它赋予一定的初始实力(initial)。让它投入战斗吧！

在与怪兽的战斗中要讲究策略。所谓知己知彼，百战不殆，一旦碰到怪兽，我们首先要查看自己和对方的实力(display)，包括双方的等级、生命值、攻击力、经验和所拥有的钱财。所谓打得赢就打，打不赢就跑。如果对手太强大，逃跑吧(escape)！偶尔逃跑无伤颜面，但会耗费一点生命值。如果总是逃跑，生命被虚耗，那英雄就当不成了。所以该出手时就出手，勇敢地战斗(attack)吧！每一回合的战斗中，怪兽会受到攻击(attacked)，怪兽也会反击(fightback)，让奥特曼受到攻击(attacked)。每一回合结束，只要奥特曼还活着(isalive)，而且怪兽也还活着，战斗就要继续。如果奥特曼的生命值太低，也许抵挡不了下一轮的进攻，那么别财迷了，掏钱出来给它补血(restore)吧。当然，如果形势确实不妙，奥特曼也可以中途逃跑。但如果获得了最终的胜利(win)，不仅能赢得战斗经验，夺取怪兽身上的钱财，足够多的经验也许能让奥特曼升级(upgrade)。
*/

/*
在实验《类定义》的基础，改进并实现游戏中的两个类：奥特曼类和怪兽类。使得两个类更加接近实际要求。

奥特曼说明如下：

1.为每个属性设置get方法，注意奥特曼所有属性都

2.初始化(利用构造函数完成初始化)，参数是等级，等级与其他属性的关系：生命是等级10倍，攻击是等级3倍，金钱是等级的10倍，经验开始为0。

3.逃跑(escape)，当生命不超过10点时，奥特曼将逃跑，逃跑将损失所有金钱，战斗结果为奥特曼失败（lose）

4.攻击（attack），（这个方法要参数么？？），当攻击怪兽时，怪兽受到的伤害等于奥特曼攻击力。（本方法实际上就是怪兽被攻击，所以不一定需要实现）

5.被攻击（attacked），（这个方法要参数么？？），当怪兽反击时，奥特曼受到的伤害等于怪兽攻击力的一半，即生命损失=怪兽攻击力值/2，取整处理

6.回复生命(restore)，如果体力不支（生命低于50%但大于10点），每10个金钱可恢复1点生命值。只要有足够的钱，可以一直恢复，直到达到生命值上限(等级的10倍)。

7.胜利（win），（这个方法要参数么？？），当怪兽生命小于等于0，战斗结果为奥特曼胜利（win），奥特曼将获得怪兽身上所有金钱和经验值。

8.升级（upgrade）,战斗结束后，达到升级条件可以升级，条件是经验值不小于等级10倍。升级将扣除相应的经验值，生命满血，更新生命上限和攻击力。

9.显示状态（display），单行输出，格式如下：

rank=等级hp=生命damage=攻击exp=经验money=金钱

怪兽说明如下：

1.为每个属性设置get方法。

2.初始化（利用构造函数完成初始化），参数是等级，等级与其他属性的关系：生命是等级20倍，攻击是等级2倍，金钱是等级的10倍，经验值是等级的10倍。

3.被攻击（attacked），（这个方法要参数么？？），当奥特曼攻击时，怪兽受到的伤害等于奥特曼攻击力，即生命损失=奥特曼攻击力值

4.反击（fightback）当怪兽被反击后，如果怪兽不死，将进行反击（本方法实际上就是奥特曼被攻击，所以不一定需要实现）

5.显示状态（display），单行输出，格式如下：

rank=等级hp=生命damage=攻击exp=经验money=金钱

****************************************************************************************

请在main函数中实现奥特曼与怪兽的“只抽”，即1对1的战斗过程，具体步骤如下：

cin>>t;   //表示有t个测试实例

while (t--)  //每个实例就是奥特曼与怪兽的1对1战斗

{

1.输入奥特曼和怪兽的等级，并调用初始化方法进行对象初始化

2.输出奥特曼和怪兽状态，调用display方法，每行输出一个

3.设置战斗标志flag为true，启动战斗循环，具体如下：

while(flag) //当战斗未结束就继续

{     //奥特曼攻击1次，或者是怪兽被攻击1次

if (怪兽没死)  //用怪兽生命来判断，用get方法啦

{     //怪兽反击1次，或者是奥特曼被攻击1次

if (奥特曼不必逃跑)           //用奥特曼生命来判断，用get方法啦

//奥特曼回血，在方法中判断是否需要加血

else

{     //奥特曼逃跑，并输出"lose"并回车

//输出奥特曼状态，调用display方法

//设置flag为false，停止战斗

}

}

else //怪兽死了

{     //奥特曼胜利，并输出"win"并回车

//输出奥特曼状态，调用display方法

//设置flag为false，停止战斗

}

}

}


输入

第一行先输入t表示有t个测试实例

接着t行输入奥特曼和怪兽的等级


输出

根据题目要求，每个实例输出4行结果：

头两行是奥特曼和怪兽的初始状态

第3行是战斗结果

第4行是奥特曼的最终状态
*/

#include <iostream>
using namespace std;
class Monster;
//奥特曼属性
class Ultraman
{   
    friend bool Fight(Ultraman &U,Monster &M);
    friend class Monster;
    private:
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
    private:
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
//奥特曼和怪兽公用函数
//显示双方状态
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
