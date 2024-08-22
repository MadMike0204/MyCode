#include <iostream>
#include <iomanip>
using namespace std;

float GetScore(int *arr,int n)
{
    float result;
    int max = 0,min = 10,sum = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        if(arr[i] < min)
        {
            min = arr[i];
        }
        sum += arr[i];
    }
    sum = sum - max - min;
    result = sum*1.0/(n-2);
    return result;
}

int main()
{
    int n,m;
    float score,max_score = -1;
    cin >> n >> m;
    while(n--)
    {
        int arr[m];
        for(int i=0;i<m;i++)
        {
            cin >> arr[i];
        }
        score = GetScore(arr,m);
        if(score > max_score)
            max_score = score;
    }
    cout << fixed << setprecision(2) << max_score << endl;

    return 0;
}