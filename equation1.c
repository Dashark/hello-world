//æ±‚è§£ä¸€å…ƒäºŒæ¬¡æ–¹ç¨‹çš„æ ¹
//æŸ¥é˜…sqrt()å‡½æ•°
//æ³¨æ„æœ‰æ²¡æœ‰è§£
#include <stdio.h>
#include <math.h>
int main () {
	double a,b,c;
	double d;
	double x,x1,x2; 
	printf("ÇëÊäÈëÈı¸öÏµÊıa£¬b£¬c\n"); 
	scanf("%lf,%lf,%lf",&a,&b,&c);
	d=b*b-4*a*c;
	if(a==0) {
		if(b==0){
			if(c==0){
				printf("·½³ÌÎŞÒâÒå\n");							 
			}
			else{
				printf("·½³ÌÎŞ½â\n"); 
			}
		}
		else {
			x=-c/b;
			printf("·½³ÌÖ»ÓĞÒ»½âx=%lf\n",x); 
		}
	}
	else {
		if(d<0){
			printf("·½³ÌÎŞÊµÊı½â\n");
		}
		else{
			x1=(-b-sqrt(d))/(2*a);
			x2=(-b+sqrt(d))/(2*a);
			printf("·½³Ì½âÎªx1=%lf,x2=%lf",x1,x2);
		}
	}
	return 0;
}
