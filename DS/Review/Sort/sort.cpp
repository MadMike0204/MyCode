#include<iostream>
using namespace std;
void InsertSort(int arr[],int length){

    for(int i=1;i<length;i++){
        for(int j=i-1;j>=0 && arr[j] > arr[j+1];j--){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}
void ShellSort(int arr[],int length){
    int gap = length;
    while(gap > 1){
        gap /= 2;
        for(int i=gap;i<length;i++){
            int temp;
            if(arr[i - gap] < arr[i]){
                temp = arr[i];
                int j = i - gap;
                while(j >= 0 && arr[j] > temp){
                    arr[j + gap] = arr[j];
                    j -= gap;
                } 
                arr[j+gap] = temp;
            }
        }
    }
}

int main(){

    int length = 10;
    int arr[10] = {-1,233,65,923,4,809,-71,40,21,4};
    InsertSort(arr,10);

    for(int i=0;i<length;i++)   cout << arr[i] << " ";
    return 0;
}


void shell(int length,int arr[]){
    int gap = length;
    while(gap > 1){
        gap /= 2;
        for(int i=gap;i<length;i++){
            int temp;
            if(arr[i-gap] < arr[i]){
                temp = arr[i];
                int j = i - gap;
                while(j >= 0 && arr[j] > temp){
                    arr[j+gap] = arr[j];
                    j -= gap;
                }
                arr[j+gap] = temp;
            }
        }
    }
}