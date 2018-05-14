#include<cstdio>
#include<cmath>
int fa(int m);
int fb(int m);
int maintwo()
{
	printf("本函数求100~9999以内的所有超级素数\n");
	int count = 0, a[20], sum=0, i;
	for (i = 100; i <= 9999; i++)
	{
		if (fb(i) == 1)//判断该数是否为超级素数，并将其存储到数组中 
		{
			a[count] = i;
			count++;
		}

	}
	printf("超级素数个数为%d，分别为：\n", count);
	for (i = 0; i<count; i++)
	{
		sum = sum + a[i];
		printf("%d\n", a[i]);
	}
	printf("所有超级素数之和为%d,最大的超级素数为%d\n", sum, a[count - 1]);
	return 0;
}

int fa(int m)//判断一个数是否为素数 
{
	int flag = 0;//设置标记 
	if (m != 1)
	{
		float t = sqrt(m);//使判断次数有效减少 
		int count = 0, i = 1;
		for (; i <= t; i++)
			if (m%i == 0)
				count++;
		if (count == 1)
			flag = 1;
	}

	return flag;
}

int fb(int i)//判断一个数是否为超级素数 
{
	int flag = 0;//设置标记 
	int sum, mult, sumu;//对一个整数的各个位数求和，求积，求平方和 
	sum = i % 10 + (i / 10) % 10 + (i / 100) % 10 + i / 1000;
	if (i / 1000 == 0)
		mult = (i % 10)*((i / 10) % 10)*((i / 100) % 10);
	else
		mult = (i % 10)*((i / 10) % 10)*((i / 100) % 10)*(i / 1000);
	sumu = (i % 10)*(i % 10) + ((i / 10) % 10)*((i / 10) % 10) + ((i / 100) % 10)*((i / 100) % 10) + (i / 1000)*(i / 1000);
	if (fa(sum) == 1 && fa(mult) == 1 && fa(sumu) == 1)
		flag = 1;
	return flag;
}