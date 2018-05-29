/*A: 计算1 + （1 + 2） + （1 + 2 + 3） + （1 + 2 + 3 + ...... + n)的值

	描述：
	从键盘输入一个正整数n（1~1000），然后计算1 + （1 + 2） + （1 + 2 + 3） + ... + （1 + 2 + 3 + ... + n）的值

	输入：
	正整数n
	输出：
	1 + （1 + 2） + （1 + 2 + 3） + ... + （1 + 2 + 3 + ... + n）的值*/
#include<iostream>
int mainA()
{
	int n;
	std::cin >> n;
	int i = 1, tmp = 0, sum = 0;
	for (; i <= n; i++)
	{
		tmp += i;
		sum += tmp;
	}
	std::cout << sum << std::endl;

	return 0;
}