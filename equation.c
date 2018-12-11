#include <stdio.h>
int main(){
	double a,b,c,d,e,f,x,y;
	scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);
	y=(c*d-a*f)/(b*d-a*e);
	x=(c-b*y)/a;
	printf("%lf %lf",x,y);
	return 0;
}
