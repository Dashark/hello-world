//素数是只有1和本身是因子的数
//2018/11/14 更新
#include<stdio.h>
int main() {
	int a;
	while (scanf("%d", &a) != EOF)
	{
		int FLAG = 0;
		for (int i = 2; i*i <= a; i++)
		{   
			if (a%i==0)
			{
				FLAG = 1;
				break;
			}
		}
		if (a == 1)
		{
			printf("1既不是素数也不是合数\n");
			continue;
		}
		if (FLAG == 0)printf("%d是素数\n", a);
		else printf("%d是合数\n", b);

    }
	return 0;
}
