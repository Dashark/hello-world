/*F: 子序列
	描述

	输入两个字符串s和t，判断是否可以从s中删除0个或多个字符(其他字符顺序不变)得到字符串t。

	输入

	分别输入两个字符串s和t，分别占一行。

	输出

	满足匹配条件，输出YES
	不满足匹配条件，输出NO*/
#include<iostream>
#include<string>
int mainF()
{
	std::string str1,str2;
	std::cin >> str1;
	std::cin >> str2;
	if (str1.find(str2) != -1)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
	return 0;
}