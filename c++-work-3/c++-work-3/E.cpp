/*E: 多个数的最大公约数
	描述

	求多个正整数的最大公约数

	输入

	每个测试输入包含1个测试用例，格式为
	第1行，数据的组数n
	第2行，第一组数据(数据之间以逗号隔开），
	第3行，第二组数据，
	...
	第n + 1行，第n组数据

	输出

	输出每组数据中的最大公约数*/
#include<iostream>
#include<string>
int f(int*a, int n);
int mainE()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::string a;
		std::cin >> a;
		int *b= new int [10];
		int sum = 0, k = 0;
		for (int j = 0; a[j] != '\0'; j++)
		{
			if (a[j] != ',')
				sum = sum * 10 + (a[j]-'0');
			else
			{
				b[k] = sum;
				sum = 0;
				k++;
			}

		}
		std::cout << f(b, k) << std::endl;
	}
	return 0;
}

int f(int*a, int n)
{
	int m = a[0];
	for (int i = 0; i < n-1; i++)
		while (a[i+1]!= 0)
		{
		 int r = m % a[i+1];
		 m = a[i+1];
		 a[i+1]= r;
		}
	return m;
}