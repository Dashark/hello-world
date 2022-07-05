#include <stdio.h>
#include <math.h>
int main(){
	printf("ÇëÊäÈëÏµÊıy£¬a£¬b£¬c£º");
	float x1,x2,y,a,b,c;
	scanf("%f,%f,%f,%f",&y,&a,&b,&c);
	c = c-y;
	float temp = sqrt(b*b-4*a*c);
	a = 2*a; 
	x1 = (-b + temp)/(a);
	x2 = (-b - temp)/(a);
	printf("x1 = %f\n",x1);
	printf("x2 = %f\n",x2);
	return 0;
} 
// x*x + 10*x +17 = y
