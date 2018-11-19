//回文数：正读与反读相等的数
//2018/11/14 更新
#include <stdio.h>
int main() {
	char num[1000];
	char a;
	int count = 0;
	int FLAG = 1;
	while ((a = getchar()) != '\n')
	{
		num[count] = a;
		char zero = '0';
		count++;
		printf("%d", a - zero);
	}
	for (int i = 0; (i + 1)*(i + 1) <= count; i++)
	{
		if (num[i] != num[count - i - 1])
		{
			FLAG = 0;
			break;
		}
	}
	if (FLAG)printf("是回文数\n");
	else printf("不是回文数\n");
	return 0;
}
