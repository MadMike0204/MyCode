#include<iostream>
#include<queue>
using namespace std;

int main(){

    int N,id;
    cin >> N;
    queue<int>oddIds,evenIds,totalQueue;
    while(N--)
    {
        cin >> id;
        if(id % 2 == 0)
        {
            evenIds.push(id);
        }
        else
        {
            oddIds.push(id);
        }
    }
    while(1)
    {
        if(oddIds.empty() || evenIds.empty())
            break;

        id = oddIds.front();
        oddIds.pop();
        cout << id;
        if(oddIds.empty() && evenIds.empty())
            break;
        else
            cout << " ";

        if(oddIds.empty())
            break;

        id = oddIds.front();
        oddIds.pop();
        cout << id;

        if(oddIds.empty() && evenIds.empty())
            break;
        else
            cout << " ";

        id = evenIds.front();
        evenIds.pop();
        cout << id;

        if(oddIds.empty() && evenIds.empty())
            break;
        else
            cout << " ";
    }
    while(!oddIds.empty())
    {
        id = oddIds.front();
        oddIds.pop();
        cout << id;
        if(oddIds.empty())
        {
            break;
        }
        cout << " ";
    }
    while(!evenIds.empty())
    {
        id = evenIds.front();
        evenIds.pop();
        cout << id;
        if(evenIds.empty())
        {
            break;
        }
        cout << " ";
    }

    return 0;
}