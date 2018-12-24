//回文数：正读与反读相等的数
//2018/11/14 更新
#include<stdio.h>
#include<stdlib.h>
	int main()
	{
	//to do sth
		int n;
		scanf("%d", &n);//输入要测试几组数据
		for (int i = 0;i < n;i++)
		{
			int x,y,z,s,k,t;
			k = 0;
			s = 0;
			t = 1;
			scanf("%d", &x);//输入要测试的数据
			z=y = x;
			do              //读取为几位数
			{
				y = y / 10;
				k += 1;
			} while (y != 0);
			for (int j = 1;j < k;j++)//用来计算最高位
			{
				t = t * 10;
			}
			for (int j=0;j<k;j++)//用来进行倒序
			{
				y = z % 10;
				z = z / 10;
				s = s + y*t;
				t = t / 10;
			}
			if (s == x)//判断是否为回文数
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
		}
		system("pause");
		return 0;
	}

