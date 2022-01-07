#include<stdio.h>

int main(){
	float a,b,c;
	float u;
	printf("请输入待开方数：\n");
	scanf("%f",&u);
	a=0.0f,b=u;
	c=(a+b)/2;
	while(b-a>0.0001){
		if(c*c>=u){
			b=c;
			c=(a+b)/2;
		}else if(c*c<u){
			a=c;
			c=(a+b)/2;
		}
	}
	printf("%.2f",c);
	return 0;
}
