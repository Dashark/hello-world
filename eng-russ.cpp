//English-russian

#include <stdio.h>

int main ()
{
	int a, b, c, d, n;
	printf("旅行社有");
	scanf("%d", &a);
	printf("会英语");
	scanf("%d", &b);
	printf("会俄语");
	scanf("%d", &c);	
	printf("两样都不会有");
	scanf("%d", &d);
	
	n = a-((a-b)+(a-c)-d);
	if(n < 0)
	  printf("输入数据错误，无法计算");
	else
	  printf("两样都会有%d人", n);
		
	return 0;
 } 

  
