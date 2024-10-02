#include<iostream>
#include<queue>
#include<iomanip>
using namespace std;

class Guest
{
    private:
        bool VIP;
        int arrivalTime;
        int handlingTime;
        int waitingTime;
    public:
        Guest(int at=0,int ht=0,bool v=0):VIP(v),arrivalTime(at),handlingTime(ht)
        {
            if(handlingTime > 60)
                handlingTime = 60;
        }
        void InitialGuest(int at,int ht,bool v)
        {
            arrivalTime = at;
            handlingTime = ht;
            VIP = v;
        }
        void SetWaitingTime(int wt)
        {
            waitingTime = wt;
        }
        bool IsVip()
        {
            return VIP;
        }
        int GetArrivalTime()
        {
            return arrivalTime;
        }
        int GetHandlingTime()
        {
            return handlingTime;
        }
        int GetWaitingTime()
        {
            return waitingTime;
        }
};
class LineUp
{
        static int currentTime;
    private:
        queue<Guest> myGuests;
        queue<Guest>* windows;
        queue<Guest> finishedGuests;
        int* numbersOfHandledGuestsEachWindow;
        int completionTime;
        int totalGuests;
        int totalWindows;
        int guestsLeft;
        bool* windowsHaveOccupied;
        int frames;
        int vipWindow;
        int vips;
        int finishedVips;
    public:
        LineUp();
        ~LineUp();
        void InitialQueue(int tG);
        void InitialWindows(int tW);
        bool HaveWindowIdle();
        int UpdateNextFrame();
        int UpdateWindows();
        int AssignNextGuest();
        void WindUp();
        int GetNextTimeToUpdate();
        Guest GetNextVipInTime();
        
};

int LineUp::currentTime = 0;

LineUp::LineUp()
{
    guestsLeft = 0;
    frames = 0;
    vips = 0;
}

LineUp::~LineUp()
{}

void LineUp::InitialQueue(int tG)
{
    totalGuests = tG;
    int arrivalTime,handlingTime;
    bool VIP;
    for(int i=0;i<totalGuests;i++)
    {
        cin >> arrivalTime >> handlingTime >> VIP;
        if(VIP)
        {
            vips++;
        }
        myGuests.push(Guest(arrivalTime,handlingTime,VIP));
    }
    guestsLeft = totalGuests;
}

void LineUp::InitialWindows(int tW)
{
    cin >> vipWindow;
    totalWindows = tW;
    windows = new queue<Guest>[totalWindows];
    numbersOfHandledGuestsEachWindow = new int[totalWindows];
    windowsHaveOccupied = new bool[totalWindows];

    for(int i=0;i<totalWindows;i++)
    {
        windowsHaveOccupied[i] = 0;
        numbersOfHandledGuestsEachWindow[i] = 0;
    }
}

int LineUp::UpdateNextFrame()
{
    frames++;
    // 判断剩余队列是否为空
    // 如果为空,则进行收尾,return 1
    if(myGuests.empty())
    {
        WindUp();
        return 1;
    }
    // 根据下一个顾客的到来时间进行更新
    Guest next = myGuests.front();
    if(next.GetArrivalTime() > currentTime)
    {
        currentTime = next.GetArrivalTime();
        int finishingTime;

        // 强制更新机制 修复了死循环的bug 啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
        Guest curGuest;
        for(int i=0;i<totalWindows;i++)
        {
            if(!windows[i].empty())
            {
                curGuest = windows[i].front();

                finishingTime = curGuest.GetArrivalTime() + curGuest.GetWaitingTime() + curGuest.GetHandlingTime();
                if(finishingTime <= currentTime)
                {
                    finishedGuests.push(windows[i].front());
                    windows[i].pop();
                    windowsHaveOccupied[i] = 0;
                }
            }
        }
    }
    // 判断窗口是否有空
    // 如果有空,根据规则分配顾客,return 0
    if(HaveWindowIdle())
    {
        if(AssignNextGuest())
            return 0;
    }
    // 找出距离下一次有窗口空余的时间差t
    // 更新t,匹配同时完成的对象
    // 根据t,对窗口进行更新(完成的pop,同时顾客进入Finished队列),return 0
    int timeLag = GetNextTimeToUpdate();
    //
    int timeLagOfGuest;
    Guest curGuest;

    for(int i=0;i<totalWindows;i++)
    {
        if(!windows[i].empty())
        {
            curGuest = windows[i].front();
            timeLagOfGuest = curGuest.GetWaitingTime() + curGuest.GetArrivalTime() + curGuest.GetHandlingTime() - currentTime;
            if(timeLagOfGuest == timeLag)
            {
                finishedGuests.push(windows[i].front());
                windows[i].pop();
                windowsHaveOccupied[i] = 0;
            }
        }
    }
    currentTime += timeLag;//
    return 0;
}
int LineUp::UpdateWindows()
{
    return 0;
}

int LineUp::AssignNextGuest()
{
    // 排队的时候,要先查看当前时间是否已经到达
    // 判断有无VIP窗口的空余
    // 如果有VIP窗口空余
        // 判断队列中有无VIP
        // 如果有VIP,为VIP分配位置,更新guest等待时间,return 1
    // 按顺序为下一个顾客分配,更新guest等待时间,return 1
    // return 1 表示分配成功
    // return 0 表示分配失败(可以分配的人还没到)
    int waitingTime;
    Guest vip,next;
    queue<Guest> tempGuests = myGuests;
    if(windows[vipWindow].empty())
    {
        if(vips)
        {
            vip = GetNextVipInTime();
            if(vip.GetHandlingTime() != 0)
            {
                // 设置等待时间
                waitingTime = currentTime-vip.GetArrivalTime();
                if(waitingTime > 0)
                    vip.SetWaitingTime(waitingTime);
                else
                    vip.SetWaitingTime(0);
                vips--;
                windows[vipWindow].push(vip);
                windowsHaveOccupied[vipWindow] = 1;
                //更新
                numbersOfHandledGuestsEachWindow[vipWindow]++;
                return 1;
            }
        }
    }
    next = myGuests.front();
    if(next.GetArrivalTime() > currentTime)
        return 0;

    myGuests.pop();
    for(int i=0;i<totalWindows;i++)
    {
        if(windows[i].empty())
        {
            // 设置等待时间
            waitingTime = currentTime-next.GetArrivalTime();
            if(waitingTime > 0)
                next.SetWaitingTime(waitingTime);
            else
                next.SetWaitingTime(0);
            
            if(next.IsVip())
                vips--;
            windows[i].push(next);
            windowsHaveOccupied[i] = 1;
            // 更新
            numbersOfHandledGuestsEachWindow[i]++;
            return 1;
        }
    }
    return 0;
}

void LineUp::WindUp()
{  
    int maxWaitingTime = -1,sum = 0;
    int curWaitingTime;

    int finishingTime = 0;
    int tp;

    for(int i=0;i<totalWindows;i++)
    {
        if(windows[i].empty())
            continue;
            
        Guest temp = windows[i].front();
        tp = temp.GetArrivalTime() + temp.GetHandlingTime() + temp.GetWaitingTime();
        if(tp > finishingTime)
            finishingTime = tp;
        finishedGuests.push(temp);
        windows[i].pop();
    }

    while(!finishedGuests.empty())
    {
        curWaitingTime = finishedGuests.front().GetWaitingTime();
        sum += curWaitingTime;
        if(maxWaitingTime < curWaitingTime)
        {
            maxWaitingTime = curWaitingTime;
        }
        finishedGuests.pop();
    }

    double averageWaitingTime = sum * 1.0 / totalGuests;

    cout << fixed << setprecision(1) << averageWaitingTime;
    cout << " " << maxWaitingTime << " " << finishingTime << endl;
    for(int i=0;i<totalWindows;i++)
    {
        printf(i==0?"%d":" %d",numbersOfHandledGuestsEachWindow[i]);
    }
    // cout << "averageWaitingTime:" << averageWaitingTime << endl
    //      << "MaxWatingTime:" << maxWaitingTime << endl
    //      << "finishingTime:" << finishingTime << endl;

    // cout << "Numbers Of Guests Each Window have handled" << endl;
    // for(int i=0;i<totalWindows;i++)
    // {
    //     cout << numbersOfHandledGuestsEachWindow[i] << " ";
    // }
    // cout << endl;
}

bool LineUp::HaveWindowIdle()
{
    for(int i=0;i<totalWindows;i++)
    {
        if(!windowsHaveOccupied[i])
            return 1;
    }
    return 0;
}

int LineUp::GetNextTimeToUpdate()
{
    int minimalTime = 999;
    int timeLag;
    Guest curGuest;
    for(int i=0;i<totalWindows;i++)
    {
        if(!windows[i].empty())
        {
            curGuest = windows[i].front();
            timeLag = curGuest.GetWaitingTime() + curGuest.GetArrivalTime() + curGuest.GetHandlingTime() - currentTime;
            if(timeLag < minimalTime)
            {
                minimalTime = timeLag;
            }
        }
    }
    return minimalTime;
}
Guest LineUp::GetNextVipInTime()
{
    Guest vip = Guest(0,0,0);
    bool found = 0;
    queue<Guest> tempGuests;
    while(!myGuests.empty())
    {
        Guest element = myGuests.front();
        myGuests.pop();
        if(!found && element.IsVip() && element.GetArrivalTime() <= currentTime)
        {
            vip = element;
            found = 1;
            continue;
        }
        tempGuests.push(element);
    }
    while(!tempGuests.empty())
    {
        myGuests.push(tempGuests.front());
        tempGuests.pop();
    }
    return vip;
}

int main(){

    int totalGuests,totalWindows;
    LineUp jojo;

    cin >> totalGuests;
    jojo.InitialQueue(totalGuests);

    cin >> totalWindows;
    jojo.InitialWindows(totalWindows);

    while(!jojo.UpdateNextFrame())
    {}


    return 0;
}