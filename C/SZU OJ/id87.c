#include<stdio.h>
#include<math.h>
int main(){

    const double min = 0.0001;
    double t1,t2,s;
    scanf("%lf",&s);
    t1 = 50 + 1.0*s/3;
    t2 = s/1.2;
    if(t1<t2)
        printf("Bike");
    else if(t1>t2)
        printf("Walk");
    else if(fabs(t1-t2) < min)
        printf("All");

    return 0;
}