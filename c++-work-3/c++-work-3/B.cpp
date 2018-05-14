/*B: 9进制数转换为2进制数
	描述

	输入一个9进制数，输出其对应的2进制数

	输入

	第一行是一个整数n，表示一共有n组测试用例；
	下面一共有n组输入，每组输入为一个正整数，表示一个9进制数

	输出

	对于每一组输入数据，输出其对应2进制数，每组输出单独占一行*/
#include<iostream>
#include<cmath>
int change(int n);
int mainB()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int text;
		std::cin >> text;
		std::cout << change(text) << std::endl;
	}
	return 0;
}
int change(int n)
{
	int sum = 0,i=0;
	for (; n > 0; i++)
	{
		sum = sum + (n % 10)*pow(9, i);
		n = n / 10;
	}
	int result = 0,k=1;
	while(sum)
	{
		i = sum % 2;
		result = k*i + result;
		k = k * 10;
		sum /= 2;
	}
	return result;
}