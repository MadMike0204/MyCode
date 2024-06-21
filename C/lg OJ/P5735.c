#include<stdio.h>
#include<math.h>

double Distance(const double x[3],const double y[3]){

    double sum=0,d;

    sum += sqrt( pow(x[0]-x[1],2) + pow(y[0]-y[1],2) );
    sum += sqrt( pow(x[0]-x[2],2) + pow(y[0]-y[2],2) );
    sum += sqrt( pow(x[1]-x[2],2) + pow(y[1]-y[2],2) );

    return sum;
}

int main(){

    double x[3],y[3];
    int i;
    for(i=0;i<3;i++)
    {
        scanf("%lf %lf",&x[i],&y[i]);
    }
    printf("%.2lf",Distance(x,y));

    return 0;
}