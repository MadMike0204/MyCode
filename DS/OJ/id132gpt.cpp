#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    int time;      // 事件发生的时间
    int guestId;   // 顾客的编号
    bool isArrival; // 是否为到达事件

    bool operator<(const Event& other) const {
        // 优先级队列默认是最大堆，所以我们需要反向比较
        return time > other.time;
    }
};

class Guest {
public:
    int id;
    bool VIP;
    int arrivalTime;
    int handlingTime;
    int startTime;   // 开始服务的时间
    int windowId;    // 服务的窗口编号

    Guest(int id_, int at, int ht, bool v) : id(id_), arrivalTime(at), handlingTime(ht), VIP(v) {
        if (handlingTime > 60)
            handlingTime = 60;
        startTime = -1;
        windowId = -1;
    }

    int getWaitingTime() const {
        if (startTime == -1)
            return 0;
        return startTime - arrivalTime;
    }
};

class LineUp {
private:
    int currentTime;
    int totalWindows;
    int vipWindow; // VIP 窗口编号，从 0 开始
    vector<Guest> guests;
    vector<queue<int>> windows; // 每个窗口服务的顾客编号
    vector<bool> windowAvailable; // 窗口是否空闲
    queue<int> normalQueue; // 普通顾客等待队列，存储顾客编号
    queue<int> vipQueue;    // VIP 顾客等待队列，存储顾客编号
    priority_queue<Event> eventQueue; // 事件队列
    vector<int> windowServiceCount; // 每个窗口服务的顾客数量

public:
    LineUp(int totalGuests, int totalWindows_, int vipWindow_) : currentTime(0), totalWindows(totalWindows_), vipWindow(vipWindow_ - 1) {
        windows.resize(totalWindows);
        windowAvailable.resize(totalWindows, true);
        windowServiceCount.resize(totalWindows, 0);

        // 读取顾客信息并创建到达事件
        for (int i = 0; i < totalGuests; ++i) {
            int arrivalTime, handlingTime, vipFlag;
            cin >> arrivalTime >> handlingTime >> vipFlag;
            bool isVIP = vipFlag == 1;
            guests.emplace_back(i, arrivalTime, handlingTime, isVIP);
            eventQueue.push({arrivalTime, i, true}); // 顾客到达事件
        }
    }

    void simulate() {
        while (!eventQueue.empty()) {
            Event currentEvent = eventQueue.top();
            eventQueue.pop();
            currentTime = currentEvent.time;

            if (currentEvent.isArrival) {
                // 顾客到达，加入相应的等待队列
                Guest& guest = guests[currentEvent.guestId];
                if (guest.VIP)
                    vipQueue.push(guest.id);
                else
                    normalQueue.push(guest.id);

                // 尝试为新到达的顾客分配窗口
                assignWindows();
            } else {
                // 顾客服务完成，释放窗口
                int windowId = guests[currentEvent.guestId].windowId;
                windowAvailable[windowId] = true;

                // 统计窗口服务数量
                windowServiceCount[windowId]++;

                // 尝试为等待中的顾客分配窗口
                assignWindows();
            }
        }

        // 输出统计信息
        outputStatistics();
    }

    void assignWindows() {
        // 优先为 VIP 窗口分配 VIP 顾客
        if (windowAvailable[vipWindow]) {
            if (!vipQueue.empty()) {
                int guestId = vipQueue.front();
                vipQueue.pop();
                serveGuest(guestId, vipWindow);
                return; // 每次只处理一个顾客
            }
        }

        // 为空闲的普通窗口分配顾客
        for (int i = 0; i < totalWindows; ++i) {
            if (windowAvailable[i]) {
                // 如果是 VIP 窗口，且已经检查过
                if (i == vipWindow && !windowAvailable[vipWindow])
                    continue;

                int guestId = -1;

                // 如果 VIP 窗口空闲，且 VIP 队列有顾客，VIP 顾客必须选择 VIP 窗口
                if (!vipQueue.empty() && i != vipWindow)
                    guestId = normalQueue.empty() ? -1 : normalQueue.front();
                else {
                    if (!vipQueue.empty()) {
                        guestId = vipQueue.front();
                        vipQueue.pop();
                    } else if (!normalQueue.empty()) {
                        guestId = normalQueue.front();
                        normalQueue.pop();
                    }
                }

                if (guestId != -1) {
                    serveGuest(guestId, i);
                    return; // 每次只处理一个顾客
                }
            }
        }
    }

    void serveGuest(int guestId, int windowId) {
        Guest& guest = guests[guestId];
        guest.startTime = currentTime;
        guest.windowId = windowId;
        windowAvailable[windowId] = false;

        // 创建服务完成事件
        int finishTime = currentTime + guest.handlingTime;
        eventQueue.push({finishTime, guestId, false});
    }

    void outputStatistics() {
        int totalWaitingTime = 0;
        int maxWaitingTime = 0;
        int finishingTime = 0;

        for (const auto& guest : guests) {
            int waitingTime = guest.getWaitingTime();
            totalWaitingTime += waitingTime;
            if (waitingTime > maxWaitingTime)
                maxWaitingTime = waitingTime;
            int completionTime = guest.startTime + guest.handlingTime;
            if (completionTime > finishingTime)
                finishingTime = completionTime;
        }

        double averageWaitingTime = totalWaitingTime / (double)guests.size();

        cout << "averageWaitingTime: " << averageWaitingTime << endl;
        cout << "MaxWaitingTime: " << maxWaitingTime << endl;
        cout << "finishingTime: " << finishingTime << endl;
        cout << "Numbers Of Guests Each Window have handled" << endl;
        for (int count : windowServiceCount) {
            cout << count << " ";
        }
        cout << endl;
    }
};

int main() {
    int totalGuests, totalWindows, vipWindow;
    cin >> totalGuests;

    cin >> totalWindows >> vipWindow;

    LineUp bank(totalGuests, totalWindows, vipWindow);
    bank.simulate();

    return 0;
}
