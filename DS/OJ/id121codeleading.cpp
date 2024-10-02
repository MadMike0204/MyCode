#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    int i, j, n;
    cin>>n;//n代表组数
    queue<int> Q[n];//定义n个队列共同构成组队列
    int num[n];//记录每组中的元素个数
    int **a;//二维数组记录每组的各个元素
    a = new int*[n];
    for(i=0; i<n; i++)
    {
        cin>>num[i];
        a[i] = new int[num[i]];
        for(j=0; j<num[i]; j++)
            cin>>a[i][j];
    }
    int s[n];//状态数组，标识该组是否已经有元素在组队列中
    for(i=0; i<n; i++)
        s[i] = 0;//初始组队列为空，s全置为0
    int k1 = 0, k2 = 0;//k1和k2分别指示组队列中存在元素队列的下标最小值和最大值
    int count = 0;//count记录有多少个DEQUEUE，stop后一起处理
    string c;
    while(cin>>c)///
    {
        if(c=="STOP")
            break;
        else if(c=="ENQUEUE")
        {
            int temp;
            cin>>temp;
            for(i=0; i<n; i++)
            {//定位输入数值所在组的下标
                for(j=0; j<num[i]; j++)
                    if(temp==a[i][j])
                        break;
                if(j!=num[i])
                    break;
            }
            if(!s[i])
            {//如果组队列中没有同组元素，就在k2（即组队列尾）位置入队，并置s为1
                Q[k2].push(temp);
                k2++;
                s[i] = 1;
            }
            else
            {//如果有同组元素，就定位出同组元素所在队列的下标，并入队
                for(j=k1; j<k2; j++)
                {
                    int r;
                    int x = Q[j].front();
                    for(r=0; r<num[i]; r++)
                        if(x==a[i][r])
                        {
                            Q[j].push(temp);
                            break;
                        }
                    if(r!=num[i])
                        break;
                }
            }
        }
        else if(c=="DEQUEUE")
            count++;
    }
    for(i=0; i<count; i++)
    {
        int temp = Q[k1].front();
        Q[k1].pop();
        if(i!=count-1)
            cout<<temp<<' ';
        else
            cout<<temp<<endl;
        if(Q[k1].empty())
            k1++;
    }
    return 0;
}
