#include <iostream>
#include <string>
using namespace std;

static int Weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
static char code[11] = {1,0,'X',9,8,7,6,5,4,3,2};

class CDate 
{
    private:
        int year, month, day;

    public:
        CDate()
        {
            year = 0;
            month = 0;
            day = 0;
        }
        CDate(int y,int m,int d)
        {
            year = y;
            month = m;
            day = d;
        }
        void SetDate(int y,int m,int d)
        {
            year = y;
            month = m;
            day = d;    
        }
        int getyear()
        {
            return year;
        }
        int getmonth()
        {
            return month;
        }
        int getday()
        {
            return day;
        }
        bool check()
        {
            if(year < 1)
            {
                return false;
            }
            if(month < 1 || month > 12)
            {
                return false;
            }
            switch(day)
            {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    if(day < 1 || day > 31)
                    {
                        return false;
                    }
                    break;
                case 4: case 6: case 9: case 11:
                    if(day < 1 || day > 30)
                    {
                        return false;
                    }
                    break;
                case 2:
                    if(isLeap())
                    {
                        if(day < 1 || day > 29)
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if(day < 1 || day > 28)
                        {
                            return false;
                        }
                    }
                    break;
            }
            return true;
        }
        bool isLeap()
        {   
            bool flag = 0;
            if(year % 4 == 0)
            {
                if(year % 100 == 0)
                {
                    if(year % 400 == 0)
                    {
                        flag = 1;
                    }
                }
            }
            return flag;
        }
        void print()
        {
            cout << year << "年" << month << "月" << day << "日";
        }
};

class CStudentID
{
    private:
        string *p_id,*p_name; 
        CDate birthday; 
        int registered; 

    public:
        CStudentID(string &p_id_in,string &p_name_in,CDate &day)
        {   
            int year_temp,month_temp,day_temp;
            int length_id = p_id_in.length();

            p_name = new string(p_name_in);
            p_id = new string(p_id_in);
            
            for(int i=0;i<length_id;i++)
            {
                if(p_id_in[i] < '0' || p_id_in[i] > '9')
                {
                    registered = 0;
                    cout << *p_name << " illegal id" << endl;
                    return;
                }
            }
            if(!(length_id == 15 || length_id == 18))
            {
                registered = 0;
                cout << *p_name << " illegal id" << endl;
                return;
            }
            else
            {
                if(length_id == 15)
                {
                    year_temp = 1900 + p_id_in[6] * 10 + p_id_in[7];
                    month_temp = p_id_in[8] *  10 + p_id_in[9];
                    day_temp = p_id_in[10] * 10 + p_id_in[11];
                    if(year_temp == day.getyear() 
                       && month_temp == day.getmonth()
                       && day_temp == day.getday())
                    {
                        if(!day.check())
                        {
                            registered = 0;
                            cout << *p_name << " illegal id" << endl;
                            return;
                        }
                    }
                }
                if(length_id == 18)
                {
                    year_temp = p_id_in[6] * 1000 + p_id_in[7] * 100 
                              + p_id_in[8] * 10 + p_id_in[9];
                    month_temp = p_id_in[10] *  10 + p_id_in[11];
                    day_temp = p_id_in[12] * 10 + p_id_in[12];
                    if(year_temp == day.getyear() 
                       && month_temp == day.getmonth()
                       && day_temp == day.getday())
                    {
                        if(!day.check())
                        {
                            registered = 0;
                            cout << *p_name << " illegal id" << endl;
                            return;
                        }
                    }
                    if(p_id_in[17] != code[GetCode(p_id_in)])
                    {
                        registered = 0;
                        cout << *p_name << " illegal id" << endl;
                        return;
                    }
                }
            }
            int length_name = p_name_in.length();

            birthday.SetDate(day.getyear(),day.getmonth(),day.getday());
            registered = 1;
            cout << *p_name << " ";
            birthday.print();
            cout << " " << *p_id << endl;
        }
        int GetCode(string &p_id)
        {
            int num[17],sum = 0;
            for(int i=0;i<17;i++)
            {
                num[i] = p_id[i] - '0';
                sum += num[i] * Weight[i];
            }
            return sum % 11;
        }
        CStudentID(const CStudentID &r)
        {
            if(!r.checked())
            {
                return;
            }
            else
            {
                p_name = new string(*r.p_name);
                int ll = r.p_name->length();
                if(r.p_id->length() == 15)
                {
                    string part1 = r.p_id->substr(0,6);
                    string part2 = r.p_id->substr(7,6);
                    string part3 = r.p_id->substr(12,3);
                    p_id = new string();
                    *p_id = part1 + "19" + part2 + part3;
                    *p_id += GetCode(*p_id);
                }
            }
        }
        bool checked()//必须保证函数不会修改引用的值     才能调用它 也就是在花括号之前加const限定
        const
        { 
            return registered; 
        }
};

int main(){

    int t;
    int year,month,day;
    string name,id;
    cin >> t;
    while(t > 0)
    {
        cin  >> year >> month >> day >> name >> id;
        CDate cancanworld(year,month,day);
        CStudentID newnew(id,name,cancanworld);
        CStudentID cancanneed(newnew);
        t--;
    }
    return 0;
}