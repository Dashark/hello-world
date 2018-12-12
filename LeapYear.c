#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	if(n%4==0&&n%100!=0||n%400==0)
	printf("%d是闰年",n);
	else
	printf("%d不是闰年",n);
	return 0;
}
