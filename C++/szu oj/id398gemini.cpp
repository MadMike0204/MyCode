#include <iostream>
#include <string>
using namespace std;

// 基本的CPeople类
class CPeople {
protected:
    string id;  // 身份号码
    string name;  // 姓名
public:
    CPeople() : id(""), name("") {}  // 构造函数，默认初始化
    CPeople(string _name, string _id) : name(_name), id(_id) {}  // 构造函数，带参数

    // 打印姓名和ID
    void print() const {
        cout << "Name: " << name << " ID: " << id << endl;
    }
};

// 继承CPeople的CInternetUser类
class CInternetUser : public virtual CPeople {
protected:
    string password;  // 登录密码
public:
    CInternetUser() : password("") {}  // 默认构造函数
    CInternetUser(string _name, string _id, string _password)
        : CPeople(_name, _id), password(_password) {}  // 带参构造函数

    // 注册函数：设置name, id, password
    void registerUser(string _name, string _id, string _password) {
        name = _name;
        id = _id;
        password = _password;
    }

    // 登录函数：判断id和password是否匹配
    int login(string _id, string _password) {
        if (id == _id && password == _password)
            return 1;  // 登录成功
        return 0;  // 登录失败
    }
};

// 继承CPeople的CBankCustomer类
class CBankCustomer : public virtual CPeople {
protected:
    double balance;  // 余额
public:
    CBankCustomer() : balance(0) {}  // 默认构造函数，余额初始化为0

    // 开户函数：设置客户姓名和id
    void openAccount(string _name, string _id) {
        name = _name;
        id = _id;
        balance = 0;  // 初始余额为0
    }

    // 存款函数：向银行账户存款
    void deposit(double amount) {
        balance += amount;
    }

    // 取款函数：从银行账户取款
    int withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return 1;  // 成功
        }
        return 0;  // 余额不足
    }

    // 获取余额
    double getBalance() const {
        return balance;
    }
};

// 多重继承CInternetUser和CBankCustomer类的CInternetBankCustomer类
class CInternetBankCustomer : public virtual CInternetUser, public virtual CBankCustomer {
private:
    double today_balance;  // 当前互联网账户余额
    double yesterday_balance;  // 前一日余额
    double today_profit;  // 今日收益
    double today_wan_profit;  // 今日万元收益
    double yesterday_wan_profit;  // 昨日万元收益

public:
    CInternetBankCustomer() 
        : today_balance(0), yesterday_balance(0), today_profit(0),
          today_wan_profit(0), yesterday_wan_profit(0) {}

    // 设置万元收益
    void setInterest(double interest) {
        today_wan_profit = interest;
    }

    // 计算收益并更新前一日余额
    void calculateProfit() {
        today_profit = today_wan_profit * 10000;  // 今日收益
        yesterday_balance = today_balance;  // 更新前一日余额
        today_balance += today_profit;  // 计算余额
    }

    // 存款操作（互联网账户存款）
    int deposit(double amount) {
        if (CBankCustomer::withdraw(amount)) {  // 先从银行账户取款
            today_balance += amount;  // 加到互联网账户
            return 1;  // 成功
        }
        return 0;  // 余额不足
    }

    // 取款操作（互联网账户取款）
    int withdraw(double amount) {
        if (today_balance >= amount) {
            today_balance -= amount;  // 从互联网账户中扣除
            return 1;  // 成功
        }
        return 0;  // 余额不足
    }

    // 打印银行账户和互联网账户余额
    void print() {
        CPeople::print();  // 打印姓名和ID
        cout << "Bank balance: " << CBankCustomer::getBalance() << endl;  // 打印银行余额
        cout << "Internet bank balance: " << today_balance << endl;  // 打印互联网金融账户余额
    }
};

// 主函数
int main()
{
    int t, no_of_days, i;
    string i_xm, i_id, i_mm, b_xm, b_id, ib_id, ib_mm;
    double money, interest;
    char op_code;

    // 输入测试案例数t
    cin >> t;
    while (t--)
    {
        // 输入互联网用户注册时的用户名,id,登陆密码
        cin >> i_xm >> i_id >> i_mm;

        // 输入银行开户用户名,id
        cin >> b_xm >> b_id;

        // 输入互联网用户登陆时的id,登陆密码
        cin >> ib_id >> ib_mm;

        CInternetBankCustomer ib_user;

        ib_user.registerUser(i_xm, i_id, i_mm);
        ib_user.openAccount(b_xm, b_id);

        if (ib_user.login(ib_id, ib_mm) == 0) // 互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
        {
            cout << "Password or ID incorrect" << endl;
            continue;
        }

        // 输入天数
        cin >> no_of_days;
        for (i = 0; i < no_of_days; i++)
        {
            // 输入操作代码, 金额, 当日万元收益
            cin >> op_code >> money >> interest;
            switch (op_code)
            {
            case 'S': // 从银行向互联网金融帐户存入
            case 's':
                if (ib_user.deposit(money) == 0)
                {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'T': // 从互联网金融转入银行帐户
            case 't':
                if (ib_user.withdraw(money) == 0)
                {
                    cout << "Internet bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'D': // 直接向银行帐户存款
            case 'd':
                ib_user.CBankCustomer::deposit(money);
                break;
            case 'W': // 直接从银行帐户取款
            case 'w':
                if (ib_user.CBankCustomer::withdraw(money) == 0)
                {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            default:
                cout << "Illegal input" << endl;
                continue;
            }
            ib_user.setInterest(interest);
            ib_user.calculateProfit();
            // 输出用户名,id
            // 输出银行余额
            // 输出互联网金融账户余额
            ib_user.print();
        }
    }
}
