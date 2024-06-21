#include<stdio.h>
#include<string.h>
int main(){

    double arr[233] = {0};
    double temp,sum = 0;
    int i = 0;
    while(1)
    {
        scanf("%lf",&temp);
        if(temp == 0)
            break;
        arr[i] = temp;
        i++;
    }
    i = 0;
    double* To_arr = &arr[0];
    while(arr[i] != 0)
    {
        sum = sum + *(To_arr + i) * 1.0;
        i++;
    }
    printf("%d %.4g",i,sum / i);
    return 0;
}