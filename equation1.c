#include <stdio.h>
#include <math.h>
int main(){
	float a,b,c,d,x1,x2;
	scanf("%f %f %f",&a,&b,&c);
	d=b*b-4*a*c;
	if(d>0){
		x1=(-b+sqrt(d))/(2*a);
		x2=-b/a-x1;
		printf("x1=%f\nx2=%f",x1,x2);
	}
		else if(d==0){
			x1=(-b)/(2*a);
			x2=x1;
			printf("有唯一解x=%f",x1);
		}
	else
		printf("无解"); 
	return 0;
}
