#include<iostream>
using namespace std;

void sortt(int(&arr)[3])
{
    int i,j,k,temp;
    for(i=0;i<2;i++)
    {
        k = i;
        for(j=k+1;j<3;j++)    
        {
            if(arr[k] < arr[j])
            {
                temp = arr[k];
                arr[k] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){

    int t;
    int arr[3];
    cin >> t;
    while(t>0)
    {   
        cin >> arr[0] >> arr[1] >> arr[2];
        sortt(arr);
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
        t--;
    }

    return 0;
}