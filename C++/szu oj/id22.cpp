#include <iostream>
#include <string>
using namespace std;

int ged(int a1, int a2)//最小公倍数
{
	int flag;
	if (a1 == 0 || a2 == 0)
    {
		return 0;
    }  

	if (a1 < a2)
	{
		flag = a1;
		a1 = a2;
		a2 = flag;
	}         

	while (a2 != 0)//辗转相除
	{
		flag = a1 % a2;
		a1 = a2;
		a2 = flag;
	}
	return a1;
}

int gbs(int m,int n)//最大公约数
{
    return (m * n / ged(m, n));
}

struct fs
{
    string original;
    int upp;
    int downn;
    int result[2];
};

fs newnew()
{
    fs OMG;
    cin >> OMG.original;

    string sub1,sub2;
    int length;
    int location;

    location = OMG.original.find("/");
    length = OMG.original.length();
    sub1 = OMG.original.substr(0,location);
    sub2 = OMG.original.substr(location+1,length-location);

    OMG.upp = (int) stof(sub1);
    OMG.downn = (int) stof(sub2);


    return OMG;
}

int addd(fs &fs1,fs &fs2)
{
    int down = gbs(fs1.downn,fs2.downn);
    int up = (fs1.upp*(down/fs1.downn)) + (fs2.upp*(down/fs2.downn));
    fs1.result[0] = up;
    fs1.result[1] = down;
    cout << up << "/" << down << endl;
    return 0;
}

int minuss(fs & fs1,fs & fs2)
{
    int flag = 0;
    int down = gbs(fs1.downn,fs2.downn);
    int up = (fs1.upp*(down/fs1.downn)) - (fs2.upp*(down/fs2.downn));
    cout << up << "/" << down << endl;
    return 0;
}

int mul(fs &fs1,fs &fs2)
{
    int up = fs1.upp * fs2.upp;
    int down = fs1.downn * fs2.downn;
    int x = ged(up,down);
    up = up/x;
    down = down/x;
    cout << up << "/" << down << endl;
    return 0;
}

int divv(fs &fs1,fs & fs2)
{
    int up = fs1.upp * fs2.downn;
    int down = fs1.downn * fs2.upp;
    int x = ged(up,down);
    up = up/x;
    down = down/x;
    cout << up << "/" << down << endl;
    return 0;
}

int main(){

    int t;
    cin >> t;
    fs fs1,fs2;
    while(t > 0)
    {
        fs1 = newnew();
        fs2 = newnew();
        int gbs,ged,temp,r;//ged最小公约数 gbs最大公倍数
        int a1 = fs1.downn;
        int a2 = fs2.downn;
        addd(fs1,fs2);
        minuss(fs1,fs2);
        mul(fs1,fs2);
        divv(fs1,fs2);
        t--;
        if(t != 0)
        {
            cout << endl;
        }
    }

    return 0;
}