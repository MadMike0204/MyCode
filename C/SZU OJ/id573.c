#include<stdio.h>
int main()
{
    double tp[4] = {6.2619,6.6744,0.0516,0.8065};//DEYH
    const double *To_tp = &tp[0];
    int t;
    char flag;
    double temp,result;
    scanf("%d",&t);
    getchar();
    while(t>0)
    {
        scanf("%c",&flag);
        getchar();
        scanf("%lf",&temp);
        getchar();
        switch(flag)
        {
            case 'Y':
                result = temp * *(To_tp + 2);
                break;
            case 'D':
                result = temp * *(To_tp + 0);
                break;
            case 'H':
                result = temp * *(To_tp + 3);
                break;
            case 'E':
                result = temp * *(To_tp + 1);
                break;
        }
        printf("%.4lf\n",result);
        t--;
    }

    return 0;
}