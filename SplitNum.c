//输入整数，将每位数字打印出来（从左向右打印，空格区分）
//2018/11/14 更新
#include<stdio.h>
int main() {
	char num[1000];
	char a;
	char zero = '0';
	int FLAG = 1;
	while ((a = getchar()) != '\n')
	{   
		if (FLAG)
		{
			printf("%d", a - zero);
			FLAG = 0;
		}
		else printf("% d", a - zero);

	}
	printf("\n");
	return 0;
}
