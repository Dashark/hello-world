#include<stdio.h>
#include<math.h>
double times(double a,int b){
	if(b==0)return 1;double x=a;
	while(--b) a*=x;
	return a;
}
double power_1(double a,double bd1,double bd2){
	if(bd2-bd1<0.000000001 || times((bd2+bd1)/2,10)==a) return (bd2+bd1)/2;
	return times((bd2+bd1)/2,10)>a ? power_1(a,bd1,(bd2+bd1)/2) : power_1(a,(bd2+bd1)/2,bd2);
}
double power(double a,double b,int n,int i,double total){
	double c=times(a,(int)b);
	for(i=1;i<n+1;i++) c=power_1(c,c>=1?1:c,c>=1?c:1);
	return (int)b==b? total*c : power(a,10*(b-(int)b),n+1,i,total*c);
}
int main(){
	double x,y;
	scanf("%lf %lf",&x,&y);
	printf("C's answer:%lf\nMy  answer:%lf\n",pow(x,y),power(x,10*(y-(int)y),1,1,times(x,(int)y)));
	return 0;
}
