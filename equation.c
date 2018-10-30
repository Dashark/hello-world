//æ±‚è§£å¦‚ä¸‹æ–¹ç¨‹ç»„
//ax + by = c
//dx + ey = f
//æ³¨æ„è¾“å…¥/è¾“å‡ºï¼Œæ•°æ®ç±»å‹

#include <stdio.h>
int main (){
	double a,b,c,d,e,f;
	double x,y;
	printf("ÇëÊäÈëÈı¸öÏµÊıa£¬b£¬c\n");
	scanf ("%lf,%lf,%lf",&a,&b,&c);
	printf("%lfx+%lfy=%lf\n",a,b,c);
	printf("ÇëÊäÈëÈı¸öÏµÊıd£¬e£¬f\n");
	scanf ("%lf,%lf,%lf",&d,&e,&f);	
	printf("%lfx+%lfy=%lf\n",d,e,f);
	x=(c*e-b*f)/(a*e-b*d);
	y=(c*d-a*f)/(b*d-a*e);
	printf("·½³Ì½âÎªx=%lf,y=%lf",x,y);
	return 0;
} 
