#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c,p,x1,x2;
	scanf("%f,%f,%f",&a,&b,&c);
	p=b*b-4*a*c;
	if(p<0)
		printf("没有实根");
	else if(p==0)
		printf("%.2f",-b/(2*a));
	else
		printf("%.2f %.2f",(-b+sqrt(p))/(2*a),(-b-sqrt(p))/(2*a));
	
}

