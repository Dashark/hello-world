/*D: 上楼楼梯
	上N阶楼梯，一次可以走两阶或一阶，问有多少种上楼方式。

	输入
	正整数N, 1 <= N <= 30

	输出
	上楼方式数*/
#include<iostream>
int f(int n);
int mainD()
{
	int n;
	std::cin >> n;
	std::cout << f(n) << std::endl;
	return 0;

}

int f(int n)
{
	if (n == 1||n==2)
		return n;
	else
		return f(n - 1) + f(n - 2);
}