/*C: 转置矩阵
	描述

	求一个矩阵的转置矩阵。

	输入

	输入整数m和n分别代表一个矩阵的行和列。再输入m*n个整数作为矩阵的元素。

	输出

	若m和n能构成矩阵，则输出原矩阵及其转置矩阵；否则输出NO。

	注意：输入和输出数字两两之间由一个空格隔开*/
#include<iostream>
int mainC()
{
	int m, n;
	std::cin >> m >> n;
	if (m*n!=0)
	{
		int a[100][100];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				std::cin >> a[i][j];
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				std::cout << a[i][j]<<" ";
			std::cout << std::endl;
		}
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; i++)
				std::cout << a[i][j]<<" ";
			std::cout << std::endl;
		}
	}
	else
		std::cout << "NO";
	return 0;

}